//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#define TokenID 100102
#define amt 1

void addToken(Player* pPlayer)
{
    int RandomNumberGenerator = RandomUInt(100);

    ItemPrototype* it = ItemPrototypeStorage.LookupEntry(TokenID);
    Item * add = pPlayer->GetItemInterface()->FindItemLessMax(TokenID, amt, false);
    SlotResult slotresult = pPlayer->GetItemInterface()->FindFreeInventorySlot(it);

    if(RandomNumberGenerator <= 50)
    {
        pPlayer->BroadcastMessage("You have gained a token.");
        if (!add)
        {
            if(!slotresult.Result)
            {
                pPlayer->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_INVENTORY_FULL);
            } else {
                Item *item = objmgr.CreateItem( TokenID, pPlayer);
                item->SetUInt32Value( ITEM_FIELD_STACK_COUNT, amt );
                if( pPlayer->GetItemInterface()->SafeAddItem( item, slotresult.ContainerSlot, slotresult.Slot ))
                {
                    pPlayer->SendItemPushResult(false,true,true,true,slotresult.ContainerSlot,slotresult.Slot,1, item->GetEntry(), item->GetItemRandomSuffixFactor(), item->GetItemRandomPropertyId(), item->GetStackCount());
                    sQuestMgr.OnPlayerItemPickup(pPlayer,item);
                } else {
                    item->DeleteMe();
                }
            }
        } else {
            add->SetStackCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + amt);
            add->m_isDirty = true;
            pPlayer->SendItemPushResult(false, true, true, false, pPlayer->GetItemInterface()->GetBagSlotByGuid(add->GetGUID()), 0xFFFFFFFF, 1, add->GetEntry(), add->GetItemRandomSuffixFactor(), add->GetItemRandomPropertyId(), add->GetStackCount());
        }
    } else {
        pPlayer->BroadcastMessage("You have not gained a token.");
    }
}

void SetupTokens(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, (void*)addToken);
}