# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>

# set up our project name
project(logon CXX)

set(sources
  AccountCache.cpp
  AuthSocket.cpp
  AutoPatcher.cpp
  LogonCommServer.cpp
  LogonConsole.cpp
  LogonOpcodes.cpp
  LogonStdAfx.cpp
  Main.cpp
  RealmList.cpp)

 SET( headers
	AccountCache.h
	AuthSocket.h
	AuthStructs.h
	AutoPatcher.h
	LogonCommServer.h
	LogonConsole.h
	LogonOpcodes.h
	LogonStdAfx.h
	Main.h
	RealmList.h
	PeriodicFunctionCall_Thread.h
   )

if(WIN32)
   set(SRC_LOGON_PROJECT ${SRC_LOGON_PROJECT} ${CMAKE_CURRENT_SOURCE_DIR}/resources.rc)
endif()

source_group(logon FILES ${SRC_LOGON_PROJECT})

include_directories(
   ${CMAKE_SOURCE_DIR}/src/shared
   ${ZLIB_INCLUDE_DIRS}
   ${OPENSSL_INCLUDE_DIR}
   ${PCRE_INCLUDE_DIR}
   ${MYSQL_INCLUDE_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(${EXTRA_LIBS_PATH} ${DEPENDENCY_LIBS})

if(WIN32)
    set(sources ${sources} resources.rc)
endif()

add_executable(${PROJECT_NAME} ${sources} ${headers})

if(USE_PCH AND PCHSupport_FOUND)
    ADD_NATIVE_PRECOMPILED_HEADER(${PROJECT_NAME} LogonStdAfx.h ${CMAKE_CURRENT_SOURCE_DIR}/LogonStdAfx.cpp)
endif()
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/LogonConf.h.in ${CMAKE_CURRENT_SOURCE_DIR}/LogonConf.h)

#Link our shared lib.
target_link_libraries(${PROJECT_NAME} shared ${MYSQL_LIBRARIES} ${ZLIB_LIBRARIES} ${PCRE_LIBRARIES})

#Provide make install rules.
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)

unset(sources)
unset(headers)
