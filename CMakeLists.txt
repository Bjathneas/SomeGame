cmake_minimum_required(VERSION 3.29)
project(Game)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG_MODE)
endif ()

add_subdirectory(deps/bEngine_lib)

include_directories(include)

add_executable(Game src/main.cpp)

target_link_libraries(Game bEngine_lib)
