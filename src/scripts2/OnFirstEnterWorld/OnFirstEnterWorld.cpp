//Keazain Project

#include "StdAfx.h"
#include "Setup.h"


#ifdef WIN32
#pragma warning(disable:4305)    // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif




void OnFirstEnterWorld(Player * pPlayer)
{
char message[500];
sprintf(message, "[WELCOMEBOT] Welcome to our new player, %s to the server!", pPlayer->GetName());
sWorld.SendWorldWideScreenText(message);
 }

        
    
void SetupOnFirstEnterWorld(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_FIRST_ENTER_WORLD, OnFirstEnterWorld);
}