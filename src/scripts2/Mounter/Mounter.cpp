//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305) // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

//Defining Warper
class SCRIPT_DECL Mounter : public GossipScript{
  public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* Plr){ GossipScript::GossipEnd(pObject, Plr); }
    void Destroy(){ delete this; }
};

void Mounter::GossipHello(Object* pObject, Player * Plr, bool AutoSend){
  if(Plr->CombatStatus.IsInCombat()){
    Plr->BroadcastMessage("You are in combat!");
  }else{
    GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
    Menu->AddItem(0, "Mount me on a Dragonhawk (level 80)", 1);
    Menu->AddItem(0, "Dismount", 2);   
    if(AutoSend) Menu->SendTo(Plr);
  }
};
//Defining Cases
void Mounter::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
  float  Speed     = 9.7;
  uint32 displayid = 0;
  uint32 eventid   = 5;
  bool   flytf     = false;
  switch(IntId){
    case 1:{ 
		if(Plr->getLevel() >= 80){
		Plr->BroadcastMessage("You have been mounted with a Dragonhawk!");
        flytf = true; eventid = 3; displayid = 21831; Speed = 20;
		Plr->SetPlayerSpeed(RUN,     Speed);
		Plr->SetPlayerSpeed(SWIM,    Speed);
		Plr->SetPlayerSpeed(RUNBACK, Speed);
		Plr->SetPlayerSpeed(FLY,     Speed);
		Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		}else {
        Plr->BroadcastMessage("You need to be atleast level 80");  
      }
		   } break;

	case 2:{
		Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
                          Plr->RemoveAura(Plr->m_MountSpellId);
                          Plr->SendAreaTriggerMessage("You have been dismounted.");
		   } break;
  }
  delete Plr;
  delete pObject;
  delete Code;
  

}
void SetupMounter(ScriptMgr *mgr){
  mgr->register_item_gossip_script(2, (GossipScript*) new Mounter());
}
