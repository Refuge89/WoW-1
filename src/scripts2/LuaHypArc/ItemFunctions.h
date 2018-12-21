#ifndef ITEMFUNCTIONS_H
#define ITEMFUNCTIONS_H

namespace luaItem
{
	int GossipCreateMenu(lua_State * L, Item * ptr);
	int GossipMenuAddItem(lua_State * L, Item * ptr);
	int GossipSendMenu(lua_State * L, Item * ptr);
	int GossipComplete(lua_State * L, Item * ptr);
	int GossipSendPOI(lua_State * L, Item * ptr);

	int PerformWorldDBQuery(lua_State * L, Item * ptr);
	int PerformCharDBQuery(lua_State * L, Item * ptr);

	int GetOwner(lua_State * L, Item* ptr);
	int RemoveEnchantment(lua_State * L, Item* ptr);
	int AddEnchantment(lua_State * L, Item* ptr);

	int GetEntryId(lua_State * L, Item* ptr);
	int GetName(lua_State * L, Item* ptr);
	int GetSpellId(lua_State * L, Item* ptr);
	int GetSpellTrigger(lua_State * L, Item* ptr);
	int GetRawGUID(lua_State * L, Item* ptr);
	int GetGUID(lua_State * L, Item* ptr);
	int AddLoot(lua_State * L, Item* ptr);
}
#endif
