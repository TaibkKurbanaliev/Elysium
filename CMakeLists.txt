cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Elysium)
set(CMAKE_CXX_STANDARD 23)
project(${PROJECT_NAME} VERSION 0.0.1)

add_executable(${PROJECT_NAME} Elysium/src/epch.cpp Elysium/Source.cpp)