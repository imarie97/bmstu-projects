#
cmake_minimum_required(VERSION 2.8)
project(DiamondSquare)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)

include_directories(glfw/include)
include_directories(glm)
include_directories(stb)
include_directories(imgui)
include_directories(imgui/examples/opengl2_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -std=c++11")

set(IMGUI_SOURCE_FILES imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_demo.cpp imgui/examples/opengl2_example/imgui_impl_glfw_gl2.cpp)

set(SOURCE_FILES main.cpp Camera.cpp Camera.h DiamondSquare.cpp DiamondSquare.hpp Triangle.cpp Triangle.hpp Skybox.cpp Skybox.hpp Application.cpp Application.hpp stdafx.hpp stdafx.cpp Terrain.cpp Terrain.hpp ${IMGUI_SOURCE_FILES})

# change working dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(DiamondSquare ${SOURCE_FILES})

target_link_libraries(DiamondSquare
        glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
