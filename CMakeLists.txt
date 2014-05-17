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
    list(APPEND Wolf4SDLIncludeDirectories "$ENV{HOMEPATH}/dev/fakeroot/include")
    list(APPEND Wolf4SDLLinkerDirectories "$ENV{HOMEPATH}/dev/fakeroot/lib")
    include_directories("C:/fakeroot/include")
    link_directories("C:/fakeroot/lib")
    add_definitions(-DTARGETWINDOWS=1)
    if(MSVC)
        add_definitions(/arch:SSE2)
    endif(MSVC)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    list(APPEND Wolf4SDLIncludeDirectories "~/dev/fakeroot/include")
    list(APPEND Wolf4SDLLinkerDirectories "~/dev/fakeroot/lib")
    list(APPEND Wolf4SDLIncludeDirectories "/opt/local/include")
    list(APPEND Wolf4SDLLinkerDirectories "/opt/local/lib")
    list(APPEND Wolf4SDLLinkerFlags "-framework Cocoa")
    list(APPEND CMAKE_PREFIX_PATH /opt/local)
    add_definitions(-DTARGETMACOSX=1)
else()
    list(APPEND Wolf4SDLIncludeDirectories "~/dev/fakeroot/include")
    list(APPEND Wolf4SDLLinkerDirectories "~/dev/fakeroot/lib")
endif()

find_package(SDL2 REQUIRED)
list(APPEND Wolf4SDLIncludeDirectories"${SDL2_INCLUDE_DIR}")
list(APPEND Wolf4SDLLinkerFlags "${SDL2_LIBRARY}")

find_package(SDL2_mixer REQUIRED)
list(APPEND Wolf4SDLIncludeDirectories "${SDLMIXER2_INCLUDE_DIR}")
list(APPEND Wolf4SDLLinkerFlags "${SDL2_MIXER_LIBRARIES}")

#Include all the found Include/Linker directories
include_directories(${Wolf4SDLIncludeDirectories})
link_directories(${Wolf4SDLLinkerDirectories})

#Source directory variables
#These are used to allow for changing file paths much
#easier then hard coding them
set(WOLF4SDL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(WOLF4SDL_PLATFORM_DIR ${WOLF4SDL_SOURCE_DIR}/Platforms)
set(WOLF4SDL_GP2X_DIR ${WOLF4SDL_SOURCE_DIR}/GP2X)

set(Wolf4SDL-Source
	${WOLF4SDL_SOURCE_DIR}/audiosod.h
	${WOLF4SDL_SOURCE_DIR}/audiowl6.h
	${WOLF4SDL_SOURCE_DIR}/f_spear.h
	${WOLF4SDL_SOURCE_DIR}/fmopl.cpp
	${WOLF4SDL_SOURCE_DIR}/fmopl.h
	${WOLF4SDL_SOURCE_DIR}/foreign.h
	${WOLF4SDL_SOURCE_DIR}/gfxv_apo.h
	${WOLF4SDL_SOURCE_DIR}/gfxv_sod.h
	${WOLF4SDL_SOURCE_DIR}/gfxv_wl6.h
	${WOLF4SDL_SOURCE_DIR}/gp2x.h
	${WOLF4SDL_SOURCE_DIR}/id_ca.cpp
	${WOLF4SDL_SOURCE_DIR}/id_ca.h
	${WOLF4SDL_SOURCE_DIR}/id_in.cpp
	${WOLF4SDL_SOURCE_DIR}/id_in.h
	${WOLF4SDL_SOURCE_DIR}/id_pm.cpp
	${WOLF4SDL_SOURCE_DIR}/id_pm.h
	${WOLF4SDL_SOURCE_DIR}/id_sd.cpp
	${WOLF4SDL_SOURCE_DIR}/id_sd.h
	${WOLF4SDL_SOURCE_DIR}/id_us.h
	${WOLF4SDL_SOURCE_DIR}/id_us_1.cpp
	${WOLF4SDL_SOURCE_DIR}/id_vh.cpp
	${WOLF4SDL_SOURCE_DIR}/id_vh.h
	${WOLF4SDL_SOURCE_DIR}/id_vl.cpp
	${WOLF4SDL_SOURCE_DIR}/id_vl.h
	${WOLF4SDL_SOURCE_DIR}/sdl_winmain.cpp
	${WOLF4SDL_SOURCE_DIR}/signon.cpp
	${WOLF4SDL_SOURCE_DIR}/version.h
	${WOLF4SDL_SOURCE_DIR}/wl_act1.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_act2.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_agent.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_atmos.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_atmos.h
	${WOLF4SDL_SOURCE_DIR}/wl_cloudsky.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_cloudsky.h
	${WOLF4SDL_SOURCE_DIR}/wl_debug.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_def.h
	${WOLF4SDL_SOURCE_DIR}/wl_dir3dspr.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_draw.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_floorceiling.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_game.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_inter.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_main.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_menu.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_menu.h
	${WOLF4SDL_SOURCE_DIR}/wl_parallax.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_play.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_shade.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_shade.h
	${WOLF4SDL_SOURCE_DIR}/wl_state.cpp
	${WOLF4SDL_SOURCE_DIR}/wl_text.cpp
	)

add_executable(${CMAKE_PROJECT_NAME} 
		${Wolf4SDL-Source}
	)

target_link_libraries(${CMAKE_PROJECT_NAME} ${Wolf4SDLLinkerFlags})