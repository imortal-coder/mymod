cmake_minimum_required(VERSION 3.22.1)
project("mymod")

include_directories(${CMAKE_SOURCE_DIR}/include)

# اضافه کردن سورس‌های Dobby
file(GLOB_RECURSE DOBBY_SOURCES 
    ${CMAKE_SOURCE_DIR}/source/*.c
    ${CMAKE_SOURCE_DIR}/source/*.cc
    ${CMAKE_SOURCE_DIR}/source/*.cpp
)

# حذف فایل‌های پلتفرم‌های غیراندروید
list(FILTER DOBBY_SOURCES EXCLUDE REGEX ".*/(Windows|Darwin|iOS|tests|docs|examples)/.*")

add_library(${CMAKE_PROJECT_NAME} SHARED 
    native-lib.c
    ${DOBBY_SOURCES}
)

# لینک کردن کتابخانه‌های لازم
target_link_libraries(${CMAKE_PROJECT_NAME} 
    log
    c++_static
    android
)
