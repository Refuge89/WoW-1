#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL HealNPC : public GossipScript
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

void HealNPC::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

		Menu->AddItem(0, "Heal Me!", 1);  

        if(AutoSend)
            Menu->SendTo(Plr);
    }

void HealNPC::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
    {
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pObject==NULL)
		return;

        GossipMenu * Menu;
        switch(IntId)
        {
        case 0:     // Return to start
				GossipHello(pObject, Plr, true);
            break;

        case 1:     
	{
		if(Plr->getLevel() <= 10)
		{
		uint32 price=10000;// 1G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 2053, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
		if((Plr->getLevel() >= 11)&&(Plr->getLevel() <= 22))
		{
		uint32 price=10000;// 1G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 2055, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
		if((Plr->getLevel() >= 23)&&(Plr->getLevel() <= 34))
		{
		uint32 price=50000;// 5G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 6064, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
		if((Plr->getLevel() >= 35)&&(Plr->getLevel() <= 36))
		{
		uint32 price=50000;// 5G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 10963, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
		if((Plr->getLevel() >= 47)&&(Plr->getLevel() <= 58))
		{
		uint32 price=100000;// 10G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 10965, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
		if((Plr->getLevel() >= 59)&&(Plr->getLevel() <= 70))
		{
		uint32 price=100000;// 10G
		uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			if (currentgold>=price){
			int32 newgold = currentgold - price; 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
                pCreature->CastSpell(Plr, 25213, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been healed!" );
			}
		}
            break;
		}
		case 99: //main menu
       		{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

		Menu->AddItem(0, "Heal Me!", 1);  
				Menu->SendTo(Plr);
			}
        }
    }

void HealNPC::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupHealNPC(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new HealNPC();
    /* Teleporter List */
    mgr->register_gossip_script(90000016, gs);
}




