//Projectfile remade by Keazain 

#include "StdAfx.h"
#include "Setup.h"

void KillPlayer(Player *pPlayer, Player *pVictim)
{
    uint32 plr_level = pPlayer->getLevel();
    uint32 vic_level = pVictim->getLevel();

    if( vic_level <= ( plr_level - 10 ) || vic_level >= ( 10 + plr_level) )
        return;

    CalculateXP(pPlayer);
}

void CalculateXP( Player * pPlayer )
{
    uint32 plr_level = pPlayer->getLevel();
    uint32 xp1;

    if( plr_level <= 10 )
    {
        xp1 = 200;
    }else if( plr_level <= 20 )
    {
        xp1 = 500;
    }else if( plr_level <= 30 )
    {
        xp1 = 1000;
    }else if( plr_level <= 40 )
    {
        xp1 = 1500;
    }else if( plr_level <= 50 )
    {
        xp1 = 2000;
    }else if( plr_level <= 60 )
    {
        xp1 = 2500;
    }else if( plr_level <= 69 )
    {
        xp1 = 3000;
    }

    pPlayer->GiveXP(xp1,0,false);
}

void SetupPlayerXP(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, &KillPlayer);
}