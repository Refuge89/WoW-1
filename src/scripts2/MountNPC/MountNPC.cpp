//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL MountNPC : public GossipScript
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

void MountNPC::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(0, "-:- Are you Happy? Click Here -:-", 3);
		Menu->AddItem(0, "Mount me with Swift Nether Drake", 1);
		Menu->AddItem(0, "Dismount me now", 2);  


        if(AutoSend)
            Menu->SendTo(Plr);
    }

void MountNPC::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
    {
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pObject==NULL)
		return;

        GossipMenu * Menu;
        switch(IntId)
        {
        case 0:     // Return to start
				GossipHello(pObject, Plr, true);
            break;

        case 1://Ruul's Nether Drake
        {
	Plr->SetPlayerSpeed(RUN, 20);
        Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 30609);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 2: //DisMount
            {
	Plr->SetPlayerSpeed(RUN, 10);
	Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
        Plr->Gossip_Complete();
        }break;

        case 3: //Author
            {
        Plr->BroadcastMessage("See me! im just SO GAY...");
        Plr->Emote(EMOTE_ONESHOT_DANCE);
        Plr->Gossip_Complete();
        }break;


        }
    }

void MountNPC::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupMountNPC(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new MountNPC();

    mgr->register_gossip_script(90000007, gs);
}