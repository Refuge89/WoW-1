# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>

if(NOT BUILD_INSTANCESCRIPTS )
  message("\tInstanceScripts was skipped because BUILD_INSTANCESCRIPTS is unchecked.")
  return()
endif()

# set up our project name
project(InstanceScripts CXX)

#sources -contains source files for our library.
set(sources
Instance_Arcatraz.cpp 
Instance_AuchenaiCrypts.cpp 
Instance_AzjolNerub.cpp 
Instance_BlackfathomDeeps.cpp 
Instance_BlackMorass.cpp 
Instance_BlackrockDepths.cpp 
Instance_BlackrockSpire.cpp 
Instance_BloodFurnace.cpp 
Instance_Botanica.cpp 
Instance_CullingOfStratholme.cpp 
Instance_Deadmines.cpp 
Instance_DireMaul.cpp 
Instance_DrakTharonKeep.cpp 
Instance_Gundrak.cpp 
Instance_HallsOfLightning.cpp 
Instance_HallsOfReflection.cpp 
Instance_HallsOfStone.cpp 
Instance_HellfireRamparts.cpp 
Instance_MagistersTerrace.cpp 
Instance_ManaTombs.cpp 
Instance_Mauradon.cpp 
Instance_Nexus.cpp 
Instance_OldHillsbradFoothills.cpp 
Instance_RagefireChasm.cpp 
Instance_RazorfenDowns.cpp 
Instance_ScarletMonastery.cpp 
Instance_Scholomance.cpp 
Instance_SethekkHalls.cpp 
Instance_ShadowLabyrinth.cpp 
Instance_ShadowfangKeep.cpp 
Instance_TheMechanar.cpp 
Instance_TheShatteredHalls.cpp 
Instance_TheSlavePens.cpp 
Instance_TheSteamvault.cpp 
Instance_TheUnderbog.cpp 
Instance_TheVioletHold.cpp 
Instance_Uldaman.cpp 
Instance_UtgardeKeep.cpp 
Instance_WailingCaverns.cpp 
Instance_TheStockade.cpp 
Instance_ZulFarrak.cpp 
../Common/Instance_Base.cpp 
../Common/Base.cpp 
Setup.cpp )

SET( headers
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
