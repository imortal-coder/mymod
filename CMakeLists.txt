cmake_minimum_required(VERSION 3.22.1)
project("mymod")

add_library(${CMAKE_PROJECT_NAME} SHARED native-lib.c)

# اضافه کردن مسیر هدرهای Dobby
include_directories(${CMAKE_SOURCE_DIR}/include)

# اضافه کردن سورس‌های Dobby به صورت دستی
file(GLOB_RECURSE DOBBY_SOURCES 
    ${CMAKE_SOURCE_DIR}/source/*.c
    ${CMAKE_SOURCE_DIR}/source/*.cc
    ${CMAKE_SOURCE_DIR}/source/*.cpp
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${DOBBY_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} log)
