# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>

if(NOT BUILD_RAIDSSCRIPTS )
  message("\tRaidsScripts was skipped because BUILD_RAIDSSCRIPTS is unchecked.")
  return()
endif()

# set up our project name
project(RaidsScripts CXX)

#sources -contains source files for our library.
set(sources
Raid_BlackTemple.cpp 
Raid_BlackwingLair.cpp 
Raid_CoT_BattleOfMountHyjal.cpp 
Raid_GruulsLair.cpp
Raid_IceCrownCitadel.cpp
Raid_Karazhan.cpp 
Raid_MoltenCore.cpp 
Raid_Naxxramas.cpp 
Raid_OnyxiasLair.cpp 
Raid_SerpentshrineCavern.cpp 
Raid_TheEye.cpp 
Raid_TheObsidianSanctum.cpp 
Raid_Ulduar.cpp 
Raid_ZulGurub.cpp 
Raid_Magtheridons_Lair.cpp 
SUNWELL_PLAT/Raid_SunwellPlateau.cpp 
Raid_WorldBosses.cpp 
Raid_ZulAman.cpp 
../Common/Instance_Base.cpp 
../Common/Base.cpp 
Setup.cpp )

SET( headers
Raid_Naxxramas.h
Raid_Ulduar.h
Raid_IceCrownCitadel.h
Setup.h
../Common/Base.h
../Common/EasyFunctions.h
../Common/Instance_Base.h 
)

include_directories(
   ${OPENSSL_INCLUDE_DIR}
   ${PCRE_INCLUDE_DIR}
   ${CMAKE_SOURCE_DIR}/dep/recastnavigation/Detour/Include
   ${CMAKE_SOURCE_DIR}/src/collision
   ${CMAKE_SOURCE_DIR}/src/collision/Maps
   ${CMAKE_SOURCE_DIR}/src/collision/Management
   ${CMAKE_SOURCE_DIR}/src/collision/Models
   ${CMAKE_SOURCE_DIR}/dep/g3dlite/include
   ${CMAKE_SOURCE_DIR}/src/shared
   ${CMAKE_SOURCE_DIR}/src/world
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${ZLIB_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED ${sources} ${headers})

target_link_libraries(${PROJECT_NAME} world)

if(USE_PCH AND PCHSupport_FOUND)
    ADD_NATIVE_PRECOMPILED_HEADER(${PROJECT_NAME} Setup.h ${CMAKE_CURRENT_SOURCE_DIR}/Setup.cpp)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${ASCEMU_SCRIPTLIB_PATH} LIBRARY DESTINATION ${ASCEMU_SCRIPTLIB_PATH})
unset(sources)
unset(headers)
