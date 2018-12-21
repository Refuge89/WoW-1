// <--->Conan-WoW Script<--->

#include "StdAfx.h"
#include "Setup.h"
 
#ifdef WIN32
#pragma warning(disable:4305)
#endif
 
 
class SCRIPT_DECL Disconnect : public GossipScript
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
void Disconnect::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                if(Plr->getLevel() < 80)
                {
                        Menu->AddItem(2, "You must be a level 80!");
                }else{
                if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
				{Menu->AddItem(0, "|cffff0000 Logout!|r", 1);}else{Menu->AddItem(1, "|cffff0000 Logout|r", 1);}                        
                

                }
                if(AutoSend)
            Menu->SendTo(Plr);
    }
 
void Disconnect::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
                        
        case 1:   // Disconnection
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(7, "|cffff0000This will be a instant logout instead of waiting 30 seconds!|r", 0);
                Menu->AddItem(5, "Disconnect Me Now!", 2);

 
                Menu->SendTo(Plr);
                                }
                break;
 
        case 2: 
            {
                Plr->GetGUID();
				Plr->SaveToDB(1);    // Saves the character before the logout
				Plr->SoftDisconnect();   // Free Disconnect Logout
            }
                        break;
		}
};

void Disconnect::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}
void SetupDisconnect(ScriptMgr * mgr)
{
        GossipScript * gs = (GossipScript*) new Disconnect();
    mgr->register_gossip_script(99000049, gs);
}