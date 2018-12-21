//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif



class SCRIPT_DECL BGNPC : public GossipScript
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


void BGNPC::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
   GossipMenu *Menu;
   objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	Menu->AddItem(0, "I wish to join a battleground", 1);
	Menu->AddItem(0, "Nevermind!", 2);
	if(AutoSend)
	Menu->SendTo(Plr);
}


void BGNPC::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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

	case 1:
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2, Plr);
	Menu->AddItem(0, "Join Warsong Gulch", 5);
	Menu->AddItem(0, "Join Arathi Basin", 6);
	Menu->AddItem(0, "Join Eye of the Storm", 7);
	Menu->AddItem(0, "Join Alterac Valley", 8);
	Menu->AddItem(0, "Join Strand of the Ancients", 9);
	Menu->SendTo(Plr);
	break;

	case 2:
	Plr->Gossip_Complete();
	break;

	case 5:
	{
	if(Plr->getLevel() < 10)
	{
	Plr->Gossip_Complete();
	Plr->BroadcastMessage("You are too low a level to enter Warsong Gulch!");
	}
else
	{
	Plr->GetSession()->SendBattlegroundList(((Creature*)pObject), 2); // Warsong Gulch
	}
	}
	break;

	case 6:
	{
	if(Plr->getLevel() < 20)
	{
	Plr->Gossip_Complete();
	Plr->BroadcastMessage("You are too low a level to enter Arathi Basin!");
	}
else
	{
	Plr->GetSession()->SendBattlegroundList(((Creature*)pObject), 3); // Arathi Basin
	}
	}
	break;

	case 7:
	{
	if(Plr->getLevel() < 61)
	{
	Plr->Gossip_Complete();
	Plr->BroadcastMessage("You are too low a level to enter Eye of the Storm!");
	}
else
	{
	Plr->GetSession()->SendBattlegroundList(((Creature*)pObject), 7); // Eye of the Storm
	}
	}
	break;

	case 8:
	{
	if(Plr->getLevel() < 60)
	{
	Plr->Gossip_Complete();
	Plr->BroadcastMessage("You are too low a level to enter Alterac Valley!");
	}
else
	{
	Plr->GetSession()->SendBattlegroundList(((Creature*)pObject), 1); // Alterac Valley
	}
	}
	break;

	case 9:
	{
	if(Plr->getLevel() < 71)
	{
	Plr->Gossip_Complete();
	Plr->BroadcastMessage("You are too low a level to enter Strand of the Ancients!");
	}
else
	{
	Plr->GetSession()->SendBattlegroundList(((Creature*)pObject), 8); // Strand of the Ancients
	}
	}
	 }
};


void BGNPC::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupBGNPC(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new BGNPC();
	mgr->register_gossip_script(99000089, gs);
}
