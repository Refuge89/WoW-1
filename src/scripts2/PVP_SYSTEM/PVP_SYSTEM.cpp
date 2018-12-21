//Projectfile remade by Keazain
#include "StdAfx.h"
#include "Setup.h"

#define GOLD_AMOUNT 1000000  //In Copper
#define TOKEN_ID 62800

void AddItem(Player* Plr, const uint32 &ItemID, const uint32 &Amt, const bool &Stack)
{
	Item* ItemToBeAdded;
	SlotResult Slot;
	
	if(Plr == NULL)
		return;
	if(Stack)
	{
		ItemToBeAdded = Plr->GetItemInterface()->FindItemLessMax(ItemID, Amt, false);
		if(ItemToBeAdded != NULL)
		{
			ItemToBeAdded->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, Amt);
			ItemToBeAdded->m_isDirty = true;
			Plr->BroadcastMessage("You have recieved %s%s x%u.", MSG_COLOR_GREEN, ItemToBeAdded->GetProto()->Name1, Amt);
			return;
		}	
	}
	for(uint32 i = 1;i <= Amt;i++)
	{
		ItemToBeAdded = objmgr.CreateItem(ItemID, Plr);
		
		if(ItemToBeAdded == NULL)
			return;
		Slot = Plr->GetItemInterface()->FindFreeInventorySlot(ItemToBeAdded->GetProto());
		if(Slot.Result)
		{
			Plr->GetItemInterface()->SafeAddItem(ItemID, Slot.ContainerSlot, Slot.Slot);
			Plr->BroadcastMessage("You have recieved %s%s x%u.", MSG_COLOR_GREEN, ItemToBeAdded->GetProto()->Name1);
		}
		else
			Plr->SendAreaTriggerMessage("You Do not have enough Free Space.");
	}
}
void OnKill(Player* pPlayer, Player* pVictim)
{
	//if(pPlayer->GetMapId() != 37 || pVictim->GetMapId() != 37)
	//	return; // Both players must be at same map to recive token
	//  to add zones - pPlayer->GetZoneId
	if(pVictim->getLevel() < pPlayer->getLevel())
		return; // Killer receives token only if victim is same level or above
	if(pPlayer->GetLowGUID() == pVictim->GetLowGUID())
		return; // No Suicides Allowed
	if(pPlayer->GetTeam() == pVictim->GetTeam())
		return; // Award only from killing the other faction
	// GOLD CHECK FUNCTIONS DEFINED HERE
		int32 gold_check_p = pPlayer->GetUInt32Value( PLAYER_FIELD_COINAGE );
		int32 gold_check_v = pVictim->GetUInt32Value( PLAYER_FIELD_COINAGE );
		int32 new_gold_p = gold_check_p + GOLD_AMOUNT;
		int32 new_gold_v;
		if(gold_check_v < GOLD_AMOUNT)
		{
		new_gold_v = 0;
		}
		else
		{
		new_gold_v = gold_check_v - GOLD_AMOUNT;
		}
				pPlayer->SetUInt32Value( PLAYER_FIELD_COINAGE, new_gold_p );
				pPlayer->BroadcastMessage("You have gained 100 gold and a SoulStone.");
				pVictim->SetUInt32Value( PLAYER_FIELD_COINAGE, new_gold_v );
				pVictim->BroadcastMessage("You have lost 100 gold!");
				AddItem(pPlayer, TOKEN_ID, 1, true);// "1" is the amount of the item to give
				pPlayer->CastSpell(pPlayer, 27239, true);//true means that we stack the item
				pPlayer->PlaySoundToSet(11466);
			return;
}
void SetupPVP_SYSTEM(ScriptMgr* mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, (void*)OnKill);
}
