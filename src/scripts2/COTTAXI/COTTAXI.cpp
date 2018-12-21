#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL COTTAXI : public GossipScript
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

void COTTAXI::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 40002, Plr);
	Menu->AddItem( 0, "I am ready to Get to Andormu", 1 );
	Menu->AddItem( 0, "No, thank you.", 2 );
	if(AutoSend)
    Menu->SendTo(Plr);
}

void COTTAXI::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

    switch(IntId)
    {
    case 1:{
	TaxiPath * taxipath = sTaxiMgr.GetTaxiPath(605);
	Plr->DismissActivePets();
	Plr->TaxiStart(taxipath, 19373 , 0);
	}break;
	
	case 2:
	{Plr->Gossip_Complete();}
	break;
    }
}

void COTTAXI::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupCOTTAXI(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new COTTAXI();
	mgr->register_gossip_script(20142, gs);
}
