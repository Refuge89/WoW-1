//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif


class SCRIPT_DECL Titlenpc : public GossipScript
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
void Titlenpc::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                {
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Buy Horde PvP Titles", 1);}else{Menu->AddItem(1, "Buy Alliance PvP Titles", 2);}
				}

		if(AutoSend)
            Menu->SendTo(Plr);
    }

void Titlenpc::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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


        case 1:    ////Horde Titles////
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		        Menu->AddItem(5, "Scout 50g Req. 100HKs", 4);
                Menu->AddItem(5, "Grunt 100g Req. 300HKs", 5);
                Menu->AddItem(5, "Sergeant 150g Req 600HKs", 6);
                Menu->AddItem(5, "Senior Sergeant 200g Req. 900HKs ", 7);
                Menu->AddItem(5, "First Sergeant 250g Req. 1,200HKs", 8);
 	            Menu->AddItem(5, "Stone Guard 300g Req. 1,500HKs", 9);
                Menu->AddItem(5, "Blood Guard 350g Req. 1,800HKs", 10);
                Menu->AddItem(5, "Legionnaire 400g Req. 2,100HKs", 11);
                Menu->AddItem(5, "Centurion 500g Req. 2,500HKs", 12);
                Menu->AddItem(5, "Champion 650g Req. 3k HKs", 13);
                Menu->AddItem(5, "Lieutenant General 800g Req. 6k HKs", 14);
                Menu->AddItem(5, "General 1000g Req. 10k HKs", 15);
                Menu->AddItem(5, "Warlord 1500g Req. 15k Hks", 16);
                Menu->AddItem(5, "High Warlord 2000g Req. 20k HKs", 17);

                Menu->SendTo(Plr);
				}
		        break;


        case 2:     ////Alliance Titles////
		        {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "Private 10g Req. 10HKs", 18);
                Menu->AddItem(5, "Corporal 50g Req. 50HKs", 19);
                Menu->AddItem(5, "Sergeant 150g Req. 300HKs", 20);
                Menu->AddItem(5, "Master Sergeant 200g Req. 900HKs", 21);
                Menu->AddItem(5, "Sergeant Major 250g Req. 1,200HKs", 22);
                Menu->AddItem(5, "Knight 300g Req. 1,500HKs", 23);
                Menu->AddItem(5, "Knight-Lieutenant 350g Req. 1,800HKs", 24);
                Menu->AddItem(5, "Knight-Captain 400g Req. 2,100HKs", 25);
                Menu->AddItem(5, "Knight-Champion 500g Req. 2,500HKs", 26);
                Menu->AddItem(5, "Lieutenant Commander 650g Req. 3k HKs", 27);
                Menu->AddItem(5, "Commander 800g Req. 6k HKs", 28);
                Menu->AddItem(5, "Marshal 1000g Req. 10k HKs", 29);
                Menu->AddItem(5, "Field Marshal 1500g Req. 15k HKs", 30);
                Menu->AddItem(5, "Grand Marshal 2000g Req. 20k HKs", 31);

                Menu->SendTo(Plr);
				}
                break;

		case 4: ////Horde////Scout////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>10){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>500000){
						int32 newgold = currentgold - 100000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(15);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Scout of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 5: ////Horde////Grunt////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>50){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>1000000){
						int32 newgold = currentgold - 500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(16);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Grunt of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 6: ////Horde////Sergeant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>300){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>1500000){
						int32 newgold = currentgold - 1500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(17);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Sergeant of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 7: ////Horde////Senior Sergeant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>900){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>2000000){
						int32 newgold = currentgold - 2000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(18);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Senior Sergeant of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 8: ////Horde////First Sergeant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1200){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>2500000){
						int32 newgold = currentgold - 2500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(19);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, First Sergeant of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 9: ////Horde////Stone Guard////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1500){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>3000000){
						int32 newgold = currentgold - 3000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(20);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Stone Guard of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 10: ////Horde////Blood Guard////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1800){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>3500000){
						int32 newgold = currentgold - 3500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(21);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Blood Guard of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 11: ////Horde////Legionaire////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>2100){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>4000000){
						int32 newgold = currentgold - 4000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(22);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Legionaire of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 12: ////Horde////Centurion////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>2500){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>5000000){
						int32 newgold = currentgold - 5000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(23);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Centurion of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 13: ////Horde////Champion////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>3000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>6500000){
						int32 newgold = currentgold - 6500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(24);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Champion of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 14: ////Horde////Lieutenant General////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>6000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>8000000){
						int32 newgold = currentgold - 8000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(25);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Lieutenant General of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 15: ////Horde////General////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>10000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>10000000){
						int32 newgold = currentgold - 10000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(26);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, General of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 16: ////Horde////Warlord////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>15000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>15000000){
						int32 newgold = currentgold - 15000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(27);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, Warlord of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 17: ////Horde////High Warlord////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>20000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>20000000){
						int32 newgold = currentgold - 20000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(28);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Horde, I hereby pronounce you as, High Warlord of the Horde Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 18: ////Alliance////Private////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>100){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>500000){
						int32 newgold = currentgold - 500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(1);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Private of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 19: ////Alliance////Corporal////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>300){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>1000000){
						int32 newgold = currentgold - 1000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(2);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Corporal of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 20: ////Alliance////Sergeant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>600){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>1500000){
						int32 newgold = currentgold - 1500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(3);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Sergeant of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 21: ////Alliance////Master Sergeant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>900){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>2000000){
						int32 newgold = currentgold - 2000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(4);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Master Sergeant of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 22: ////Alliance////Sergeant Major////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1200){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>2500000){
						int32 newgold = currentgold - 2500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(5);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Sergeant Major of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 23: ////Alliance////Knight////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1500){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>3000000){
						int32 newgold = currentgold - 3000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(6);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Knight of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 24: ////Alliance////Knight-Lieutenant////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>1800){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>3500000){
						int32 newgold = currentgold - 3500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(7);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Knight-Lieutenant of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 25: ////Alliance////Knight-Captain////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>2100){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>4000000){
						int32 newgold = currentgold - 4000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(8);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Knight-Captain of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 26: ////Alliance////Knight-Champion////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>2500){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>5000000){
						int32 newgold = currentgold - 5000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(9);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Knight-Champion of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 27: ////Alliance////Lieutenant Commander////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>3000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>6500000){
						int32 newgold = currentgold - 6500000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(10);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Lieutenant Commander of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 28: ////Alliance////Commander////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>6000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>8000000){
						int32 newgold = currentgold - 8000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(11);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Commander of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 29: ////Alliance////Marshal////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>10000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>10000000){
						int32 newgold = currentgold - 10000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(12);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Marshal of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 30: ////Alliance////Field Marshal////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>15000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>15000000){
						int32 newgold = currentgold - 15000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(13);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Field Marshal of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		case 31: ////Alliance////Grand Marshal////
			{
			uint32 m_killsLifeTime = Plr->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
			if (m_killsLifeTime>20000){
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					if(currentgold>20000000){
						int32 newgold = currentgold - 20000000;
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
						Plr->SetPVPRank(14);
						pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL,"For your services to the Alliance, I hereby pronounce you as, Grand Marshal of the Alliance Forces.");
						Plr->BroadcastMessage("!!!!Please relog for title to become active!!!!");
					}else{
						Plr->BroadcastMessage("You do not have enough gold for that title.");
						Plr->Gossip_Complete();
					}break;
			}else{
				Plr->BroadcastMessage("You do not meet the Honorable Kill requirements for that title.");
				Plr->Gossip_Complete();
			}break;
			}

		}
}
						

void Titlenpc::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupTitlenpc(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Titlenpc();
    mgr->register_gossip_script(90000013, gs);
}
