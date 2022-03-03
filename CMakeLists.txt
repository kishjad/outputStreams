cmake_minimum_required (VERSION 3.1)

project (outputStream)

set(OUTPUT_STREAM_TARGET_NAME ${PROJECT_NAME})
set(OUTPUT_STREAM_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
include_directories(${OUTPUT_STREAM_INCLUDE_DIRS})

message(${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})


# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    message(STATUS "Compiler is GNU C++")
    
# endif()
