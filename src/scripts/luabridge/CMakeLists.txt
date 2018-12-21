# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>

if(NOT BUILD_LUABRIDGE)
  message("\tluabridge was skipped because BUILD_LUABRIDGE is unchecked.")
  return()
endif()

# set up our project name
project(luabridge CXX)

#SRCS - contains the source files that compose this project.
set(SRCS
  interpreter/LUAEngine.cpp 
  luabridge_src/luabridge.cpp 
  object_functions/aura_functions.cpp
  object_functions/gameobject_functions.cpp
  object_functions/global_functions.cpp 
  object_functions/instance_functions.cpp 
  object_functions/item_functions.cpp 
  object_functions/object_functions.cpp 
  object_functions/packet_functions.cpp 
  object_functions/player_functions.cpp 
  object_functions/quest_functions.cpp 
  object_functions/register_functions.cpp 
  object_functions/spell_functions.cpp 
  object_functions/sql_functions.cpp 
  object_functions/taxi_functions.cpp 
  object_functions/unit_functions.cpp 
  object_functions/creature_functions.cpp
  object_functions/lua_hooks.cpp
)

set(HEADERS
  interpreter/class_decls.h
  interpreter/lua_defs.h
  interpreter/lua_instance.h
  interpreter/LUAEngine.h
  luabridge_src/luabridge.hpp
  object_functions/GlobalFunctions.h
  object_functions/lua_creature.h
  object_functions/lua_gameobject.h
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
   ${CMAKE_SOURCE_DIR}/dep/lualib
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${ZLIB_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED ${SRCS} ${HEADERS})
target_link_libraries(${PROJECT_NAME} world lualib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${ASCEMU_SCRIPTLIB_PATH} LIBRARY DESTINATION ${ASCEMU_SCRIPTLIB_PATH})
unset(sources)
unset(headers)
