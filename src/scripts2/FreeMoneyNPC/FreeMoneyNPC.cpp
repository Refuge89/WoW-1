#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305) // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

class SCRIPT_DECL FreeMoneyNPC : public GossipScript
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
void FreeMoneyNPC::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
   {
      GossipMenu *Menu;
   objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
      Menu->AddItem(0, "1 Gold", 1);
      Menu->AddItem(0, "10 Gold", 2);
      Menu->AddItem(0, "100 Gold", 3);
      Menu->AddItem(0, "1000 Gold", 4);
      Menu->AddItem(0, "10000 Gold", 5);
      Menu->AddItem(0, "Greedy Phat B4stard Gold", 6);
   if(AutoSend)
      Menu->SendTo(Plr);
   }

void FreeMoneyNPC::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
   {
   Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
   if(pCreature==NULL)
      return;

   switch(IntId)
   {
      case 1:
      {
         uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
         if (currentgold >= 899999999)
            {
            Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,990000000);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Money is the root of all evil, you must be BAD...real BAD!");
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I have set your gold at a reasonable level!");
            }
         else
         {
         uint32 amount = 10000;
         
         int32 newgold = currentgold + amount;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Dont spend it all in one shop!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
         }
      }
      break;
      case 2:
      {
         uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
         if (currentgold >= 899999999)
            {
            Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,990000000);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Money is the root of all evil, you must be BAD...real BAD!");
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I have set your gold at a reasonable level!");
            }
         else
         {
         uint32 amount = 100000;
         int32 newgold = currentgold + amount;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "A modest choice my friend!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
         }
      }
      break;
      case 3:
      {
         uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
         if (currentgold >= 899999999)
            {
            Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,990000000);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Money is the root of all evil, you must be BAD...real BAD!");
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I have set your gold at a reasonable level!");
            }
         else
         {
         uint32 amount = 1000000;
         int32 newgold = currentgold + amount;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Go forth my friend and spend!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
         }
      }
      break;
      case 4:
      {
         uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
         if (currentgold >= 899999999)
            {
            Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,990000000);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Money is the root of all evil, you must be BAD...real BAD!");
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I have set your gold at a reasonable level!");
            }
         else
         {
         uint32 amount = 10000000;

         int32 newgold = currentgold + amount;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Have a bag o' sand!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
         }
      }
      break;
      break;
      case 5:
      {
         uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
         if (currentgold >= 899999999)
            {
            Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,990000000);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Money is the root of all evil, you must be BAD...real BAD!");
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I have set your gold at a reasonable level!");
            }
         else
         {
         uint32 amount = 100000000;

         int32 newgold = currentgold + amount;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "A big sack of cash!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
         }
      }
      break;
      case 6:
      {
         uint32 amount = 990000000;
         Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,amount);
         pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "WOW, but...im considerably richer than yow!");
         pCreature->Emote(EMOTE_ONESHOT_CHEER);
      }
      break;
   }
};


void FreeMoneyNPC::GossipEnd(Object * pObject, Player* Plr)
{
   GossipScript::GossipEnd(pObject, Plr);
}

void SetupFreeMoneyNPC(ScriptMgr * mgr)
{
   GossipScript * gs = (GossipScript*) new FreeMoneyNPC();
   mgr->register_gossip_script(99000054, gs);
}
