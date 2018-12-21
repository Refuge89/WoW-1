#ifndef GOFUNCTIONS_H
#define GOFUNCTIONS_H

namespace luaGameObject
{
	int GossipCreateMenu(lua_State * L, GameObject * ptr);
	int GossipMenuAddItem(lua_State * L, GameObject * ptr);
	int GossipSendMenu(lua_State * L, GameObject * ptr);
	int GossipComplete(lua_State * L, GameObject * ptr);
	int GossipSendPOI(lua_State * L, GameObject * ptr);
	/* I have no idea why, but this comment was in original LUA++... probably a kind of todo? I will check that...
	int luaGameObject_GossipObjectCreateMenu(lua_State * L, GameObject * ptr);
	int luaGameObject_GossipObjectMenuAddItem(lua_State * L, GameObject * ptr);
	int luaGameObject_GossipObjectSendMenu(lua_State * L, GameObject * ptr);
	int luaGameObject_GossipObjectComplete(lua_State * L, GameObject * ptr);
	int luaGameObject_GossipObjectSendPOI(lua_State * L, GameObject * ptr);
	int luaGameObject_ModUInt32Value(lua_State * L, GameObject * ptr);
	int luaGameObject_ModFloatValue(lua_State * L, GameObject * ptr);
	int luaGameObject_GetFloatValue(lua_State * L, GameObject * ptr);
	int luaGameObject_InitPacket(lua_State * L, GameObject * ptr);
	int luaGameObject_AddDataToPacket(lua_State * L, GameObject * ptr);
	int luaGameObject_AddGuidDataToPacket(lua_State * L, GameObject * ptr);
	int luaGameObject_SendData(lua_State * L, GameObject * ptr);
	*/


	//////////////////
	/////GET STUFF////
	//////////////////
	int GetName(lua_State * L, GameObject * ptr);
	int GetMapId(lua_State * L, GameObject * ptr);
	int GetCreatureNearestCoords(lua_State * L, GameObject * ptr);
	int GetGameObjectNearestCoords(lua_State *L, GameObject * ptr);
	//int GetAreaID(lua_State * L, GameObject * ptr);
	int GetClosestPlayer(lua_State * L, GameObject * ptr);
	int GetZoneId(lua_State *L, GameObject * ptr);
	int GetItemCount(lua_State * L, GameObject * ptr);
	int GetSpawnX(lua_State * L, GameObject * ptr);
	int GetSpawnY(lua_State * L, GameObject * ptr);
	int GetSpawnZ(lua_State * L, GameObject * ptr);
	int GetSpawnO(lua_State * L, GameObject * ptr);
	int GetInRangePlayersCount(lua_State * L, GameObject * ptr);
	int GetEntry(lua_State * L, GameObject * ptr);
	int GetX(lua_State * L, GameObject * ptr);
	int GetY(lua_State * L, GameObject * ptr);
	int GetZ(lua_State * L, GameObject * ptr);
	int GetO(lua_State * L, GameObject * ptr);
	int GetInRangePlayers(lua_State * L, GameObject * ptr);
	int GetInRangeGameObjects(lua_State * L, GameObject * ptr);
	int GetInstanceID(lua_State * L, GameObject * ptr);
	int GetUInt64Value(lua_State * L, GameObject * ptr);
	int GetUInt32Value(lua_State * L, GameObject * ptr);
	int GetFloatValue(lua_State * L, GameObject * ptr);
	int GetGUID(lua_State * L, GameObject* ptr);

	//////////////////
	//////END/////////
	/////////////////

	int Teleport(lua_State * L, GameObject * ptr);
	int AddItem(lua_State * L, GameObject * ptr);
	int Despawn(lua_State * L, GameObject * ptr);
	int IsInWorld(lua_State * L, GameObject * ptr);
	int IsInBack(lua_State * L, GameObject * ptr);
	int IsInFront(lua_State * L, GameObject * ptr);
	int PlaySoundToSet(lua_State * L, GameObject * ptr);
	int SpawnCreature(lua_State * L, GameObject * ptr);
	int SpawnGameObject(lua_State * L, GameObject * ptr);
	int CalcDistance(lua_State * L, GameObject * ptr);
	int SetOrientation(lua_State * L, GameObject * ptr);
	int RemoveFromWorld(lua_State * L, GameObject * ptr);
	int CalcRadAngle(lua_State * L, GameObject * ptr);
	int SetUInt32Value(lua_State * L, GameObject * ptr);
	int SetUInt64Value(lua_State * L, GameObject * ptr);
	int SetFloatValue(lua_State * L, GameObject * ptr);
	int ModUInt32Value(lua_State * L, GameObject * ptr);
	int CastSpell(lua_State * L, GameObject * ptr);
	int FullCastSpell(lua_State * L, GameObject * ptr);
	int CastSpellOnTarget(lua_State * L, GameObject * ptr);
	int FullCastSpellOnTarget(lua_State * L, GameObject * ptr);
	int EventCastSpell(lua_State * L, GameObject * ptr);
	int RegisterAIUpdate(lua_State *L, GameObject * ptr);
	int ModAIUpdate(lua_State * L, GameObject * ptr);
	int RemoveAIUpdate(lua_State * L, GameObject * ptr);

	int PerformWorldDBQuery(lua_State * L, GameObject * ptr);
	int PerformCharDBQuery(lua_State * L, GameObject * ptr);

	int Activate(lua_State * L, GameObject* ptr);
	int IsActive(lua_State * L, GameObject* ptr);
	int DespawnObject(lua_State * L, GameObject* ptr);

	int GetGameTime(lua_State * L, GameObject * ptr);
	int GetLandHeight(lua_State * L, GameObject * ptr);
	int SetZoneWeather(lua_State * L, GameObject * ptr);
	int GetDistanceYards(lua_State * L, GameObject * ptr);
	int PhaseSet(lua_State * L, GameObject * ptr);
	int PhaseAdd(lua_State * L, GameObject * ptr);
	int PhaseDelete(lua_State * L, GameObject * ptr);
	int GetPhase(lua_State * L, GameObject * ptr);
	int InitPacket(lua_State * L, GameObject * ptr);
	int AddDataToPacket(lua_State * L, GameObject * ptr);
	int SendPacketToSet(lua_State * L, GameObject * ptr);
	int SendPacketToZone(lua_State * L, GameObject * ptr);
	int SendPacketToInstance(lua_State * L, GameObject * ptr);
	int SendPacketToWorld(lua_State * L, GameObject * ptr);
	int GetRawGUID(lua_State * L, GameObject* ptr);
	int AddLoot(lua_State * L, GameObject* ptr);
}
#endif
