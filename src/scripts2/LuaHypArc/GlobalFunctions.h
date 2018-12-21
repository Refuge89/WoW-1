#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

namespace luaGlobalFunctions {

	static int GetLUAEngine(lua_State * L);
	static int PerformIngameSpawn(lua_State * L);
	static int GetPlayer(lua_State * L);
	static int CharDBQuery(lua_State * L);
	static int WorldDBQuery(lua_State * L);
	static int SendWorldMessage(lua_State * L);
	static int GetLuaEngineVersion(lua_State * L);
	static int GetGameTime(lua_State * L);
	static int ReloadTable(lua_State * L);
	static int ReloadLuaEngine(lua_State * L);
	static int Rehash(lua_State * L);


	void Register(lua_State *L);
}
#endif
