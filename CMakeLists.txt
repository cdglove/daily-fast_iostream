cmake_minimum_required(VERSION 3.5)
project(daily.fast_iostream)

set(LIBRARY_NAME fast_iostream)

file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS include/*.hpp)
add_library(${LIBRARY_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}) 
target_include_directories(${LIBRARY_NAME} PUBLIC "include/")
target_include_directories(${LIBRARY_NAME} SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})

set(Daily_Libraries ${Daily_Libraries} ${LIBRARY_NAME} PARENT_SCOPE)