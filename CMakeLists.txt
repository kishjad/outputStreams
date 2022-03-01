cmake_minimum_required (VERSION 3.22.1)
project (osmanip)

include_directories(src)
include_directories(include)
message(${CMAKE_CURRENT_BINARY_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})


# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    message(STATUS "Compiler is GNU C++")
    add_definitions(-std=c++17)
# endif()

add_library(osmanip SHARED
./src/graphics/canvas.cpp
./src/graphics/plot_2D.cpp
./src/manipulators/csmanip.cpp
./src/progressbar/progress_bar.cpp
./src/utils/helper_tools.cpp
)

add_executable(osmanip_test_suite src/main.cpp)
target_link_libraries(osmanip_test_suite osmanip)