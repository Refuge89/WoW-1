/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _LOGON_SERVER_DEFINES_HPP
#define _LOGON_SERVER_DEFINES_HPP

enum RealmFlags
{
    REALM_FLAG_NONE         = 0x00,
    REALM_FLAG_INVALID      = 0x01,
    REALM_FLAG_OFFLINE      = 0x02,
    REALM_FLAG_SPECIFYBUILD = 0x04,     // client will show realm version in RealmList screen in form "RealmName (major.minor.revision.build)"
    REALM_FLAG_UNK1         = 0x08,
    REALM_FLAG_UNK2         = 0x10,
    REALM_FLAG_NEW_PLAYERS  = 0x20,
    REALM_FLAG_RECOMMENDED  = 0x40,
    REALM_FLAG_FULL         = 0x80
};

struct RealmListQueryResult
{
    uint32 id;
    std::string name;
    std::string address;
    uint32 port;
    uint16 icon;
    uint8 flags; // uint8 color;
    uint8 timezone;
    float Population;
    uint16 gamebuild;
};

class Realms
{
    public:
        uint32 id;
        std::string name;
        std::string address;
        uint32 port;
        uint16 icon;
		uint8 flags; // uint8 color;
        uint8 timezone;
		float Population;
        uint16 gamebuild;

        Realms(RealmListQueryResult result)
        {
            id = result.id;
            name = result.name;
            address = result.address;
            port = result.port;
            icon = result.icon;
            flags = result.flags;
            timezone = result.timezone;
            Population = result.Population;
            gamebuild = result.gamebuild;
        }

        Realms() {}
};

struct AllowedIP
{
    unsigned int IP;
    unsigned char Bytes;
};

#endif  //_LOGON_SERVER_DEFINES_HPP
