cmake_minimum_required (VERSION 3.1)

project (outputStream VERSION 1.0 LANGUAGES CXX)

message(${CMAKE_CXX_COMPILER_ID})
set(OUTPUT_STREAM_TARGET_NAME ${PROJECT_NAME})
set(OUTPUT_STREAM_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
include_directories(${OUTPUT_STREAM_INCLUDE_DIRS})