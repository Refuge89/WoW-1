//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

class SCRIPT_DECL GMHelper : public GossipScript
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
void GMHelper::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
if (!Plr->GetSession()->HasGMPermissions())
{
Plr->BroadcastMessage("You Are Not A GameMaster");
Menu->AddItem(0, "You are not a gamemaster and you can't use this menu!", 0);
}	
if (Plr->GetSession()->HasGMPermissions())
{
Plr->BroadcastMessage("Server GameMaster Menu");
Menu->AddItem(6, "GM Gold Giver Menu", 1);
Menu->AddItem(0, "GM Spell Trainer Menu", 2);
Menu->AddItem(0, "GM Teleports Menu", 100);
Menu->AddItem(0, "GM Buffs Menu", 3);
Menu->AddItem(0, "GM Items Menu", 4);
Menu->AddItem(0, "Full Heal", 5);
Menu->AddItem(0, "Advance All Skills", 6);
Menu->AddItem(0, "Give Me GM Gear", 7);
Menu->AddItem(0, "Remove Ressuretion Sickness", 8);

}	
		if(AutoSend)
            Menu->SendTo(Plr);
    }

void GMHelper::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
		
		case 1: //GM Gold Giver Main Menu
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(6, "1 Gold", 9);
			Menu->AddItem(6, "10 Gold", 10);
			Menu->AddItem(6, "1000 Gold", 11);
			Menu->AddItem(6, "5000 Gold", 12); 
			Menu->AddItem(6, "50000 Gold", 13); 

			                Menu->SendTo(Plr);
        break;

		case 2: //Spell Trainer
		    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Death Touch", 14); //5
			Menu->AddItem(0, "Suicide", 15); //7
			Menu->AddItem(0, "FrostBolt Of Ages", 16); //11
			Menu->AddItem(0, "Area Death", 17); //265
			Menu->AddItem(0, "Master Buff (Melee)", 18); //35874
			Menu->AddItem(0, "Master Buff (Magic)", 19); //35912
			Menu->AddItem(0, "Master Buff (Magic)", 20); //36001
			Menu->AddItem(0, "Uber Heal Over Time", 21); //1908
			Menu->AddItem(0, "Shackle", 22); //38505
			Menu->AddItem(0, "Automation Root Spell", 23); //39258
			Menu->AddItem(1, "WindFury Weapon", 201); //35886
			Menu->AddItem(1, "All This Spells At Once", 200); 

			                Menu->SendTo(Plr);
        break;

		case 100: //Teleports Menu
		    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "GM Box", 101); //5
			Menu->AddItem(0, "GM Island", 102); //5
			//Menu->AddItem(0, "Emerald Forest", 103); //5
			Menu->AddItem(0, "Testing Box", 104); //5
			Menu->AddItem(0, "Old Ironforge", 105); //5

			                Menu->SendTo(Plr);
        break;

		case 3: //GM Buffs Main Menu
		    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		    Menu->AddItem(0, "Master Buff (Melee)", 24); //35874
			Menu->AddItem(0, "Master Buff (Magic)", 25); //35912
			Menu->AddItem(0, "Master Buff (Magic)", 26); //36001
			Menu->AddItem(0, "WindFury Weapon", 27); //35886

			                Menu->SendTo(Plr);
        break;

		case 4: //GM Items Main Menu
		  	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		    Menu->AddItem(9, "Martin Thunder", 28); //192
			Menu->AddItem(9, "Alex's Ring of Audacity", 29); //12947
			Menu->AddItem(9, "Gamemaster's Robe", 30); //2586
			Menu->AddItem(9, "Gamemaster's Slippers", 31); //11508
			Menu->AddItem(9, "Gamemaster Hood", 21); //12064

			                Menu->SendTo(Plr);
        break;

		case 5: //Full Heal
			pCreature->CastSpell(Plr, 25840, 0);
			Plr->BroadcastMessage("You are now in full health!");
			Plr->Gossip_Complete();
        break;

		case 6: //Advance All Skills
			{
					if (Plr->_HasSkillLine(43))
				{Plr->_AdvanceSkillLine(43, 1775);}
			if (Plr->_HasSkillLine(55))
				{Plr->_AdvanceSkillLine(55, 1775);}
			if (Plr->_HasSkillLine(44))
				{Plr->_AdvanceSkillLine(44, 1775);}
			if (Plr->_HasSkillLine(95))
				{Plr->_AdvanceSkillLine(95, 1775);}
			if (Plr->_HasSkillLine(54))
				{Plr->_AdvanceSkillLine(54, 1775);}
			if (Plr->_HasSkillLine(45))
				{Plr->_AdvanceSkillLine(45, 1775);}
			if (Plr->_HasSkillLine(46))
				{Plr->_AdvanceSkillLine(46, 1775);}
			if (Plr->_HasSkillLine(136))
				{Plr->_AdvanceSkillLine(136, 1775);}
			if (Plr->_HasSkillLine(160))
				{Plr->_AdvanceSkillLine(160, 1775);}
			if (Plr->_HasSkillLine(162))
				{Plr->_AdvanceSkillLine(162, 1775);}
			if (Plr->_HasSkillLine(172))
				{Plr->_AdvanceSkillLine(172, 1775);}
			if (Plr->_HasSkillLine(173))
				{Plr->_AdvanceSkillLine(173, 1775);}
			if (Plr->_HasSkillLine(176))
				{Plr->_AdvanceSkillLine(176, 1775);}
			if (Plr->_HasSkillLine(226))
				{Plr->_AdvanceSkillLine(226, 1775);}
			if (Plr->_HasSkillLine(228))
				{Plr->_AdvanceSkillLine(228, 1775);}
			if (Plr->_HasSkillLine(229))
				{Plr->_AdvanceSkillLine(229, 1775);}
			if (Plr->_HasSkillLine(473))
				{Plr->_AdvanceSkillLine(473, 1775);}
				Plr->BroadcastMessage("All skills are now advanced to 1775!");
			Plr->Gossip_Complete(); 
			}
        break;

		case 7: //GM Gear
			{
					Item * pItem1 = objmgr.CreateItem(2586,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem1);
					Item * pItem2 = objmgr.CreateItem(11508,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem2);
					Item * pItem3 = objmgr.CreateItem(12064,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem3);
					Plr->Gossip_Complete();
			}

        break;

		case 8: //Ress Sickness
		Plr->addSpell(15007);
		Plr->removeSpell(15007,0,0,0);
		Plr->Gossip_Complete();
        break;

		case 9: //1 Gold
			{
			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			int32 newgold = currentgold + 10000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
					Plr->Gossip_Complete();
			}
        break;

		case 10: //10 Gold
			{
			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			int32 newgold = currentgold + 100000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
					Plr->Gossip_Complete();
			}
        break;
		
		case 11: //1000 Gold
			{
			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			int32 newgold = currentgold + 10000000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
					Plr->Gossip_Complete();
			}
        break;

		case 12: //5000 Gold
			{
			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			int32 newgold = currentgold + 50000000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
					Plr->Gossip_Complete();
			}
        break;

		case 13: //50000 Gold
			{
			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
			int32 newgold = currentgold + 500000000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
					Plr->Gossip_Complete();
			}
        break;
		
///////////////
//Spell Learn Codes
//////////////
			
		case 14:
Plr->addSpell(5);
        break;
		
		case 15: 
Plr->addSpell(7);
        break;
		
		case 16: 
Plr->addSpell(11);
        break;
		
		case 17: 
Plr->addSpell(265);
        break;
		
		case 18: 
Plr->addSpell(35874);
        break;
	
		case 19:
Plr->addSpell(35912);	
        break;
		
		case 20: 
Plr->addSpell(36001);
        break;
		
		case 21: 
Plr->addSpell(1908);	
        break;
	
		case 22: 
Plr->addSpell(38505);		
        break;
		
		case 23: 
Plr->addSpell(39258);	Plr->addSpell(265);Plr->addSpell(11);
        break;

		case 201: 
Plr->addSpell(35886);	
        break;
		
		case 200:  //All That Shit At Once
		Plr->addSpell(35912);	
		Plr->addSpell(35874);
		Plr->addSpell(7);
		Plr->addSpell(5);
		Plr->addSpell(265);
		Plr->addSpell(11);
		Plr->addSpell(35886);
		Plr->addSpell(39258);	
		Plr->addSpell(38505);	
		Plr->addSpell(1908);	
		Plr->addSpell(36001);
        break;
		//End Spell Learn Codes

		
		case 24: //Buff
       		pCreature->CastSpell(Plr, 35874, 0);
		Plr->Gossip_Complete();
        break;
		
		case 25: //Buff
		pCreature->CastSpell(Plr, 35912, 0);
		Plr->Gossip_Complete();
        break;
		
		case 26: //Buff
		pCreature->CastSpell(Plr, 36001, 0);
		Plr->Gossip_Complete();
        break;
		
		case 27: //Buff
		pCreature->CastSpell(Plr, 35886, 0);
		Plr->Gossip_Complete();
        break;
		

			
		case 28: //AddItem
			{
					Item * pItem12 = objmgr.CreateItem(192,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem12);
			}
        break;
		case 29: //AddItem
			{
					Item * pItem13 = objmgr.CreateItem(12947,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem13);
			}
        break;
		case 31: //AddItem
			{
					Item * pItem14 = objmgr.CreateItem(11508,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem14);
			}
        break;
		case 32: //AddItem
			{
					Item * pItem15 = objmgr.CreateItem(12064,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem15);
			}
        break;
		case 30: //AddItem
			{
					Item * pItem16 = objmgr.CreateItem(2586,Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem16);
			}
        break;
			Menu->AddItem(0, "GM Box", 101); //5
			Menu->AddItem(0, "GM Island", 102); //5
			Menu->AddItem(0, "Testing Box", 104); //5
		case 101: //Teleport GM Box
 Plr->EventTeleport(1, 16221, 16416, -64);
        break;
		case 102: //Teleport GMIsle 
 Plr->EventTeleport(1, 16222.1, 16252.1, 12.5872);
        break;

		case 104: //Teleport Old IF
 Plr->EventTeleport(42, 0, 0, -25);
        break;
		case 105: //Teleport Testing
 Plr->EventTeleport(0, -4843.0874, -1066.9552, 500.9893);
        break;


 }
 }

void GMHelper::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupGMHelper(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new GMHelper();
    mgr->register_gossip_script(90000001, gs);
}
