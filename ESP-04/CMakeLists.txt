cmake_minimum_required(VERSION 3.28)

project(zeus VERSION 0.1)

configure_file(config.h.in ${CMAKE_SOURCE_DIR}/config.h)

add_executable(zeus main.cpp)

target_include_directories(zeus
    PUBLIC ${CMAKE_SOURCE_DIR}
)