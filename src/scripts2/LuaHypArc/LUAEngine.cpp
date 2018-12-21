/*************************************************************\
|                           LuaHypArc                         |
|                      ==================                     |
|                   An extension of LUAppArc                  |
|                                                             |
|                     luahyparc.zapto.org                     |
\*************************************************************/

#include "StdAfx.h"
#include "LUAEngine.h"
#include "LUAFunctions.h"
#include <ScriptSetup.h>

#ifdef WIN32
	#pragma warning(disable:4129)
#endif

#if PLATFORM != PLATFORM_WIN32
#include <dirent.h>
#endif

bool lua_is_starting_up = false;
ScriptMgr * m_scriptMgr;
LuaEngineMgr g_luaMgr;
LuaEngine * g_engine;

extern "C" SCRIPT_DECL uint32 _exp_get_script_type()
{ 
	return SCRIPT_TYPE_SCRIPT_ENGINE | SCRIPT_TYPE_SCRIPT_ENGINE_LUA;
}

extern "C" SCRIPT_DECL void _exp_script_register(ScriptMgr* mgr)
{
	m_scriptMgr = mgr;
	g_luaMgr.Startup();
}

template<typename T> const char * GetTClassName() { return "UNKNOWN"; }

template<>
const char * GetTClassName<Unit>()
{
	return "Unit";
}

template<>
const char * GetTClassName<Item>()
{
	return "Item";
}

template<>
const char * GetTClassName<GameObject>()
{
	return "GameObject";
}

template<typename T>
struct RegType
{
	const char * name;
	int(*mfunc)(lua_State*,T*);
};

#include "FunctionTables.cpp" // >.<

template<typename T> RegType<T>* GetMethodTable() { return NULL; }
template<>
RegType<Unit>* GetMethodTable<Unit>() { return UnitMethods; }

template<>
RegType<Item>* GetMethodTable<Item>() { return ItemMethods; }

template<>
RegType<GameObject>* GetMethodTable<GameObject>() { return GOMethods; }

template <typename T> class Lunar {
	typedef struct { T *pT; } userdataType;
public:
	typedef int (*mfp)(lua_State *L, T* ptr);
	typedef struct { const char *name; mfp mfunc; } RegType;

	static void Register(lua_State *L) {
		lua_newtable(L);
		int methods = lua_gettop(L);

		luaL_newmetatable(L, GetTClassName<T>());
		int metatable = lua_gettop(L);

		// store method table in globals so that
		// scripts can add functions written in Lua.
		lua_pushvalue(L, methods);
		set(L, LUA_GLOBALSINDEX, GetTClassName<T>());

		// hide metatable from Lua getmetatable()
		lua_pushvalue(L, methods);
		set(L, metatable, "__metatable");

		lua_pushvalue(L, methods);
		set(L, metatable, "__index");

		lua_pushcfunction(L, tostring_T);
		set(L, metatable, "__tostring");

		lua_pushcfunction(L, gc_T);
		set(L, metatable, "__gc");

		lua_newtable(L);                // mt for method table
		lua_pushcfunction(L, new_T);
		lua_pushvalue(L, -1);           // dup new_T function
		set(L, methods, "new");         // add new_T to method table
		set(L, -3, "__call");           // mt.__call = new_T
		lua_setmetatable(L, methods);

		// fill method table with methods from class T
		for (RegType *l = ((RegType*)GetMethodTable<T>()); l->name; l++) {
			lua_pushstring(L, l->name);
			lua_pushlightuserdata(L, (void*)l);
			lua_pushcclosure(L, thunk, 1);
			lua_settable(L, methods);
		}

		lua_pop(L, 2);  // drop metatable and method table
	}

	// call named lua method from userdata method table
	static int call(lua_State *L, const char *method,
		int nargs=0, int nresults=LUA_MULTRET, int errfunc=0)
	{
		int base = lua_gettop(L) - nargs;  // userdata index
		if (!luaL_checkudata(L, base, T::className)) {
			lua_settop(L, base-1);           // drop userdata and args
			lua_pushfstring(L, "not a valid %s userdata", T::className);
			return -1;
		}

		lua_pushstring(L, method);         // method name
		lua_gettable(L, base);             // get method from userdata
		if (lua_isnil(L, -1)) {            // no method?
			lua_settop(L, base-1);           // drop userdata and args
			lua_pushfstring(L, "%s missing method '%s'", T::className, method);
			return -1;
		}
		lua_insert(L, base);               // put method under userdata, args

		int status = lua_pcall(L, 1+nargs, nresults, errfunc);  // call method
		if (status) {
			const char *msg = lua_tostring(L, -1);
			if (msg == NULL) msg = "(error with no message)";
			lua_pushfstring(L, "%s:%s status = %d\n%s",
				T::className, method, status, msg);
			lua_remove(L, base);             // remove old message
			return -1;
		}
		return lua_gettop(L) - base + 1;   // number of results
	}

	// push onto the Lua stack a userdata containing a pointer to T object
	static int push(lua_State *L, T *obj, bool gc=false) {
		if (!obj) { lua_pushnil(L); return 0; }
		luaL_getmetatable(L, GetTClassName<T>());  // lookup metatable in Lua registry
		if (lua_isnil(L, -1)) luaL_error(L, "%s missing metatable", GetTClassName<T>());
		int mt = lua_gettop(L);
		subtable(L, mt, "userdata", "v");
		userdataType *ud =
			static_cast<userdataType*>(pushuserdata(L, obj, sizeof(userdataType)));
		if (ud) {
			ud->pT = obj;  // store pointer to object in userdata
			lua_pushvalue(L, mt);
			lua_setmetatable(L, -2);
			if (gc == false) {
				lua_checkstack(L, 3);
				subtable(L, mt, "do not trash", "k");
				lua_pushvalue(L, -2);
				lua_pushboolean(L, 1);
				lua_settable(L, -3);
				lua_pop(L, 1);
			}
		}
		lua_replace(L, mt);
		lua_settop(L, mt);
		return mt;  // index of userdata containing pointer to T object
	}

	// get userdata from Lua stack and return pointer to T object
	static T *check(lua_State *L, int narg) {
		userdataType *ud =
			static_cast<userdataType*>(luaL_checkudata(L, narg, GetTClassName<T>()));
		if(!ud) { luaL_typerror(L, narg, GetTClassName<T>()); return NULL; }
		return ud->pT;  // pointer to T object
	}

private:
	Lunar();  // hide default constructor

	// member function dispatcher
	static int thunk(lua_State *L) {
		// stack has userdata, followed by method args
		T *obj = check(L, 1);  // get 'self', or if you prefer, 'this'
		lua_remove(L, 1);  // remove self so member function args start at index 1
		// get member function from upvalue
		RegType *l = static_cast<RegType*>(lua_touserdata(L, lua_upvalueindex(1)));
		//return (obj->*(l->mfunc))(L);  // call member function
		return l->mfunc(L,obj);
	}

	// create a new T object and
	// push onto the Lua stack a userdata containing a pointer to T object
	static int new_T(lua_State *L) {
		lua_remove(L, 1);   // use classname:new(), instead of classname.new()
		T *obj = NULL/*new T(L)*/;  // call constructor for T objects
		assert(false);
		push(L, obj, true); // gc_T will delete this object
		return 1;           // userdata containing pointer to T object
	}

	// garbage collection metamethod
	static int gc_T(lua_State *L) {
		if (luaL_getmetafield(L, 1, "do not trash")) {
			lua_pushvalue(L, 1);  // dup userdata
			lua_gettable(L, -2);
			if (!lua_isnil(L, -1)) return 0;  // do not delete object
		}
		userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
		T *obj = ud->pT;
		if (obj) delete obj;  // call destructor for T objects
		return 0;
	}

	static int tostring_T (lua_State *L) {
		char buff[32];
		userdataType *ud = static_cast<userdataType*>(lua_touserdata(L, 1));
		T *obj = ud->pT;
		sprintf(buff, "%p", obj);
		lua_pushfstring(L, "%s (%s)", GetTClassName<T>(), buff);
		return 1;
	}

	static void set(lua_State *L, int table_index, const char *key) {
		lua_pushstring(L, key);
		lua_insert(L, -2);  // swap value and key
		lua_settable(L, table_index);
	}

	static void weaktable(lua_State *L, const char *mode) {
		lua_newtable(L);
		lua_pushvalue(L, -1);  // table is its own metatable
		lua_setmetatable(L, -2);
		lua_pushliteral(L, "__mode");
		lua_pushstring(L, mode);
		lua_settable(L, -3);   // metatable.__mode = mode
	}

	static void subtable(lua_State *L, int tindex, const char *name, const char *mode) {
		lua_pushstring(L, name);
		lua_gettable(L, tindex);
		if (lua_isnil(L, -1)) {
			lua_pop(L, 1);
			lua_checkstack(L, 3);
			weaktable(L, mode);
			lua_pushstring(L, name);
			lua_pushvalue(L, -2);
			lua_settable(L, tindex);
		}
	}

	static void *pushuserdata(lua_State *L, void *key, size_t sz) {
		void *ud = 0;
		lua_pushlightuserdata(L, key);
		lua_gettable(L, -2);     // lookup[key]
		if (lua_isnil(L, -1)) {
			lua_pop(L, 1);         // drop nil
			lua_checkstack(L, 3);
			ud = lua_newuserdata(L, sz);  // create new userdata
			lua_pushlightuserdata(L, key);
			lua_pushvalue(L, -2);  // dup userdata
			lua_settable(L, -4);   // lookup[key] = userdata
		}
		return ud;
	}
};

void report(lua_State * L)
{
	const char * msg= lua_tostring(L,-1);
	while(msg)
	{
		lua_pop(L,-1);
		printf("\t%s\n", msg);
		msg=lua_tostring(L,-1);
	}
}

LuaEngine::LuaEngine()
{
	this->L = lua_open();
}

LuaEngine::~LuaEngine()
{
	lua_close(L);
}

void LuaEngine::ScriptLoadDir(char* Dirname, LUALoadScripts *pak)
{
	#ifdef WIN32
		Log.Success("LuaEngine", "Scanning Directory %s", Dirname);
		HANDLE hFile;
		WIN32_FIND_DATA FindData;
		memset(&FindData,0,sizeof(FindData));

		char SearchName[MAX_PATH];
	        
		strcpy(SearchName,Dirname);
		strcat(SearchName,"\\*.*");

		hFile = FindFirstFile(SearchName,&FindData);
		FindNextFile(hFile, &FindData);
	    
		while( FindNextFile(hFile, &FindData) )
		{
			if( FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) //Credits for this 'if' go to Cebernic from ArcScripts Team. Thanks, you saved me some work ;-)
			{
				strcpy(SearchName,Dirname);
				strcat(SearchName,"\\");
				strcat(SearchName,FindData.cFileName);
				ScriptLoadDir(SearchName, pak);
			}
			else
			{
						string fname = Dirname;
						fname += "\\";
						fname += FindData.cFileName;

			  		int len = strlen(fname.c_str());
					  int i=0;
					  char ext[MAX_PATH];
					  
					  while(len > 0)
					  {  
					   ext[i++] = fname[--len];
					   if(fname[len] == '.')
		  		   break;
	  			  }
	  			  ext[i++] = '\0';
	  			  if ( !_stricmp(ext,"aul.") ) pak->luaFiles.insert(fname);
	  			  if ( !_stricmp(ext,"cul.") ) pak->luaBytecodeFiles.insert(fname);
			}
		}
	  FindClose(hFile);
	#else
		char *pch=strrchr(Dirname,'/');
		if (strcmp(Dirname, "..")==0 || strcmp(Dirname, ".")==0) return; //Against Endless-Loop
		if (pch != NULL && (strcmp(pch, "/..")==0 || strcmp(pch, "/.")==0 || strcmp(pch, "/.svn")==0)) return;
		struct dirent ** list;
		int filecount = scandir(Dirname, &list, 0, 0);

		if(filecount <= 0 || !list)
			return;

		struct stat attributes;
		bool err;
		Log.Success("LuaEngine", "Scanning Directory %s", Dirname);
		while(filecount--)
		{
			char dottedrelpath[200];
			sprintf(dottedrelpath, "%s/%s", Dirname, list[filecount]->d_name);
			if(stat(dottedrelpath, &attributes) == -1) {
				err=true;
				Log.Error("LuaEngine","Error opening %s: %s\n", dottedrelpath, strerror(errno));
			} else err=false;

			if (!err && S_ISDIR(attributes.st_mode))
			{
				ScriptLoadDir((char *)dottedrelpath, pak); //Subdirectory
			} else {
				char* ext = strrchr(list[filecount]->d_name, '.');
				if(ext != NULL && !strcmp(ext, ".lua"))
				{
					pak->luaFiles.insert(dottedrelpath);
				}
				else if(!stricmp(ext, ".luc"))
				{
					pak->luaBytecodeFiles.insert(dottedrelpath);
				}
			}

			free(list[filecount]);
		}
		free(list);
	#endif
}

void LuaEngine::LoadScripts()
{
	LUALoadScripts rtn;
	Log.Notice("LuaEngine", "Scanning Script-Directories...");
	ScriptLoadDir((char*)"scripts", &rtn);

	unsigned int cnt_comp=0;
	unsigned int cnt_uncomp=0;

	// we prefer precompiled code.
	for(set<string>::iterator itr = rtn.luaBytecodeFiles.begin(); itr != rtn.luaBytecodeFiles.end(); ++itr)
	{
		set<string>::iterator it2 = rtn.luaFiles.find(*itr);
		if(it2 == rtn.luaFiles.end())
			rtn.luaFiles.erase(it2);
			cnt_comp++;
	}

	luaL_openlibs(L);
	RegisterCoreFunctions();

	if(lua_is_starting_up)
		Log.Notice("LuaEngine", "Loading Scripts...");

	char filename[200];

	for(set<string>::iterator itr = rtn.luaFiles.begin(); itr != rtn.luaFiles.end(); ++itr)
	{ 
		strcpy(filename, itr->c_str());
		if(luaL_loadfile(L, filename) != 0)
		{
			if(lua_is_starting_up)
				#ifdef WIN32
					Log.Notice("LuaEngine", "loading %s...", itr->c_str());
					SetConsoleTextAttribute(stdout_handle, (WORD)TRED);
				#else
					Log.Notice("LuaEngine", "\033[22;31m loading %s...", itr->c_str());
					printf("\033[22;31m");
				#endif
			printf("failed. (could not load)\n");
			const char * msg = lua_tostring(L, -1);
			if(msg!=NULL&&lua_is_starting_up)
				printf("\t%s\n",msg);
				#ifdef WIN32
					SetConsoleTextAttribute(stdout_handle, (WORD)TWHITE);
				#else
					printf("\033[01;37m");
				#endif
		}
		else
		{
			if(lua_pcall(L, 0, LUA_MULTRET, 0) != 0)
			{	if(lua_is_starting_up)
					#ifdef WIN32
					Log.Notice("Modded LuaEngine", "running %s...", itr->c_str());
					SetConsoleTextAttribute(stdout_handle, (WORD)TRED);
					#else
					Log.Notice("Modded LuaEngine", "\033[22;31m running %s...", itr->c_str());
					printf("\033[22;31m");
					#endif
				printf("failed. (could not run)\n");
				const char * msg = lua_tostring(L, -1);
				if(msg!=NULL&&lua_is_starting_up)
					printf("\t%s\n",msg);
				#ifdef WIN32
					SetConsoleTextAttribute(stdout_handle, (WORD)TWHITE);
				#else
					printf("\033[01;37m");
				#endif
			} else if(lua_is_starting_up) {
				Log.Success("Modded LuaEngine", "loaded: %s...", itr->c_str());
			}
		}
		cnt_uncomp++;
	}
	sLog.outColor(TGREEN,"Modded LuaEngine: Loaded %u uncompiled and %u compiled LUA-scripts.", cnt_uncomp, cnt_comp);
}

void LuaEngine::OnUnitEvent(Unit * pUnit, const char * FunctionName, uint32 EventType, Unit * pMiscUnit, uint32 Misc, int32 Misc2, float Misc3, bool Yes, ItemPrototype * Misc4)
{
	if(FunctionName==NULL)
		return;

	m_Lock.Acquire();
	lua_pushstring(L, FunctionName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L,-1))
	{
		Log.Notice("Modded LuaEngine", "Tried to call invalid LUA function '%s' from ArcEmu (Unit)!\n", FunctionName);
		m_Lock.Release();
		return;
	}

	Lunar<Unit>::push(L, pUnit);
	lua_pushinteger(L,EventType);
	if(pMiscUnit!=NULL)
		Lunar<Unit>::push(L, pMiscUnit);
	else
		lua_pushnil(L);
	lua_pushinteger(L,Misc);
	
	int r = lua_pcall(L,4,LUA_MULTRET,0);
	if(r)
		report(L);

	m_Lock.Release();
}

void LuaEngine::OnQuestEvent(Player * QuestOwner, const char * FunctionName, uint32 QuestID, uint32 EventType, Object * QuestStarter, uint32 Misc, uint32 Misc2)
{
	if(FunctionName==NULL)
		return;

	m_Lock.Acquire();
	lua_pushstring(L, FunctionName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L,-1))
	{
		Log.Notice("LuaEngine", "Tried to call invalid LUA function '%s' from ArcEmu (Quest)!\n", FunctionName);
		m_Lock.Release();
		return;
	}

	if (QuestOwner)
		Lunar<Unit>::push(L, (Unit*)QuestOwner);
	else
		lua_pushnil(L);

	lua_pushinteger(L,EventType);

	if(QuestStarter!=NULL && QuestStarter->GetTypeId() == TYPEID_UNIT)
		Lunar<Unit>::push(L, (Unit*)QuestStarter);
	else
		lua_pushnil(L);

	int r = lua_pcall(L,3,LUA_MULTRET,0);
	if(r)
		report(L);

	m_Lock.Release();
	
}

void LuaEngine::CallFunction(Unit * pUnit, const char * FuncName)
{
	m_Lock.Acquire();
	lua_pushstring(L, FuncName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L,-1))
	{
		Log.Notice("LuaEngine", "Tried to call invalid LUA function '%s' from ArcEmu (Unit)!\n", FuncName);
		m_Lock.Release();
		return;
	}

	Lunar<Unit>::push(L, pUnit);
	int r = lua_pcall(L,1,LUA_MULTRET,0);
	if(r)
		report(L);

	m_Lock.Release();
}

void LuaEngine::OnGameObjectEvent(GameObject * pGameObject, const char * FunctionName, uint32 EventType, Unit * pMiscUnit, uint32 Misc, ItemPrototype * Misc2)
{
	if(FunctionName==NULL)
		return;

	m_Lock.Acquire();
	lua_pushstring(L, FunctionName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L,-1))
	{
		Log.Notice("LuaEngine", "Tried to call invalid LUA function '%s' from ArcEmu (GO)!\n", FunctionName);
		m_Lock.Release();
		return;
	}

	Lunar<GameObject>::push(L, pGameObject);
	lua_pushinteger(L,EventType);
	if(!pMiscUnit)
		lua_pushnil(L);
	else
		Lunar<Unit>::push(L, pMiscUnit);

	int r = lua_pcall(L,3,LUA_MULTRET,0);
	if(r)
		report(L);

	m_Lock.Release();
}
void LuaEngine::OnGossipEvent(Object * pObject, const char * FunctionName, uint32 EventType, Player * mPlayer, uint32 Id, uint32 IntId, const char * Code)
{
	if(FunctionName==NULL)
		return;

	m_Lock.Acquire();
	lua_pushstring(L, FunctionName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L, -1))
	{
		Log.Notice("LuaEngine", "Tried to call invalid LUA function '%s' from ArcEmu (Gossip)!\n", FunctionName);
		m_Lock.Release();
		return;
	}
   if(pObject->GetTypeId() == TYPEID_UNIT)
       Lunar<Unit>::push(L, (Unit *)pObject);

    else if(pObject->GetTypeId() == TYPEID_ITEM)
        Lunar<Item>::push(L, (Item *)pObject);

    else if(pObject->GetTypeId() == TYPEID_GAMEOBJECT)
        Lunar<GameObject>::push(L, (GameObject *)pObject);

    lua_pushinteger(L, EventType);
	Lunar<Unit>::push(L, (Player *)mPlayer);

    lua_pushinteger(L, Id);
    lua_pushinteger(L, IntId);

    lua_pushstring(L, Code);

	int r = lua_pcall(L, 6, LUA_MULTRET, 0);
	if(r)
		report(L);

	m_Lock.Release();
}

/*void LuaEngine::OnServerHook(Unit * pUnit, const char * FunctionName, uint32 EventType, uint32 Misc, int32 Misc2, float Misc3, bool Yes, ItemPrototype * Misc4)
{
	if(FunctionName==NULL)
		return;

	m_Lock.Acquire();
	lua_pushstring(L, FunctionName);
	lua_gettable(L, LUA_GLOBALSINDEX);
	if(lua_isnil(L,-1))
	{
		printf("Tried to call invalid LUA function '%s' from ArcEmu (ServerHook)!\n", FunctionName);
		m_Lock.Release();
		return;
	}

	Lunar<Unit>::push(L, pUnit);
	lua_pushinteger(L,EventType);
	lua_pushinteger(L,Misc);
	
	int r = lua_pcall(L,4,LUA_MULTRET,0);
	if(r)
		report(L);

	m_Lock.Release();
}

static int RegisterServerHook(lua_State * L);*/
static int RegisterUnitEvent(lua_State * L);
static int RegisterQuestEvent(lua_State * L);
static int RegisterGameObjectEvent(lua_State * L);
static int RegisterUnitGossipEvent(lua_State * L);
static int RegisterItemGossipEvent(lua_State * L);
static int RegisterGOGossipEvent(lua_State * L);
#include "GlobalFunctions.h"

void LuaEngine::RegisterCoreFunctions()
{
	lua_pushcfunction(L, &RegisterUnitEvent);
	lua_setglobal(L, "RegisterUnitEvent");

	lua_pushcfunction(L, &RegisterGameObjectEvent);
	lua_setglobal(L, "RegisterGameObjectEvent");

	lua_pushcfunction(L, &RegisterQuestEvent);
	lua_setglobal(L, "RegisterQuestEvent");
	
    lua_pushcfunction(L, &RegisterUnitGossipEvent);
	lua_setglobal(L, "RegisterUnitGossipEvent"); 
 
    lua_pushcfunction(L, &RegisterItemGossipEvent);
	lua_setglobal(L, "RegisterItemGossipEvent"); 

   	lua_pushcfunction(L, &RegisterGOGossipEvent);
	lua_setglobal(L, "RegisterGOGossipEvent");

	/*lua_pushcfunction(L, &RegisterServerHook);
	lua_setglobal(L, "RegisterServerHook");*/

	luaGlobalFunctions::Register(L);

	Lunar<Unit>::Register(L);
	Lunar<Item>::Register(L);
	Lunar<GameObject>::Register(L);
	//Lunar<Quest>::Register(L); quest isn't a class
}

/*static int RegisterServerHook(lua_State * L)
{
	int ev = luaL_checkint(L, 1);
	const char * str = luaL_checkstring(L, 2);

	if(!ev || !str || !lua_is_starting_up)
		return 0;

	//g_luaMgr.RegisterUnitEvent(entry,ev,str);
	printf("LUAppArc Engine: Sorry but ServerHookEvents are currently in development!");
	g_luaMgr.RegisterServerHook(ev, str);
	return 0;
}*/

static int RegisterUnitEvent(lua_State * L)
{
	int entry = luaL_checkint(L, 1);
	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);

	if(!entry || !ev || !str || !lua_is_starting_up)
		return 0;

	g_luaMgr.RegisterUnitEvent(entry,ev,str);
	return 0;
}

static int RegisterQuestEvent(lua_State * L)
{
	int entry = luaL_checkint(L, 1);
	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);

	if(!entry || !ev || !str || !lua_is_starting_up)
		return 0;

	g_luaMgr.RegisterQuestEvent(entry,ev,str);
	return 0;
}

static int RegisterGameObjectEvent(lua_State * L)
{
	int entry = luaL_checkint(L, 1);
	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);

	if(!entry || !ev || !str || !lua_is_starting_up)
		return 0;

	g_luaMgr.RegisterGameObjectEvent(entry,ev,str);
	return 0;
}

static int RegisterUnitGossipEvent(lua_State * L)
{
	int entry = luaL_checkint(L, 1);
	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);
	if(!entry || !ev || !str || !lua_is_starting_up)
		return 0;

    g_luaMgr.RegisterUnitGossipEvent(entry, ev, str);
	return 0;
}
static int RegisterItemGossipEvent(lua_State * L)
 {
 	int entry = luaL_checkint(L, 1);
 	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);

 	if(!entry || !ev || !str || !lua_is_starting_up)
 		return 0;
    g_luaMgr.RegisterItemGossipEvent(entry, ev, str);
 	return 0;
 }
static int RegisterGOGossipEvent(lua_State * L)
{
	int entry = luaL_checkint(L, 1);
	int ev = luaL_checkint(L, 2);
	const char * str = luaL_checkstring(L, 3);

	if(!entry || !ev || !str || !lua_is_starting_up)
		return 0;

    g_luaMgr.RegisterGOGossipEvent(entry, ev, str);
	return 0;
}

#include "GlobalFunctions.cpp"

/************************************************************************/
/* Manager Stuff                                                        */
/************************************************************************/

/*class LuaServerHook : public HookInterface
{
public:
	LuaServerHook() : HookInterface() {};
	~LuaServerHook() {};

	bool LuaServerHook::OnNewCharacter(uint32 Race, uint32 Class, WorldSession * Session, const char * Name)
	{
		if( m_binding->Functions[SERVER_HOOK_NEW_CHARACTER] != NULL )
			g_engine->OnServerHook( NULL, m_binding->Functions[SERVER_HOOK_NEW_CHARACTER], SERVER_HOOK_NEW_CHARACTER, 0,0,0, NULL, NULL);
	}*/

/*	void LuaServerHook::OnKillPlayer(Player * pPlayer, Player * pVictim)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_KILL_PLAYER, tOnKillPlayer)
			(call)(pPlayer, pVictim);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnFirstEnterWorld(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_FIRST_ENTER_WORLD, tOnFirstEnterWorld)
			(call)(pPlayer);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnCharacterCreate(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_CHARACTER_CREATE, tOCharacterCreate)
			(call)(pPlayer);
		OUTER_LOOP_END
	}*/

	/*void LuaServerHook::OnEnterWorld(Player * pPlayer)
	{
		if( m_binding->Functions[SERVER_HOOK_ENTER_WORLD] != NULL )
			g_engine->OnServerHook( pPlayer, m_binding->Functions[SERVER_HOOK_ENTER_WORLD], SERVER_HOOK_ENTER_WORLD, 0,0,0, NULL, NULL);
	}*/

	/*void LuaServerHook::OnGuildCreate(Player * pLeader, Guild * pGuild)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_GUILD_CREATE, tOnGuildCreate)
			(call)(pLeader, pGuild);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnGuildJoin(Player * pPlayer, Guild * pGuild)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_GUILD_JOIN, tOnGuildJoin)
			(call)(pPlayer, pGuild);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnDeath(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_DEATH, tOnDeath)
			(call)(pPlayer);
		OUTER_LOOP_END
	}

	bool LuaServerHook::OnRepop(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN_COND(SERVER_HOOK_EVENT_ON_REPOP, tOnRepop)
			ret_val = (call)(pPlayer);
		OUTER_LOOP_END_COND
	}

	void LuaServerHook::OnEmote(Player * pPlayer, uint32 Emote, Unit * pUnit)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_EMOTE, tOnEmote)
			(call)(pPlayer, Emote, pUnit);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnEnterCombat(Player * pPlayer, Unit * pTarget)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_ENTER_COMBAT, tOnEnterCombat)
			(call)(pPlayer, pTarget);
		OUTER_LOOP_END
	}

	bool LuaServerHook::OnCastSpell(Player * pPlayer, SpellEntry* pSpell)
	{
		OUTER_LOOP_BEGIN_COND(SERVER_HOOK_EVENT_ON_CAST_SPELL, tOnCastSpell)
			ret_val = (call)(pPlayer, pSpell);
		OUTER_LOOP_END_COND
	}

	bool LuaServerHook::OnLogoutRequest(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN_COND(SERVER_HOOK_EVENT_ON_LOGOUT_REQUEST, tOnLogoutRequest)
			ret_val = (call)(pPlayer);
		OUTER_LOOP_END_COND
	}

	void LuaServerHook::OnLogout(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_LOGOUT, tOnLogout)
			(call)(pPlayer);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnQuestAccept(Player * pPlayer, Quest * pQuest, Object * pQuestGiver)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_QUEST_ACCEPT, tOnQuestAccept)
			(call)(pPlayer, pQuest, pQuestGiver);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnZone(Player * pPlayer, uint32 Zone)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_ZONE, tOnZone)
			(call)(pPlayer, Zone);
		OUTER_LOOP_END
	}

	bool LuaServerHook::OnChat(Player * pPlayer, uint32 Type, uint32 Lang, const char * Message, const char * Misc)
	{
		OUTER_LOOP_BEGIN_COND(SERVER_HOOK_EVENT_ON_CHAT, tOnChat)
			ret_val = (call)(pPlayer, Type, Lang, Message, Misc);
		OUTER_LOOP_END_COND
	}

	void LuaServerHook::OnLoot(Player * pPlayer, Unit * pTarget, uint32 Money, uint32 ItemId)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_LOOT, tOnLoot)
			(call)(pPlayer, pTarget, Money, ItemId);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnObjectLoot(Player * pPlayer, Object * pTarget, uint32 Money, uint32 ItemId)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_OBJECTLOOT, tOnObjectLoot)
			(call)(pPlayer, pTarget, Money, ItemId);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnEnterWorld2(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_ENTER_WORLD_2, tOnEnterWorld)
			(call)(pPlayer);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnQuestCancelled(Player * pPlayer, Quest * pQuest)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_QUEST_CANCELLED, tOnQuestCancel)
			(call)(pPlayer, pQuest);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnQuestFinished(Player * pPlayer, Quest * pQuest, Object * pQuestGiver)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_QUEST_FINISHED, tOnQuestFinished)
			(call)(pPlayer, pQuest, pQuestGiver);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnHonorableKill(Player * pPlayer, Player * pKilled)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_HONORABLE_KILL, tOnHonorableKill)
			(call)(pPlayer, pKilled);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnArenaFinish(Player * pPlayer, ArenaTeam* pTeam, bool victory, bool rated)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_ARENA_FINISH, tOnArenaFinish)
			(call)(pPlayer, pTeam, victory, rated);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnAreaTrigger(Player * pPlayer, uint32 areaTrigger)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_AREATRIGGER, tOnAreaTrigger)
			(call)(pPlayer, areaTrigger);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnPostLevelUp(Player * pPlayer)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_POST_LEVELUP, tOnPostLevelUp)
			(call)(pPlayer);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnPreUnitDie(Unit *Killer, Unit *Victim)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_PRE_DIE, tOnPreUnitDie)
			(call)(Killer, Victim);
		OUTER_LOOP_END
	}

	void LuaServerHook::OnAdvanceSkillLine(Player * pPlayer, uint32 SkillLine, uint32 Current)
	{
		OUTER_LOOP_BEGIN(SERVER_HOOK_EVENT_ON_ADVANCE_SKILLLINE, tOnAdvanceSkillLine)
			(call)(pPlayer, SkillLine, Current);
		OUTER_LOOP_END
	}*/
/*
	LuaHookBinding * m_binding;
};*/


class LuaCreature : public CreatureAIScript
{
public:
	LuaCreature(Creature* creature) : CreatureAIScript(creature) {};
	~LuaCreature() {};

	void OnCombatStart(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_ENTER_COMBAT] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_ENTER_COMBAT], CREATURE_EVENT_ON_ENTER_COMBAT, mTarget, 0,0,0, 0, NULL);
	}

	void OnCombatStop(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_LEAVE_COMBAT] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_LEAVE_COMBAT], CREATURE_EVENT_ON_LEAVE_COMBAT, mTarget, 0, 0,0,0, NULL );
	}

	void OnTargetDied(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_TARGET_DIED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_TARGET_DIED], CREATURE_EVENT_ON_TARGET_DIED, mTarget, 0,0,0,0, NULL );
	}

	void OnDied(Unit *mKiller)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_DIED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_DIED], CREATURE_EVENT_ON_DIED, mKiller, 0,0,0,0, NULL );
	}
	void OnTargetParried(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_TARGET_PARRIED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_TARGET_PARRIED], CREATURE_EVENT_ON_TARGET_PARRIED, mTarget, 0,0,0,0, NULL );
	}
	void OnTargetDodged(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_TARGET_DODGED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_TARGET_DODGED], CREATURE_EVENT_ON_TARGET_DODGED, mTarget, 0,0,0,0, NULL);
	}
	void OnTargetBlocked(Unit* mTarget, int32 iAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_TARGET_BLOCKED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_TARGET_BLOCKED], CREATURE_EVENT_ON_TARGET_BLOCKED, mTarget, 0,iAmount,0,0, NULL );
	}
	void OnTargetCritHit(Unit* mTarget, float fAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_TARGET_CRIT_HIT] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_TARGET_CRIT_HIT], CREATURE_EVENT_ON_TARGET_CRIT_HIT, mTarget, 0, 0, fAmount, 0, NULL);
	}
	void OnParried(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_PARRY] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_PARRY], CREATURE_EVENT_ON_PARRY, mTarget, 0, 0, 0, 0, NULL);
	}
	void OnDodged(Unit* mTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_DODGED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_DODGED], CREATURE_EVENT_ON_DODGED, mTarget, 0, 0, 0, 0, NULL);
	}
	void OnBlocked(Unit* mTarget, int32 iAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_BLOCKED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_BLOCKED], CREATURE_EVENT_ON_BLOCKED, mTarget, 0, iAmount, 0, 0, NULL);
	}
	void OnCritHit(Unit* mTarget, float fAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_CRIT_HIT] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_CRIT_HIT], CREATURE_EVENT_ON_CRIT_HIT, mTarget, 0, 0, fAmount, 0, NULL);
	}
	void OnHit(Unit* mTarget, float fAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_HIT] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_HIT], CREATURE_EVENT_ON_HIT, mTarget, 0, 0, fAmount, 0, NULL);
	}
	void OnAssistTargetDied(Unit* mAssistTarget)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_ASSIST_TARGET_DIED] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_ASSIST_TARGET_DIED], CREATURE_EVENT_ON_ASSIST_TARGET_DIED, mAssistTarget, 0, 0, 0, 0, NULL);
	}
	void OnFear(Unit* mFeared, uint32 iSpellId)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_FEAR] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_FEAR], CREATURE_EVENT_ON_FEAR, mFeared, iSpellId, 0, 0, 0, NULL );
	}
	void OnFlee(Unit* mFlee)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_FLEE] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_FLEE], CREATURE_EVENT_ON_FLEE, mFlee, 0, 0, 0, 0, NULL);
	}
	void OnCallForHelp()
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_CALL_FOR_HELP] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_CALL_FOR_HELP], CREATURE_EVENT_ON_CALL_FOR_HELP, NULL, 0, 0, 0, 0, NULL);
	}
	void OnLoad()
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_LOAD] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_LOAD], CREATURE_EVENT_ON_LOAD, NULL, 0, 0, 0, 0, NULL );
	}
	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_REACH_WP] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_REACH_WP], CREATURE_EVENT_ON_REACH_WP, NULL, iWaypointId,0, 0, bForwards, NULL );
	}
	void OnLootTaken(Player* pPlayer, ItemPrototype *pItemPrototype)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_LOOT_TAKEN] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_LOOT_TAKEN], CREATURE_EVENT_ON_LOOT_TAKEN, pPlayer, 0, 0, 0, 0, pItemPrototype );
	}
	void AIUpdate()
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_AIUPDATE] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_AIUPDATE], CREATURE_EVENT_ON_AIUPDATE, NULL, 0, 0, 0, 0, NULL );
	}
	void OnEmote(Player * pPlayer, EmoteType Emote)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_EMOTE] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_EMOTE], CREATURE_EVENT_ON_EMOTE, pPlayer, 0, 0, 0, 0, NULL);
	}
	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		if( m_binding->Functions[CREATURE_EVENT_ON_DAMAGE_TAKEN] != NULL )
			g_engine->OnUnitEvent( _unit, m_binding->Functions[CREATURE_EVENT_ON_DAMAGE_TAKEN], CREATURE_EVENT_ON_DAMAGE_TAKEN, mAttacker, 0, 0, fAmount, 0, NULL);
	}
	void StringFunctionCall(const char * pFunction)
	{
		g_engine->CallFunction( _unit, pFunction );
	}

	void Destroy()
	{
		delete this;
	}

	LuaUnitBinding * m_binding;
};

class LuaGameObject : public GameObjectAIScript
{
public:
	LuaGameObject(GameObject * go) : GameObjectAIScript(go) {}
	~LuaGameObject() {}

	void OnCreate()
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_ON_CREATE] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_ON_CREATE], GAMEOBJECT_EVENT_ON_CREATE, NULL, 0, NULL );
	}
	void OnSpawn()
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_ON_SPAWN] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_ON_SPAWN], GAMEOBJECT_EVENT_ON_SPAWN, NULL, 0, NULL );
	}
	void OnDespawn()
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_ON_DESPAWN] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_ON_DESPAWN], GAMEOBJECT_EVENT_ON_DESPAWN, NULL, 0, NULL );
	}
	void OnLootTaken(Player * pLooter, ItemPrototype *pItemInfo)
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_ON_LOOT_TAKEN] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_ON_LOOT_TAKEN], GAMEOBJECT_EVENT_ON_LOOT_TAKEN, pLooter,0, pItemInfo );
	}
	void OnActivate(Player * pPlayer)
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_ON_USE] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_ON_USE], GAMEOBJECT_EVENT_ON_USE, pPlayer, 0, NULL );
	}
	
	void AIUpdate()
	{
		if( m_binding->Functions[GAMEOBJECT_EVENT_AIUPDATE] != NULL )
			g_engine->OnGameObjectEvent( _gameobject, m_binding->Functions[GAMEOBJECT_EVENT_AIUPDATE], GAMEOBJECT_EVENT_AIUPDATE, NULL, 0, NULL );
	}
	void Destroy ()
	{
		delete this;
	}

	LuaGameObjectBinding * m_binding;
};

class LuaGossip : public GossipScript
{
public:
	LuaGossip() : GossipScript() {}
	~LuaGossip() {}

	void GossipHello(Object* pObject, Player* Plr, bool AutoSend)
	{
		if(pObject->GetTypeId() == TYPEID_UNIT)
        {
           if( m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_TALK] != NULL )
			    g_engine->OnGossipEvent( pObject, m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_TALK], GOSSIP_EVENT_ON_TALK, Plr, 0, 0, NULL );
       }
        else if(pObject->GetTypeId() == TYPEID_ITEM)
        {
            if( m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_TALK] != NULL )
			    g_engine->OnGossipEvent( pObject, m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_TALK], GOSSIP_EVENT_ON_TALK, Plr, 0, 0, NULL );
        }
	}

	void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(pObject->GetTypeId() == TYPEID_UNIT)
        {
            if( m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION] != NULL )
			    g_engine->OnGossipEvent( pObject, m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION], GOSSIP_EVENT_ON_SELECT_OPTION, Plr, Id, IntId, EnteredCode);
        }
        else if(pObject->GetTypeId() == TYPEID_ITEM)
        {
            if( m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION] != NULL )
                g_engine->OnGossipEvent( pObject, m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION], GOSSIP_EVENT_ON_SELECT_OPTION, Plr, Id, IntId, EnteredCode);
        }
        else if(pObject->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            if( m_go_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION] != NULL )
                g_engine->OnGossipEvent( pObject, m_go_gossip_binding->Functions[GOSSIP_EVENT_ON_SELECT_OPTION], GOSSIP_EVENT_ON_SELECT_OPTION, Plr, Id, IntId, EnteredCode);
        }
	}

	void GossipEnd(Object* pObject, Player* Plr)
	{
		if(pObject->GetTypeId() == TYPEID_UNIT)
        {
		    if( m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_END] != NULL )
			    g_engine->OnGossipEvent( pObject, m_unit_gossip_binding->Functions[GOSSIP_EVENT_ON_END], GOSSIP_EVENT_ON_END, Plr, 0, 0, NULL );
        }
        else if(pObject->GetTypeId() == TYPEID_ITEM)
        {
            if( m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_END] != NULL )
			    g_engine->OnGossipEvent( pObject, m_item_gossip_binding->Functions[GOSSIP_EVENT_ON_END], GOSSIP_EVENT_ON_END, Plr, 0, 0, NULL );
        }
        else if(pObject->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            if( m_go_gossip_binding->Functions[GOSSIP_EVENT_ON_END] != NULL )
			    g_engine->OnGossipEvent( pObject, m_go_gossip_binding->Functions[GOSSIP_EVENT_ON_END], GOSSIP_EVENT_ON_END, Plr, 0, 0, NULL );
        }
	}

	LuaUnitGossipBinding * m_unit_gossip_binding;
	LuaItemGossipBinding * m_item_gossip_binding;
    LuaGOGossipBinding * m_go_gossip_binding;
};

class LuaQuest : public QuestScript
{
public:
	LuaQuest() : QuestScript() {}
	~LuaQuest() {}

	void OnQuestStart(Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_ACCEPT] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_ACCEPT], qLogEntry->GetQuest()->id, QUEST_EVENT_ON_ACCEPT, mTarget, 0, 0 );
	}

	void OnQuestComplete(Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_COMPLETE] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_COMPLETE], qLogEntry->GetQuest()->id, QUEST_EVENT_ON_COMPLETE, mTarget, 0, 0 );
	}
	void OnQuestCancel(Player* mTarget)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_CANCEL] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_CANCEL], 0, QUEST_EVENT_ON_CANCEL, mTarget, 0 , 0 ); //3rd was NULL
	}
	void OnGameObjectActivate(uint32 entry, Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_GAMEOBJECT_ACTIVATE] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_GAMEOBJECT_ACTIVATE], qLogEntry->GetQuest()->id, QUEST_EVENT_GAMEOBJECT_ACTIVATE, mTarget, entry, 0 );
	}
	void OnCreatureKill(uint32 entry, Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_CREATURE_KILL] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_CREATURE_KILL], qLogEntry->GetQuest()->id, QUEST_EVENT_ON_CREATURE_KILL, mTarget, entry , 0 );
	}
	void OnExploreArea(uint32 areaId, Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_EXPLORE_AREA] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_EXPLORE_AREA], qLogEntry->GetQuest()->id, QUEST_EVENT_ON_EXPLORE_AREA, mTarget, areaId, 0 );
	}
	void OnPlayerItemPickup(uint32 itemId, uint32 totalCount, Player* mTarget, QuestLogEntry *qLogEntry)
	{
		if( m_binding->Functions[QUEST_EVENT_ON_PLAYER_ITEMPICKUP] != NULL )
			g_engine->OnQuestEvent( mTarget, m_binding->Functions[QUEST_EVENT_ON_PLAYER_ITEMPICKUP], qLogEntry->GetQuest()->id, QUEST_EVENT_ON_PLAYER_ITEMPICKUP, mTarget, itemId, totalCount );
	}

	LuaQuestBinding * m_binding;
};

CreatureAIScript * CreateLuaCreature(Creature * src)
{
	LuaUnitBinding * pBinding = g_luaMgr.GetUnitBinding( src->GetEntry() );
	if( pBinding == NULL )
		return NULL;

	LuaCreature * pLua = new LuaCreature( src );
	pLua->m_binding = pBinding;
	return pLua;
}

GameObjectAIScript * CreateLuaGameObject(GameObject * src)
{
	LuaGameObjectBinding * pBinding = g_luaMgr.GetGameObjectBinding( src->GetEntry() );
	if( pBinding == NULL )
		return NULL;

	LuaGameObject * pLua = new LuaGameObject( src );
	pLua->m_binding = pBinding;
	return pLua;
}

QuestScript * CreateLuaQuestScript(uint32 id)
{
	LuaQuestBinding * pBinding = g_luaMgr.GetQuestBinding( id );
	if( pBinding == NULL )
		return NULL;

	LuaQuest * pLua = new LuaQuest();
	pLua->m_binding = pBinding;
	return pLua;
}

GossipScript * CreateLuaUnitGossipScript(uint32 id)
{
    LuaUnitGossipBinding * pBinding = g_luaMgr.GetLuaUnitGossipBinding( id );
	if( pBinding == NULL )
		return NULL;
	LuaGossip * pLua = new LuaGossip();
	pLua->m_unit_gossip_binding = pBinding;
	return pLua;
}
GossipScript * CreateLuaItemGossipScript(uint32 id)
 {
    LuaItemGossipBinding * pBinding = g_luaMgr.GetLuaItemGossipBinding( id );
 	if( pBinding == NULL )
 		return NULL;
 
 	LuaGossip * pLua = new LuaGossip();
	pLua->m_item_gossip_binding = pBinding;
 	return pLua;
 }
GossipScript * CreateLuaGOGossipScript(uint32 id)
{
    LuaGOGossipBinding * pBinding = g_luaMgr.GetLuaGOGossipBinding( id );
	if( pBinding == NULL )
		return NULL;

	LuaGossip * pLua = new LuaGossip();
    pLua->m_go_gossip_binding = pBinding;
	return pLua;
}

void LuaEngineMgr::Startup()
{
	Log.Notice("LuaEngineMgr", "Spawning Lua Engine...");
	m_engine = new LuaEngine();
	#ifdef WIN32
	Log.Color(TGREEN);
	printf(" \_\_                        \_\_  \_\_                  \_\_\_\_\_\_                 \n");
	Log.Color(TGREEN);
	printf("/\\ \\                      /\\ \\/\\ \\                /\\  \_  \\                 \n");
	Log.Color(TGREEN);
	printf("\\ \\ \\      \_\_  \_\_     \_\_  \\ \\ \\\_\\ \\  \_\_  \_\_  \_\_\_\_\_\\ \\ \\\_\\ \\  \_\_\_\_\_  \_\_\_    \n");
	Log.Color(TGREEN);
	printf(" \\ \\ \\  \_\_/\\ \\/\\ \\  /'\_\_`\\ \\ \\  \_  \\/\\ \\/\\ \\/\\  \_\_`\\ \\  \_\_ \\/\\  \_\_\\/'\_\_\_\\  \n");
	Log.Color(TGREEN);
	printf("  \\ \\ \\\_\\ \\ \\ \\\_\\ \\/\\ \\\_\\.\\\_\\ \\ \\ \\ \\ \\ \\\_\\ \\ \\ \\\_\\ \\ \\ \\/\\ \\ \\ \\//\\ \\\_\_/  \n");
	Log.Color(TGREEN);
	printf("   \\ \\\_\_\_\_/\\ \\\_\_\_\_/\\ \\\_\_/ \\\_\\\\ \\\_\\ \\\_\\/`\_\_\_\_ \\ \\  \_\_/\\ \\\_\\ \\\_\\ \\\_\\\\ \\\_\_\_\_\\ \n");
	Log.Color(TGREEN);
	printf("    \\/\_\_\_/  \\/\_\_\_/  \\/\_\_/\\/\_/ \\/\_/\\/\_/`/\_\_\_// \\ \\ \\/  \\/\_/\\/\_/\\/\_/ \\/\_\_\_\_/ \n");
	Log.Color(TGREEN);
	printf("                                         /\\\_\_\_/\\ \\\_\\                       \n");
	Log.Color(TGREEN);
	printf("                                         \\/\_\_/  \\/\_/      .zapto.org      \n");
	#else
	Log.Color(TGREEN);
	printf("LuaHypArc.zapto.org");
	#endif
	Log.Line();
	Log.Notice("LuaEngineMgr", "Modded LuaHypArc Lua Engine %s: Loaded", ARCH);
	Log.Color(TNORMAL);
	Log.Line();
	Sleep(1200);
	lua_is_starting_up = true;
	m_engine->LoadScripts();
	g_engine = m_engine;

	lua_is_starting_up = false;

	// stuff is registered, so lets go ahead and make our emulated C++ scripted lua classes.
	for(UnitBindingMap::iterator itr = m_unitBinding.begin(); itr != m_unitBinding.end(); ++itr)
	{
		m_scriptMgr->register_creature_script( itr->first, CreateLuaCreature );
	}

	for(GameObjectBindingMap::iterator itr = m_gameobjectBinding.begin(); itr != m_gameobjectBinding.end(); ++itr)
	{
		m_scriptMgr->register_gameobject_script( itr->first, CreateLuaGameObject );
	}

	for(QuestBindingMap::iterator itr = m_questBinding.begin(); itr != m_questBinding.end(); ++itr)
	{
		QuestScript * qs = CreateLuaQuestScript( itr->first );
		if( qs != NULL )
			m_scriptMgr->register_quest_script( itr->first, qs );
	}

    for(GossipUnitScriptsBindingMap::iterator itr = m_unit_gossipBinding.begin(); itr != m_unit_gossipBinding.end(); ++itr)
 	{
		GossipScript * gs = CreateLuaUnitGossipScript( itr->first );
 		if( gs != NULL )
 			m_scriptMgr->register_gossip_script( itr->first, gs );
	}

    for(GossipItemScriptsBindingMap::iterator itr = m_item_gossipBinding.begin(); itr != m_item_gossipBinding.end(); ++itr)
	{
		GossipScript * gs = CreateLuaItemGossipScript( itr->first );
		if( gs != NULL )
			m_scriptMgr->register_item_gossip_script( itr->first, gs );
    }

    for(GossipGOScriptsBindingMap::iterator itr = m_go_gossipBinding.begin(); itr != m_go_gossipBinding.end(); ++itr)
	{
		GossipScript * gs = CreateLuaGOGossipScript( itr->first );
		if( gs != NULL )
			m_scriptMgr->register_go_gossip_script( itr->first, gs );
    }
}

/*void LuaEngineMgr::RegisterServerHook(uint32 Event, const char * FunctionName)
{
	HookBindingMap::iterator itr = m_hookBinding.find(0);
	if(itr == m_hookBinding.end())
	{
		LuaHookBinding ub;
		memset(&ub,0,sizeof(LuaHookBinding));
		ub.Functions[Event] = strdup(FunctionName);
		m_hookBinding.insert(make_pair(0,ub));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);

		itr->second.Functions[Event]=strdup(FunctionName);
	}
}*/

void LuaEngineMgr::RegisterUnitEvent(uint32 Id, uint32 Event, const char * FunctionName)
{
	UnitBindingMap::iterator itr = m_unitBinding.find(Id);
	if(itr == m_unitBinding.end())
	{
		LuaUnitBinding ub;
		memset(&ub,0,sizeof(LuaUnitBinding));
		ub.Functions[Event] = strdup(FunctionName);
		m_unitBinding.insert(make_pair(Id,ub));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);

		itr->second.Functions[Event]=strdup(FunctionName);
	}
}

void LuaEngineMgr::RegisterQuestEvent(uint32 Id, uint32 Event, const char * FunctionName)
{
	QuestBindingMap::iterator itr = m_questBinding.find(Id);
	if(itr == m_questBinding.end())
	{
		LuaQuestBinding qb;
		memset(&qb,0,sizeof(LuaQuestBinding));
		qb.Functions[Event] = strdup(FunctionName);
		m_questBinding.insert(make_pair(Id,qb));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);

		itr->second.Functions[Event]=strdup(FunctionName);
	}
}
void LuaEngineMgr::RegisterGameObjectEvent(uint32 Id, uint32 Event, const char * FunctionName)
{
	GameObjectBindingMap::iterator itr = m_gameobjectBinding.find(Id);
	if(itr == m_gameobjectBinding.end())
	{
		LuaGameObjectBinding ub;
		memset(&ub,0,sizeof(LuaGameObjectBinding));
		ub.Functions[Event] = strdup(FunctionName);
		m_gameobjectBinding.insert(make_pair(Id,ub));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);

		itr->second.Functions[Event]=strdup(FunctionName);
	}
}

void LuaEngineMgr::RegisterUnitGossipEvent(uint32 Id, uint32 Event, const char * FunctionName)
{
    GossipUnitScriptsBindingMap::iterator itr = m_unit_gossipBinding.find(Id);
 
    if(itr == m_unit_gossipBinding.end())
	{
		LuaUnitGossipBinding gb;
		memset(&gb, 0, sizeof(LuaUnitGossipBinding));
		gb.Functions[Event] = strdup(FunctionName);
		m_unit_gossipBinding.insert(make_pair(Id, gb));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);
		itr->second.Functions[Event]=strdup(FunctionName);
	}
}
void LuaEngineMgr::RegisterItemGossipEvent(uint32 Id, uint32 Event, const char * FunctionName)
 {
    GossipItemScriptsBindingMap::iterator itr = m_item_gossipBinding.find(Id);

    if(itr == m_item_gossipBinding.end())
 	{
		LuaItemGossipBinding gb;
		memset(&gb, 0, sizeof(LuaItemGossipBinding));
 		gb.Functions[Event] = strdup(FunctionName);
		m_item_gossipBinding.insert(make_pair(Id, gb));
 	}
	else
	{
		if(itr->second.Functions[Event] != NULL)
			free((void*)itr->second.Functions[Event]);
		itr->second.Functions[Event]=strdup(FunctionName);
	}
}
void LuaEngineMgr::RegisterGOGossipEvent(uint32 Id, uint32 Event, const char * FunctionName)
{
    GossipGOScriptsBindingMap::iterator itr = m_go_gossipBinding.find(Id);

    if(itr == m_go_gossipBinding.end())
	{
		LuaGOGossipBinding gb;
		memset(&gb, 0, sizeof(LuaGOGossipBinding));
		gb.Functions[Event] = strdup(FunctionName);
		m_go_gossipBinding.insert(make_pair(Id, gb));
	}
	else
	{
		if(itr->second.Functions[Event]!=NULL)
			free((void*)itr->second.Functions[Event]);

		itr->second.Functions[Event]=strdup(FunctionName);
	}
}

void LuaEngine::Restart()
{
	m_Lock.Acquire();
	g_engine->LoadScripts();
	m_Lock.Release();
}

void LuaEngineMgr::Unload()
{
}

/*{
	for(UnitBindingMap::iterator itr = m_unitBinding.begin(); itr != m_unitBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < CREATURE_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	
	for(GameObjectBindingMap::iterator itr = m_gameobjectBinding.begin(); itr != m_gameobjectBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < GAMEOBJECT_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	for(GossipUnitScriptsBindingMap::iterator itr = m_unit_gossipBinding.begin(); itr != m_unit_gossipBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < GOSSIP_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	for(GossipItemScriptsBindingMap::iterator itr = m_item_gossipBinding.begin(); itr != m_item_gossipBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < GOSSIP_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	for(GossipGOScriptsBindingMap::iterator itr = m_go_gossipBinding.begin(); itr != m_go_gossipBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < GOSSIP_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	m_gameobjectBinding.clear();
	m_unitBinding.clear();
	m_unit_gossipBinding.clear();
	m_item_gossipBinding.clear();
	m_go_gossipBinding.clear();
	
	delete g_engine;

	LuaEngineMgr * l;
	l->Startup();
}*/
/*void LuaEngine::ReloadScripts()
{
	m_Lock.Acquire();

	// acquire the locks on all the luaengines so they don't do anything.
	for(LuaEngine::iterator itr = g_engine.begin(); itr != g_engine.end(); ++itr)
		itr->first->GetLock().Acquire();

	// remove all the function name bindings
	for(UnitBindingMap::iterator itr = m_unitBinding.begin(); itr != m_unitBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < CREATURE_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}
	
	for(GameObjectBindingMap::iterator itr = m_gameobjectBinding.begin(); itr != m_gameobjectBinding.end(); ++itr)
	{
		for(uint32 i = 0; i < GAMEOBJECT_EVENT_COUNT; ++i)
			if(itr->second.Functions[i] != NULL)
				free((void*)itr->second.Functions[i]);
	}

	// clear the maps
	m_gameobjectBinding.clear();
	m_unitBinding.clear();

	// grab the first lua engine in the list, use it to re-create all the binding names.
	LuaEngine * l = g_engine.begin()->first;
	lua_is_starting_up = true;
	l->Restart();
	lua_is_starting_up = false;

	// all our bindings have been re-created, go through the lua engines and restart them all, and then release their locks.
	for(LuaEngine::iterator itr = g_engine.begin(); itr != g_engine.end(); ++itr)
	{
		if(itr->first != l)		// this one is already done
		{
			itr->first->Restart();
			itr->first->GetLock().Release();
		}
	}

	// release the big lock
	m_Lock.Release();
}*/



/************************************************************************/
/* SCRIPT FUNCTION IMPLEMENTATION                                       */
/************************************************************************/
#define CHECK_TYPEID(expected_type) if(!ptr || !ptr->IsInWorld() || ptr->GetTypeId() != expected_type) { return 0; }
#define CHECK_TYPEID_RET(expected_type) if(!ptr || !ptr->IsInWorld() || ptr->GetTypeId() != expected_type) { lua_pushboolean(L,0); return 0; }
#define CHECK_TYPEID_RET_INT(expected_type) if(!ptr || !ptr->IsInWorld() || ptr->GetTypeId() != expected_type) { lua_pushinteger(L,0); return 0; }


//I know its not a good idea to do it like that BUT it is the easiest way. I will make it better in steps:
#include "GameobjectFunctions.cpp"
#include "UnitFunctions.cpp"
#include "ItemFunctions.cpp"

