# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>

if(NOT BUILD_SERVERSTATUSPLUGIN )
  message("\tServerStatusPlugin was skipped because BUILD_SERVERSTATUSPLUGIN is unchecked.")
  return()
endif(NOT BUILD_SERVERSTATUSPLUGIN)

# set up our project name
project(ServerStatusPlugin CXX)

#sources -contains source files for our library.
set(sources
   ServerStatusPlugin.cpp
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
add_library(${PROJECT_NAME} SHARED ${sources} )

target_link_libraries(${PROJECT_NAME} world)


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${ASCEMU_SCRIPTLIB_PATH} LIBRARY DESTINATION ${ASCEMU_SCRIPTLIB_PATH})
unset(sources)
unset(headers)
