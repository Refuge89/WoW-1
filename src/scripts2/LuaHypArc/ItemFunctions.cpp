/*************************************************************\
|                           LuaHypArc                         |
|                      ==================                     |
|                   An extension of LUAppArc                  |
|                                                             |
|                     luahyparc.zapto.org                     |
\*************************************************************/
#include "StdAfx.h"
#include "LUAEngine.h"
#include "ItemFunctions.h"

namespace luaItem
{
	///////GOSSIP///////
	int GossipCreateMenu(lua_State * L, Item * ptr)
	{
		int text_id = luaL_checkint(L, 1);
		Unit* target = Lunar<Unit>::check(L, 2);
 		int autosend = luaL_checkint(L, 3);
	 
		Player* plr = (Player*)target;
	    
		objmgr.CreateGossipMenuForPlayer(&Menu, ptr->GetGUID(), text_id, plr);
		if(autosend)
			Menu->SendTo(plr);
		return 1;
	}

	int GossipMenuAddItem(lua_State * L, Item * ptr)
	{
		int icon = luaL_checkint(L, 1);
		const char * menu_text = luaL_checkstring(L, 2);
		int IntId = luaL_checkint(L, 3);
		int extra = luaL_checkint(L, 4);

		Menu->AddItem(icon, menu_text, IntId, extra);
		return 1;
	}

	int GossipSendMenu(lua_State * L, Item * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player * plr = (Player*)target;
		Menu->SendTo(plr);
		return 1;
	}

	int GossipComplete(lua_State * L, Item * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player * plr = (Player*)target;
		plr->Gossip_Complete();
		return 1;
	}

	int GossipSendPOI(lua_State * L, Item * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player * plr = (Player*)target;
		float x = (float)luaL_checknumber(L, 2);
		float y = (float)luaL_checknumber(L, 3);
		int icon = luaL_checkint(L, 4);
		int flags = luaL_checkint(L, 5);
		int data = luaL_checkint(L, 6);
		const char * name = luaL_checkstring(L, 7);

		plr->Gossip_SendPOI(x, y, icon, flags, data, name);
		return 1;
	}

	int PerformWorldDBQuery(lua_State * L, Item* ptr)
	{
		const char * qStr = luaL_checkstring(L,1);
		if(!qStr) return 0;
		if (!Config.OptionalConfig.GetBoolDefault("LUAppArc", "AllowWorldDBQueries", false)) {
			lua_pushnumber(L, (lua_Number)0); //0=Disabled
			return 1;
		}
		QueryResult * result = WorldDatabase.Query(qStr);
		if (result) {
			lua_pushnumber(L, (lua_Number)1); //1=GotData
		} else lua_pushnumber(L, (lua_Number)2); //2=NoData
		return 1;
	}

	int PerformCharDBQuery(lua_State * L, Item* ptr)
	{
		const char * qStr = luaL_checkstring(L,1);
		if(!qStr) return 0;
		if (!Config.OptionalConfig.GetBoolDefault("LUAppArc", "AllowCharDBQueries", false)) {
			lua_pushnumber(L, (lua_Number)0); //0=Disabled
			return 1;
		}
		QueryResult * result = CharacterDatabase.Query(qStr);
		if (result) {
			lua_pushnumber(L, (lua_Number)1); //1=GotData
		} else lua_pushnumber(L, (lua_Number)2); //2=NoData
		return 1;
	}

	int GetOwner(lua_State * L, Item* ptr)
	{
		Lunar<Player>::push(L, ptr->GetOwner(), false);
		return 1;
	}

	int AddEnchantment(lua_State * L, Item* ptr)
	{
		int entry = luaL_checkint(L,1);
		int duration = luaL_checkint(L,2);
		bool permanent = (duration == 0) ? true : false;
		bool temp = (luaL_checkint(L, 3) == 1) ? true : false;

		EnchantEntry *eentry = dbcEnchant.LookupEntry( entry );

		lua_pushinteger(L, ptr->AddEnchantment(eentry, duration, permanent, true, temp)); //Return the enchantment Slot back to LUA
		return 1;
	}

	int GetGUID(lua_State * L, Item* ptr)
	{
		lua_pushnumber(L, (lua_Number)ptr->GetGUID());
		return 1;
	}

	int GetRawGUID(lua_State * L, Item* ptr)
	{	//since Lua can't handle huge uint64's, this makes it a string.
		//if you require a guid, you should get this string and turn it back into a uint64.
		//see luaUnit::SendLootWindow for info on how to achieve this.
		if(!ptr) 
			return 0;
		uint64 guid = ptr->GetGUID();
		std::string guidString;
		std::stringstream out;
		out << guid;
		guidString = out.str();
		lua_pushstring(L, guidString.c_str());
		return 1;
	}

	int RemoveEnchantment(lua_State * L, Item* ptr)
	{
		int slot = luaL_checkint(L,1);
		bool temp = (luaL_IsInt(L,2)==1) ? true : false;

		if (slot == -1)	ptr->RemoveAllEnchantments(temp);
		else if (slot == -2) ptr->RemoveProfessionEnchant();
		else if (slot == -3) ptr->RemoveSocketBonusEnchant();
		else if (slot >= 0) ptr->RemoveEnchantment(slot);

		return 0;
	}

	int GetEntryId(lua_State * L, Item* ptr)
	{
		if (!ptr) return 0;
		ItemPrototype * proto = ptr->GetProto();
		lua_pushnumber(L, proto->ItemId);
		return 1;
	}

	int GetName(lua_State * L, Item* ptr)
	{
		if (!ptr) 
			return 0;
		ItemPrototype * proto = ptr->GetProto();
		lua_pushstring(L, proto->Name1);
		return 1;
	}

	int GetSpellId(lua_State * L, Item* ptr)
	{
		uint32 index = luaL_checkint(L, 1);
		if (!ptr || index < 0 || index > 5)
			return 0;
		ItemPrototype * proto = ptr->GetProto();
		lua_pushnumber(L, proto->Spells[index].Id);
		return 1;
	}

	int GetSpellTrigger(lua_State * L, Item* ptr)
	{
		uint32 index = luaL_checkint(L, 1);
		if (!ptr || index < 0 || index > 5)
			return 0;
		ItemPrototype * proto = ptr->GetProto();
		lua_pushnumber(L, proto->Spells[index].Trigger);
		/*	
			USE				= 0,
			ON_EQUIP		= 1,
			CHANCE_ON_HIT	= 2,
			SOULSTONE		= 4,
			LEARNING		= 6,
		*/
		return 1;
	}

	int AddLoot(lua_State * L, Item* ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		uint32 itemid = luaL_checkint(L,1);
		uint32 mincount = luaL_checkint(L,2);
		uint32 maxcount = luaL_checkint(L,3);
		uint32 ffa_loot = luaL_checkint(L,4);
		lootmgr.AddLoot(ptr->loot,itemid,mincount,maxcount,ffa_loot);
		return 1;
	}
}
