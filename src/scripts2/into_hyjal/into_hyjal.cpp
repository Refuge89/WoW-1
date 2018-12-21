#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif


class SCRIPT_DECL into_hyjal : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* Plr);
	void Destroy()
	{
		delete this;
	}
};
void into_hyjal::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Hyjal Horde 4 Leveling up", 20201);}else{Menu->AddItem(1, "Hyjal Alliance 4 Leveling up", 30301);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}				
		Menu->AddItem(8, "Buff me up, baby!", 96);	
		Menu->AddItem(9, "Remove Resurrection Sickness", 97);

		if(AutoSend)
            Menu->SendTo(Plr);
    }

void into_hyjal::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
    {
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

        GossipMenu * Menu;
        switch(IntId)
        {
        case 0:
		GossipHello(pObject, Plr, true);
        break;
	                
        case 20201:     // Hord Cities
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "Hyjal Horde Leveling up", 5022);

                Menu->SendTo(Plr);
				}
		break;


        case 30301:     // Alliance Cities
				{
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "Hyjal Alliance Leveling up", 5033);

                Menu->SendTo(Plr);
				}
            break;

        case 5022://Hyjal Horde Leveling up
            {
                Plr->EventTeleport(1, 4621.73, -3857.79, 944.318);
            }
			break;
        case 5033: //Hyjal Alliance Leveling up
            {
                Plr->EventTeleport(1, 4372.62, -3241.74, 1040.21);
            }
			break;


        case 96: // Buff me up
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		pCreature->CastSpell(Plr, 15366, 0);
		pCreature->CastSpell(Plr, 33077, 0);
		pCreature->CastSpell(Plr, 33078, 0);
		pCreature->CastSpell(Plr, 33079, 0);
		pCreature->CastSpell(Plr, 33080, 0);
		pCreature->CastSpell(Plr, 33081, 0);
		pCreature->CastSpell(Plr, 33082, 0);
		pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "By all that is wrong in this world, I bless you." );
		
        Menu->SendTo(Plr);
		}break;
				
				
				
		case 97: // REMOVE RESSURECTION SICKNESS
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
        Plr->addSpell(15007);
		Plr->removeSpell(15007,0,0,0);
		pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been cured of that dreaded sickness." );
		
        Menu->SendTo(Plr);
		}break;

                
                
		case 99: //main menu
		{
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Hyjal Horde 4 Leveling up", 20201);}else{Menu->AddItem(1, "Hyjal Alliance 4 Leveling up", 30301);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}
		Menu->AddItem(8, "Buff me up, baby!", 96);	
		Menu->AddItem(9, "Remove Resurrection Sickness", 97);
		Menu->SendTo(Plr);
		}break;
			

		case 1000: //Horde Mall
			{
				Plr->EventTeleport(1, 7444.66, -1690.38, 194.64);
			}break;

		case 1001: //Alliance Mall
			{
				Plr->EventTeleport(0, -8638.7, -553.833, 145.207);
			}break;

}
};

void into_hyjal::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void Setupinto_hyjal(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new into_hyjal();
    mgr->register_gossip_script(99900555, gs);
}
