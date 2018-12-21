#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif

class SCRIPT_DECL Vekjik_Gossip : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* plr, Creature * pCreature);
	void Destroy()
	{
		delete this;
	}
};

void Vekjik_Gossip::GossipHello(Object* pObject, Player * plr, bool AutoSend)
	{
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 40002, plr);
		if(plr->GetQuestLogForEntry(12573) != NULL)
		Menu->AddItem( 0, "The High-Oracle likes to make a peace offering to your tribe.", 1 );
		if(AutoSend)
			Menu->SendTo(plr);
	};

void Vekjik_Gossip::GossipSelectOption(Object* pObject, Player * plr, uint32 Id, uint32 IntId, const char * Code)
{
		Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
		if( pCreature == NULL )
			return;
		switch(IntId)
		{
			case 1:
			{
				/*Following spell does not seem to work properly, wont cast at all.
				probably missing support.
				pCreature->CastSpell(plr, dbcSpell.LookupEntry(51469), true);*/
				
				QuestLogEntry *qle = plr->GetQuestLogForEntry(12573);
				if(qle == NULL)
					return;
				
				if(qle->GetMobCount(0) != 0)
					return;
				qle->SetMobCount(0, 1);
				qle->SendUpdateAddKill(0);
				qle->UpdatePlayerFields();

				
			}
			break;
		}
};
void Vekjik_Gossip::GossipEnd(Object * pObject, Player* plr, Creature * pCreature)
{
    GossipScript::GossipEnd(pObject, plr);

}
void SetupVekjik_Gossip(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Vekjik_Gossip();
	mgr->register_gossip_script(28315, gs); //Knockback player
	
}