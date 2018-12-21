/*
PvP Token Plug-in, this plug in will add a token of your choice to the killer of the opposite faction.
Copyright (C) 2008  Plexor/zxc

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
Credits to NCDB for original Source
Credits to me for modifying it
*/
#include "StdAfx.h"
#include "Setup.h"

void onPvpKill(Player* plr, Player* victim)
{
    int itemID;
    uint32 tokenItem = Config.MainConfig.GetInt("NCDB", "PvPTokenID", &itemID);

    sLog.outColor(TGREEN,"n[NCDB] (%u)%s killed (%u)%s", plr->getLevel(), plr->GetName(), victim->getLevel(), victim->GetName());
    char onkill[1024];
    snprintf((char*)onkill, 1024, "[PVP]%s has killed %s", plr->GetName(), victim->GetName());
    sWorld.SendWorldWideScreenText(onkill);

    if(plr->getLevel() >= 70 && victim->getLevel() >= 70 && plr->GetTeam() != victim->GetTeam())
    {
        sLog.outColor(TGREEN,"n[NCDB] Adding token to %s", plr->GetName());
        sLog.outColor(TNORMAL,"n");
        ItemPrototype *proto = ItemPrototypeStorage.LookupEntry(itemID);
        SlotResult slotresult;
        slotresult = plr->GetItemInterface()->FindFreeInventorySlot(proto);

        if(!slotresult.Result)
        {
            plr->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_INVENTORY_FULL);
        }
        else
        {
            Item *itm = objmgr.CreateItem(itemID, plr);
            itm->SetUInt32Value(ITEM_FIELD_STACK_COUNT, 1);
            plr->GetItemInterface()->SafeAddItem(itm,slotresult.ContainerSlot, slotresult.Slot);
            plr->SaveToDB(false);
        }
    }
    else
    {
        sLog.outColor(TGREEN,"n[NCDB] Not adding token since they both are not level 70");
        sLog.outColor(TNORMAL,"n");
    }
}

void SetupPvPToken(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, onPvpKill);
}
