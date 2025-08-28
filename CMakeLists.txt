cmake_minimum_required(VERSION 3.10)
project(mineclone)

set(CMAKE_CXX_STANDARD 17)

# Includes
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Libs
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Collect all .cpp and .c
file(GLOB_RECURSE SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

add_executable(mineclone ${SRC_FILES})

target_link_libraries(mineclone PRIVATE glfw3 opengl32)
target_include_directories(mineclone PRIVATE ${CMAKE_SOURCE_DIR}/include)

