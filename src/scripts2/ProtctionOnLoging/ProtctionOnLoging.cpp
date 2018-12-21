#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)    // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif




void ProtctionOnLoging(Player * pPlayer)
{
pPlayer->CastSpell(pPlayer, 63148, true);
 }

        
    
void SetupProtctionOnLoging(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_ENTER_WORLD, ProtctionOnLoging);
}