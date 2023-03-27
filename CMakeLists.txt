cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BulletTank)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

file(GLOB App_Sources app/src/*.cpp)
file(GLOB Game_Sources game/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${App_Sources} ${Game_Sources})
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image ${SDL2_LIBRARIES})
