cmake_minimum_required(VERSION 3.28)

project(zeus VERSION 0.1)

add_subdirectory(external/glfw)

find_library(myglfwlib glew NAMES glew2 GLEW GLEW2 DOC "glew library")

if (${myglfwlib} STREQUAL myglfwlib-NOTFOUND)
    message(FATAL_ERROR "no glfw, sad day")
else()
    message(STATUS "glfw found! as ${myglfwlib}")
endif()

add_executable(zeus main.cpp)

target_include_directories(zeus
    PUBLIC ${CMAKE_SOURCE_DIR}
)

