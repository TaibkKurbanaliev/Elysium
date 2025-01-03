cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Elysium)
set(CMAKE_CXX_STANDARD 23)

set(SOURCES Elysium/src/epch.cpp Elysium/Source.cpp)
set(INCLUDES Elysium/src/epch.h)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set(CMAKE_SUPPRESS_REGENERATION TRUE)

project(${PROJECT_NAME} VERSION 0.0.1)

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Elysium/src)