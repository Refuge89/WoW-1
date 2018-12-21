//Projectfile remade by Keazain
#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305) // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

#define MAGE_STONE 62016 // Item ID

#define MOUNTER_TEXT_ID 2593 // Text ID

//All this Definition above does is tells the script below what NPC Text ID we are reading out of the DataBase
//It then reads this npc_text ID -2593- from your world Database, this way if you want your opening  the BattleMage Stone
//item page to say smething besides - Hi Galv, how are you today?  You could make a custom npc_text to say whatever you
//wish 

class SCRIPT_DECL BattleMage : public GossipScript{
  public:
    void GossipHello(Object* pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object* pObject, Player* Plr){ GossipScript::GossipEnd(pObject, Plr); }
    void Destroy(){ delete this; }
};

void BattleMage::GossipHello(Object* pObject, Player* Plr, bool AutoSend){
  // combat check
  if(Plr->CombatStatus.IsInCombat()){
    Plr->BroadcastMessage("You are in combat!");


  }else{
    GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), MOUNTER_TEXT_ID, Plr);
    Menu->AddItem(0, "I wish to become a BattleMage", 1);
	Menu->AddItem(2, "Nevermind", 3);
    if(AutoSend) Menu->SendTo(Plr);
  }
};

void BattleMage::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code){
  switch(IntId){
    case 1:{
	// Checks for allowable classes - mage = 8
      if(Plr->getClass() == 8)
{
	if(Plr->GetMapId() != 0 && Plr->GetMapId() != 1 && Plr->GetMapId() != 530 && Plr->GetMapId() != 571)
 {
 
    Plr->BroadcastMessage("You can't use that here!");
             return;
 }
            Plr->addSpell(55976); // Spell Deflection
            Plr->addSpell(674);   // Dual Wield Baby!
            Plr->addSpell(3260);  // Violet Shield
            Plr->addSpell(20705); // Power Shield
            Plr->addSpell(41196); // Shield Wall
            Plr->addSpell(6821);  // Corrupted Strength
            Plr->addSpell(14538); // Aural Shock
            Plr->addSpell(41106); // Battle Aura
            Plr->addSpell(37526); // Battle Rush
            Plr->addSpell(12975); // Last Stand
            Plr->addSpell(29594); // Imp Defensive Stance
		Plr->addSpell(7164); // 3 Minute - Defensive Stance
		Plr->BroadcastMessage("You are now a BattleMage!");
	  Plr->Gossip_Complete();
      }else {
        Plr->BroadcastMessage("You Must Be a Mage to use this Class Upgrade"); 
      }break;
    }
    
	case 2:{
	  Plr->Gossip_Complete();
    }
  }
}
void SetupBattleMage(ScriptMgr *mgr){
  GossipScript * gs = (GossipScript*) new BattleMage();
  mgr->register_item_gossip_script(MAGE_STONE, gs);
}
