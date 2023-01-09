cmake_minimum_required(VERSION 3.24)
project(03_Moving_Point_SDL)

set(CMAKE_CXX_STANDARD 20)

add_executable(03_Moving_Point_SDL main.cpp)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(03_Moving_Point_SDL ${SDL2_LIBRARY})
