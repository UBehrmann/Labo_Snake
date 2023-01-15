cmake_minimum_required(VERSION 3.24)
project(Labo_SDL)

set(CMAKE_CXX_STANDARD 20)

set(SDL2_INCLUDE_DIR C:/libs/sdl2/include)
set(SDL2_LIB_DIR C:/libs/sdl2/lib/x64)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(PRJ_SOURCE_FILES
        main.cpp
        Annexe.cpp Annexe.h Coordonnee.cpp Coordonnee.h Snake.cpp Snake.h Fenetre.cpp Fenetre.h GameMaster.cpp GameMaster.h)

add_executable(${PROJECT_NAME}
        ${PRJ_SOURCE_FILES}
        )
target_link_libraries(${PROJECT_NAME}
        SDL2main
        SDL2
        )