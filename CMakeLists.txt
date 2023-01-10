cmake_minimum_required(VERSION 3.24)
project(Labo_Snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labo_Snake main.cpp GameMaster.cpp GameMaster.h Snake.cpp Snake.h Fenetre.cpp
        Fenetre.h Annexe.cpp Annexe.h Pixel.cpp Pixel.h)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(Labo_Snake ${SDL2_LIBRARY})
