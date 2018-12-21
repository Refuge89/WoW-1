#include "StdAfx.h"
#include "Setup.h"

//Items above this level cannot be dropped.
//As of 2.4.2 the highest leveled blizz items
//are the TK items at level 175.
#define ITEMLEVEL 80
#define DROPCHANCE 100

void OnKill(Player *pPlayer, Player *pVictim)
{
	if(pPlayer == pVictim || (rand() % 100 + 1) > DROPCHANCE) return;
	Item * pItem = pVictim->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(!pItem || pItem->GetProto()->ItemLevel >= ITEMLEVEL) return;
	SlotResult slt = pPlayer->GetItemInterface()->FindFreeInventorySlot(pItem->GetProto());
	if(!slt.Result) return; //Player doesn't have room for the weapon
	pItem = pVictim->GetItemInterface()->SafeRemoveAndRetreiveItemByGuid(pItem->GetGUID(), false);
	pItem->SetOwner(pPlayer);
	pPlayer->GetItemInterface()->SafeAddItem(pItem, slt.ContainerSlot, slt.Slot);
	pItem->m_isDirty = true;
	pVictim->BroadcastMessage("Upon your defeat, your weapon [%s] has been taken by %s.", pItem->GetProto()->Name1, pPlayer->GetName());
	pPlayer->BroadcastMessage("You have slain %s and took his weapon, [%s], as a trophy.", pVictim->GetName(), pItem->GetProto()->Name1);
}
void SetupWeaponDropper(ScriptMgr *mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, &OnKill);
}