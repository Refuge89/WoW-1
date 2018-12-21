//Keazain Project

#include "stdafx.h"
#include "setup.h"
   
       
  void OnGuildjoin(Player * pPlayer, Guild * pGuild)
 
  {

if(pPlayer->GetItemInterface()->GetItemCount(5976, false)>= 1)

  {    
  
			 pPlayer->BroadcastMessage("You already have a tabard.");
 
  
         } else {
 
Item *  pItem = objmgr.CreateItem(5976, pPlayer);

      pPlayer->GetItemInterface()->AddItemToFreeSlot(pItem);
 }
   }
 
       
void SetupOnGuildjoin(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_GUILD_JOIN, OnGuildjoin);

}