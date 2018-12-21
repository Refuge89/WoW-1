/*************************************************************\
|                           LuaHypArc                         |
|                      ==================                     |
|                   An extension of LUAppArc                  |
|                                                             |
|                     luahyparc.zapto.org                     |
\*************************************************************/

#include "StdAfx.h"
#include "LUAEngine.h"
#include "GlobalFunctions.h"

char *engine_name="LuaHypArc"; //You should check in your scripts that GetLuaEngine() == "LuaHypArc"
int engine_version=1062; //If you need a specific version for your script to work, check GetLuaEngineVersion() >= number

namespace luaGlobalFunctions {
	static int PerformIngameSpawn(lua_State * L)
	{
		uint32 spawntype = luaL_checkint(L, 1);
		uint32 entry_id = luaL_checkint(L, 2);
		uint32 map = luaL_checkint(L, 3);
		float x = (float)luaL_checkint(L, 4);
		float y = (float)luaL_checkint(L, 5);
		float z = (float)luaL_checkint(L, 6);
		float o = (float)luaL_checkint(L, 7);
		uint32 faction = luaL_checkint(L, 8);
		uint32 duration = luaL_checkint(L, 9);
		//std::string name = luaL_optstring(L, 10, "");
		uint32 equip1 = luaL_optint(L, 10, 1);
		uint32 equip2 = luaL_optint(L, 11, 1);
		uint32 equip3 = luaL_optint(L, 12, 1);

		if( !x || !y || !z || !entry_id || !map )
		{
			lua_pushnil(L);
			return 0;
		}

		if (spawntype==1) { //Unit
			CreatureProto *p = CreatureProtoStorage.LookupEntry(entry_id);
			//CreatureInfo *i = CreatureNameStorage.LookupEntry(entry_id);
			if (p == NULL)// || i == NULL) 
				return 0;
			MapMgr *mapMgr = sInstanceMgr.GetMapMgr(map);
			Creature * pCreature = mapMgr->GetInterface()->SpawnCreature(entry_id,x,y,z,o,true,true,0,0);
			pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,faction);
			pCreature->_setFaction();
			pCreature->SetInstanceID(mapMgr->GetInstanceID());
			pCreature->SetMapId(map);
			pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, equip1);
			pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, equip2);
			pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+2, equip3);
			if (duration>0) 
				pCreature->Despawn(duration,0);
			/*if (name.size()>0) {
				char *name2 = new char[50];
				strcpy(name2,name.c_str());
				i->Name = name2;
				pCreature->SetCreatureInfo(i);
			}*/
			Lunar<Unit>::push(L,pCreature);
			return 1;
		} else if (spawntype==2) { //GO
			GameObjectInfo *n = GameObjectNameStorage.LookupEntry(entry_id);
			if (n == NULL)
				return 0;
			GameObject *go = new GameObject(objmgr.GenerateGameObjectSpawnID());
			go->CreateFromProto(entry_id, map, x, y, z, o);
			if (duration > 0) go->Despawn(duration, 0);
			Lunar<GameObject>::push(L,go,false);
			return 1;
		} else return 0;
	}
	
	static int GetGameTime(lua_State * L)
	{
		lua_pushnumber(L, ((uint32)sWorld.GetGameTime())); //in seconds.
		return 1;
	}

	static int GetPlayer(lua_State * L)
	{
		string playa = luaL_checkstring(L, 1);
		//hypersniper: prevented world crashes with query
		string final = "SELECT online FROM `characters` WHERE `name` = '"+playa+"'";
		QueryResult * result = CharacterDatabase.Query(final.c_str());
		if (result) {
			Field *fields = result->Fetch();
			//sLog.outDebug("fields[0].GetString(): %s", fields[0].GetString());
			if (atoi(fields[0].GetString()) == 1) {
				Player * plr = objmgr.GetPlayer(playa.c_str());
				if (plr->IsInWorld()) {
					Lunar<Unit>::push(L,plr,false);
					return 1;
				}
			}
			else
				lua_pushboolean(L, 0);
		}
		return 0;
	}

	static int GetLUAEngine(lua_State * L) //also mapped to GetLuaEngine()
	{
		lua_pushstring(L, engine_name);
		return 1;
	}

	static int GetLuaEngineVersion(lua_State * L)
	{
		lua_pushnumber(L, engine_version);
		return 1;
	}
	
	static int WorldDBQuery(lua_State * L)
	{
		const char * qStr = luaL_checkstring(L,1);
		uint32 fID = luaL_checkint(L,2);
		if(!qStr) return 0;
		if (!Config.OptionalConfig.GetBoolDefault("LUAppArc", "AllowWorldDBQueries", false) || !Config.OptionalConfig.GetBoolDefault("LuaHypArc", "AllowWorldDBQueries", false)) {
			lua_pushboolean(L, 0);
			return 1;
		}
		QueryResult * result = WorldDatabase.Query(qStr);
		if (result) {
			Field *fields = result->Fetch();
			lua_pushstring(L, fields[fID].GetString()); 
		} else lua_pushboolean(L, 0);
		return 1;
	}

	static int CharDBQuery(lua_State * L)
	{
		const char * qStr = luaL_checkstring(L,1);
		uint32 fID = luaL_checkint(L,2);
		if(!qStr) return 0;
		if (!Config.OptionalConfig.GetBoolDefault("LUAppArc", "AllowCharDBQueries", false) || !Config.OptionalConfig.GetBoolDefault("LuaHypArc", "AllowCharDBQueries", false)) {
			lua_pushboolean(L, 0);
			return 1;
		}
		QueryResult * result = CharacterDatabase.Query(qStr);
		if (result) {
			Field *fields = result->Fetch();
			lua_pushstring(L, fields[fID].GetString()); 
		} else lua_pushboolean(L, 0);
		return 1;
	}
	
	static int SendWorldMessage(lua_State * L)
	{
	  const char * msg = luaL_checkstring(L,1);
	  uint32 MsgType = luaL_checkint(L,2);
	  if(!msg || !MsgType)
		{
			lua_pushnil(L);
			return 0;
		}
      char message[200];
		sprintf(message, msg);
		if (MsgType == 1)
		sWorld.SendWorldWideScreenText(message);
		if (MsgType == 2)
		sWorld.SendWorldText(message);
			return 0;
	}

	static int ReloadTable(lua_State * L)
	{
		const char * TableName = luaL_checkstring(L,1);
		if (0 == stricmp(TableName, "spell_disable"))
		{
			objmgr.ReloadDisabledSpells();
		} 
		else if (0 == stricmp(TableName, "vendors"))
		{
			objmgr.ReloadVendors();
		}
		else
		{
			if(!stricmp(TableName, "items"))					// Items
				ItemPrototypeStorage.Reload();
			else if(!stricmp(TableName, "creature_proto"))		// Creature Proto
				CreatureProtoStorage.Reload();
			else if(!stricmp(TableName, "creature_names"))		// Creature Names
				CreatureNameStorage.Reload();
			else if(!stricmp(TableName, "gameobject_names"))	// GO Names
				GameObjectNameStorage.Reload();
			else if(!stricmp(TableName, "areatriggers"))		// Areatriggers
				AreaTriggerStorage.Reload();
			else if(!stricmp(TableName, "itempages"))			// Item Pages
				ItemPageStorage.Reload();
			else if(!stricmp(TableName, "worldstring_tables"))			// wst
				WorldStringTableStorage.Reload();
			else if(!stricmp(TableName, "worldbroadcast"))			// wb
				WorldBroadCastStorage.Reload();
			else if(!stricmp(TableName, "quests"))				// Quests
				QuestStorage.Reload();
			else if(!stricmp(TableName, "npc_text"))			// NPC Text Storage
				NpcTextStorage.Reload();
			else if(!stricmp(TableName, "fishing"))				// Fishing Zones
				FishingZoneStorage.Reload();
			else if(!stricmp(TableName, "teleport_coords"))		// Teleport coords
				TeleportCoordStorage.Reload();
			else if(!stricmp(TableName, "graveyards"))			// Graveyards
				GraveyardStorage.Reload();
			else if(!stricmp(TableName, "worldmap_info"))		// WorldMapInfo
				WorldMapInfoStorage.Reload();
			else if(!stricmp(TableName, "zoneguards"))
				ZoneGuardStorage.Reload();
			else if(!stricmp(TableName, "unit_display_sizes"))
				UnitModelSizeStorage.Reload();
			else if(!stricmp(TableName, "command_overrides"))	// Command Overrides
			{
				CommandTableStorage::getSingleton().Dealloc();
				CommandTableStorage::getSingleton().Init();
				CommandTableStorage::getSingleton().Load();
			}
		}
		return 1;
	}

	static int ReloadLuaEngine(lua_State * L)
	{
		g_luaMgr.m_engine->Restart();
		return 1;
	}

	static int Rehash(lua_State * L)
	{
		sWorld.Rehash(true);
		return 1;
	}


	void Register(lua_State *L) {
		lua_pushcfunction(L, &PerformIngameSpawn);
		lua_setglobal(L, "PerformIngameSpawn");

		lua_pushcfunction(L, &GetPlayer);
		lua_setglobal(L, "GetPlayer");

		lua_pushcfunction(L, &GetLUAEngine);
		lua_setglobal(L, "GetLUAEngine");

		lua_pushcfunction(L, &GetLUAEngine);
		lua_setglobal(L, "GetLuaEngine");

		lua_pushcfunction(L, &GetLuaEngineVersion);
		lua_setglobal(L, "GetLuaEngineVersion");

		lua_pushcfunction(L, &GetGameTime);
		lua_setglobal(L, "GetGameTime");
		
		lua_pushcfunction(L, &WorldDBQuery);
		lua_setglobal(L, "WorldDBQuery");

		lua_pushcfunction(L, &CharDBQuery);
		lua_setglobal(L, "CharDBQuery");
		
		lua_pushcfunction(L, &SendWorldMessage);
		lua_setglobal(L, "SendWorldMessage");

		lua_pushcfunction(L, &ReloadTable);
		lua_setglobal(L, "ReloadTable");

		lua_pushcfunction(L, &ReloadLuaEngine);
		lua_setglobal(L, "ReloadLuaEngine");

		lua_pushcfunction(L, &Rehash);
		lua_setglobal(L, "Rehash");
	}
}
