cmake_minimum_required(VERSION 3.16)

project(testing LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/
    )

add_subdirectory(src)

add_executable(run main.c $<TARGET_OBJECTS:vector>)


