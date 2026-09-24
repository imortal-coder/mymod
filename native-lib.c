cmake_minimum_required(VERSION 3.22.1)
project("mymod")

add_library(${CMAKE_PROJECT_NAME} SHARED native-lib.c)

include_directories(${CMAKE_SOURCE_DIR}/Dobby/include)
add_subdirectory(${CMAKE_SOURCE_DIR}/Dobby)

target_link_libraries(${CMAKE_PROJECT_NAME} dobby log)
