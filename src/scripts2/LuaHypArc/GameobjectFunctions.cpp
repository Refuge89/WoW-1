/*************************************************************\
|                           LuaHypArc                         |
|                      ==================                     |
|                   An extension of LUAppArc                  |
|                                                             |
|                     luahyparc.zapto.org                     |
\*************************************************************/
#include "StdAfx.h"
#include "LUAEngine.h"
#include "GameobjectFunctions.h"

namespace luaGameObject
{
	WorldPacket Bufferdata[16];
	int GossipCreateMenu(lua_State * L, GameObject * ptr)
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
	int GossipMenuAddItem(lua_State * L, GameObject * ptr)
	 {
		int icon = luaL_checkint(L, 1);
		const char * menu_text = luaL_checkstring(L, 2);
		int IntId = luaL_checkint(L, 3);
		int extra = luaL_checkint(L, 4);

		Menu->AddItem(icon, menu_text, IntId, extra);
		return 1;
	}
	int GossipSendMenu(lua_State * L, GameObject * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player * plr = (Player*)target;
		Menu->SendTo(plr);
		return 1;
	}
	int GossipComplete(lua_State * L, GameObject * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player * plr = (Player*)target;
 		plr->Gossip_Complete();
 		return 1;
	 }
	int GossipSendPOI(lua_State * L, GameObject * ptr)
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

	int RegisterAIUpdate(lua_State *L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 time = luaL_checkint(L,1);
		sEventMgr.AddEvent(ptr,&GameObject::CallScriptUpdate, EVENT_SCRIPT_UPDATE_EVENT, time, 0, 0);
		return 0;
	}

	int ModAIUpdate(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 newtime = luaL_checkint(L,1);
		sEventMgr.ModifyEventTimeAndTimeLeft(ptr, EVENT_SCRIPT_UPDATE_EVENT, newtime);
		return 0;
	}
	int RemoveAIUpdate(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		sEventMgr.RemoveEvents(ptr, EVENT_SCRIPT_UPDATE_EVENT);
		return 0;
	}
	/*int EventCastSpell(lua_State * L, GameObject * ptr)
	{
		uint32 guid = luaL_checkint(L,1);
		uint32 sp = luaL_checkint(L,2);
		uint32 delay = luaL_checkint(L,3);
		uint32 repeats = luaL_checkint(L,4);
		if(guid && sp && delay)
		{
			sEventMgr.AddEvent(ptr,&GameObject::EventCastSpell,guid,sp,false,EVENT_GAMEOBJECT_UPDATE,delay,repeats,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
		return 0;
	}*/
	int GetMapId(lua_State * L, GameObject * ptr)
	{
		if(ptr)
		{
			lua_pushinteger(L,ptr->GetMapId());
		}
		return 1;
	}
	int RemoveFromWorld(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			ptr->RemoveFromWorld(true);
		return 0;
	}
	//int GetAreaID(lua_State * L, GameObject * ptr)
	//{
	//	float x = (float)luaL_checkint(L, 1);
	//	float y = (float)luaL_checkint(L, 2);
	//	if(ptr)
	//		lua_pushinteger(L,ptr->GetMapMgr()->GetAreaID(x, y));
	//	return 1;
	//}
	int GetName(lua_State * L, GameObject * ptr)
	{
		if(!ptr||ptr->GetTypeId()!=TYPEID_GAMEOBJECT||!ptr->GetInfo())
		{
			lua_pushstring(L,"Unknown");
			return 1;
		}

		lua_pushstring(L,ptr->GetInfo()->Name);
		return 1;
	}
	int Teleport(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		Player* target = Lunar<Player>::check(L, 1);
		int mapId = luaL_checkint(L, 2);
		double posX = luaL_checknumber(L, 3);
		double posY = luaL_checknumber(L, 4);
		double posZ = luaL_checknumber(L, 5);
		//Log.Notice("LuaEngine", "LUATeleporter GO running. Player:"); //You may comment this because I still don't know what this function is for. If it wss ...
		//Log.Notice("LuaEngine", ((Player*)target)->GetName()); //...bugged before it is in this rev, too! These two Lines were only added for debugging reasons.
		if(!posX || !posY || !posZ) {
			//Log.Notice("LuaEngine", "LUATeleporter GO ERROR - Coordinates");
			return 0;
		}
		if (!mapId) mapId = 0;
		LocationVector vec((float)posX, (float)posY, (float)posZ);
		((Player*)target)->SafeTeleport((uint32)mapId, 0, vec);
		return 0;
	}
	int GetCreatureNearestCoords(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		if(!ptr) return 0;
		uint32 entryid = luaL_checkint(L,4);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		if(!entryid) 
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,ptr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(x, y, z, entryid), false);
		return 1;
	}
	int GetGameObjectNearestCoords(lua_State *L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);

		uint32 entryid = luaL_checkint(L,4);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		if(!entryid) 
			lua_pushnil(L);
		else
			Lunar<GameObject>::push(L,ptr->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(x, y, z, entryid), false);
		return 1;
	}
	int AddItem(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int id = luaL_checkint(L,1);
		int count = luaL_checkint(L,2);

		Player * plr = (Player*)ptr;
		ItemPrototype * proto = ItemPrototypeStorage.LookupEntry(id);
		if(proto==NULL)
			return 0;

		Item * add = plr->GetItemInterface()->FindItemLessMax(id,count,false);
		if(add==NULL)
		{
			add=objmgr.CreateItem(id,plr);
			add->SetUInt32Value(ITEM_FIELD_STACK_COUNT,count);
			if(plr->GetItemInterface()->AddItemToFreeSlot(add))
				plr->GetSession()->SendItemPushResult(add,false,true,false,true,plr->GetItemInterface()->LastSearchItemBagSlot(),plr->GetItemInterface()->LastSearchItemSlot(),count);
			else
				delete add;
		}
		else
		{
			add->ModSignedInt32Value(ITEM_FIELD_STACK_COUNT,count);
			plr->GetSession()->SendItemPushResult(add,false,true,false,false,(uint8)plr->GetItemInterface()->GetBagSlotByGuid(add->GetGUID()),0xFFFFFFFF,count);
		}

		return 0;
	}
	int GetClosestPlayer(lua_State * L, GameObject * ptr)
	{
		if(!ptr)
			return 0;

		float d2=0;
		float dist=0;
		Player * ret=NULL;

		for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); )//itr)
		{
			d2=(*itr)->GetDistanceSq(ptr);
			if(!ret||d2<dist)
			{
				dist=d2;
				ret=*itr;
			}
		}

		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,((Unit*)ret),false);

		return 1;
	}
	int GetDistance(lua_State * L, GameObject * ptr)
	{
		if(!ptr)
			return 0;
		Unit * target = Lunar<Unit>::check(L, 1);
		lua_pushnumber(L,ptr->GetDistance2dSq(target));
		return 1;
	}
	int IsInWorld(lua_State * L, GameObject * ptr)
	{
		if (ptr)
			if(ptr->IsInWorld())
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int GetZoneId(lua_State *L, GameObject * ptr)
	{
		if(!ptr)
			return 0;
		lua_pushinteger(L,(ptr->GetZoneId()));
		return 1;
	}
	int PlaySoundToSet(lua_State * L, GameObject * ptr)
	{
		if(!ptr) return 0;
		int soundid = luaL_checkint(L,1);
		ptr->PlaySoundToSet(soundid);
		return 0;
	}
	int SpawnCreature(lua_State * L, GameObject * ptr)
	{
		if(ptr == NULL) return 0;
		uint32 entry_id = luaL_checkint(L, 1);
		float x = (float)luaL_checkint(L, 2);
		float y = (float)luaL_checkint(L, 3);
		float z = (float)luaL_checkint(L, 4);
		float o = (float)luaL_checkint(L, 5);
		uint32 faction = luaL_checkint(L, 6);
		uint32 duration = luaL_checkint(L, 7);

		if( !x || !y || !z || !entry_id || !faction /*|| !duration*/) //Shady: is it really required?
		{
			lua_pushnil(L);
			return 1;
		}
		CreatureProto *p = CreatureProtoStorage.LookupEntry(entry_id);
	    
		if(p == NULL)
		  return 0;

		Creature *pCreature = ptr->GetMapMgr()->CreateCreature(entry_id);
		pCreature->spawnid = 0;
		pCreature->m_spawn = 0;
		pCreature->Load(p,x,y,z);
		if(faction)
			pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,faction);
		pCreature->_setFaction();
		pCreature->SetMapId(ptr->GetMapId());
		pCreature->SetOrientation(o);
		pCreature->Despawn(duration, 0);
		pCreature->SetInstanceID(ptr->GetInstanceID());
		pCreature->PushToWorld(ptr->GetMapMgr());
		if(duration)
		{
			pCreature->Despawn(duration,0);
		}
		Lunar<Unit>::push(L,pCreature);
		return 0;
	}
	int GetItemCount(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_PLAYER);
		int itemid = luaL_checkint(L,1);
		lua_pushinteger(L, ((Player*)ptr)->GetItemInterface()->GetItemCount(itemid,false));
		return 1;
	}
	int SpawnGameObject(lua_State * L, GameObject * ptr)
	{
		if(ptr == NULL) return 0;
		uint32 entry_id = luaL_checkint(L, 1);
		float x = (float)luaL_checkint(L, 2);
		float y = (float)luaL_checkint(L, 3);
		float z = (float)luaL_checkint(L, 4);
		float o = (float)luaL_checkint(L, 5);
		uint32 duration = luaL_checkint(L, 6);
		float scale = (float)(luaL_optint(L, 7, 100)/100); 
		if (!scale) scale = 1;
		if(!entry_id || !duration)
		{
			lua_pushnil(L);
			return 1;
		}

		GameObjectInfo *goi = GameObjectNameStorage.LookupEntry(entry_id);
		if (goi == NULL){
			dropWarning("Invalid GameObject ID specified: %u", entry_id);
			lua_error(L);
			return 0;
		}
		GameObject *pC = ptr->GetMapMgr()->CreateGameObject(entry_id);
		pC->m_spawn=0;
		pC->CreateFromProto(entry_id, ptr->GetMapId(), (float)x, (float)y, (float)z, (float)o);
		pC->SetMapId(ptr->GetMapId());
		pC->SetInstanceID(ptr->GetInstanceID());
		pC->SetFloatValue(OBJECT_FIELD_SCALE_X, scale);
		pC->Spawn(ptr->GetMapMgr());
		if(duration)
		{
			sEventMgr.AddEvent(pC, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_UPDATE, duration, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
		Lunar<GameObject>::push(L,pC);

		return 0;
	}
	int CalcDistance(lua_State * L, GameObject * ptr)
	{
		Object * ob = Lunar<Object>::check(L,1);
		if(ob)
			lua_pushnumber(L,ptr->CalcDistance(ob));
		return 1;
	}
	int GetSpawnX(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnX());
		return 1;
	}
	int GetSpawnY(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnY());
		return 1;
	}
	int GetSpawnZ(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnZ());
		return 1;
	}
	int GetSpawnO(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnO());
		return 1;
	}
	int GetX(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetPositionX());
		return 0;
	}
	int GetY(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetPositionY());
		return 0;
	}
	int GetZ(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetPositionZ());
		return 0;
	}
	int GetO(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetOrientation());
		return 0;
	}

	int GetInRangePlayersCount(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetInRangePlayersCount());
		return 1;
	}
	int GetEntry(lua_State * L, GameObject * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetEntry());
		return 1;
	}
	int SetOrientation(lua_State * L, GameObject * ptr)
	{
		float newo = (float)luaL_checkint(L, 1);
		if(!newo|!ptr)
			return 0;
		ptr->SetOrientation(newo);
		return 0;
	}
	int CalcRadAngle(lua_State * L, GameObject * ptr)
	{
		float x = (float)luaL_checkint(L,1 );
		float y = (float)luaL_checkint(L, 2);
		float x2 = (float)luaL_checkint(L, 3);
		float y2 = (float)luaL_checkint(L, 4);
		if(!x||!y||!x2||!y2||!ptr)
			return 0;
		lua_pushnumber(L,ptr->calcRadAngle(x,y,x2,y2));
		return 0;
	}
	int GetInstanceID(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		if(ptr->GetMapMgr()->GetMapInfo()->type == INSTANCE_NULL)
			lua_pushnil(L);
		else
			lua_pushinteger(L,ptr->GetInstanceID());
		return 1;
	}
	int GetInRangePlayers(lua_State * L, GameObject * ptr)
	{
		uint32 count = 0;
		lua_newtable(L);
		for(std::set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); itr++)
		{
			if( (*itr) ->IsUnit())
			{
				count++,
				lua_pushinteger(L,count);
				Lunar<Unit>::push(L,((Unit*)*itr),false);
				lua_rawset(L,-3);
			}
		}
		return 1;
	}

	int GetInRangeGameObjects(lua_State * L, GameObject * ptr)
	{
		uint32 count = 0;
		lua_newtable(L);
		for (std::set<Object*>::iterator itr = ptr->GetInRangeSetBegin();itr!= ptr->GetInRangeSetEnd();itr++)
		{
			if( (*itr) ->GetTypeId() == TYPEID_GAMEOBJECT)
			{
				count++,
				lua_pushinteger(L,count);
				Lunar<GameObject>::push(L,((GameObject*)*itr),false);
				lua_rawset(L,-3);
			}
		}
		return 1;
	}
	int IsInFront(lua_State * L, GameObject * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			if(ptr->isInFront(target))
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int IsInBack(lua_State * L, GameObject * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			if(ptr->isInBack(target))
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int GetUInt32Value(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		if (field == -1) {
			lua_pushinteger(L,500);
		}
		if (ptr)
			lua_pushinteger(L,ptr->GetUInt32Value(field));
		return 1;
	}
	int GetUInt64Value(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		if (ptr && field)
		{
			lua_pushinteger(L,(int)ptr->GetUInt64Value(field));
		}
		return 1;
	}
	int SetUInt32Value(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		int value = luaL_checkint(L,2);
		if (!value) value = (int)0;
		if(ptr && field && value)
		{
			ptr->SetUInt32Value(field,value);
		}
		return 1;
	}
	int SetUInt64Value(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		int value = luaL_checkint(L,2);
		if (!value) value = (int)0;
		if(ptr && field && value)
		{
			ptr->SetUInt64Value(field,value);
		}
		return 1;
	}
	int SetFloatValue(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		float value = (float)luaL_checkint(L,2);
		if (!value) value = (float)0.0;
		if( ptr && value)
		{
			ptr->SetFloatValue(field,value);
		}
		return 1;
	}
	int GetFloatValue(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		if( ptr && field)
		{
			lua_pushnumber(L,ptr->GetFloatValue(field));
		}
		return 1;
	}
	int ModUInt32Value(lua_State * L, GameObject * ptr)
	{
		int field = luaL_checkint(L,1);
		int value = luaL_checkint(L,2);
		if (!value) value = (int)0;
		if( ptr && field && value)
		{
			ptr->ModSignedInt32Value(field,value);
		}
		return 1;
	}
	int CastSpell(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 sp = luaL_checkint(L,1);
		if( !ptr || !sp|| sp == 0) return 0;
		
		Spell * spp = new Spell(ptr,dbcSpell.LookupEntry(sp),true,NULL);
		SpellCastTargets tar(ptr->GetGUID());
		spp->prepare(&tar);
		return 0;
	}
	int FullCastSpell(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 sp = luaL_checkint(L,1);
		if( !ptr || !sp|| sp == 0) return 0;
		
		Spell * spp = new Spell(ptr,dbcSpell.LookupEntry(sp),false,NULL);
		SpellCastTargets tar(ptr->GetGUID());
		spp->prepare(&tar);
		return 0;
	}
	int CastSpellOnTarget(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 sp = luaL_checkint(L,1);
		Unit * target = Lunar<Unit>::check(L,2);
		if( !ptr || !sp || sp == 0 || target==NULL) return 0;

		Spell * spp = new Spell(ptr,dbcSpell.LookupEntry(sp),true,NULL);
		spp->m_targets.m_unitTarget = target->GetGUID();
		//prepare digest
		SpellCastTargets tar(target->GetGUID());
		spp->m_targets = tar;
		spp->SendSpellStart();
		spp->cast(false);
		//finish digest
		delete spp;
		return 0;
	}
	int GetGameTime(lua_State * L, GameObject * ptr)
	{
		lua_pushnumber(L, ((uint32)sWorld.GetGameTime()));
		Log.Notice("LuaEngine","Please use the global function GetGameTime instead. This GO-based one is deprecated.");
		return 1;
	}
	int GetLandHeight(lua_State * L, GameObject * ptr)
	{
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		if (!ptr || !x || !y) 
			return 0;
		float lH = ptr->GetMapMgr()->GetLandHeight(x,y);
		lua_pushnumber(L, lH);
		return 0;
	}
	int SetZoneWeather(lua_State * L, GameObject * ptr)
	{
		/*
		WEATHER_TYPE_NORMAL            = 0, // NORMAL (SUNNY)
		WEATHER_TYPE_FOG               = 1, // FOG
		WEATHER_TYPE_RAIN              = 2, // RAIN
		WEATHER_TYPE_HEAVY_RAIN        = 4, // HEAVY_RAIN
		WEATHER_TYPE_SNOW              = 8, // SNOW
		WEATHER_TYPE_SANDSTORM         = 16 // SANDSTORM
		*/
		uint32 zone_id = (uint32)luaL_checknumber(L, 1);
		uint32 type = (uint32)luaL_checknumber(L, 2);
		float Density = (float)luaL_checknumber(L, 3); //min: 0.30 max: 2.00
		if (Density<0.30f || Density>2.0f || !zone_id || !type)
			return 0;

		uint32 sound;
		if(Density<=0.30f)
			sound = 0;

		switch(type)
		{
			case 2:                                             //rain
			case 4:                                             
				if(Density  <0.40f)
					 sound = 8533;
				else if(Density  <0.70f)
					sound = 8534;
				else
					sound = 8535;
				break;
			case 8:                                             //snow
				if(Density  <0.40f)
					sound = 8536;
				else if(Density  <0.70f)
					sound = 8537;
				else
					sound = 8538;
				break;
			case 16:                                             //storm
				if(Density  <0.40f)
					sound = 8556;
				else if(Density  <0.70f)
					sound = 8557;
				else
					sound = 8558;
				break;
			default:											//no sound
				sound = 0;
				break;
		}
		WorldPacket data(SMSG_WEATHER, 9);
		data.Initialize(SMSG_WEATHER);
		if(type == 0 ) // set all parameter to 0 for sunny.
			data << uint32(0) << float(0) << uint32(0) << uint8(0);		
		else if (type == 1) // No sound/density for fog
			data << type << float(0) << uint32(0) << uint8(0);		
		else
			data << type << Density << sound << uint8(0) ;

		sWorld.SendZoneMessage(&data, zone_id, 0);

		return 0;
	}
	int GetDistanceYards(lua_State * L, GameObject * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(!ptr || !target)
			return 0;
		LocationVector vec = ptr->GetPosition();
		lua_pushnumber(L,(float)vec.Distance(target->GetPosition()));
		return 1;
	}
	int PhaseSet(lua_State * L, GameObject * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_optint(L,2,false)>0 ? true:false);
		if (!ptr)
			return 0;
		ptr->Phase(PHASE_SET, newphase);
		if (ptr->m_spawn) 
			ptr->m_spawn->phase = newphase; 
		if (Save)
		{
			ptr->SaveToDB();
			ptr->m_loadedFromDB = true;
		}
		return 1;
	}

	int PhaseAdd(lua_State * L, GameObject * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_optint(L,2,false)>0 ? true:false);
		if (!ptr)
			return 0;
		ptr->Phase(PHASE_ADD, newphase);
		if (ptr->m_spawn) 
			ptr->m_spawn->phase |= newphase; 
		if (Save)
		{
			ptr->SaveToDB();
			ptr->m_loadedFromDB = true;
		}
		return 1;
	}

	int PhaseDelete(lua_State * L, GameObject * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_optint(L,2,false)>0 ? true:false);
		if (!ptr)
			return 0;
		ptr->Phase(PHASE_DEL, newphase);
		if (ptr->m_spawn) 
			ptr->m_spawn->phase &= ~newphase; 
		if (Save)
		{
			ptr->SaveToDB();
			ptr->m_loadedFromDB = true;
		}
		return 1;
	}

	int GetPhase(lua_State * L, GameObject * ptr)
	{
		if (!ptr) return 0;
		lua_pushnumber(L,ptr->m_phase);
		return 1;
	}
	int InitPacket(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		int packet_id = luaL_checkint(L, 2);
		Bufferdata[buffer_index].Initialize(packet_id);
		return 1;
	}

	int AddDataToPacket(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		int type = luaL_checkint(L, 2);
		switch(type)
		{
			case 0:
				// int
				Bufferdata[buffer_index] << luaL_checkint(L, 3);
				break;
			case 1:
				// uint8
				Bufferdata[buffer_index] << (uint8)luaL_checknumber(L, 3);
				break;
			case 2:
				// uint16
				Bufferdata[buffer_index] << (uint16)luaL_checknumber(L, 3);
				break;
			case 3:
				// uint32
				Bufferdata[buffer_index] << (uint32)luaL_checknumber(L, 3);
				break;
			case 4:
				// uint64
				Bufferdata[buffer_index] << (uint64)luaL_checknumber(L, 3);
				break;
			case 5:
				// float
				Bufferdata[buffer_index] << (float)luaL_checknumber(L, 3);
				break;
			case 6:
				// double
				Bufferdata[buffer_index] << (double)luaL_checknumber(L, 3);
				break;
			case 7:
				// string
				Bufferdata[buffer_index] << luaL_checkstring(L, 3);
				break;
		}
		return 1;
	}

	int SendPacketToSet(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		if (!ptr) return 0;
		ptr->SendMessageToSet(&Bufferdata[buffer_index],true);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToZone(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		uint32 zone_id = (uint32)luaL_checknumber(L, 2);
		sWorld.SendZoneMessage(&Bufferdata[buffer_index],zone_id);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToInstance(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		uint32 instance_id = (uint32)luaL_checknumber(L, 2);
		sWorld.SendInstanceMessage(&Bufferdata[buffer_index],instance_id);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToWorld(lua_State * L, GameObject * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		sWorld.SendGlobalMessage(&Bufferdata[buffer_index]);
		Bufferdata[buffer_index].clear();
		return 1;
	}
	int FullCastSpellOnTarget(lua_State * L, GameObject * ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		uint32 sp = luaL_checkint(L,1);
		Unit * target = Lunar<Unit>::check(L,2);
		if( !ptr || !sp || sp == 0) return 0;
		Spell * spp = new Spell(ptr,dbcSpell.LookupEntry(sp),false,NULL);; 
		//SpellCastTargets tar(ptr->GetGUID());
		SpellCastTargets tar(target->GetGUID());
		spp->prepare(&tar);
		return 0;
	}
	int GetGUID(lua_State * L, GameObject* ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);

		lua_pushinteger(L,(lua_Integer)ptr->GetGUID());
		return 1;
	}

	int GetRawGUID(lua_State * L, GameObject* ptr)
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

	int PerformWorldDBQuery(lua_State * L, GameObject* ptr)
	{
		Log.Notice("LuaEngine", "GO:PerformWorldDBQuery(...) is outdated! Please use the global function WorldDBQuery(...) instead! (This warning will be removed in some revisions then your Scripts will abort if you do not change that!)");
		return 0;
	}

	int PerformCharDBQuery(lua_State * L, GameObject* ptr)
	{
		Log.Notice("LuaEngine", "GO:PerformCharDBQuery(...) is outdated! Please use the global function CharDBQuery(...) instead! (This warning will be removed in some revisions then your Scripts will abort if you do not change that!)");
		return 0;
	}

	int IsActive(lua_State * L, GameObject* ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		if (ptr->IsActive()) {
			lua_pushboolean(L, 1);
		} else lua_pushboolean(L, 0);
		return 1;
	}
	int Activate(lua_State * L, GameObject* ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		if(ptr->GetUInt32Value(GAMEOBJECT_DYNAMIC) == 1)
		{
			// Deactivate
			ptr->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0);
		} else {
			// /Activate
			ptr->SetUInt32Value(GAMEOBJECT_DYNAMIC, 1);
		}
		return 1;
	}
	
	int DespawnObject(lua_State * L, GameObject* ptr)
	{
		CHECK_TYPEID(TYPEID_GAMEOBJECT);
		int delay = luaL_IsInt(L,1);
		int respawntime = luaL_IsInt(L,2);
		if (!ptr) return 0;
		if (!delay) delay=1; //Delay 0 might cause bugs
		if (!respawntime) respawntime=0;
		((GameObject*)ptr)->Despawn(delay,respawntime);
		return 0;
	}

	int AddLoot(lua_State * L, GameObject* ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		uint32 itemid = luaL_checkint(L,1);
		uint32 mincount = luaL_checkint(L,2);
		uint32 maxcount = luaL_checkint(L,3);
		uint32 ffa_loot = luaL_checkint(L,4);
		lootmgr.AddLoot(&ptr->loot,itemid,mincount,maxcount,ffa_loot);
		return 1;
	}
}
