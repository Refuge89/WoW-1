//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

class SCRIPT_DECL LvlToken : public GossipScript
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

void LvlToken::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
    uint32 TextID = 820;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
    if (Plr->getLevel() == 1)
    {
	Menu->AddItem( 0, "I would like to Levelup to Level 60", 1 );
    }
    else
    {
	Menu->AddItem( 0, "I would like to Levelup 1 Level", 1 );
	Menu->AddItem( 0, "I would like to Levelup 2 Levels", 2 );
	Menu->AddItem( 0, "I would like to Levelup 5 Levels", 3 );
	Menu->AddItem( 0, "I would like to Levelup 10 Levels", 4 );
    }
    if(AutoSend)
    {
	Menu->SendTo(Plr);
    }
}

void LvlToken::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
    Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
    if(pCreature==NULL)
    {
	return;
    }
    uint32 lev = Plr->getLevel();
    uint32 nlev = 0;
    switch(IntId)
    {
	case 1:
	    if (Plr->getLevel() == 1)
	    {
		nlev = 59;
	    }
	    else
	    {
		nlev = 1;
	    }
    	break;
	case 2:
	    nlev = 2;
        break;
	case 3:
	    nlev = 5;
        break;
	case 4:
	    nlev = 10;
        break;
    }
    if (Plr->GetItemInterface()->GetItemCount(100102) < nlev)
    {
	sChatHandler.SystemMessage(Plr->GetSession(), "You do not have any <Level UP Tokens>. Please find our Vendor who sells Level UP Tokens");
	return;
    }
    LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), lev+nlev);
    Plr->GetItemInterface()->RemoveItemAmt(100102, nlev);
    Plr->ApplyLevelInfo(Info, lev + nlev);
}

void LvlToken::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupLvlToken(ScriptMgr * mgr)
{
    GossipScript * gs = (GossipScript*) new LvlToken();
    mgr->register_gossip_script(90000002, gs);   
}
