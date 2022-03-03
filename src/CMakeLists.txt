

include_directories(${PROJECT_SOURCE_DIR}/include)
    
add_definitions(-std=c++17)
add_library(osmanip SHARED
    canvas.cpp
    plot_2D.cpp
    csmanip.cpp
    progress_bar.cpp
    helper_tools.cpp
)


add_executable(osmanip_test_suite main.cpp)
target_link_libraries(osmanip_test_suite osmanip)