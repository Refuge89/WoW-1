/*	http://www.wowhead.com/?npc=24040.
	Taxi McGoyver <Pro>
	Djhenghiz made it so leave credits if u use it 
	What script needs : some one to check how this is on retail
	Need : Gossip and the layout of the menu and hw the adding of the 
	Dark Iron Ingots is handled, is it you get the flight only
	when having Quest ?*/
#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL McGoyver : public GossipScript
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

void McGoyver::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 40002, Plr);
	Menu->AddItem( 0, "Fly Me!", 1 );
	if( Plr->GetQuestLogForEntry(11483)!= NULL)
        {	Menu->AddItem( 0, "Give me Dark Iron Ingots", 2 );    } 
	Menu->AddItem( 0, "No, thank you.", 3 );
	if(AutoSend)
    Menu->SendTo(Plr);
}

void McGoyver::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

    switch(IntId)
    {
    case 1:{
	TaxiPath * taxipath = sTaxiMgr.GetTaxiPath(760);
	Plr->DismissActivePets();
	Plr->TaxiStart(taxipath, 22878, 0); //"Mount" the plane
	}break;
	
	case 2: 
		{
		Plr->GetItemInterface()->AddItemById( 34135, 1, 0 );
		Plr->Gossip_Complete();
		}
	
	case 3:
	{Plr->Gossip_Complete();}
	break;
    }
}

void McGoyver::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupMcGoyver (ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new McGoyver();
	mgr->register_gossip_script(24040, gs);
}

/*	http://www.wowhead.com/?npc=24040.
	Taxi McGoyver <Pro>
	Djhenghiz made it so leave credits if u use it 
	What script needs : some one to check how this is on retail
	Need : Gossip and the layout of the menu and hw the adding of the 
	Dark Iron Ingots is handled, is it you get the flight only
	when having Quest ?*/
