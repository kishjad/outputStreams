

include_directories(${PROJECT_SOURCE_DIR}/include)
    
add_library(osmanip SHARED
    canvas.cpp
    plot_2D.cpp
    csmanip.cpp
    progress_bar.cpp
    helper_tools.cpp
)

set_property(TARGET osmanip PROPERTY
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    #Turn to max optimizations
    message(STATUS "Turning to max optimizations")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-unused-parameter -O3 -DNDEBUG")

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    #debug build
    message(STATUS "Debug build")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-unused-parameter -O0 -g")
endif()

add_executable(osmanip_test_suite main.cpp)
target_link_libraries(osmanip_test_suite osmanip)
set_property(TARGET osmanip_test_suite PROPERTY
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)