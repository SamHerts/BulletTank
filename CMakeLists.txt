cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BulletTank)

set(CMAKE_CXX_STANDARD 17)

# Add the shared header directory
include_directories(SDL2/x64/include/SDL2)

add_executable(${PROJECT_NAME} main.cpp)
