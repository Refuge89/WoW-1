/**
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (c) 2014-2018 AscEmu Team <http://www.ascemu.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "WorldSession.h"
#include "Log.h"
#include "Player.h"

/// \todo CalendarHandler
void WorldSession::HandleCalendarGetCalendar(WorldPacket& /*recv_data*/)
{
	time_t cur_time = time(NULL);

	WorldPacket data(SMSG_CALENDAR_SEND_CALENDAR, 4+4*0+4+4*0+4+4);

	// TODO: calendar invite event output
	// TODO: calendar event output
	data << uint32(0);                                // invite node count
	data << uint32(0);                                // event count
	data << uint32(0);
	data << uint32(secsToTimeBitFields(cur_time));    // current time

	uint32 count = 0;
	size_t p_count = data.wpos();
	data << uint32(count);                            // Calender shit.
	data.put<uint32>(p_count,count);
	data << uint32(1135753200);                       // Unix Time for when calendars started?
	data << uint32(0);                                //  unk counter 4
	data << uint32(0);                                // unk counter 5
	SendPacket(&data);

}

void WorldSession::HandleCalendarComplain(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarComplain","Not handled");
}

void WorldSession::HandleCalendarGetNumPending(WorldPacket& /*recv_data*/)
{
    WorldPacket data(SMSG_CALENDAR_SEND_NUM_PENDING, 4);
#if VERSION_STRING == Cata
    data << uint32(0);  // num pending
#endif
    SendPacket(&data);
}

void WorldSession::HandleCalendarAddEvent(WorldPacket& recv_data)
{
    // Create an Event and save it to char db 
    Log.Debug("HandleCalendarAddEvent","Not handled");

	uint32 guid = static_cast<uint32>(_player->GetGUID());

	uint32 count = 0;
    std::string title;
    std::string description;
    uint8 type;
    uint8 repeatable;
    uint32 maxInvites;
    int32 dungeonId;
    uint32 eventPackedTime;
    uint32 unkPackedTime;
    uint32 flags;

    recv_data >> title;
    recv_data >> description;
    recv_data >> type;
    recv_data >> repeatable;
    recv_data >> maxInvites;
    recv_data >> dungeonId;
    recv_data.ReadPackedTime(eventPackedTime);
    recv_data.ReadPackedTime(unkPackedTime);
    recv_data >> flags;
	if(!((flags >> 6) & 1))
	{
		recv_data >> count;
		if (count)
		{
			uint8 unk12,unk13;
			WoWGuid Guid_d;
			for (unsigned int i = 0; i < count; i++)
			{
				recv_data >> Guid_d;
				recv_data >> unk12;
				recv_data >> unk13;
				/// \todo save it to db
				Log.Success("HandleCalendarAddEvent", "WoWGuid: %u sends Calendarevent: Title: %s, Description: %s, Type: %u, Repeatable: %u, maxInvites: %u, dungeonId: %u, PackedTime: %u, unkPackedTime: %u, Flags: %u, unk12: %u, unk13: %u,",
				Guid_d, title.c_str(), description.c_str(), type, repeatable, maxInvites, dungeonId, eventPackedTime, unkPackedTime, flags, unk12, unk13);

			}
		}
	}

    /// \todo save it to db
    Log.Success("HandleCalendarAddEvent", "Playerguid: %u sends Calendarevent: Title: %s, Description: %s, Type: %u, Repeatable: %u, maxInvites: %u, dungeonId: %u, PackedTime: %u, unkPackedTime: %u, Flags: %u,",
        guid, title.c_str(), description.c_str(), type, repeatable, maxInvites, dungeonId, eventPackedTime, unkPackedTime, flags);

}

void WorldSession::HandleCalendarGetEvent(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarGetEvent","Not handled");
}

void WorldSession::HandleCalendarGuildFilter(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarGuildFilter","Not handled");
}

void WorldSession::HandleCalendarArenaTeam(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarArenaTeam","Not handled");
}

void WorldSession::HandleCalendarUpdateEvent(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarUpdateEvent","Not handled");
}

void WorldSession::HandleCalendarRemoveEvent(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarRemoveEvent","Not handled");
}

void WorldSession::HandleCalendarCopyEvent(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarCopyEvent","Not handled");
}

void WorldSession::HandleCalendarEventInvite(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarEventInvite","Not handled");
}

void WorldSession::HandleCalendarEventRsvp(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarEventRsvp","Not handled");
}

void WorldSession::HandleCalendarEventRemoveInvite(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarEventRemoveInvite","Not handled");
}

void WorldSession::HandleCalendarEventStatus(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarEventStatus","Not handled");
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPacket& /*recv_data*/)
{
    Log.Debug("HandleCalendarEventModeratorStatus","Not handled");
}
