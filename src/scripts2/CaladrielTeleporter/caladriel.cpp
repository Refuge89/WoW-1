//Projectfile remade by Keazain

    #include "StdAfx.h"
    #include "Setup.h"

    #ifdef WIN32
    #pragma warning(disable:4305)        // warning C4305: 'argument' : truncation from 'double' to 'float'
    #endif

    //Defining Pwarper2
    class SCRIPT_DECL Pwarper2 : public GossipScript
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

    void Pwarper2::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
    {
        if(Plr->CombatStatus.IsInCombat())
        {
            Plr->BroadcastMessage("You are in combat!");
        }
        if(!Plr->CombatStatus.IsInCombat())
        {
        
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
        Menu->AddItem(0, "magic", 1);
            if(AutoSend)
            Menu->SendTo(Plr);
    }
};




    //Defining Cases
    void Pwarper2::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
    {
        GossipMenu * Menu;
        switch(IntId)
        {
                case 1:
                    {   //magic
                        Plr->SafeTeleport(0, 0, 0, 0, 0, 0);
                        Plr->Gossip_Complete();
                    }break;
                  
        }
    };

    void Pwarper2::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

    void SetupPwarper2(ScriptMgr * mgr)
    {
    GossipScript * gs = (GossipScript*) new Pwarper2();
    mgr->register_item_gossip_script(99000050,gs);
    }