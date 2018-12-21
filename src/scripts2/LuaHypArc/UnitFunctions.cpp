/*************************************************************\
|                           LuaHypArc                         |
|                      ==================                     |
|                   An extension of LUAppArc                  |
|                                                             |
|                     luahyparc.zapto.org                     |
\*************************************************************/
#include "StdAfx.h"
#include "LUAEngine.h"
#include "UnitFunctions.h"


#define MAX_TAXIPATH_NODES 100

namespace luaUnit
{
	WorldPacket Bufferdata[16];
	int GetDisplay(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_DISPLAYID ) );

		return 1;
	}

	int GetNativeDisplay(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_NATIVEDISPLAYID ) );

		return 1;
	}

	int GossipCreateMenu(lua_State * L, Unit * ptr)
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

	int GossipMenuAddItem(lua_State * L, Unit * ptr)
	{
		int icon = luaL_checkint(L, 1);
   		const char * menu_text = luaL_checkstring(L, 2);
		int IntId = luaL_checkint(L, 3);
		int extra = luaL_checkint(L, 4);
	    
		Menu->AddItem(icon, menu_text, IntId, extra);
		return 1;
	}

	int GossipSendMenu(lua_State * L, Unit * ptr)
	{
		Unit* target = Lunar<Unit>::check(L, 1);
		Player* plr = (Player*)target;
		Menu->SendTo(plr);
		return 1;
	}

	int GossipSendPOI(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		float x = (float)luaL_checknumber(L, 1);
		float y = (float)luaL_checknumber(L, 2);
		int icon = luaL_checkint(L, 3);
		int flags = luaL_checkint(L, 4);
		int data = luaL_checkint(L, 5);
		const char * name = luaL_checkstring(L, 6);

		plr->Gossip_SendPOI(x, y, icon, flags, data, name);
		return 1;
	}

	int GossipComplete(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
 		plr->Gossip_Complete();
 		return 1;
	 }

	int IsPlayer(lua_State * L, Unit * ptr)
	{
		if(!ptr)
		{
			lua_pushboolean(L, 0);
			return 1;
		}

		if(ptr->IsPlayer())
			lua_pushboolean(L, 1);
		else
			lua_pushboolean(L, 0);

		return 1;
	}

	int IsCreature(lua_State * L, Unit * ptr)
	{
		if(!ptr)
		{
			lua_pushboolean(L, 0);
			return 1;
		}

		if(ptr->GetTypeId()==TYPEID_UNIT)
			lua_pushboolean(L, 1);
		else
			lua_pushboolean(L, 0);

		return 1;
	}

	int Emote(lua_State * L, Unit * ptr)
	{
		if(ptr==NULL) return 0;
		uint32 emote_id = luaL_checkint(L, 1);
		uint32 time = luaL_IsInt(L, 2);
		if(emote_id==0) 
			return 0;
		if (time!=0) {
			time = luaL_checkint(L, 2);
			if (time > 0)
				ptr->EventAddEmote((EmoteType)emote_id,time);
			else
				ptr->Emote((EmoteType)emote_id);
		} else ptr->Emote((EmoteType)emote_id);
		return 1;
	}

	int GetManaPct(lua_State * L, Unit * ptr)
	{
		if(!ptr) 
			return 0;
		if (ptr->GetPowerType() == POWER_TYPE_MANA)
			lua_pushnumber(L, (int)(ptr->GetUInt32Value(UNIT_FIELD_POWER1) * 100.0f / ptr->GetUInt32Value(UNIT_FIELD_MAXPOWER1)));
		else
			lua_pushnil(L);
		return 1;
	}

	int GetName(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;

		switch(ptr->GetTypeId())
		{
		case TYPEID_UNIT:
			lua_pushstring(L, ((Creature*)ptr)->GetCreatureInfo() ? ((Creature*)ptr)->GetCreatureInfo()->Name : "Unknown");
			break;

		case TYPEID_PLAYER:
			lua_pushstring(L, ((Player*)ptr)->GetName());
			break;

		default:
			lua_pushstring(L, "Unknown");
			break;
		}

		return 1;
	}

	int PhaseSet(lua_State * L, Unit * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_optint(L,2,false)>0 ? true:false); 
		Creature * crt = 0;
		Player * p_target = 0;
		//Save is only for creatures. if you want to save to DB with players, use your own query (security purposes).
		//Lua: CharDBQuery("UPDATE `characters` SET `phase`='"..phase.."' WHERE (`name`='"..player:GetName().."'",0)
		if (!ptr)
			return 0;

		switch (ptr->GetTypeId())
		{
		case TYPEID_UNIT:
			crt = (Creature*)ptr;
			crt->Phase(PHASE_SET, newphase);
			if (crt->m_spawn) 
				crt->m_spawn->phase = newphase; 
			if (Save)
			{
				crt->SaveToDB();
				crt->m_loadedFromDB = true;
			}
			break;

		case TYPEID_PLAYER:
			p_target = (Player*)ptr;
			p_target->Phase(PHASE_SET, newphase);
			if( p_target->GetSession() )
			{
				WorldPacket data(SMSG_SET_PHASE_SHIFT, 4);
				data << newphase;
				p_target->GetSession()->SendPacket(&data);
			}
			break;

		default:
			break;
		}
		return 1;
	}

	int PhaseAdd(lua_State * L, Unit * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_optint(L,2,false)>0 ? true:false);
		Creature * crt = 0;
		Player * p_target = 0;
		//Save is only for creatures. if you want to save to DB with players, use your own query (security purposes).
		//Lua: CharDBQuery("UPDATE `characters` SET `phase`='"..player:GetPhase().."' WHERE (`name`='"..player:GetName().."'",0)
		if (!ptr)
			return 0;

		switch (ptr->GetTypeId())
		{
		case TYPEID_UNIT:
			crt = (Creature*)ptr;
			crt->Phase(PHASE_ADD, newphase);
			if (crt->m_spawn) 
				crt->m_spawn->phase |= newphase; 
			if (Save)
			{
				crt->SaveToDB();
				crt->m_loadedFromDB = true;
			}
			break;

		case TYPEID_PLAYER:
			p_target = (Player*)ptr;
			p_target->Phase(PHASE_ADD, newphase);
			if( p_target->GetSession() )
			{
				WorldPacket data(SMSG_SET_PHASE_SHIFT, 4);
				data << p_target->m_phase;
				p_target->GetSession()->SendPacket(&data);
			}
			break;

		default:
			break;
		}
		return 1;
	}

	int PhaseDelete(lua_State * L, Unit * ptr)
	{
		uint32 newphase = (uint32)luaL_checknumber(L,1);
		bool Save = (luaL_checkint(L,2)>0 ? true:false);
		Creature * crt = 0;
		Player * p_target = 0;
		//Save is only for creatures. if you want to save to DB with players, use your own query (security purposes).
		//Lua: CharDBQuery("UPDATE `characters` SET `phase`='"..player:GetPhase().."' WHERE (`name`='"..player:GetName().."'",0)
		if (!ptr)
			return 0;

		switch (ptr->GetTypeId())
		{
		case TYPEID_UNIT:
			crt = (Creature*)ptr;
			crt->Phase(PHASE_DEL, newphase);
			if (crt->m_spawn) 
				crt->m_spawn->phase &= ~newphase; 
			if (Save)
			{
				crt->SaveToDB();
				crt->m_loadedFromDB = true;
			}
			break;

		case TYPEID_PLAYER:
			p_target = (Player*)ptr;
			p_target->Phase(PHASE_DEL, newphase);
			if( p_target->GetSession() )
			{
				WorldPacket data(SMSG_SET_PHASE_SHIFT, 4);
				data << p_target->m_phase;
				p_target->GetSession()->SendPacket(&data);
			}
			break;

		default:
			break;
		}
		return 1;
	}

	int GetPhase(lua_State * L, Unit * ptr)
	{
		if (!ptr) return 0;
		lua_pushnumber(L,ptr->m_phase);
		return 1;
	}

	int SendChatMessage(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 typ = luaL_checkint(L, 1);
		uint32 lang = luaL_checkint(L, 2);
		const char * message = luaL_checklstring(L, 3, NULL);
		if(message == NULL)
			return 0;

		ptr->SendChatMessage(typ, lang, message);
		return 0;
	}

	int PlayerSendChatMessage(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 type = luaL_checkint(L, 1);
		uint32 lang = luaL_checkint(L, 2);
		const char * msg = luaL_checklstring(L, 3, NULL);
		Player * plr = (Player*)ptr;
		if(msg == NULL || !plr)
			return 0;
		WorldPacket *data = sChatHandler.FillMessageData( type, lang, msg, plr->GetGUID(), 0 );
		plr->GetSession()->SendChatPacket(data, 1, lang, plr->GetSession());
		for(set<Player*>::iterator itr = plr->GetInRangePlayerSetBegin(); itr != plr->GetInRangePlayerSetEnd(); ++itr)
		{
			(*itr)->GetSession()->SendChatPacket(data, 1, lang, plr->GetSession());
		}
		return 0;
	}

	int AggroWithInRangeFriends(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		// If Pointer isn't in combat skip everything
		if (!ptr->CombatStatus.IsInCombat())
		  return 0;

		Unit * pTarget = ptr->GetAIInterface()->GetNextTarget();
		if (!pTarget)
		  return 0;

		Unit * pUnit = NULL;
		for(set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
		{
		 Object * obj = TO_OBJECT(*itr);
		// No Object, Object Isn't a Unit, Unit is Dead
		if (!obj || !obj->IsUnit() || TO_UNIT(obj)->IsDead())
		   continue;

		 if (!isFriendly(obj, ptr))
		   continue;

		if (ptr->GetDistance2dSq(obj) > 10*10) // 10yrd range?
		   continue;

		 pUnit = TO_UNIT(obj);
		if (!pUnit) // Should never happen!
		   continue;

		pUnit->GetAIInterface()->SetNextTarget(pTarget);
		pUnit->GetAIInterface()->AttackReaction(pTarget, 1, 0);
		}
		return 1;
	}

	int MoveTo(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		double x = luaL_checknumber(L, 1);
		double y = luaL_checknumber(L, 2);
		double z = luaL_checknumber(L, 3);
		double o = luaL_checknumber(L, 4);

		if(x == 0 || y == 0 || z == 0)
			return 0;

		ptr->GetAIInterface()->MoveTo( (float)x, (float)y, (float)z, (float)o );
		return 0;
	}

	int MoveRandomArea(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		float x1 = (float)luaL_checknumber(L, 1);
		float y1 = (float)luaL_checknumber(L, 2);
		float z1 = (float)luaL_checknumber(L, 3);
		float x2 = (float)luaL_checknumber(L, 4);
		float y2 = (float)luaL_checknumber(L, 5);
		float z2 = (float)luaL_checknumber(L, 6);
		float o2 = (float)luaL_checknumber(L, 7);

		ptr->GetAIInterface()->MoveTo( x1+(RandomFloat(x2-x1)), y1+(RandomFloat(y2-y1)), z1+(RandomFloat(z2-z1)), o2 );
		return 0;
	}

	int SetMovementType(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 typ = luaL_checkint(L, 1);
		ptr->GetAIInterface()->setMoveType(typ);
		return 0;
	}

	int GetX(lua_State * L, Unit * ptr)
	{
		if(ptr==NULL) return 0;
		lua_pushnumber(L, ptr->GetPositionX());
		return 1;
	}

	int GetY(lua_State * L, Unit * ptr)
	{
		if(ptr==NULL) return 0;
		lua_pushnumber(L, ptr->GetPositionY());
		return 1;
	}

	int GetZ(lua_State * L, Unit * ptr)
	{
		if(ptr==NULL) return 0;
		lua_pushnumber(L, ptr->GetPositionZ());
		return 1;
	}

	int GetO(lua_State * L, Unit * ptr)
	{
		if(ptr==NULL) return 0;
		lua_pushnumber(L, ptr->GetOrientation());
		return 1;
	}

	int CastSpell(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 sp = luaL_checkint(L, 1);
		if(sp==0)
			return 0;
		ptr->CastSpell(ptr,dbcSpell.LookupEntry(sp),true);
		return 0;
	}

	int FullCastSpell(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 sp = luaL_checkint(L, 1);
		if(sp==0)
			return 0;
		ptr->CastSpell(ptr,dbcSpell.LookupEntry(sp),false);
		return 0;
	}
		int CastSpellOnTarget(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
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

	int FullCastSpellOnTarget(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 sp = luaL_checkint(L, 1);
		Unit * target = Lunar<Unit>::check(L, 2);

		if(sp==0 || target==NULL)
			return 0;
		ptr->CastSpell(target,dbcSpell.LookupEntry(sp),false);
		return 0;
	}
	int SpawnCreature(lua_State * L, Unit * ptr)
	{
	if(ptr == NULL) return 0;
	uint32 entry_id = luaL_checkint(L, 1);
	float x = (float)luaL_checkint(L, 2);
	float y = (float)luaL_checkint(L, 3);
	float z = (float)luaL_checkint(L, 4);
	float o = (float)luaL_checkint(L, 5);
	uint32 faction = luaL_checkint(L, 6);
	uint32 duration = luaL_checkint(L, 7);
	uint32 equip1 = luaL_optint(L, 8, 1);
	uint32 equip2 = luaL_optint(L, 9, 1);
	uint32 equip3 = luaL_optint(L, 10, 1);
	uint32 phase = luaL_optint(L, 11, ptr->m_phase); 

	if( !x || !y || !z || !entry_id || !faction )
	{
		lua_pushnil(L);
		return 1;
	}
	CreatureProto *p = CreatureProtoStorage.LookupEntry(entry_id);
    
    if(p == NULL)
      return 0;
	Creature * pCreature = ptr->GetMapMgr()->GetInterface()->SpawnCreature(entry_id,x,y,z,o,true,true,0,0,phase);
	pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,faction);
	pCreature->_setFaction();
	pCreature->SetInstanceID(ptr->GetInstanceID());
	pCreature->SetMapId(ptr->GetMapId());
	pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, equip1);
	pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, equip2);
	pCreature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+2, equip3);
	if(duration)
		pCreature->Despawn(duration,0);
	Lunar<Unit>::push(L,pCreature);
		return 1;
	}
	int SpawnGameObject(lua_State * L, Unit * ptr)
	{
		if(ptr == NULL) return 0;
		uint32 entry_id = luaL_checkint(L, 1);
		float x = (float)luaL_checkint(L, 2);
		float y = (float)luaL_checkint(L, 3);
		float z = (float)luaL_checkint(L, 4);
		float o = (float)luaL_checkint(L, 5);
		uint32 duration = luaL_checkint(L, 6);
		float scale = (float)(luaL_optint(L, 7, 100)/100); 
		uint32 phase = luaL_optint(L, 8, ptr->m_phase);
		if(entry_id)
		{
			GameObject* pC = ptr->GetMapMgr()->GetInterface()->SpawnGameObject(entry_id,x,y,z,o,false,0,0,phase);
			pC->SetInstanceID(ptr->GetInstanceID());
			pC->SetMapId(ptr->GetMapId());
			pC->SetFloatValue(OBJECT_FIELD_SCALE_X, scale);  
			pC->Spawn(ptr->GetMapMgr());
			if(duration && duration > 0)
				sEventMgr.AddEvent(pC,&GameObject::ExpireAndDelete,EVENT_GAMEOBJECT_UPDATE,duration,1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			Lunar<GameObject>::push(L,pC,false);
		}
		return 1;


	}

	int RegisterEvent(lua_State * L, Unit * ptr)
	{
		//Log.Notice("RegisterEvent","%s - Executing - %s",((Creature*)ptr)->GetCreatureInfo()->Name, luaL_checkstring(L,1));
		if(!ptr||ptr->GetTypeId()!=TYPEID_UNIT)
		{
			//Log.Notice("RegisterEvent","%s - !ptr||ptr->GetTypeId()!=TYPEID_UNIT - %s",((Creature*)ptr)->GetCreatureInfo()->Name,luaL_checkstring(L,1));
			return 0;
		}

		const char * func_to_call = luaL_checkstring(L,1);
		int delay=luaL_checkint(L,2);
		int repeats=luaL_checkint(L,3);

		if(!func_to_call||!delay)
		{
			//Log.Notice("RegisterEvent","%s - !func_to_call||!delay - %s",((Creature*)ptr)->GetCreatureInfo()->Name, luaL_checkstring(L,1));
			return 0;
		}

		Creature * pCreature = ((Creature*)ptr);
		string strFunc = string(func_to_call);
		sEventMgr.AddEvent(pCreature, &Creature::TriggerScriptEvent, strFunc, EVENT_CREATURE_UPDATE, (uint32)delay, (uint32)repeats, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		//Log.Notice("RegisterEvent","%s - Completed - %s",((Creature*)ptr)->GetCreatureInfo()->Name, luaL_checkstring(L,1));
		return 0;
	}

	int RemoveEvents(lua_State * L, Unit * ptr)
	{
		if(!ptr||ptr->GetTypeId()!=TYPEID_UNIT)
			return 0;

		Creature * pCreature = ((Creature*)ptr);
		sEventMgr.RemoveEvents(pCreature);
		return 0;
	}

	int AddEventHolder(lua_State * L, Unit * ptr)
	{
		EventableObjectHolder * holder = Lunar<EventableObjectHolder>::check(L,1);

		if(ptr&&holder)
		{
			sEventMgr.AddEventHolder(holder,ptr->GetInstanceID());
		}
		return 1;
	}

	int SetFaction(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int faction = luaL_checkint(L,1);
		if(!faction)
			return 0;

		ptr->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,faction);
		ptr->_setFaction();
		return 0;
	}
	int SetStandState(lua_State * L, Unit * ptr) //states 0..8
	{
		if (!ptr)
			return 0;
		int state = luaL_checkint(L,1);
		if(state<=0)
			return 0;
		ptr->SetStandState(state);
		return 0;
	}
	int IsInCombat(lua_State * L, Unit * ptr)
	{
		if (!ptr)
			return 0;
		if(ptr->CombatStatus.IsInCombat())
			lua_pushboolean(L, 1);
		else
			lua_pushboolean(L, 0);
		return 1;
	}

	int SetScale(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		double scale = luaL_checknumber(L,1);
		if(scale==0.0)
			return 0;

		ptr->SetFloatValue(OBJECT_FIELD_SCALE_X,(float)scale);
		return 0;
	}

	int SetModel(lua_State * L, Unit * ptr)
	{
		if(!ptr)//||!ptr->IsUnit())
			return 0;

		int modelid = luaL_checkint(L,1);
		ptr->SetUInt32Value(UNIT_FIELD_DISPLAYID,modelid);
		return 0;
	}

	int SetNPCFlags(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int flags = luaL_checkint(L,1);
		if(!flags)
			return 0;

		ptr->SetUInt32Value(UNIT_NPC_FLAGS,flags);
		return 0;
	}

	int SetCombatCapable(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L,1);
		ptr->GetAIInterface()->disable_combat = (enabled > 0) ? true : false;
		return 0;
	}

	int SetCombatMeleeCapable(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L,1);
		ptr->GetAIInterface()->disable_melee = (enabled > 0) ? true : false;
		return 0;
	}

	int SetCombatRangedCapable(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L,1);
		ptr->GetAIInterface()->disable_ranged = (enabled > 0) ? true : false;
		return 0;
	}

	int SetCombatSpellCapable(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L,1);
		ptr->GetAIInterface()->disable_spell = (enabled > 0) ? true : false;
		return 0;
	}

	int SetCombatTargetingCapable(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L,1);
		ptr->GetAIInterface()->disable_targeting = (enabled > 0) ? true : false;
		return 0;
	}

	int SetMount(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		uint32 DsplId = luaL_checkint(L, 1);
		ptr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, DsplId);
		return 0;
	}

	int DestroyCustomWaypointMap(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		((Creature*)ptr)->DestroyCustomWaypointMap();
		return 0;
	}

	int CreateCustomWaypointMap(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Creature * pCreature = (Creature*)ptr;
		if(pCreature->m_custom_waypoint_map)
		{
			for(WayPointMap::iterator itr = pCreature->m_custom_waypoint_map->begin(); itr != pCreature->m_custom_waypoint_map->end(); ++itr)
				delete (*itr);
			delete pCreature->m_custom_waypoint_map;
		}

		pCreature->m_custom_waypoint_map = new WayPointMap;
		pCreature->GetAIInterface()->SetWaypointMap(pCreature->m_custom_waypoint_map);
		return 0;
	}

	int CreateWaypoint(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		float o = (float)luaL_checknumber(L,4);
		int waittime = luaL_checkint(L,5);
		int flags = luaL_checkint(L,6);
		int modelid = luaL_checkint(L,7);

		Creature * pCreature = ((Creature*)ptr);
		if(!pCreature->m_custom_waypoint_map)
		{
			pCreature->m_custom_waypoint_map = new WayPointMap;
			pCreature->GetAIInterface()->SetWaypointMap(pCreature->m_custom_waypoint_map);
		}

		if(!modelid)
			modelid = pCreature->GetUInt32Value(UNIT_FIELD_DISPLAYID);

		WayPoint * wp = new WayPoint;
		wp->id = (uint32)pCreature->m_custom_waypoint_map->size() + 1;
		wp->x = x;
		wp->y = y;
		wp->z = z;
		wp->o = o;
		wp->flags = flags;
		wp->backwardskinid = modelid;
		wp->forwardskinid = modelid;
		wp->backwardemoteid = wp->forwardemoteid = 0;
		wp->backwardemoteoneshot = wp->forwardemoteoneshot = false;
		wp->waittime = waittime;
		pCreature->m_custom_waypoint_map->push_back(wp);
		pCreature->GetAIInterface()->addWayPoint(wp);
		return 0;
	}

	int MoveToWaypoint(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int id = luaL_checkint(L,1);
		if(id)
			ptr->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
			ptr->GetAIInterface()->setWaypointToMove(id);
		return 0;
	}

	int RemoveItem(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int id = luaL_checkint(L,1);
		int count = luaL_checkint(L,2);

		((Player*)ptr)->GetItemInterface()->RemoveItemAmt(id,count);
		return 0;
	}

	int AddItem(lua_State * L, Unit * ptr)
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
	int GetInstanceID(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		if( ptr->GetMapMgr()->GetMapInfo()->type == INSTANCE_NULL )
			lua_pushnil(L);
		else
			lua_pushinteger(L,ptr->GetInstanceID());
		return 1;
	}

	int GetClosestPlayer(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;

		float dist=0;
		float d2=0;
		Player * ret=NULL;

		for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
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
	int GetRandomPlayer(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			return 0;

		int flag = luaL_checkint( L, 1 );

		Player* ret = NULL;

		switch( flag )
		{
		case RANDOM_ANY:
			{
				uint32 count = (uint32)ptr->GetInRangePlayersCount();
				uint32 r = RandomUInt(count-1);
				count=0;

				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					if (count==r)
					{
						ret=*itr;
						break;
					}
					++count;
				}
			}
			break;
		case RANDOM_IN_SHORTRANGE:

			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj && obj->CalcDistance(obj,ptr)<=8)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj->CalcDistance(obj,ptr)<=8 && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_IN_MIDRANGE:
			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (!obj)
						continue;
					float distance = obj->CalcDistance(obj,ptr);
					if (distance<20 && distance>8)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (!obj)
							continue;
						float distance = obj->CalcDistance(obj,ptr);
						if (distance<20 && distance>8 && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_IN_LONGRANGE:
			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj && obj->CalcDistance(obj,ptr)>=20)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj->CalcDistance(obj,ptr)>=20 && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_WITH_MANA:
			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj && obj->GetPowerType() == POWER_TYPE_MANA)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj->GetPowerType() == POWER_TYPE_MANA && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_WITH_ENERGY:
			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj && obj->GetPowerType() == POWER_TYPE_ENERGY)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj->GetPowerType() == POWER_TYPE_ENERGY && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_WITH_RAGE:
			{
				uint32 count = 0;
				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj && obj->GetPowerType() == POWER_TYPE_RAGE)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj->GetPowerType() == POWER_TYPE_RAGE && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		case RANDOM_NOT_MAINTANK:
			{
				uint32 count = 0;
				Unit* mt = ptr->GetAIInterface()->GetMostHated();
				if (!mt->IsPlayer())
					return 0;

				for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
				{
					Player* obj = (Player*)(*itr);
					if (obj != mt)
						++count;
				}
				if (count)
				{
					uint32 r = RandomUInt(count-1);
					count=0;
					for(set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); ++itr)
					{
						Player* obj = (Player*)(*itr);
						if (obj && obj != mt && count==r)
						{
							ret=obj;
							break;
						}
						++count;
					}
				}
			}
			break;
		}

		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,((Unit*)ret),false);

		return 1;
	}
	int GetRandomFriend(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;

		Unit * ret=NULL;
		uint32 count = 0;

		for(set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
		{
			Object* obj = (Object*)(*itr);
			if (obj->IsUnit() && isFriendly(obj,ptr))
				++count;
		}

		if (count)
		{
			uint32 r = RandomUInt(count-1);
			count=0;
			for(set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
			{
				Object* obj = (Object*)(*itr);
				if (obj->IsUnit() && isFriendly(obj,ptr) && count==r)
				{
					ret=(Unit*)obj;
					break;
				}
				++count;
			}
		}
		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,(ret),false);
		return 1;
	}
	int GetRandomEnemy(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;

		Unit * ret=NULL;
		uint32 count = 0;

		for(set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
		{
			Object* obj = (Object*)(*itr);
			if (obj->IsUnit() && !isFriendly(obj,ptr))
				++count;
		}

		if (count)
		{
			uint32 r = RandomUInt(count-1);
			count=0;
			for(set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
			{
				Object* obj = (Object*)(*itr);
				if (obj->IsUnit() && !isFriendly(obj,ptr) && count==r)
				{
					ret=(Unit*)obj;
					break;
				}
				++count;
			}
		}
		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,(ret),false);
		return 1;
	}

	int StopMovement(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int tim = luaL_checkint(L,1);
		ptr->GetAIInterface()->StopMovement(tim);
		return 0;
	}

	int RemoveAura(lua_State * L, Unit * ptr)
	{
		if(!ptr)return 0;
		int auraid = luaL_checkint(L,1);
		ptr->RemoveAura(auraid);
		return 0;
	}

	int PlaySoundToSet(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		int soundid = luaL_checkint(L,1);
		ptr->PlaySoundToSet(soundid);
		return 0;
	}

	int PlaySoundToPlayer(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		int soundid = luaL_checkint(L,1);

		Player* plr = (Player*)ptr;
		if (!plr) return 0;
		WorldPacket data;
        data.Initialize(SMSG_PLAY_OBJECT_SOUND);
		data << uint32(soundid) << plr->GetGUID();
		plr->GetSession()->SendPacket(&data);
		return 0;
	}

	int GetUnitBySqlId(lua_State * L, Unit * ptr)
	{
		int sqlid = luaL_checkint(L,1);
		if(!ptr || !sqlid)
			return 0;
		Lunar<Unit>::push(L,ptr->GetMapMgr()->GetSqlIdCreature(sqlid));
		return 1;
	}

	int GetInventoryItem(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int8 containerslot = luaL_checkint(L, 1);
		int16 slot = luaL_checkint(L, 2);
		Player * plr = (Player*)ptr;
		if (!plr) return 0;
		Lunar<Item>::push(L, plr->GetItemInterface()->GetInventoryItem(containerslot, slot));
		return 1;
	}

	int GetInventoryItemById(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 entry = luaL_checkint(L, 1);
		Player * plr = (Player*)ptr;
		int16 slot = plr->GetItemInterface()->GetInventorySlotById(entry);
		Lunar<Item>::push(L, plr->GetItemInterface()->GetInventoryItem(slot));
		return 1;
	}

	int SetZoneWeather(lua_State * L, Unit * ptr)
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

	int SetPlayerWeather(lua_State * L, Unit * ptr)
	{
		/*
		WEATHER_TYPE_NORMAL            = 0, // NORMAL (SUNNY)
		WEATHER_TYPE_FOG               = 1, // FOG
		WEATHER_TYPE_RAIN              = 2, // RAIN
		WEATHER_TYPE_HEAVY_RAIN        = 4, // HEAVY_RAIN
		WEATHER_TYPE_SNOW              = 8, // SNOW
		WEATHER_TYPE_SANDSTORM         = 16 // SANDSTORM
		*/
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		uint32 type = (uint32)luaL_checknumber(L, 1);
		float Density = (float)luaL_checknumber(L, 2); //min: 0.30 max: 2.00
		if (Density<0.30f || Density>2.0f || !type)
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

		plr->GetSession()->SendPacket(&data);

		return 0;
	}

	int Despawn(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int delay = luaL_checkint(L,1);
		int respawntime = luaL_checkint(L,2);
		((Creature*)ptr)->Despawn(delay,respawntime);
		return 0;
	}
	int GetInRangeFriends(lua_State * L, Unit * ptr)
	{
		Object * pC = NULL;
		uint32 count = 0;
		lua_newtable(L);
		for( set<Object*>::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); itr++)
		{
			if( (*itr) ->IsUnit() )
				count++,
				pC = *itr;
				lua_pushinteger(L,count);
				Lunar<Unit>::push(L,((Unit*)pC),false);
				lua_rawset(L,-3);
		}
		return 1;
	}

	int GetHealthPct(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			lua_pushinteger(L,0);
		else
			lua_pushinteger(L, ptr->GetHealthPct());

		return 1;

	}
	int SetHealthPct(lua_State * L, Unit * ptr)
	{
		int val = luaL_checkint(L,1);
		if (val>0)
			ptr->SetHealthPct(val);
		return 1;
	}
	int GetItemCount(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_PLAYER);
		int itemid = luaL_checkint(L,1);
		lua_pushinteger(L, ((Player*)ptr)->GetItemInterface()->GetItemCount(itemid,false));
		return 1;
	}

	int GetPrimaryCombatTarget(lua_State * L, Unit * ptr)
	{//should use now instead of GetTarget
		CHECK_TYPEID(TYPEID_PLAYER);
		if (!ptr->CombatStatus.IsInCombat())
			return 0;
		else
			Lunar<Unit>::push(L, ptr->GetMapMgr()->GetUnit(((Player*)ptr)->CombatStatus.GetPrimaryAttackTarget()));
		return 1;
	}

	int GetMainTank(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		Unit* ret = ptr->GetAIInterface()->GetMostHated();
		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,(ret),false);
		return 1;
	}
	int GetAddTank(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		Unit* ret = ptr->GetAIInterface()->GetSecondHated();
		if(ret==NULL)
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,(ret),false);
		return 1;
	}
	int ClearThreatList(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		ptr->ClearHateList();
		return 1;
	}

	int GetTauntedBy(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)

			if (!ptr->GetAIInterface()->getTauntedBy())
				lua_pushnil(L);
			else
				Lunar<Unit>::push(L,ptr->GetAIInterface()->getTauntedBy(),false);
		return 1;
	}
	int SetTauntedBy(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)
			Unit * target = Lunar<Unit>::check(L, 1);

		if (!target || ptr->GetAIInterface()->GetIsTaunted() || target==ptr)
			return 0;
		else
			ptr->GetAIInterface()->taunt(target);
		return 1;
	}
	int ModThreat(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L,1);
		int32 amount = luaL_checkint(L,2);
		if(ptr&&target&&amount)
			ptr->GetAIInterface()->modThreatByPtr(target,amount);
		return 0;
	}
	int GetThreatByPtr(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L,1);
		if(ptr&&target)
			lua_pushnumber(L,ptr->GetAIInterface()->getThreatByPtr(target));
		return 0;
	}

	int GetSoulLinkedWith(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)

			if (!ptr->GetAIInterface()->GetIsSoulLinked())
				lua_pushnil(L);
			else
				Lunar<Unit>::push(L,ptr->GetAIInterface()->getSoullinkedWith(),false);
		return 1;
	}
	int SetSoulLinkedWith(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)
			Unit * target = Lunar<Unit>::check(L, 1);

		if (!target || ptr->GetAIInterface()->GetIsSoulLinked() || target==ptr)
			return 0;
		else
			ptr->GetAIInterface()->SetSoulLinkedWith(ptr);
		return 1;
	}
	int ChangeTarget(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)
			Unit * target = Lunar<Unit>::check(L, 1);

		if (!target || !isHostile(ptr,target) || ptr==target)
			return 0;
		else
			ptr->GetAIInterface()->SetNextTarget(target);
		return 1;
	}

	int HasFinishedQuest(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		int questid = luaL_checkint(L,1);
		if(((Player*)ptr)->HasFinishedQuest(questid))
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);

		return 1;
	}

	int FinishQuest(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		int quest_id = luaL_checkint(L,1);
		Player *plr = (Player*)ptr;
		Quest * qst = QuestStorage.LookupEntry(quest_id);
		if(qst)
		{
			if (plr->HasFinishedQuest(quest_id)) {
				lua_pushnumber(L, 0);
				return 1;
			}
			else
			{
				QuestLogEntry * IsPlrOnQuest = plr->GetQuestLogForEntry(quest_id);
				if (IsPlrOnQuest)
				{	
					sQuestMgr.GenerateQuestXP(plr, qst);
					sQuestMgr.BuildQuestComplete(plr, qst);

					IsPlrOnQuest->Finish();
					lua_pushnumber(L, 1);
					return 1;
				}
				else
					lua_pushnumber(L, 2);
					return 1;
				
				plr->AddToFinishedQuests(quest_id);
			}
		}
		else
		{
			return 0;
		}
	}

	int StartQuest(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		int quest_id = luaL_checkint(L,1);
		Player *plr = (Player*)ptr;

		Quest * qst = QuestStorage.LookupEntry(quest_id);
		if(qst)
		{
			if (plr->HasFinishedQuest(quest_id)) {
				lua_pushnumber(L, 0);
				return 1;
			}
			else
			{
				QuestLogEntry * IsPlrOnQuest = plr->GetQuestLogForEntry(quest_id);
				if (IsPlrOnQuest) {
					lua_pushnumber(L, 1);
					return 1;
				}
				else
				{
					int32 open_slot = plr->GetOpenQuestSlot();

					if (open_slot == -1)
					{
						sQuestMgr.SendQuestLogFull(plr);
						lua_pushnumber(L, 2);
						return 1;
					}
					else
					{
						QuestLogEntry *qle = new QuestLogEntry();
						qle->Init(qst, plr, (uint32)open_slot);
						qle->UpdatePlayerFields();
			
						// If the quest should give any items on begin, give them the items.
						for(uint32 i = 0; i < 4; ++i)
						{
							if(qst->receive_items[i])
							{
								Item *item = objmgr.CreateItem( qst->receive_items[i], plr);
								if(item==NULL)
									return false;

								if(!plr->GetItemInterface()->AddItemToFreeSlot(item))
									item->DeleteMe();
							}
						}

						if(qst->srcitem && qst->srcitem != qst->receive_items[0])
						{
							Item * item = objmgr.CreateItem( qst->srcitem, plr);
							if(item)
							{
								item->SetUInt32Value(ITEM_FIELD_STACK_COUNT, qst->srcitemcount ? qst->srcitemcount : 1);
								if(!plr->GetItemInterface()->AddItemToFreeSlot(item))
									item->DeleteMe();
							}
						}
					

						//if(qst->count_required_item || qst_giver->GetTypeId() == TYPEID_GAMEOBJECT)	// gameobject quests deactivate
						//	plr->UpdateNearbyGameObjects();
						//ScriptSystem->OnQuestEvent(qst, static_cast< Creature* >( qst_giver ), _player, QUEST_EVENT_ON_ACCEPT);
					
						sHookInterface.OnQuestAccept( plr, qst, NULL );

						lua_pushnumber(L, 3);
						return 1;
					}
				}
			}
		}
		else
		{
					return 0;
		}
		
		lua_pushnumber(L, 999);
		return 1;
	} //StartQuest

	int UnlearnSpell(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int spellid = luaL_checkint(L,1);
		((Player*)ptr)->removeSpell(spellid,false,false,0);
		return 0;
	}

	int LearnSpell(lua_State * L, Unit* ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int spellid = luaL_checkint(L,1);
		((Player*)ptr)->addSpell(spellid);
		return 0;
	}

	int MarkQuestObjectiveAsComplete(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int questid = luaL_checkint(L,1);
		int objective = luaL_checkint(L,2);
		Player * pl = ((Player*)ptr);
		if (!pl->HasFinishedQuest(questid)) 
		{
			QuestLogEntry * qle = pl->GetQuestLogForEntry(questid);
			qle->SetMobCount(objective, qle->GetQuest()->required_mobcount[objective]);
			qle->SendUpdateAddKill(objective);
				if(qle->CanBeFinished())
				{
					qle->SendQuestComplete();
					qle->UpdatePlayerFields();
				}
		}

		return 0;
	}


	int KnockBack(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		double dx = luaL_checknumber(L,1);
		double dy = luaL_checknumber(L,2);
		double affect1 = luaL_checknumber(L,3);
		double affect2 = luaL_checknumber(L,4);
		WorldPacket data(SMSG_MOVE_KNOCK_BACK, 30);
		data << ptr->GetNewGUID();
		data << getMSTime();
		data << dx << dy << affect1 << affect2;
		ptr->SendMessageToSet(&data, true);

		return 0;
	}

	int SendAreaTriggerMessage(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		const char * msg = luaL_checkstring(L,1);
		if(!msg) return 0;
		((Player*)ptr)->SendAreaTriggerMessage(msg);
		return 0;
	}

	int SendBroadcastMessage(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		const char * msg = luaL_checkstring(L,1);
		if(!msg) return 0;
		((Player*)ptr)->BroadcastMessage(msg);
		return 0;
	}

	int TeleportUnit(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 mapId = luaL_checkint(L, 1);
		float posX = (float)luaL_checknumber(L, 2);
		float posY = (float)luaL_checknumber(L, 3);
		float posZ = (float)luaL_checknumber(L, 4);
		if(!posX || !posY || !posZ || !mapId) {
			if (mapId) {
				Log.Notice("LuaEngineMgr", "LUATeleporter ERROR - Wrong Coordinates given (Map, X, Y, Z) :: Map%f%s%f%s%f%s%u", mapId, " X", posX, " Y", posY, " Z", posZ);
				return 0;
			} else mapId = 0; //MapId is false reported as empty if you use Eastern Kingdoms (0) So lets override it IF it is reported as empty.
		}
		LocationVector vec(posX,posY,posZ);
		static_cast<Player*>( ptr ) ->SafeTeleport(mapId,0,vec);
		return 0;
	}

	int SendPOI(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		float posX = (float)luaL_checknumber(L, 1);
		float posY = (float)luaL_checknumber(L, 2);
		uint32 icon = (uint32)luaL_checknumber(L, 3);
		uint32 flags = (uint32)luaL_checknumber(L, 4);
		uint32 data = (uint32)luaL_checknumber(L, 5);
		const char *name = (const char*)luaL_checkstring(L, 6);
		if(!posX || !posY || !icon) {
			Log.Notice("LuaEngineMgr", "LUAPOI ERROR - Wrong Coordinates or Icon given (X, Y, Icon) :: %s%f%s%f%s%u", " X", posX, " Y", posY, " Z", icon);
			return 0;
		}
		static_cast<Player*>( ptr )->Gossip_SendPOI(posX,posY,icon,flags,data,name);
		return 0;
	}

	int GetHealth(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_HEALTH ) );

		return 1;
	}

	int GetMaxHealth(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_MAXHEALTH ) );

		return 1;
	}

	int SetHealth(lua_State * L, Unit * ptr)
	{
		int val = luaL_checkint( L, 1 );
		if( ptr != NULL && val > 0 )
			if( (uint32)val > ptr->GetUInt32Value( UNIT_FIELD_MAXHEALTH ) )
				ptr->SetUInt32Value( UNIT_FIELD_HEALTH, ptr->GetUInt32Value( UNIT_FIELD_MAXHEALTH ) );
			else
				ptr->SetUInt32Value( UNIT_FIELD_HEALTH, val );
		return 1;
	}

	int SetMaxHealth(lua_State * L, Unit * ptr)
	{
		int val = luaL_checkint( L, 1 );
		if( ptr != NULL && val > 0 )
			if( (uint32)val < ptr->GetUInt32Value( UNIT_FIELD_HEALTH ) )
				ptr->SetUInt32Value( UNIT_FIELD_HEALTH, val );
			ptr->SetUInt32Value( UNIT_FIELD_MAXHEALTH, val );
		return 1;
	}

	int WipeHateList(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		ptr->WipeHateList();
		return 1;
	}

	int WipeTargetList(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		ptr->GetAIInterface()->WipeTargetList();
		return 1;
	}

	int WipeCurrentTarget(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		ptr->GetAIInterface()->WipeCurrentTarget();
		return 1;
	}

	int GetPlayerClass(lua_State * L, Unit * ptr)
	{
	   if(!ptr || ptr->GetTypeId()!=TYPEID_PLAYER) {
		  lua_pushstring(L, "Unknown");
		  return 1;
	   }
	   int plrclass = ((Player*)ptr)->getClass();

	   switch(plrclass) {
		  case 1:
			 lua_pushstring(L, "Warrior");
			 break;
		  case 2:
			 lua_pushstring(L, "Paladin");
			 break;
		  case 3:
			 lua_pushstring(L, "Hunter");
			 break;
		  case 4:
			 lua_pushstring(L, "Rogue");
			 break;
		  case 5:
			 lua_pushstring(L, "Priest");
			 break;
		  case 6:
			 lua_pushstring(L, "Death Knight");
			 break;
		  case 7:
			 lua_pushstring(L, "Shaman");
			 break;
		  case 8:
			 lua_pushstring(L, "Mage");
			 break;
		  case 9:
			 lua_pushstring(L, "Warlock");
			 break;
		  //case 10:
		  case 11:
			 lua_pushstring(L, "Druid");
			 break;
		  default:
			 lua_pushstring(L, "Unknown");
			 break;
	   }

	   return 1;
	}


	int ClearHateList(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET_INT(TYPEID_UNIT);
		ptr->ClearHateList();
		return 1;
	}
	int SetMana(lua_State * L, Unit * ptr)
	{
		int val = luaL_checkint( L, 1);
		if( ptr != NULL)
			ptr->SetUInt32Value( UNIT_FIELD_POWER1, val );
		return 1;
	}
	int SetMaxMana(lua_State * L, Unit * ptr)
	{
		int val = luaL_checkint( L, 1);
		if( ptr != NULL && val > 0 )
			if( (uint32)val < ptr->GetUInt32Value( UNIT_FIELD_POWER1) )
				ptr->SetUInt32Value( UNIT_FIELD_POWER1, val);
			ptr->SetUInt32Value( UNIT_FIELD_MAXPOWER1, val );
		return 1;
	}
	int GetPlayerRace(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET( TYPEID_PLAYER );
		lua_pushinteger( L, static_cast< Player* >( ptr )->getRace() );
		return 1;
	}
	int SetFlying(lua_State * L, Unit * ptr)
	{
		WorldPacket data(SMSG_MOVE_SET_HOVER, 13);
		data << ptr->GetNewGUID();
		data << uint32(0);
		ptr->SendMessageToSet(&data, true);
		ptr->GetAIInterface()->disable_melee = true;
		ptr->GetAIInterface()->m_moveFly = true;
		ptr->Emote(EMOTE_ONESHOT_LIFTOFF);
		return 0;
	}
	 
	int Land(lua_State * L, Unit * ptr)
	{
		WorldPacket data(SMSG_MOVE_UNSET_HOVER, 13);
		data << ptr->GetNewGUID();
		data << uint32(0);
		ptr->SendMessageToSet(&data, true);
		ptr->GetAIInterface()->m_moveFly = false;
		ptr->GetAIInterface()->disable_melee = false;
		ptr->Emote(EMOTE_ONESHOT_LAND);
		return 0;
	}
	int HasAura(lua_State * L, Unit * ptr)
	{
		int spellid = luaL_checkint (L,1);
		if (!ptr || !spellid )
			return 0;
		else
			if(ptr->HasAura(spellid))
				lua_pushboolean(L,1);
			else
				lua_pushboolean(L,0);
		return 1;
	}
	int ReturnToSpawnPoint(lua_State * L, Unit * ptr)
	{
		float x = ptr->GetSpawnX();
		float y = ptr->GetSpawnY();
		float z = ptr->GetSpawnZ();
		float o = ptr->GetSpawnO();
		if(ptr)
			ptr->GetAIInterface()->MoveTo(x, y, z, o);
		return 0;
	}
	int GetGUID(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		lua_pushinteger(L,(lua_Integer)ptr->GetGUID()); return 1;
	}
	int GetRawGUID(lua_State * L, Unit * ptr)
	{	//since Lua can't handle huge uint64's, this makes it a string.
		//if you require a guid, you should get this string and turn it back into a uint64.
		//see SendLootWindow for info on how to achieve this.
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
	int GetDistance(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;
		Unit * target = Lunar<Unit>::check(L, 1);
		lua_pushnumber(L,(float)ptr->GetDistance2dSq(target) );
		return 1;
	}
	int GetDistanceYards(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(!ptr || !target)
			return 0;
		LocationVector vec = ptr->GetPosition();
		lua_pushnumber(L,(float)vec.Distance(target->GetPosition()));
		return 1;
	}
	int GetDuelState(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player* plr = (Player*)ptr;
		//sLog.outDebug("plr->GetDuelState(): %d",plr->GetDuelState());
		lua_pushnumber(L,plr->GetDuelState());
		/*Returns
		  DUEL_STATE_REQUESTED = 0
		  DUEL_STATE_STARTED = 1
		  DUEL_STATE_FINISHED = 2 (Default)
		*/
		return 1;
	}
	int GetCreatureNearestCoords(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		uint32 entryid = luaL_checkint(L,4);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		if(entryid==0) 
			lua_pushnil(L);
		else
			Lunar<Unit>::push(L,ptr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(x, y, z, entryid), false);
		return 1;
	    
	}
	int GetGameObjectNearestCoords(lua_State *L, Unit * ptr)
	{
		if(!ptr) return 0;
		uint32 entryid = luaL_checkint(L,4);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		if(entryid==0) 
			lua_pushnil(L);
		else
			Lunar<GameObject>::push(L,ptr->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(x, y, z, entryid), false);
		return 1;
	}
	int SetPosition(lua_State * L, Unit * ptr)
	{//experimental
		CHECK_TYPEID(TYPEID_UNIT);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		float o = (float)luaL_checknumber(L,4);
		if(x == 0 || y == 0 || z == 0)
			return 0;
		ptr->SetPosition(x,y,z,o,true);
		ptr->PushToWorld( ptr->GetMapMgr() );
		return 0;
	}
	int GetLandHeight(lua_State * L, Unit * ptr)
	{
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		if (!ptr || !x || !y) 
			return 0;
		float lH = ptr->GetMapMgr()->GetLandHeight(x,y);
		lua_pushnumber(L, lH);
		return 0;
	}
	int QuestAddStarter(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Creature * unit = (Creature*)ptr;
		uint32 quest_id = (uint32)luaL_checknumber(L, 1);
		if (!unit->HasFlag(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_QUESTGIVER))
			unit->SetUInt32Value(UNIT_NPC_FLAGS, unit->GetUInt32Value(UNIT_NPC_FLAGS)+UNIT_NPC_FLAG_QUESTGIVER);
		if(quest_id==0)
		{
			return 0;
		}
		Quest * qst = QuestStorage.LookupEntry(quest_id);

		if (qst == NULL)
		{
			return 0;
		}

		uint32 quest_giver = unit->GetEntry();
		
		char my_query1 [200];
		sprintf(my_query1,"SELECT id FROM creature_quest_starter WHERE id = %d AND quest = %d", quest_giver, quest_id);
		QueryResult *selectResult1 = WorldDatabase.Query(my_query1);
		if (selectResult1)
		{
			delete selectResult1; //already has quest
		}
		else
		{
			char my_insert1 [200];
			sprintf(my_insert1, "INSERT INTO creature_quest_starter (id, quest) VALUES (%d,%d)", quest_giver, quest_id);
			WorldDatabase.Execute(my_insert1);
		}
		sQuestMgr.LoadExtraQuestStuff();

		QuestRelation *qstrel = new QuestRelation;
		qstrel->qst = qst;
		qstrel->type = QUESTGIVER_QUEST_START;

		uint8 qstrelid;
		if ( unit->HasQuests() )
		{
			qstrelid = (uint8)unit->GetQuestRelation(quest_id);
			unit->DeleteQuest(qstrel);
		}
		unit->_LoadQuests();
		return 1;
	}
	int QuestAddFinisher(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Creature * unit = (Creature*)ptr;
		uint32 quest_id = (uint32)luaL_checknumber(L, 1);
		if (!unit->HasFlag(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_QUESTGIVER))
			unit->SetUInt32Value(UNIT_NPC_FLAGS, unit->GetUInt32Value(UNIT_NPC_FLAGS)+UNIT_NPC_FLAG_QUESTGIVER);
		if(quest_id==0)
		{
			return 0;
		}
		Quest * qst = QuestStorage.LookupEntry(quest_id);

		if (qst == NULL)
		{
			return 0;
		}

		uint32 quest_giver = unit->GetEntry();
		
		char my_query1 [200];
		sprintf(my_query1,"SELECT id FROM creature_quest_finisher WHERE id = %d AND quest = %d", quest_giver, quest_id);
		QueryResult *selectResult1 = WorldDatabase.Query(my_query1);
		if (selectResult1)
		{
			delete selectResult1; //already has quest
		}
		else
		{
			char my_insert1 [200];
			sprintf(my_insert1, "INSERT INTO creature_quest_finisher (id, quest) VALUES (%d,%d)", quest_giver, quest_id);
			WorldDatabase.Execute(my_insert1);
		}
		sQuestMgr.LoadExtraQuestStuff();

		QuestRelation *qstrel = new QuestRelation;
		qstrel->qst = qst;
		qstrel->type = QUESTGIVER_QUEST_END;

		uint8 qstrelid;
		if ( unit->HasQuests() )
		{
			qstrelid = (uint8)unit->GetQuestRelation(quest_id);
			unit->DeleteQuest(qstrel);
		}
		unit->_LoadQuests();
		return 1;
	}
	int CastSpellAoF(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		uint32 sp = luaL_checkint(L, 4);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		if(!sp | !x | !y | !z)
			return 0;
		ptr->CastSpellAoF(x,y,z,dbcSpell.LookupEntry(sp), true);
		return 0;
	}
	int SetInFront(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(!target)
			return 0;
		ptr->GetAIInterface()->setInFront(target);
		return 1;
	}
	int RemoveAllAuras(lua_State *L, Unit * ptr)
	{
		if (!ptr)
			return 0;
		ptr->RemoveAllAuras();
		return 1;
	}
	int CancelSpell(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;
		ptr->CancelSpell(ptr->GetCurrentSpell());
		return 0;
	}
	int IsAlive(lua_State * L, Unit * ptr)
	{
		if(ptr)
			if(ptr->isAlive())
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int IsDead(lua_State * L, Unit * ptr)
	{
		if(ptr)
			if(ptr->isAlive())
				lua_pushboolean(L, 0);
			else
				lua_pushboolean(L, 1);
		return 1;
	}
	int IsInWorld(lua_State * L, Unit * ptr)
	{
		if (ptr)
			if(ptr->IsInWorld())
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int GetZoneId(lua_State *L, Unit * ptr)
	{
		if(!ptr)
			return 0;
		lua_pushinteger(L,(ptr->GetZoneId()));
		return 1;
	}
	int GetMana(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_POWER1 ) );

		return 1;
	}

	int GetMaxMana(lua_State * L, Unit * ptr)
	{
		if( ptr == NULL )
			lua_pushinteger( L, 0 );
		else
			lua_pushinteger( L, ptr->GetUInt32Value( UNIT_FIELD_MAXPOWER1 ) );

		return 1;
	}
	int Root(lua_State * L, Unit * ptr)
	{
		if(ptr)
			ptr->Root();
		return 0;
	}
	int Unroot(lua_State * L, Unit * ptr)
	{
		if(ptr)
			ptr->Unroot();
		return 0;
	}
	int IsCreatureMoving(lua_State * L, Unit * ptr)
	{
		if(ptr && ptr->GetTypeId() == TYPEID_UNIT)
			if(ptr->GetAIInterface()->m_creatureState == MOVING)
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int SetOutOfCombatRange(lua_State * L, Unit * ptr)
	{
		int range = luaL_checkint(L, 1);
		if((ptr != NULL || range != 0) && ptr->GetTypeId() == TYPEID_UNIT)
			ptr->GetAIInterface()->setOutOfCombatRange(range);
		return 0;
	}
	int ModifyRunSpeed(lua_State * L, Unit * ptr)
	{
		float Speed = (float)luaL_checkint(L, 1);
		if(ptr)
			ptr->m_runSpeed = Speed;
		return 0;
	}
	int ModifyWalkSpeed(lua_State * L, Unit * ptr)
	{
		float Speed = (float)luaL_checkint(L,1);
		if(ptr&&Speed)
			ptr->m_walkSpeed = Speed;
		return 0;
	}
	int ModifyFlySpeed(lua_State * L, Unit * ptr)
	{
		float Speed = (float)luaL_checkint(L,1);
		if(ptr&&Speed)
			ptr->m_flySpeed = Speed;
		return 0;
	}
	int IsFlying(lua_State * L, Unit * ptr)
	{
		if(ptr && ptr->GetTypeId() == TYPEID_UNIT)
			if(ptr->GetAIInterface()->IsFlying())
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int SetRotation(lua_State * L, Unit * ptr)
	{
		ptr->SetRotation(ptr->GetGUID());
		return 0;
	}

	int SetOrientation(lua_State * L, Unit * ptr)
	{
		float O = (float)luaL_checknumber(L, 1);
		if(ptr)
			ptr->SetOrientation(O);
		return 0;
	}
	int CalcDistance(lua_State * L, Unit * ptr)
	{
		Object * ob = Lunar<Object>::check(L,1);
		if(ob)
			lua_pushnumber(L,(float)ptr->CalcDistance(ob));
		return 1;
	}
	int GetSpawnX(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnX());
		return 1;
	}
	int GetSpawnY(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnY());
		return 1;
	}
	int GetSpawnZ(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnZ());
		return 1;
	}
	int GetSpawnO(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetSpawnO());
		return 1;
	}
	int GetGameTime(lua_State * L, Unit * ptr)
	{
		lua_pushnumber(L, ((uint32)sWorld.GetGameTime()));
		Log.Notice("LuaEngine","Please use the global function GetGameTime instead. This unit-based one is deprecated.");
		//deprecated, use global function GetGameTime.
		return 1;
	}
	int GetInRangePlayersCount(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetInRangePlayersCount());
		return 1;
	}
	int GetEntry(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetEntry());
		return 1;
	}
	int SetMoveRunFlag(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		int enabled = luaL_checkint(L, 1);
		ptr->GetAIInterface()->setMoveRunFlag((enabled > 0) ? true : false);
		return 0;
	}

	int HandleEvent(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Unit * target = Lunar<Unit>::check(L, 1);
		int event_id = luaL_checkint(L, 2);
		int misc_1 = luaL_checkint(L, 3);
		ptr->GetAIInterface()->HandleEvent(event_id, target, misc_1);
		return 1;
	}
	int GetCurrentSpellId(lua_State * L, Unit * ptr)
	{
		if(ptr->GetCurrentSpell())
			lua_pushnumber(L, ptr->GetCurrentSpell()->m_spellInfo->Id);
		else 
			lua_pushnil(L);
		return 1;
	}
	int GetCurrentSpell(lua_State * L, Unit * ptr)
	{
		if(ptr)
			if(ptr->GetCurrentSpell() != 0)
			{
				lua_pushlstring(L,ptr->GetCurrentSpell()->m_spellInfo->Name,strlen(ptr->GetCurrentSpell()->m_spellInfo->Name));
			}
		return 1;
	}
	int AddAssistTargets(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Unit * Friend = Lunar<Unit>::check(L,1);
		if(ptr && Friend)
		{
			if( isFriendly(ptr, Friend))
				ptr->GetAIInterface()->addAssistTargets(Friend);
		}
		return 0;
	}
	int GetAIState(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		lua_pushnumber(L, ptr->GetAIInterface()->getAIState());
		return 1;
	}

	int GetFloatValue(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		if( ptr != NULL ) 
			lua_pushnumber(L, ptr->GetFloatValue(field));
		return 1;
	}

	int InitPacket(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		int packet_id = luaL_checkint(L, 2);
		Bufferdata[buffer_index].Initialize(packet_id);
		return 1;
	}

	int AddDataToPacket(lua_State * L, Unit * ptr)
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

	int AddGuidDataToPacket(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		int type = luaL_checkint(L, 2);
		switch(type)
		{
			// not sure... maybee we should use ptr->GetMapMgr->GetGUID??
			case 0:
				Bufferdata[buffer_index] << ptr->GetGUID();
				break;
			case 1:
				Bufferdata[buffer_index] << ptr->GetTypeFromGUID();
				break;
			case 2:
				Bufferdata[buffer_index] << ptr->GetUIdFromGUID();
				break;
			case 3:
				Bufferdata[buffer_index] << ptr->GetNewGUID(); 
				break;
		}
		return 1;
	}

	int SendPacketToSet(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		if (!ptr) return 0;
		ptr->SendMessageToSet(&Bufferdata[buffer_index],true);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToPlayer(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		plr->GetSession()->SendPacket(&Bufferdata[buffer_index]);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToZone(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		uint32 zone_id = (uint32)luaL_checknumber(L, 2);
		sWorld.SendZoneMessage(&Bufferdata[buffer_index],zone_id);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToInstance(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		uint32 instance_id = (uint32)luaL_checknumber(L, 2);
		sWorld.SendInstanceMessage(&Bufferdata[buffer_index],instance_id);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int SendPacketToWorld(lua_State * L, Unit * ptr)
	{
		int buffer_index = luaL_checkint(L, 1);
		sWorld.SendGlobalMessage(&Bufferdata[buffer_index]);
		Bufferdata[buffer_index].clear();
		return 1;
	}

	int ModUInt32Value(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		int value = luaL_checkint(L, 2);
		if( ptr != NULL ) ptr->ModSignedInt32Value(field, value);
		return 1;
	}

	int ModFloatValue(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		float value = (float)luaL_checknumber(L, 2);
		if( ptr != NULL ) ptr->ModFloatValue(field, value);
		return 1;
	}

	int SetUInt32Value(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		int value = luaL_checkint(L, 2);
		if( ptr != NULL ) ptr->SetUInt32Value(field, value);
		return 1;
	}

	int SetUInt64Value(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		int value = luaL_checkint(L, 2);
		if( ptr != NULL ) ptr->SetUInt64Value(field, value);
		return 1;
	}
	int RemoveFlag(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID( TYPEID_GAMEOBJECT ||TYPEID_PLAYER||TYPEID_UNIT);
		int field = luaL_checkint(L,1);
		int value = luaL_checkint(L,2);
		if(field && value)
			ptr->RemoveFlag(field,value);
		return 0;
	}

	int SetFloatValue(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		float value = (float)luaL_checknumber(L, 2);
		if( ptr != NULL ) ptr->SetFloatValue(field, value);
		return 1;
	}

	int GetUInt32Value(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		if( ptr != NULL ) 
			lua_pushnumber(L, ptr->GetUInt32Value(field));
		return 1;
	}

	int GetUInt64Value(lua_State * L, Unit * ptr)
	{
		int field = luaL_checkint(L, 1);
		if( ptr != NULL )
			lua_pushinteger(L, (int)ptr->GetUInt64Value(field));
		return 1;
	}

	int AdvanceQuestObjective(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int questid = luaL_checkint(L,1);
		int objective = luaL_checkint(L,2);
		Player * pl = ((Player*)ptr);
		QuestLogEntry * qle = pl->GetQuestLogForEntry(questid);
		qle->SetMobCount(objective, qle->GetMobCount(objective) + 1);
		qle->SendUpdateAddKill(objective);
		if(qle->CanBeFinished())
			qle->SendQuestComplete();

		qle->UpdatePlayerFields();
		return 0;
	}
	int Heal(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		uint32 spellid = luaL_checkint(L, 2);
		uint32 amount = luaL_checkint(L, 3);
		if (!target || !spellid || !amount || !ptr)
			return 0;
		ptr->Heal(target,spellid,amount);
		return 0;
	}
	int Energize(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		uint32 spellid = luaL_checkint(L, 2);
		uint32 amount = luaL_checkint(L, 3);
		uint32 type = luaL_checkint(L, 4);
		if(!target||!spellid||!amount||!type||!ptr)
			return 0;
		ptr->Energize(target,spellid,amount,type);
		return 0;
	}
	int SendChatMessageAlternateEntry(lua_State * L, Unit * ptr)
	{
		uint32 entry = luaL_checkint(L, 1);
		uint8 type = luaL_checkint(L, 2);
		uint32 lang = luaL_checkint(L, 3);
		const char * msg = luaL_checkstring(L, 4);
		if(!entry||!type||!lang||!msg)
			return 0;
		ptr->SendChatMessageAlternateEntry(entry,type,lang,msg);
		return 0;
	}
	int SendChatMessageToPlayer(lua_State * L, Unit * ptr)
	{
		uint8 type = luaL_checkint(L, 1);
		uint32 lang = luaL_checkint(L, 2);
		const char *msg = luaL_checkstring(L,3);
		Player *plr = Lunar<Player>::check(L,4);
		if(!plr||!msg)
			return 0;
		ptr->SendChatMessageToPlayer(type,lang,msg,plr);
		return 0;
	}
	int SetPowerType(lua_State * L, Unit * ptr)
	{
		const char * message = luaL_checklstring(L,1,NULL);
		if(!ptr||!message)
			return 0;
		if( message == "health")
			ptr->SetPowerType(POWER_TYPE_HEALTH);
		else if( message == "mana")
			ptr->SetPowerType(POWER_TYPE_MANA);
		else if(message == "rage")
			ptr->SetPowerType(POWER_TYPE_RAGE);
		else if(message == "focus")
			ptr->SetPowerType(POWER_TYPE_FOCUS);
		else if (message == "energy")
			ptr->SetPowerType(POWER_TYPE_ENERGY);
		return 1;
	}
	int GetPowerType(lua_State * L, Unit * ptr)
	{
		if(ptr)
		{
			switch(ptr->GetPowerType())
			{
			case POWER_TYPE_HEALTH:
				lua_pushstring(L,"Health");
			case POWER_TYPE_MANA:
				lua_pushstring(L, "Mana");
			case POWER_TYPE_RAGE:
				lua_pushstring(L, "Rage");
			case POWER_TYPE_FOCUS:
				lua_pushstring(L, "Focus");
			case POWER_TYPE_ENERGY:
				lua_pushstring(L, "Energy");
			}
		}
		return 1;
	}
	int Strike(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_UNIT);

		Unit * target = Lunar<Unit>::check(L, 1);
		uint32 weapon_damage_type = luaL_checkint(L, 2);
		uint32 sp = luaL_checkint(L, 3);
		int32 adddmg = luaL_checkint(L, 4);
		uint32 exclusive_damage = luaL_checkint(L, 5);
		int32 pct_dmg_mod = luaL_checkint(L, 6);

		if(!target||!weapon_damage_type||!sp||!adddmg||!pct_dmg_mod)
			return 0;
		ptr->Strike(target,weapon_damage_type,dbcSpell.LookupEntry(sp),adddmg,pct_dmg_mod,exclusive_damage,false,false);
		return 0;
	}
	int SetAttackTimer(lua_State * L, Unit * ptr)
	{
		int32 timer = luaL_checkint(L, 1);
		uint32 offhand = luaL_checkint(L,2);
		if(!timer||!ptr||!offhand||offhand != 1||offhand != 0)
			return 0;
		ptr->setAttackTimer(timer,false);
		return 0;
	}
	int Kill(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		Unit * target = Lunar<Unit>::check(L, 1);
		if (!ptr ||!target)
			return 0;
		ptr->DealDamage(target,target->GetUInt32Value(UNIT_FIELD_HEALTH),0,0,0,true);
		return 0;
	}
	int DealDamage(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		Unit * target = Lunar<Unit>::check(L, 1);
		uint32 damage = luaL_checkint(L, 2);
		uint32 spellid = luaL_checkint(L, 3);
		if(!ptr||!target)
			return 0;
		ptr->DealDamage(target,damage,0,0,spellid,true);
		return 0;
	}
	int SetNextTarget(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			ptr->GetAIInterface()->SetNextTarget(target);
		return 0;
	}
	int GetNextTarget(lua_State * L, Unit * ptr)
	{
		if(ptr || ptr->IsInWorld())
		{
			Lunar<Unit>::push(L, ptr->GetAIInterface()->GetNextTarget());
		}
		return 0;
	}
	int SetPetOwner(lua_State * L, Unit * ptr)
	{
		Unit * owner = Lunar<Unit>::check(L, 1);
		if(ptr || owner)
			ptr->GetAIInterface()->SetPetOwner(owner);
		return 0;
	}
	int DismissPet(lua_State * L, Unit * ptr)
	{
		if(ptr)
			ptr->GetAIInterface()->DismissPet();
		return 0;
	}
	int IsPet(lua_State * L, Unit * ptr)
	{
		if(ptr)
			if(ptr->IsPet())
				lua_pushboolean(L,1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int GetPetOwner(lua_State * L, Unit * ptr)
	{
		if(ptr)
			Lunar<Unit>::push(L, ptr->GetAIInterface()->GetPetOwner());
		return 0;
	}
	int SetUnitToFollow(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		float dist = (float)luaL_checkint(L, 2);
		float angle = (float)luaL_checknumber(L, 3);
		if(!target||!ptr||!dist||dist<=0||!angle)
			return 0;
		//Log.Notice("hypersniper","angle: %.5f",angle);
		ptr->GetAIInterface()->SetUnitToFollow(target);
		ptr->GetAIInterface()->SetFollowDistance(dist);
		return 0;
	}
	int GetUnitToFollow(lua_State * L, Unit * ptr)
	{
		if(ptr)
			Lunar<Unit>::push(L,ptr->GetAIInterface()->getUnitToFollow());
		return 0;
	}
	int IsInFront(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			if(ptr->isInFront(target))
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}

	int IsInBack(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			if(ptr->isInBack(target))
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int IsPacified(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushboolean(L,(ptr->IsPacified())?1:0);
		return 1;
	}
	int SetPacified(lua_State * L, Unit * ptr)
	{
		uint32 pacified = luaL_checkint(L,1) > 0 ? 1 : 0;
		if(ptr)
			ptr->m_pacified = pacified;
		return 1;
	}
	int IsFeared(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushboolean(L,(ptr->IsFeared())?1:0);
		return 1;
	}
	int IsStunned(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushboolean(L,(ptr->IsStunned())?1:0);
		return 1;
	}
	int CreateGuardian(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);

		uint32 guardian_entry = luaL_checkint(L,1);
		uint32 duration = luaL_checkint(L, 2);
		float angle = (float)luaL_checkint(L, 3);
		uint32 lvl  = luaL_checkint(L, 4);
		if(!ptr||!guardian_entry||!lvl)
			return 0;
		ptr->create_guardian(guardian_entry,duration,angle,lvl,NULL);
		return 0;
	}
	int IsInArc(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		float degrees = (float)luaL_checkint(L, 2);
		if(!target||!ptr||!degrees)
			return 0;
		else
			if(ptr->isInArc(target,degrees))
				lua_pushboolean(L,1);
			else
				lua_pushboolean(L,0);
		return 1;
	}
	int IsInWater(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		if(ptr)
			if(static_cast< Player* >( ptr )->m_UnderwaterState)
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
		
	int GetAITargetsCount(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetAIInterface()->getAITargetsCount());
		return 1;
	}
	int GetUnitByGUID(lua_State * L, Unit * ptr)
	{
		uint64 guid = luaL_checkint(L,1);
		if(ptr && guid)
			Lunar<Unit>::push(L,ptr->GetMapMgr()->GetUnit(guid));
		return 1;
	}
	int GetUnitByRawGUID(lua_State * L, Unit * ptr)
	{
		const char * raw_guid = luaL_checkstring(L,1);
		istringstream buffer(raw_guid);
		uint64 guid;
		buffer >> guid;
		if(ptr && guid)
			Lunar<Unit>::push(L,ptr->GetMapMgr()->GetUnit(guid));
		return 1;
	}

	int GetAITargets(lua_State * L, Unit * ptr)
	{
		Unit * ret = NULL;
		TargetMap::iterator itr;
		lua_newtable(L);
		int count = 0;
		for( itr = ptr->GetAIInterface()->GetAITargets()->begin();itr!= ptr->GetAIInterface()->GetAITargets()->end();itr++)
		{
			ret = ptr->GetMapMgr()->GetUnit(itr->first);
			count++;
			lua_pushvalue(L,count);
			Lunar<Unit>::push(L,ret,false);
			lua_rawset(L,-3);
		}
		return 1;
	}
	int GetInRangeObjectsCount(lua_State * L, Unit * ptr)
	{
		if(ptr)
			lua_pushnumber(L,ptr->GetInRangeCount());
		return 1;
	}
	int GetInRangePlayers(lua_State * L, Unit * ptr)
	{
		Player * ret = NULL;
		uint32 count = 0;
		lua_newtable(L);
		for(std::set<Player*>::iterator itr = ptr->GetInRangePlayerSetBegin(); itr != ptr->GetInRangePlayerSetEnd(); itr++)
		{
			if( (*itr) ->GetTypeId() == TYPEID_PLAYER)
			{
				count++,
				ret = *itr;
				lua_pushinteger(L,count);
				Lunar<Unit>::push(L,((Unit*)ret),false);
				lua_rawset(L,-3);
			}
		}
		return 1;
	}
	int GetInRangeGameObjects(lua_State * L, Unit * ptr)
	{
		lua_newtable(L);
		uint32 count = 0;
		for (std::set<Object*>::iterator itr = ptr->GetInRangeSetBegin();itr!= ptr->GetInRangeSetEnd();itr++)
		{
			if( (*itr) ->GetTypeId() == TYPEID_GAMEOBJECT)
			{
				count++,
				lua_pushinteger(L,count);
				Lunar<GameObject>::push(L,(GameObject*)(*itr));
				lua_rawset(L,-3);
			}
		}
		return 1;
	}
		
	int HasInRangeObjects(lua_State * L, Unit * ptr)
	{

		if(ptr)
			if(ptr->HasInRangeObjects())
				lua_pushboolean(L, 1);
			else
				lua_pushboolean(L, 0);
		return 1;
	}
	int SetFacing(lua_State * L, Unit * ptr)
	{
		float newo = (float)luaL_checkint(L, 1);
		if(!ptr|!newo)
			return 0;
		ptr->SetFacing(newo);
		return 0;
	}
	int CalcToDistance(lua_State * L, Unit * ptr)
	{
		float x = (float)luaL_checkint(L,1 );
		float y = (float)luaL_checkint(L, 2);
		float z = (float)luaL_checkint(L, 3);
		if (!ptr|!x|!y|!z)
			return 0;
		lua_pushnumber(L,ptr->CalcDistance(x,y,z));
		return 1;
	}
	int CalcAngle(lua_State * L, Unit * ptr)
	{
		float x = (float)luaL_checkint(L,1 );
		float y = (float)luaL_checkint(L, 2);
		float x2 = (float)luaL_checkint(L, 3);
		float y2 = (float)luaL_checkint(L, 4);
		if(!x||!y||!x2||!y2||!ptr)
			return 0;
		lua_pushnumber(L,ptr->calcAngle(x,y,x2,y2));
		return 1;
	}
	int CalcRadAngle(lua_State * L, Unit * ptr)
	{
		float ang = 0;
		float x = (float)luaL_checkint(L,1 );
		float y = (float)luaL_checkint(L, 2);
		float dx = (float)luaL_checkint(L, 3);
		float dy = (float)luaL_checkint(L, 4);
		if(!x||!y||!dx||!dy||!ptr)
			return 0;
		else
			ang = ptr->calcRadAngle(x,y,dx,dy);
		lua_pushnumber(L,ang);
		return 1;
	}
	int IsInvisible(lua_State * L, Unit * ptr) //THIS IS NOT "IS" IT'S SET!
	{
		int enabled = luaL_checkint(L, 1);
		if(!ptr|!enabled)
			return 0;
		if(enabled > 0)
			ptr->m_invisFlag = INVIS_FLAG_TOTAL;
			ptr->m_invisible = true;
		return 1;
	}
	int MoveFly(lua_State * L, Unit * ptr)
	{
		int enabled = luaL_checkint(L,1);
		if(ptr)
			ptr->GetAIInterface()->m_moveFly = ((enabled > 0)?true:false);
		return 1;
	}
	int IsInvincible(lua_State * L, Unit * ptr) //THIS IS NOT "IS" IT'S SET!
	{
		int enabled = luaL_checkint(L, 1);
		if(ptr)
			ptr->bInvincible = ((enabled > 0)? true : false );
		return 0;
	}
	int ResurrectPlayer(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		if(ptr)
			static_cast< Player * > ( ptr ) ->RemoteRevive();
		return 0;
	}
	int KickPlayer(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		int delay = luaL_checkint(L,1);
		if(ptr)
			static_cast<Player*>(ptr)->Kick(delay);
		return 0;
	}
	int CanCallForHelp(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT)
		int enabled = luaL_checkint(L, 1);
		if(!ptr|!enabled)
			return 0;
		ptr->GetAIInterface()->m_canCallForHelp = ((enabled < 0)? true: false);
		return 0;
	}
	int CallForHelpHp(lua_State * L, Unit * ptr)
	{
		float hp = (float)luaL_checkint(L, 1);
		if(ptr)
			ptr->GetAIInterface()->m_CallForHelpHealth = hp;
		return 0;
	}
	int SetDeathState(lua_State * L, Unit * ptr)
	{
		int state = luaL_checkint(L, 1);
		if(ptr)
			switch(state)
		{
			case 0:
				ptr->setDeathState (ALIVE);
				break;
			case 1:
				ptr->setDeathState (JUST_DIED);
				break;
			case 2:
				ptr->setDeathState (CORPSE);
				break;
			case 3:
				ptr->setDeathState (DEAD);
				break;
		}
		return 1;
	}
	int SetCreatureName(lua_State * L, Unit * ptr)
	{
		uint32 id = luaL_checkint(L,1);
		if(!ptr|!id)
			return 0;
		static_cast<Creature*>(ptr)->SetCreatureInfo(CreatureNameStorage.LookupEntry(id));
		return 0;
	}
	int SetBindPoint(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		float x = (float)luaL_checknumber(L, 1);
		float y = (float)luaL_checknumber(L, 2);
		float z = (float)luaL_checknumber(L, 3);
		uint32 map = (uint32)luaL_checknumber(L, 4);
		uint32 zone = (uint32)luaL_checknumber(L, 5);
		if (!x || !y || !z || !map || !zone)
			return 0;
		plr->SetBindPoint(x, y, z, map, zone);
		return 0;
	}

	int SoftDisconnect(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		if (!plr)
			return 0;
		plr->SoftDisconnect();
		return 0;
	}
	int GetSpellId(lua_State * L, Unit * ptr)
	{
		uint32 spellid = luaL_checkint(L,1);
		if(ptr)
			Lunar<SpellEntry>::push(L,ptr->GetAIInterface()->getSpellEntry(spellid));
		return 1;
	}
	int SetNextSpell(lua_State * L, Unit * ptr)
	{
		SpellEntry * sp = dbcSpell.LookupEntry(luaL_checkint(L,1));
		if(ptr || sp)
			ptr->GetAIInterface()->SetNextSpell((AI_Spell*)sp);
		return 0;
	}
	int Possess(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);

		Unit * target = Lunar<Unit>::check(L,1);
		if(target)
			static_cast<Player*>(ptr)->Possess(target);
		return 0;
	}
	int Unpossess(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player* target = Lunar<Player>::check(L,1);
		if(target)
			target->UnPossess();
		return 0;
	}
	int RemoveFromWorld(lua_State * L, Unit * ptr)
	{
		if(ptr)
			ptr->RemoveFromWorld(true);
		return 0;
	}
	int GetFaction(lua_State * L, Unit * ptr)
	{
		if(ptr)
		{
			lua_pushnumber(L,ptr->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
		}
		return 1;
	}
	int SpellNonMeleeDamageLog(lua_State * L, Unit * ptr)
	{
		Unit * pVictim = Lunar<Unit>::check(L,1);
		uint32 spellid = luaL_checkint(L,2);
		uint32 damage = luaL_checkint(L,3);
		int allowproc = luaL_checkint(L,4);
		int static_dmg = luaL_checkint(L,5);
		int no_remove_auras = luaL_checkint(L,6);
		if(pVictim&&spellid&&damage&&allowproc&&static_dmg&&no_remove_auras)
		{
			ptr->SpellNonMeleeDamageLog(pVictim,spellid,damage,((allowproc >0)?true:false),((static_dmg>0)?true:false),((no_remove_auras>0)?true:false));
		}
		return 1;
	}
	int NoRespawn(lua_State * L, Unit * ptr)
	{
		int enabled = luaL_checkint(L,1);
		if(ptr&&enabled&&ptr->GetTypeId() == TYPEID_UNIT)
			static_cast<Creature*>( ptr ) ->m_noRespawn = ((enabled < 0)? true:false);
		return 1;
	}
	
	int GetMapId(lua_State * L, Unit * ptr)
	{
		if(!ptr)
			return 0;
		lua_pushnumber(L,ptr->GetMapId());
		return 1;
	}

	int AttackReaction(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L,1);
		uint32 damage = luaL_checkint(L,2);
		uint32 spell = luaL_checkint(L,3);
		if(ptr && target && damage)
		{
			ptr->GetAIInterface()->AttackReaction(target,damage,spell);
		}
		return 1;
	}
	int EventCastSpell(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		Unit * target = Lunar<Unit>::check(L, 1);
		uint32 sp = luaL_checkint(L,2);
		uint32 delay = luaL_checkint(L,3);
		uint32 repeats = luaL_checkint(L,4);
		if ( ptr && sp)
		{
			switch(ptr->GetTypeId())
			{
			case TYPEID_PLAYER:
				sEventMgr.AddEvent(ptr, &Player::EventCastSpell,target,dbcSpell.LookupEntry(sp),EVENT_PLAYER_UPDATE,delay,repeats,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			case TYPEID_UNIT:
				sEventMgr.AddEvent(ptr, &Unit::EventCastSpell,target,dbcSpell.LookupEntry(sp),EVENT_CREATURE_UPDATE,delay,repeats,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			}
		}
		return 0;
	}
	int IsPlayerMoving(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		if( static_cast<Player*>( ptr ) ->m_isMoving)
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
		return 1;
	}
	int IsPlayerAttacking(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		if( static_cast<Player*>( ptr ) ->IsAttacking())
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
		return 1;
	}
	int GetFactionStanding(lua_State * L, Unit * ptr)
	{
		uint32 faction = luaL_checkint(L,1);
		if (ptr && faction)
		{
			switch(((Player*)ptr)->GetStanding(faction))
			{
			case STANDING_HATED:
				lua_pushstring(L, "Hated");
			case STANDING_HOSTILE:
				lua_pushstring(L, "Hostile");
			case STANDING_UNFRIENDLY:
				lua_pushstring(L, "Unfriendly");
			case STANDING_NEUTRAL:
				lua_pushstring(L, "Neutral");
			case STANDING_FRIENDLY:
				lua_pushstring(L, "Friendly");
			case STANDING_HONORED:
				lua_pushstring(L, "Honored");
			case STANDING_REVERED:
				lua_pushstring(L, "Revered");
			case STANDING_EXALTED:
				lua_pushstring(L, "Exalted");
			}
		}
	return 1;
	}
	int SetPlayerAtWar(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		uint32 faction = luaL_checkint(L,1);
		uint32 set = luaL_checkint(L,2);
		if(ptr && faction && set)
		{
			((Player*)ptr)->SetAtWar(faction,((set > 0)? true : false));
		}
		return 0;
	}
	/*int IsPlayerAtWar(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		uint32 faction = luaL_checkint(L,1);
		if (ptr && faction)
			if( ((Player*)ptr)->IsAtWar(faction))
				lua_pushboolean(L,1);
			else
				lua_pushboolean(L,0);
		return 1;
	}*/
	int SetPlayerStanding(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 faction = luaL_checkint(L,1);
		uint32 value = luaL_checkint(L,2);
		if(faction && value)
			((Player*)ptr)->SetStanding(faction,value);
		return 0;
	}
	int SetPlayerSpeed(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		float Speed = (float)luaL_checknumber(L,1);
		if (Speed<1 || Speed>255)
			return 0;
		plr->SetPlayerSpeed(RUN, Speed);
		plr->SetPlayerSpeed(SWIM, Speed);
		plr->SetPlayerSpeed(RUNBACK, Speed / 2);
		plr->SetPlayerSpeed(FLY, Speed * 2);
		return 0;
	}
	int GiveHonor(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		uint32 honor = (uint32)luaL_checknumber(L,1);
		plr->m_honorToday += honor;
		plr->m_honorPoints += honor;
		plr->RecalculateHonor();
		return 0;
	}

	int GetStanding(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 faction = luaL_checkint(L,1);
		if(ptr && faction)
			lua_pushinteger(L,((Player*)ptr)->GetStanding(faction));
		return 0;
	}
	int RemoveThreatByPtr(lua_State * L, Unit * ptr)
	{
		Unit * target = Lunar<Unit>::check(L, 1);
		if( ptr && target)
		{
			ptr->GetAIInterface()->RemoveThreatByPtr(target);
		}
		return 0;
	}
	int HasItem(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 itemid = luaL_checkint(L,1);
		if(ptr && itemid)
		{
			if( ((Player*)ptr)->GetItemInterface()->GetItemCount(itemid,false) > 0 )
				lua_pushboolean(L,1);
			else
				lua_pushboolean(L,0);
		}
		return 1;
	}
	int PlaySpellVisual(lua_State * L, Unit * ptr)
	{
		uint64 guid = luaL_checkint(L,1);
		uint32 spell = luaL_checkint(L,2);
		if( ptr && guid && spell)
		{
			packetSMSG_PLAY_SPELL_VISUAL data;
			data.guid = guid;
			data.visualid = spell;
			ptr->OutPacketToSet( SMSG_PLAY_SPELL_VISUAL, sizeof(packetSMSG_PLAY_SPELL_VISUAL), &data, true );
		}
		return 1;
	}
	int PlaySpellVisualByRawGUID(lua_State * L, Unit * ptr)
	{
		const char * raw_guid = luaL_checkstring(L,1);
		istringstream buffer(raw_guid);
		uint64 guid;
		buffer >> guid;
		uint32 spell = luaL_checkint(L,2);
		if( ptr && guid && spell)
		{
			WorldPacket data(SMSG_PLAY_SPELL_VISUAL,2);
			data.Initialize(SMSG_PLAY_SPELL_VISUAL);
			data << guid;
			SpellEntry * pSpell = dbcSpell.LookupEntry(spell);
			data << pSpell->SpellVisual;
			ptr->SendMessageToSet( &data, true );
		}
		return 1;
	}
	int GetPlayerLevel(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		if(ptr)
		{
			lua_pushinteger(L, ptr->getLevel());
		}
		return 1;
	}
	int SetPlayerLevel(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID_RET(TYPEID_PLAYER);
		uint32 level = luaL_checkint(L,1);
		if( level <= 80)
		{
			LevelInfo * Info = objmgr.GetLevelInfo(ptr->getRace(),ptr->getClass(),level);
			if (Info != 0)
			{
				static_cast<Player*>(ptr) ->ApplyLevelInfo(Info, level);
			}
		}
		return 0;
	}
	int AddSkill(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 skill = luaL_checkint(L,1);
		uint32 current = luaL_checkint(L,2);
		uint32 max = luaL_checkint(L,3);
		if(!max) max = 475;
		if(current > max)
			((Player*)ptr)->BroadcastMessage("CURRENT LEVEL CAN'T BE GREATER THAN MAX LEVEL");
			return 0;
		((Player*)ptr)->_AddSkillLine(skill,current,max);
		((Player*)ptr)->_UpdateMaxSkillCounts();
		return 0;
	}
	int RemoveSkill(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 skill = luaL_checkint(L,1);
		if(!ptr ||!skill) return 0;
		((Player*)ptr)->_RemoveSkillLine(skill);
		((Player*)ptr)->_UpdateMaxSkillCounts();
		return 1;
	}
	int FlyCheat(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 enabled = luaL_checkint(L,1);
		if(ptr && enabled)
			((Player*)ptr)->FlyCheat = ((enabled > 0)? true : false);
		return 0;
	}
	int AdvanceSkill(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 skill = luaL_checkint(L,1);
		uint32 count = luaL_checkint(L,2);
		if(skill && count)
		{
			if( ((Player*)ptr)->_HasSkillLine(skill))
				((Player*)ptr)->_AdvanceSkillLine(skill,count);
		}
		return 0;
	}
	int RemoveAurasByMechanic(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 mechanic = luaL_checkint(L,1);
		uint32 hostileonly = luaL_checkint(L,2);
		if(ptr && mechanic && hostileonly)
		{
			ptr->RemoveAllAurasByMechanic(mechanic,-1,((hostileonly > 0)? true : false));
		}
		return 0;
	}
	int RemoveAurasType(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 type = luaL_checkint(L,1);
		if(ptr && type)
		{
			ptr->RemoveAllAuraType(type);
		}
		return 0;
	}
	int AddAura(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 spellid = luaL_checkint(L,1);
		uint32 duration = luaL_checkint(L,2);
		uint32 temp = luaL_checkint(L,3);
		if(ptr && spellid)
		{
			Aura * aura = new Aura();
			aura->Init(dbcSpell.LookupEntry(spellid), duration, ptr, ptr, ((temp > 0)? true : false));
			ptr->AddAura(aura);
			lua_pushboolean(L, 1);
			return 1;
		}
		return 0;
	}
	int SetAIState(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 state = luaL_checkint(L,1);
		if(state)
			switch(state)
		{
			case 0:
				ptr->GetAIInterface()->SetAIState(STATE_IDLE);
			case 1:
				ptr->GetAIInterface()->SetAIState(STATE_ATTACKING);
			case 2:
				ptr->GetAIInterface()->SetAIState(STATE_CASTING);
			case 3:
				ptr->GetAIInterface()->SetAIState(STATE_FLEEING);
			case 4:
				ptr->GetAIInterface()->SetAIState(STATE_FOLLOWING);
			case 5:
				ptr->GetAIInterface()->SetAIState(STATE_EVADE);
			case 6:
				ptr->GetAIInterface()->SetAIState(STATE_MOVEWP);
			case 7:
				ptr->GetAIInterface()->SetAIState(STATE_FEAR);
			case 8:
				ptr->GetAIInterface()->SetAIState(STATE_WANDER);
			case 9:
				ptr->GetAIInterface()->SetAIState(STATE_STOPPED);
			case 10:
				ptr->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
			case 11:
				ptr->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
		}
		return 0;
	}
	int SetStealth(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		uint32 stealthlevel = luaL_checkint(L,1);
		if(!stealthlevel) stealthlevel = 0;
		ptr->SetStealth(stealthlevel);
		return 0;
	}
	int GetStealthLevel(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER || TYPEID_UNIT); //Even players can be stealthed.
		lua_pushinteger(L,ptr->GetStealthLevel());
		return 1;
	}
	int IsStealthed(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		if(ptr->IsStealth())
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
		return 1;
	}
	int RemoveStealth(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		ptr->RemoveStealth();
		return 0;
	}
	int InterruptSpell(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		ptr->InterruptSpell();
		return 0;
	}
	int IsPoisoned(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER);
		if(ptr->IsPoisoned())
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
		return 1;
	}
	int RegisterAIUpdateEvent(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 time = luaL_checkint(L,1);
		sEventMgr.AddEvent( ((Creature*)ptr), &Creature::CallScriptUpdate, EVENT_SCRIPT_UPDATE_EVENT,time,0,0);
		return 0;
	}
	int ModifyAIUpdateEvent(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 newtime = luaL_checkint(L,1);
		sEventMgr.ModifyEventTimeAndTimeLeft(ptr,EVENT_SCRIPT_UPDATE_EVENT,newtime);
		return 0;
	}
	int RemoveAIUpdateEvent(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		sEventMgr.RemoveEvents(ptr, EVENT_SCRIPT_UPDATE_EVENT);
		return 0;
	}
	int deleteWaypoint(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 wp = luaL_checkint(L,1);
		if(ptr && wp)
			((Creature*)ptr)->GetAIInterface()->deleteWayPoint(wp);
		return 0;
	}

	int PerformWorldDBQuery(lua_State * L, Unit* ptr)
	{
		Log.Notice("LuaEngine", "Unit:PerformWorldDBQuery(...) is outdated! Please use the global function WorldDBQuery(...) instead! (This warning will be removed in some revisions then your Scripts will abort if you do not change that!)");
		return 0;
	}

	int PerformCharDBQuery(lua_State * L, Unit* ptr)
	{
		Log.Notice("LuaEngine", "Unit:PerformCharDBQuery(...) is outdated! Please use the global function CharDBQuery(...) instead! (This warning will be removed in some revisions then your Scripts will abort if you do not change that!)");
		return 0;
	}

	int DealGoldCost(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 money = (uint32)ptr->GetUInt32Value(PLAYER_FIELD_COINAGE);
		money -= (uint32)luaL_checknumber(L, 1);
		if (money < 0) {
			lua_pushboolean(L, 0);
			return 1;
		}
		ptr->SetUInt32Value(PLAYER_FIELD_COINAGE, money);
		lua_pushboolean(L, 1);
		return 1;
	}

	int DealGoldMerit(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		uint32 money = (uint32)ptr->GetUInt32Value(PLAYER_FIELD_COINAGE);
		money += (uint32)luaL_checknumber(L, 1);
		ptr->SetUInt32Value(PLAYER_FIELD_COINAGE, money);
		return 0;
	}

	int DeMorph(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_PLAYER || TYPEID_UNIT);
		//Player * plr = (Player*)ptr;
		//plr->DeMorph();
		ptr->DeMorph();
		return 0;
	}
	int Attack(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Unit * target = Lunar<Unit>::check(L, 1);
		if(ptr && target)
			ptr->GetAIInterface()->WipeTargetList();
			ptr->GetAIInterface()->ClearHateList();
			ptr->GetAIInterface()->WipeCurrentTarget();
			ptr->GetAIInterface()->taunt(target);
		lua_pushnumber(L, 1);
		return 1;
	}

	int CanUseCommand(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		char cmdlevel = (char)luaL_checkstring(L,1)[0];
		Player * plr = (Player*)ptr;
		if (plr->GetSession()->CanUseCommand(cmdlevel))
		{
			lua_pushboolean(L, 1);
		} else {
			lua_pushboolean(L, 0);
		}
		return 1;
	}

	int GetTarget(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0; //broken function
		Log.Notice("LuaEngine", "GetTarget is outdated. Please use GetPrimaryCombatTarget.");
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		//Lunar<Unit>::push(L,ptr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(x, y, z, entryid), false);
		Lunar<Unit>::push(L,ptr->GetMapMgr()->GetUnit(plr->GetTarget()), false);
		return 1;
	    
	}

	int GetSelection(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		//Lunar<Unit>::push(L,ptr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(x, y, z, entryid), false);
		Lunar<Unit>::push(L,ptr->GetMapMgr()->GetUnit(plr->GetSelection()), false);
		return 1;
	    
	}

	int RepairAllPlayerItems(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		Item * pItem;
		Container * pContainer;
		uint32 j, i;

		for( i = 0; i < MAX_INVENTORY_SLOT; i++ )
		{
			pItem = plr->GetItemInterface()->GetInventoryItem( i );
			if( pItem != NULL )
			{
				if( pItem->IsContainer() )
				{
					pContainer = static_cast<Container*>( pItem );
					for( j = 0; j < pContainer->GetProto()->ContainerSlots; ++j )
					{
						pItem = pContainer->GetItem( j );
						if( pItem != NULL ){
							pItem->SetDurabilityToMax();
						}
					}
				}
				else
				{
					if( pItem->GetProto()->MaxDurability > 0 && i < INVENTORY_SLOT_BAG_END && pItem->GetDurability() <= 0 )
					{
						pItem->SetDurabilityToMax();
						plr->ApplyItemMods( pItem, i, true );
					}
					else
					{
						pItem->SetDurabilityToMax();
					}                    
				}
			}
		}
		return 0;
	}

	int SetKnownTitle(lua_State * L, Unit * ptr)
	{
		int title = luaL_checkint(L,1);
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		plr->SetKnownTitle(static_cast<RankTitles>(title), true );
		((Player*)ptr)->SaveToDB(false);
			return 0;
	}

	int LifeTimeKills(lua_State * L, Unit * ptr)
	{
		int kills = luaL_checkint(L, 1);
		const char * check = luaL_checklstring(L,2,NULL);
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		int killscheck = plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
		if(check == "add" && kills > 0) { plr->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS, killscheck+kills);
		plr->SaveToDB(false); return 0; }
		if(check == "del" && killscheck >= kills) { plr->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS, killscheck-kills);
		plr->SaveToDB(false); return 0; }
		if(check == "set" && kills >= 0) { plr->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS, kills); 
		plr->SaveToDB(false); return 0; }
		if(check == NULL || kills == 0) { lua_pushinteger( L, killscheck ); return 1; }
			return 0;
	}

	int HasTitle(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		int title = luaL_checkint(L, 1);
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		if (plr->HasTitle(static_cast<RankTitles>(title)) == true) 

			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
				return 1;
	}

	int GetMaxSkill(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		uint32 skill = luaL_checkint(L, 1);
		CHECK_TYPEID(TYPEID_PLAYER);
		lua_pushinteger(L, ((Player*)ptr)->_GetSkillLineMax(skill));
			return 1;
	}

	int GetCurrentSkill(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		uint32 skill = luaL_checkint(L, 1);
		CHECK_TYPEID(TYPEID_PLAYER);
		lua_pushinteger(L, ((Player*)ptr)->_GetSkillLineCurrent(skill));
			return 1;
	}

	int HasSkill(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		uint32 skill = luaL_checkint(L, 1);
		CHECK_TYPEID(TYPEID_PLAYER);
		if (((Player*)ptr)->_HasSkillLine(skill) == true) 

			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
				return 1;
	}

	int GetGuildName(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		lua_pushstring(L,objmgr.GetGuild(((Player*)ptr)->GetGuildId())->GetGuildName());
			return 1;
	}

	int ClearCooldownForSpell(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		plr->ClearCooldownForSpell(luaL_checkint(L, 1));
			return 0;
	}

	int HasSpell(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		if (((Player*)ptr)->HasSpell(luaL_checkint(L, 1)) == true) 

			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
				return 1;
	}

	int ClearAllCooldowns(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		((Player*)ptr)->ResetAllCooldowns();
			return 0;
	}

	int ResetAllTalents(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		((Player*)ptr)->Reset_Talents();
			return 0;
	}

	int GetAccountName(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		lua_pushstring(L,((Player*)ptr)->GetSession()->GetAccountName().c_str());
			return 1;
	}

	int GetGmRank(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		const char * level = ((Player*)ptr)->GetSession()->GetPermissions();
		lua_pushstring(L,level);
			return 1;
	}

	int SavePlayer(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		((Player*)ptr)->SaveToDB(false);
			return 0;
	}

	int HasQuest(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		if (((Player*)ptr)->HasQuest(luaL_checkint(L, 1)))
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
				return 1;
	}

	int CreatureHasQuest(lua_State * L, Unit * ptr)
	{
		if(!ptr) return 0;
		CHECK_TYPEID(TYPEID_UNIT);
		Creature * ctr = (Creature*)ptr;
		uint32 questid = (uint32)luaL_checknumber(L,1);
		Quest * qst = QuestStorage.LookupEntry(questid);
		if (ctr->HasQuest(qst->id, qst->type))
			lua_pushboolean(L,1);
		else
			lua_pushboolean(L,0);
		return 1;
	}

	int RemovePvPFlag(lua_State * L, Unit * ptr)
	{
		if(!ptr && !((Player*)ptr)->IsPvPFlagged()) return 0;
		CHECK_TYPEID(TYPEID_PLAYER);
		((Player*)ptr)->RemovePvPFlag();
			return 0;
	}

	int RemoveNegativeAuras(lua_State * L, Unit * ptr)
	{
		if (!ptr) return 0;
		ptr->RemoveNegativeAuras();
			return 0;
	}

	int GossipMiscAction(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 2);
		int miscint = luaL_checkint(L, 3);
		int actionid = luaL_checkint(L, 1);
		if (!plr || !object && actionid < 9) return 0;
		if (actionid == 1) {plr->GetSession()->SendInventoryList(((Creature*)object));}
		if (actionid == 2) {plr->GetSession()->SendTrainerList(((Creature*)object));}
		if (actionid == 3) {plr->GetSession()->SendInnkeeperBind(((Creature*)object));}
		if (actionid == 4) {plr->GetSession()->SendBankerList(((Creature*)object));}
		if (actionid == 5) {plr->GetSession()->SendBattlegroundList(((Creature*)object), miscint);}
		if (actionid == 6) {plr->GetSession()->SendAuctionList(((Creature*)object));}
		if (actionid == 7) {plr->GetSession()->SendTabardHelp(((Creature*)object));}
		if (actionid == 8) {plr->GetSession()->SendSpiritHealerRequest(((Creature*)object));}
		if (actionid == 9) {plr->SendTalentResetConfirm();}
		if (actionid == 10) {plr->SendPetUntrainConfirm();}
			return 0;
	}

	int SendVendorWindow(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 1); //NOT entry. The unit pointer.
		if (!plr || !object) 
			return 0;
		plr->GetSession()->SendInventoryList(((Creature*)object));
		return 0;
	}

	int SendTrainerWindow(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 1); //NOT entry. The unit pointer.
		if (!plr || !object) 
			return 0;
		plr->GetSession()->SendTrainerList(((Creature*)object));
		return 0;
	}

	int SendInnkeeperWindow(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 1); //NOT entry. The unit pointer.
		if (!plr || !object) 
			return 0;
		plr->GetSession()->SendInnkeeperBind(((Creature*)object));
		return 0;
	}

	int SendBankWindow(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 1); //NOT entry. The unit pointer.
		if (!plr || !object) 
			return 0;
		plr->GetSession()->SendBankerList(((Creature*)object));
		return 0;
	}

	int SendAuctionWindow(lua_State * L, Unit * ptr)
	{
		Player* plr = ((Player*)ptr);
		Unit* object = Lunar<Unit>::check(L, 1); //NOT entry. The unit pointer.
		if (!plr || !object) 
			return 0;
		plr->GetSession()->SendAuctionList(((Creature*)object));
		return 0;
	}

	int SendBattlegroundWindow(lua_State * L, Unit * ptr)
	{
		/*	BATTLEGROUND_ALTERAC_VALLEY		= 1,
		BATTLEGROUND_WARSONG_GULCH			= 2,
		BATTLEGROUND_ARATHI_BASIN			= 3,
		BATTLEGROUND_ARENA_2V2				= 4,
		BATTLEGROUND_ARENA_3V3				= 5,
		BATTLEGROUND_ARENA_5V5				= 6,
		BATTLEGROUND_EYE_OF_THE_STORM		= 7,
		BATTLEGROUND_STRAND_OF_THE_ANCIENT	= 9,   */
		Player * plr = (Player*)ptr;
		uint32 bgid = luaL_checkint(L,1);
		if (!plr || bgid==NULL)
			return 0;
		plr->GetSession()->SendBattlegroundList(((Creature*)plr), bgid); //player filler ftw
		return 0;
	}

	int SendLootWindow(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		//utilising new raw_guid thingo.
		const char * raw_guid = luaL_checkstring(L,1);
		istringstream buffer(raw_guid);
		uint64 guid;
		buffer >> guid;
		//by now guid holds the uint64 you want.
		uint8 loot_type = (uint8)luaL_checkint(L,2);
		uint8 loot_type2 = 1;
		Player * plr = (Player*)ptr;
		/*Loot type MUST be
			1-creature, regular
			2-creature, skinning
			3-creature, pickpocketing
			4-go, regular (includes fishing schools)
			5-go, herbalism/mining
			6-item, regular/milling/prospecting
			7-item, disenchanting
		*/
		plr->SetLootGUID(guid);
		uint32 guidtype = GET_TYPE_FROM_GUID(guid);
		if(guidtype == HIGHGUID_TYPE_UNIT)
		{
			Unit* pUnit = plr->GetMapMgr()->GetUnit(guid);
			CreatureProto * proto = ((Creature*)pUnit)->GetProto();
			switch (loot_type) {
				default:
					lootmgr.FillCreatureLoot(&pUnit->loot, pUnit->GetEntry(), pUnit->GetMapMgr() ? ( pUnit->GetMapMgr()->iInstanceMode ? true : false ) : false);
					pUnit->loot.gold = proto ? proto->money : 0;
					loot_type2 = 1;
					break;
				case 2:
					lootmgr.FillSkinningLoot(&pUnit->loot, pUnit->GetEntry());
					loot_type2 = 2;
					break;
				case 3:
					lootmgr.FillPickpocketingLoot(&pUnit->loot, pUnit->GetEntry());
					loot_type2 = 2;
					break;
			}
		}
		else if(guidtype == HIGHGUID_TYPE_GAMEOBJECT)
		{
			GameObject* pGO = plr->GetMapMgr()->GetGameObject(GET_LOWGUID_PART(guid));
			switch (loot_type) {
				default:
					lootmgr.FillGOLoot(&pGO->loot, pGO->GetEntry(), pGO->GetMapMgr() ? ( pGO->GetMapMgr()->iInstanceMode ? true : false ) : false);
					loot_type2 = 1;
					break;
				case 5:
					lootmgr.FillSkinningLoot(&pGO->loot, pGO->GetEntry());
					loot_type2 = 2;
					break;
			}
		}
		else if( (guidtype == HIGHGUID_TYPE_ITEM) )
		{
			Item *pItem = plr->GetItemInterface()->GetItemByGUID(guid);
			switch (loot_type) {
				default:
					if (lootmgr.MillingLoot.find(pItem->GetEntry())->first)
					{
						lootmgr.FillMillingLoot(pItem->loot,pItem->GetEntry());
						loot_type2 = 2;
					}
					else if (lootmgr.ProspectingLoot.find(pItem->GetEntry())->first)
					{
						lootmgr.FillProspectingLoot(pItem->loot,pItem->GetEntry());
						loot_type2 = 2;
					}
					else
					{
						lootmgr.FillItemLoot(pItem->loot,pItem->GetEntry());
						loot_type2 = 1;
					}
					break;
				case 7:
					lootmgr.FillDisenchantingLoot(pItem->loot,pItem->GetEntry());
					loot_type2 = 2;
					break;
			}
		}
		/*Loot type2 MUST be
			1-corpse, go
			2-skinning/herbalism/minning
			3-Fishing
			only 2 seems to work in for this...
		*/
		plr->SendLoot(guid,2);
		return 1;
	}

	int AddLoot(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 itemid = luaL_checkint(L,1);
		uint32 mincount = luaL_checkint(L,2);
		uint32 maxcount = luaL_checkint(L,3);
		uint32 ffa_loot = luaL_checkint(L,4);
		lootmgr.AddLoot(&ptr->loot,itemid,mincount,maxcount,ffa_loot);
		return 1;
	}

	int VendorAddItem(lua_State * L, Unit * ptr)
	{
		Creature * ctr = (Creature*)ptr;
		uint32 itemid = (uint32)luaL_checknumber(L, 1);
		uint32 amount = (uint32)luaL_checknumber(L, 2);
		uint32 costid = (uint32)luaL_checknumber(L, 3);
		ItemExtendedCostEntry * ec = ( costid > 0 ) ? dbcItemExtendedCost.LookupEntryForced( costid ) : NULL;
		if (itemid == NULL || !ctr || amount == NULL)
			return 0;
		ctr->AddVendorItem(itemid, amount, ec);
		return 0;
	}
	int VendorRemoveItem(lua_State * L, Unit * ptr)
	{
		Creature * ctr = (Creature*)ptr;
		uint32 itemid = (uint32)luaL_checknumber(L, 1); 
		int slot = ctr->GetSlotByItemId(itemid);
		if(slot == -1 || !ctr || itemid == NULL)
			return 0;
		ctr->RemoveVendorItem(itemid);
		return 0;
	}
	int VendorRemoveAllItems(lua_State * L, Unit * ptr)
	{
		Creature * ctr = (Creature*)ptr;
		uint32 i = 0;
		if (!ctr || !ctr->HasItems())
			return 0;
		uint32 creatureitemids[200];
		//sLog.outDebug("ctr->GetSellItemCount(): %d",ctr->GetSellItemCount());
		for(std::vector<CreatureItem>::iterator itr = ctr->GetSellItemBegin(); itr != ctr->GetSellItemEnd(); ++itr)
		{
			creatureitemids[i] = itr->itemid;
			i+=1;
			//sLog.outDebug("%d: %d",i,creatureitemids[i]);
		}
		for (i=0; i<=ctr->GetSellItemCount(); i++) {
			ctr->RemoveVendorItem(creatureitemids[i]);
			//sLog.outDebug("%d, %d: Removal done.",i,creatureitemids[i]);
		}
		//sLog.outDebug("Done with VendorRemoveAllItems.");
		return 0;
	}
	int EquipWeapons(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		uint32 equip1 = luaL_checkint(L, 1);
		uint32 equip2 = luaL_checkint(L, 2);
		uint32 equip3 = luaL_checkint(L, 3);
		if(equip1!=0 || equip2!=0 || equip3!=0)
		{
		ptr->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, equip1);
		ptr->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+1, equip2);
		ptr->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID+2, equip3);
		return 1;
		}
		else
			return 0;
	}

	int Mount(lua_State * L, Unit * ptr)
	{
		uint32 modelid = luaL_checkint(L,1);
		if(modelid==0 || !modelid)
			return 0;

		CHECK_TYPEID(TYPEID_UNIT || TYPEID_PLAYER)

		ptr->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , modelid);
		return 1;
	}

	int Dismount(lua_State * L, Unit * ptr)
	{
		Player * plr = ((Player*)ptr);

		if(ptr->IsPlayer())
		{
			plr->RemoveAura(plr->m_MountSpellId);
			plr->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , 0);
			return 1;
		}
		else
		{
			ptr->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , 0);
			return 1;
		}
	}

	int GiveXp(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * pl = ((Player*)ptr);
		uint32 exp = luaL_checkint(L, 1);
		pl->GiveXP(exp, pl->GetGUID(), true);
		return 1;
	}

	int AdvanceAllSkills(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = ((Player*)ptr);
		uint32 skillvalue = luaL_checkint(L, 1);
		if(!plr) return 0;
		plr->_AdvanceAllSkills(skillvalue);
		return 0;
	}

	int GetTeam(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = ((Player*)ptr);
		if(!plr) return 0;
		lua_pushinteger(L, plr->GetTeam());
		return 1;
	}

	int StartTaxi(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = ((Player*)ptr);
		if (!plr) return 0;
		int id = luaL_checkint(L,1);
		TaxiPath* newtp = new TaxiPath();
		int i;
		for( i = 2; luaL_checkint(L,(i+1)) != 0; i+=4 ) //Cannot check mapid against zero because it CAN be zero.
		{
			TaxiPathNode* ntpn = new TaxiPathNode();
			ntpn->x = (float)luaL_checknumber(L,(i+1));
			ntpn->y = (float)luaL_checknumber(L,(i+2));
			ntpn->z = (float)luaL_checknumber(L,(i+3));
			ntpn->mapid = luaL_checkint(L,i);
			newtp->AddPathNode(i, ntpn);
		}
		plr->TaxiStart(newtp, id, 0);
		lua_pushboolean(L,1);
		return 1;
	}
	
	int ChannelSpell(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		uint32 Csp = luaL_checkint(L, 1);
		Unit * target = Lunar<Unit>::check(L, 2);

		if(Csp==0 || target==NULL)
			return 0;
		
		ptr->CastSpell(target,dbcSpell.LookupEntry(Csp),false);
		ptr->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, target->GetGUID());
		ptr->SetUInt32Value(UNIT_CHANNEL_SPELL, Csp);
		return 0;
	}

	int StopChannel(lua_State * L, Unit * ptr)
	{
		//CHECK_TYPEID(TYPEID_UNIT);
		ptr->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
		ptr->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
		return 0;
	}

	int SetWorldState(lua_State * L, Unit * ptr)
	{
		int zone = luaL_checkint(L, 1);
		int index = luaL_checkint(L, 2);
		int value = luaL_checkint(L, 3);
		
		if(!zone || !index || !value)
				lua_pushnil(L);

		ptr->GetMapMgr()->SetWorldState(zone, index, value);
		lua_pushboolean(L, 1);
		return 1;
	}

	int EnableFlight(lua_State * L, Unit * ptr)
	{	
		CHECK_TYPEID(TYPEID_PLAYER);
		Player *plr = ((Player*)ptr);
		uint32 Switch = luaL_checkint(L, 1);

		if (Switch == 1)
		{
			WorldPacket fly(835, 13);
			ptr->EnableFlight();
			fly << ptr->GetNewGUID();
			fly << uint32(2);
			ptr->SendMessageToSet(&fly, true);
			return 0;
		}
		if (Switch == 0)
		{
			WorldPacket fly(836, 13);
			ptr->DisableFlight();
			fly << ptr->GetNewGUID();
			fly << uint32(5);
			ptr->SendMessageToSet(&fly, true);
			return 0;
		}
		if ((Switch != 0) || (Switch != 1))
		{
			lua_pushnil(L);
		}
		return 0;
	}

	int GetCoinage(lua_State * L, Unit * ptr)
	{
	CHECK_TYPEID(TYPEID_PLAYER);
	Player * plr = ((Player*)ptr);
	lua_pushinteger(L,plr->GetUInt32Value(PLAYER_FIELD_COINAGE));
	return 1;
	}

	int FlagPvP(lua_State * L, Unit * ptr)
	{
	CHECK_TYPEID(TYPEID_PLAYER);
	Player * plr = ((Player*)ptr);
	plr->SetPvPFlag();
	return 1;
	}

	int IsMounted(lua_State * L, Unit * ptr)
	{
	CHECK_TYPEID(TYPEID_PLAYER);
	Player * plr = ((Player*)ptr);
	if(!ptr)
	lua_pushinteger(L,0);
	else
	lua_pushinteger(L, plr->IsMounted());

	return 1;
	}


    int FlagWorldPvP(lua_State * L, Unit * ptr)
	{
	CHECK_TYPEID(TYPEID_PLAYER);
	Player * plr = ((Player*)ptr);
	plr->SetFFAPvPFlag();
	return 1;
	}

	int DisableWorldPvP(lua_State * L, Unit * ptr)
	{
	CHECK_TYPEID(TYPEID_PLAYER);
	Player * plr = ((Player*)ptr);
	if (plr->IsFFAPvPFlagged())
		plr->RemoveFFAPvPFlag();
	return 1;
	}

	int SpawnVehicle(lua_State * L, Unit * ptr)
	{
		uint32 entry = (uint32)luaL_checknumber(L,1);
		float x = (float)luaL_checknumber(L,2);
		float y = (float)luaL_checknumber(L,3);
		float z = (float)luaL_checknumber(L,4);
		float o = (float)luaL_checknumber(L,5);
		uint32 faction = (uint32)luaL_checknumber(L,6);
		uint32 duration = (uint32)luaL_checknumber(L,7);
		uint32 phase = luaL_optint(L, 8, ptr->m_phase); 
		uint8 gender = 0; 

		if(entry == 0 || !ptr)
			return 0;

		CreatureProto * proto = CreatureProtoStorage.LookupEntry(entry);
		CreatureInfo * info = CreatureNameStorage.LookupEntry(entry);
		if(proto == 0 || info == 0)
		{
			return 1;
		}

		CreatureSpawn * sp = new CreatureSpawn;
		sp->entry = entry;
		uint32 DisplayID = 0;
		uint8 Gender = info->GenerateModelId(&DisplayID);
		sp->displayid = DisplayID;
		sp->form = 0;
		sp->id = 0;
		sp->movetype = 0;
		sp->x = x;
		sp->y = y;
		sp->z = z;
		sp->o = o;
		sp->emote_state = 0;
		sp->flags = 0;
		sp->factionid = faction;
		sp->bytes0 = 0;
		sp->bytes1 = 0;
		sp->bytes2 = 0;
		//sp->respawnNpcLink = 0;
		sp->stand_state = 0;
		sp->channel_target_creature = sp->channel_target_go = sp->channel_spell = 0;
		sp->MountedDisplayID = 0;
		sp->Item1SlotDisplay = 0;
		sp->Item2SlotDisplay = 0;
		sp->Item3SlotDisplay = 0;

		Creature * p = ptr->GetMapMgr()->CreateCreature(entry,true);
		ASSERT(p);
		p->Load(sp, (uint32)NULL, NULL);
		p->setGender(gender);
		p->spawnid = 0;
		p->m_spawn = 0;
		p->m_phase = phase;
		delete sp;
		p->PushToWorld(ptr->GetMapMgr());
		p->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE,faction);
		p->_setFaction();
		p->SetInstanceID(ptr->GetInstanceID());
		p->SetMapId(ptr->GetMapId());
		if(duration)
			p->Despawn(duration,0);
		Lunar<Unit>::push(L,TO_UNIT(p));
		return 1;
	}

	int SetVehicle(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		Unit * unitVehicle = Lunar<Unit>::check(L,1);
		int8 seat = luaL_checkint(L,2); //make it -1 for auto-choose.
		Vehicle * vehicle = ((Vehicle*)unitVehicle);
		if (vehicle && seat >= -1 && plr)
		{
			vehicle->AddPassenger(plr,seat);
		}
		return 1;
	}

	int GetVehicle(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = (Player*)ptr;
		if (plr)
			Lunar<Unit>::push(L,TO_UNIT(plr->GetVehicle()));
		return 1;
	}

	int RemoveFromVehicle(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = TO_PLAYER(ptr);
		if (!plr || !plr->GetVehicle())
			return 0;
		Vehicle * veh = plr->GetVehicle();
		veh->RemovePassenger(plr);
		return 1;
	}

	int GetVehicleSeat(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_PLAYER);
		Player * plr = TO_PLAYER(ptr);
		if (!plr || !plr->GetVehicle())
			return 0;
		lua_pushnumber(L,plr->GetVehicleSeat());
		return 1;
	}

	int IsVehicle(lua_State * L, Unit * ptr)
	{
		((Creature*)ptr)->IsVehicle() ? lua_pushboolean(L,1) : lua_pushboolean(L,0);
		return 1;
	}

	int GetPassengerCount(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		Vehicle * veh = (Vehicle*)ptr;
		if (veh)
			lua_pushnumber(L,veh->GetPassengerCount());
		return 1;
	}

	int MoveVehicle(lua_State * L, Unit * ptr)
	{
		CHECK_TYPEID(TYPEID_UNIT);
		float x = (float)luaL_checknumber(L,1);
		float y = (float)luaL_checknumber(L,2);
		float z = (float)luaL_checknumber(L,3);
		float o = (float)luaL_checknumber(L,4);
		Vehicle * veh = (Vehicle*)ptr;
		if (!veh)
			return 0;
		veh->MoveVehicle(x,y,z,o);
		return 1;
	}
}
