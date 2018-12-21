//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32

#pragma warning(disable:4305)	

#endif

void OnFirstEnterWorld(Player * Plr)
{
   char message[200];
    sprintf(message, "Welcome our new player, |cff00FF00%s|r.", Plr->GetName());
     sWorld.SendWorldText(message);
}


void SetupOnPlayerFirstEnterWorld(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_FIRST_ENTER_WORLD, OnFirstEnterWorld);
}
