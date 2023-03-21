cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BulletTank)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# Add the shared header directory
include_directories(SDL2_x86_mingw32)

add_executable(${PROJECT_NAME} main.cpp)
