cmake_minimum_required(VERSION 3.28)


project(zeus)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS zeus DESTINATION ${CMAKE_BINARY_DIR}/bin)