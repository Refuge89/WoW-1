local MSG_REVIVE = "#res"

function ReviveOnChat(event, player, message, type, language)
	if(message == MSG_REVIVE) then
		if (player:IsAlive() == true) then 
			player:SendAreaTriggerMessage("|cFF00FFFF[Revive System]|cFFFFA500|cFFFFA500You are not dead so you can't revive yourself!")
			player:SendBroadcastMessage("|cFF00FFFF[Revive System]|cFFFFA500|cFFFFA500You are not dead so you can't revive yourself!")
			else
				if (player:GetItemCount(34057) >= 1) then
				player:ResurrectPlayer()
				player:RemoveItem(34057, 1)
				player:SendBroadcastMessage("|cFF00FFFF[Revive System]|cFFFFA500Success.. You have been revived!")
				else
				player:ResurrectPlayer()
				player:SendBroadcastMessage("|cFF00FFFF[Revive System]|cFFFFA500Success.. You have been revived!")
			end
		end
	end
end
RegisterServerHook(16, "ReviveOnChat")