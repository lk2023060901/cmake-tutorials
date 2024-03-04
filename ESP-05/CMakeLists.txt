cmake_minimum_required(VERSION 3.28)

project(zeus VERSION 0.1)

configure_file(config.h.in ${CMAKE_SOURCE_DIR}/config.h)

add_executable(zeus main.cpp)

target_include_directories(zeus
    PUBLIC ${CMAKE_SOURCE_DIR}
)

option(USE_MATHLIB "A simple library for adding 2 floats." ON)

if (USE_MATHLIB)
    add_subdirectory(mathlib)
    target_compile_definitions(zeus PRIVATE USE_MATHLIB)
    target_include_directories(zeus
        PRIVATE ${CMAKE_SOURCE_DIR}/include/mathlib
    )
    target_link_directories(zeus
        PRIVATE lib/mathlib/$<CONFIG>
    )
    target_link_libraries(zeus PRIVATE mathlib)
endif()