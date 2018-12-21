/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (C) 2014-2015 AscEmu Team <http://www.ascemu.org>
 * Copyright (C) 2009-2012 ArcEmu Team <http://www.arcemu.org>
 * Copyright (C) 2007-2008 Moon++ Team <http://moonplusplus.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include "StdAfx.h"
#include "Setup.h"
#include "../Common/EasyFunctions.h"
#include "../Common/Base.h"

bool PoweringOurDefenses(uint32 i, Spell * pSpell)
{
	if(!pSpell->u_caster->IsPlayer())
    return true;

	Player * plr = TO_PLAYER(pSpell->u_caster);
	if( !plr )
		return true;

	QuestLogEntry *qle = plr->GetQuestLogForEntry( 8490 );
	if( !qle )
		return true;

	// Angelis : Need to script the scourge attack

	if( qle && qle->GetMobCount(0) < qle->GetQuest()->required_mobcount[0] )
	{
		qle->SetMobCount(0, qle->GetMobCount(0)+1);
		qle->SendUpdateAddKill(0);
		qle->UpdatePlayerFields();
	}
	return true;
}

///////////////////////////////////////////////////////
//Quest: The Drwarfen Spy
//ID: 8486

// Anvilward say
#define ANVILWARD_SAY_0 "Follow me!"
#define ANVILWARD_SAY_1 "Very well. Let's see what you have to show me."
#define ANVILWARD_SAY_2 "What manner of trick is this, blood elf? If you seek to ambush me, I warn you I will not go down quietly!"

enum eGossipTexts
{
    ANVILWARD_1 = 8239,
    ANVILWARD_2 = 8240,
};

class SCRIPT_DECL ProspectorAnvilwardGossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* Plr);
    void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char* EnteredCode);
    void GossipEnd(Object* pObject, Player* Plr) { Plr->CloseGossip(); }
};

void ProspectorAnvilwardGossip::GossipHello(Object* pObject, Player * Plr)
{
    GossipMenu* Menu;

    Creature* pCreature = static_cast<Creature*>(pObject);
    if (pCreature == NULL)
        return;

    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), ANVILWARD_1, Plr);

    if (Plr->HasQuest(8483))
        Menu->AddItem(0, "I need a moment of your time, Sir", 1);     // I need a moment of your time, Sir.

    Menu->SendTo(Plr);
}

void ProspectorAnvilwardGossip::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
    GossipMenu* Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), ANVILWARD_2, Plr);

    if(!pObject->IsCreature())
        return;

    Creature* pCreature = static_cast<Creature*>(pObject);

    switch (IntId)
    {
        case 1:
        {
			Menu->AddItem(0, "Why... yes, of course. I've something to show you right inside this building. Mr. Anvilward.", 2);
			Menu->SendTo(Plr);
        }break;
        case 2:
        {
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, ANVILWARD_SAY_0);
		//	pCreature->GetAIInterface()->StopMovement(1);
		//	pCreature->GetAIInterface()->setMoveType(Flag_Walk);
		//	pCreature->GetAIInterface()->setMoveType(WALK);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, ANVILWARD_SAY_1, 5000);
			GossipEnd(pObject, Plr);
            pCreature->GetAIInterface()->setMoveType(MOVEMENTTYPE_FORWARDTHANSTOP);
            //Every Gossip NPC has a "StopMovement(30000)" by default.... lets overwrite it.
            pCreature->GetAIInterface()->StopMovement(10);
            Plr->Gossip_Complete();
        }break;
    }
};

class ProspectorAnvilward : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(ProspectorAnvilward);
    ProspectorAnvilward(Creature* pCreature) : CreatureAIScript(pCreature)
    {
        pCreature->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
    }

    void OnReachWP(uint32 iWaypointId, bool bForwards)
    {
        if (iWaypointId == 9)
        {
			Player* plr = _unit->GetMapMgr()->GetInterface()->GetPlayerNearestCoords(_unit->GetPositionX(),_unit->GetPositionY(),_unit->GetPositionZ()+2);

			_unit->SetFaction(38);

			if( plr )
			{
				_unit->Despawn(10 * 60 * 1000, 1000); //if failed allow other players to do quest from beggining
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, ANVILWARD_SAY_2);
				_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
			//	_unit->GetAIInterface()->setMoveType(RUN);
				_unit->GetAIInterface()->setMoveType(Flag_Run);
				_unit->GetAIInterface()->AttackReaction( plr, 500, 0 );
				_unit->GetAIInterface()->setNextTarget( plr );
				_unit->GetAIInterface()->SetAIState(STATE_ATTACKING);
			//	_unit->GetAIInterface()->EventEnterCombat( plr, 0 );
				_unit->GetAIInterface()->HandleEvent(EVENT_ENTERCOMBAT, plr, 0 );
			//	_unit->GetAIInterface()->getNextTarget();
			//	_unit->GetAIInterface()->AttackReaction(GetNearestPlayer() , 1);   // hackfix
			}
        }

        if (iWaypointId == 10)
        {
            _unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
        }
    }
};

void SetupEversongWoods(ScriptMgr* mgr)
{
//	mgr->register_dummy_spell(28247, &PoweringOurDefenses);

    mgr->register_gossip_script(15420, new ProspectorAnvilwardGossip);
    mgr->register_creature_script(15420, ProspectorAnvilward::Create);
}
