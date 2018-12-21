#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif


class SCRIPT_DECL getout_hyjal : public GossipScript
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
void getout_hyjal::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Horde Cities", 1);}else{Menu->AddItem(1, "Alliance Cities", 2);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}
		Menu->AddItem(8, "Buff me up, baby!", 96);
		Menu->AddItem(7, "Make This Place Your Home", 95);		
		Menu->AddItem(9, "Remove Resurrection Sickness", 97);

		if(AutoSend)
            Menu->SendTo(Plr);
    }

void getout_hyjal::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
	                
        case 1:     // Hord Cities
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		        Menu->AddItem(5, "Silvermoon", 4);
                Menu->AddItem(5, "Orgrimmar", 5);
                Menu->AddItem(5, "Thunder Bluff", 6);
                Menu->AddItem(5, "Undercity", 7);

                Menu->SendTo(Plr);
				}
		break;


        case 2:     // Alliance Cities
				{
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "The Exodar", 8);
                Menu->AddItem(5, "Stormwind", 9);
                Menu->AddItem(5, "Ironforge", 10);
                Menu->AddItem(5, "Darnassus", 11);

                Menu->SendTo(Plr);
				}
            break;


        case 4://Silvermoon
        {
        Plr->EventTeleport(530, 9400.486328, -7278.376953, 14.206780);
        }break;

        case 5://Orgrimmar
        {
        Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
        }break;

        case 6://ThunderBluff
            {
                Plr->EventTeleport(1, -1304.569946, 205.285004, 68.681396);
            }
			break;

        case 7://Undercity
            {
                Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
            }
			break;

        case 8: //Exodar
            {
                Plr->EventTeleport(530, -4072.202393, -12014.337891, -1.277277);
            }
			break;

        case 9: //Stormwind
            {
                Plr->EventTeleport(0, -9100.480469, 406.950745, 92.594185);
            }
			break;

        case 10: //Ironforge
            {
                Plr->EventTeleport(0, -5028.265137, -825.976563, 495.301575);
            }
			break;

        case 11: //Darnassus
            {
                Plr->EventTeleport(1, 9985.907227, 1971.155640, 1326.815674);
            }
			break;

		case 95: // Bind Position
            {
                Plr->GetSession()->SendInnkeeperBind(pCreature);

                
                }break;
                
    
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
		{Menu->AddItem(0, "Horde Cities", 1);}else{Menu->AddItem(1, "Alliance Cities", 2);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}
		Menu->AddItem(8, "Buff me up, baby!", 96);
		Menu->AddItem(7, "Make This Place Your Home", 95);		
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

void getout_hyjal::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void Setupgetout_hyjal(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new getout_hyjal();
    mgr->register_gossip_script(99900666, gs);
}
