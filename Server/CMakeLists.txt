cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 99)
add_executable(Server main.c ${SOURCE_FILES} Server.h)
target_link_libraries(Server ${CMAKE_SOURCE_DIR}/libjson-c.a)


