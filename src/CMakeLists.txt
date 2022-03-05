

include_directories(${PROJECT_SOURCE_DIR}/include)
    
add_library(${OUTPUT_STREAM_TARGET_NAME} SHARED
    canvas.cpp
    plot_2D.cpp
    csmanip.cpp
    progress_bar.cpp
    helper_tools.cpp
)

set_property(TARGET ${OUTPUT_STREAM_TARGET_NAME} PROPERTY
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
target_link_libraries(osmanip_test_suite ${OUTPUT_STREAM_TARGET_NAME})
set_property(TARGET osmanip_test_suite PROPERTY
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)