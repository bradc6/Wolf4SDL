#Use the lastest Cmake policy on FindCmake Includes
cmake_policy(SET CMP0017 NEW)

#Set the name of the project that we are
#going to reference throughout the rest of the
#codebase.
project(Wolf4SDL)
cmake_minimum_required(VERSION 2.8.6)


#Sets the directory for cmake to find Cmake configration packages,
#these packages allow for cmake to find libraries that are not included
#in the standard installation of Cmake. The standard packages can be
#found @ /usr/share/cmake-2.8/Modules
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})

#These variables will act as our list of include folders and linker flags
#for compilation
set(Wolf4SDLLinkerFlags)
set(Wolf4SDLIncludeDirectories)
set(Wolf4SDLLinkerDirectories)

###Platform dependant include/linker Directories
###Add fakeroot directores for different platforms
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    list(APPEND DAFTEngineIncludeDirectories "$ENV{HOMEPATH}/dev/fakeroot/include")
    list(APPEND DAFTEngineLinkerDirectories "$ENV{HOMEPATH}/dev/fakeroot/lib")
    include_directories("C:/fakeroot/include")
    link_directories("C:/fakeroot/lib")
    add_definitions(-DTARGETWINDOWS=1)
    if(MSVC)
        add_definitions(/arch:SSE2)
    endif(MSVC)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    list(APPEND DAFTEngineIncludeDirectories "~/dev/fakeroot/include")
    list(APPEND DAFTEngineLinkerDirectories "~/dev/fakeroot/lib")
    list(APPEND DAFTEngineIncludeDirectories "/opt/local/include")
    list(APPEND DAFTEngineLinkerDirectories "/opt/local/lib")
    list(APPEND DAFTEngineLinkerFlags "-framework Cocoa")
    list(APPEND CMAKE_PREFIX_PATH /opt/local)
    add_definitions(-DTARGETMACOSX=1)
else()
    list(APPEND DAFTEngineIncludeDirectories "~/dev/fakeroot/include")
    list(APPEND DAFTEngineLinkerDirectories "~/dev/fakeroot/lib")
endif()

find_package(SDL REQUIRED)
list(APPEND DAFTEngineIncludeDirectories "${SDL_INCLUDE_DIR}")
list(APPEND DAFTEngineLinkerFlags "${SDL_LIBRARY}")