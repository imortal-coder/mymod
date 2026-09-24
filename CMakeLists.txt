cmake_minimum_required(VERSION 3.22.1)
project("mymod")

add_library(${CMAKE_PROJECT_NAME} SHARED native-lib.c)

# مسیر Dobby (چون فایل‌ها تو ریشه هستن، نه تو پوشه Dobby)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_SOURCE_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} dobby log)
