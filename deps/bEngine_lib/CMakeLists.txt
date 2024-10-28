cmake_minimum_required(VERSION 3.29)
project(bEngine_lib)

find_package(OpenGL REQUIRED)
find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(tomlplusplus REQUIRED IMPORTED_TARGET tomlplusplus)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(DEBUG_MODE)
endif ()

add_library(bEngine_lib SHARED
        src/Core/Application.cpp
        src/Utils/Logger.cpp
        include/bEngine/Core/ResourceManager.h
        src/Core/Config.cpp
        src/Core/Input.cpp
        src/Utils/Math.cpp
        src/Graphics/Color.cpp
        src/Graphics/Shader.cpp
        src/Graphics/Camera.cpp
        src/imgui_impl_glfw.cpp
        src/imgui_impl_opengl3.cpp
        src/Graphics/GFX.cpp
)

target_include_directories(bEngine_lib PUBLIC include)

target_link_libraries(bEngine_lib glfw)
target_link_libraries(bEngine_lib OpenGL::GL)
target_link_libraries(bEngine_lib glad::glad)
target_link_libraries(bEngine_lib imgui::imgui)
target_link_libraries(bEngine_lib PkgConfig::tomlplusplus)