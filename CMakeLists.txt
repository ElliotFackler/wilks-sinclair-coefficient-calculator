cmake_minimum_required(VERSION 3.10)
project(wilks-sinclair)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(imgui
 GIT_REPOSITORY https://github.com/ocornut/imgui.git
 GIT_TAG v1.91.6) # Or the latest version

 FetchContent_Declare(implot
 GIT_REPOSITORY https://github.com/epezent/implot.git
 GIT_TAG v0.16)

 FetchContent_Declare(GLFW
 GIT_REPOSITORY https://github.com/glfw/glfw.git
 GIT_TAG 3.4)

 # Download the libraries from github
 FetchContent_MakeAvailable(imgui implot glfw)

add_executable(wilks-sinclair src/main.cpp src/core/utils.cpp)

target_include_directories(wilks-sinclair PRIVATE src/core)
