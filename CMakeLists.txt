cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BulletTank)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/Users/SamHerts/CLionProjects/BulletTank/SDL2/x64/include/SDL2)
set(SDL2_LIB_DIR C:/Users/SamHerts/CLionProjects/BulletTank/SDL2/x64/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

file(GLOB App_Sources app/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${App_Soruces})
target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 )
