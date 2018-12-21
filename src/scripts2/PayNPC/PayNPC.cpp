//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL Paymaster : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player * plr, bool AutoSend)
	{

		GossipMenu *Menu;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 9998, plr);
		Menu->AddItem( 0, "10.000 Gold", 0);

		if(AutoSend)
			Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player * plr, uint32 Id, uint32 IntId, const char * Code)
	{
		Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
		if(pCreature==NULL)
			return;

		switch(IntId)
		{
			case 0:
				plr->SetUInt32Value(PLAYER_FIELD_COINAGE, 100000000);
				break;
		}
	}

	void GossipEnd(Object * pObject, Player* Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	}

	void Destroy()
	{
		delete this;
	}
};

void SetupPayNPC(ScriptMgr * mgr)
{
	GossipScript * PayNPC = (GossipScript*) new Paymaster;
	mgr->register_gossip_script(90000009, PayNPC);
}
