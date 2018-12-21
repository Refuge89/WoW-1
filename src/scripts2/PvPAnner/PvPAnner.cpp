//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

//arena coords
#define ARENAMAPID 0
#define ARENAX -13226.732422
#define ARENAY 231.588669
#define ARENAZ 34.537

#define PVPITEM	90022

class SCRIPT_DECL PvPAnner : public GossipScript
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

void PvPAnner::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
{
	GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
	Menu->AddItem(0, "Port to the Arena!", 1);
	Menu->AddItem(0, "Challenge the World!", 2);
	Menu->AddItem(0, "[Exit]", 0);
	if(AutoSend)
		Menu->SendTo(Plr);
}




//Defining Cases
void PvPAnner::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	GossipMenu * Menu;
	switch(IntId)
	{
		case 0:
		{   //Main menu
			Plr->Gossip_Complete();
		}break;
				
		case 1:
		{   //Goto Arena
			if(Plr->CombatStatus.IsInCombat())
			{
				Plr->Gossip_Complete();
				return;
			}
			Plr->EventTeleport(ARENAMAPID, ARENAX, ARENAY, ARENAZ);
			Plr->Gossip_Complete();
		}break;
				
		case 2:
		{   //Announce
			char announce[255];
			sprintf(announce, "[|cffff0000PvP|r]|cff00ff00 %s |r|cffffffff is waiting in the arena, come and fight me.|r", Plr->GetName());
			sWorld.SendWorldText(announce);
			Plr->Gossip_Complete();
		}break;

	}//switch
}

void PvPAnner::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupPvPAnner(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new PvPAnner();
	mgr->register_item_gossip_script(90022,gs);
}