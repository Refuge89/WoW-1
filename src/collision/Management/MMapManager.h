/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (c) 2014-2018 AscEmu Team <http://www.ascemu.org>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#ifndef _MMAP_MANAGER_H
#define _MMAP_MANAGER_H

#include <G3D/g3dmath.h>
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"

#include <string>
#include <unordered_map>
#include <vector>

//  move map related classes
namespace MMAP
{
    typedef std::unordered_map<G3D::uint32, dtTileRef> MMapTileSet;
    typedef std::unordered_map<G3D::uint32, dtNavMeshQuery*> NavMeshQuerySet;

    // dummy struct to hold map's mmap data
    struct MMapData
    {
        MMapData(dtNavMesh* mesh) : navMesh(mesh) { }
        ~MMapData()
        {
            for (NavMeshQuerySet::iterator i = navMeshQueries.begin(); i != navMeshQueries.end(); ++i)
                dtFreeNavMeshQuery(i->second);

            if (navMesh)
                dtFreeNavMesh(navMesh);
        }

        dtNavMesh* navMesh;

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet navMeshQueries;     // instanceId to query
        MMapTileSet mmapLoadedTiles;        // maps [map grid coords] to [dtTile]
    };


    typedef std::unordered_map<G3D::uint32, MMapData*> MMapDataSet;

    // singleton class
    // holds all all access to mmap loading unloading and meshes
    class MMapManager
    {
        public:
            MMapManager() : loadedTiles(0), thread_safe_environment(true) {}
            ~MMapManager();

            void InitializeThreadUnsafe(std::vector<G3D::uint32>& mapIds);
            bool loadMap(const std::string& basePath, G3D::uint32 mapId, G3D::int32 x, G3D::int32 y);
            bool unloadMap(G3D::uint32 mapId, G3D::int32 x, G3D::int32 y);
            bool unloadMap(G3D::uint32 mapId);
            bool unloadMapInstance(G3D::uint32 mapId, G3D::uint32 instanceId);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(G3D::uint32 mapId, G3D::uint32 instanceId);
            dtNavMesh const* GetNavMesh(G3D::uint32 mapId);

            G3D::uint32 getLoadedTilesCount() const { return loadedTiles; }
            G3D::uint32 getLoadedMapsCount() const { return G3D::uint32(loadedMMaps.size()); }
        private:
            bool loadMapData(G3D::uint32 mapId);
            G3D::uint32 packTileID(G3D::int32 x, G3D::int32 y);

            MMapDataSet::const_iterator GetMMapData(G3D::uint32 mapId) const;
            MMapDataSet loadedMMaps;
            G3D::uint32 loadedTiles;
	//	public:
            bool thread_safe_environment;
    };
}

#endif