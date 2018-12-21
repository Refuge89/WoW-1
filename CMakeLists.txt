# Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org>
project(Ascemu)
cmake_minimum_required(VERSION 2.8)

# set runtime binary where all compiled (before install) binary will compiled in
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set build type on unix if it wasn't defined by user
if(UNIX)
    if(NOT CMAKE_BUILD_TYPE)
        message(STATUS "Build configuration was not detected, setting to \"Release\"")
        set(CMAKE_BUILD_TYPE "Release")
    else()
        message(STATUS "Detected ${CMAKE_BUILD_TYPE} configuration")
    endif()
endif()

# cmake options
include(${CMAKE_SOURCE_DIR}/cmake/Options.cmake)

# perform system tasks
include(${CMAKE_SOURCE_DIR}/cmake/CheckSystem.cmake)

# cmake Dev
IF(BUILD_SCRIPTS2)
message("* Recursing into dev.")
include(${CMAKE_SOURCE_DIR}/cmake/Dev.cmake)
ENDIF(BUILD_SCRIPTS2)

# set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# add dependecies
add_subdirectory(dep)

# add executables
add_subdirectory(src)

# add script libraries
add_subdirectory(src/scripts)

IF(BUILD_SCRIPTS2)
add_subdirectory(src/scripts2)
ENDIF(BUILD_SCRIPTS2)

# install libraries for windows build (libmysql.dll, libey32.dll)
if(WIN32)
    install(FILES ${INSTALLED_DEPENDENCIES} DESTINATION .)
endif()
