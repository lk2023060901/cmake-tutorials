cmake_minimum_required(VERSION 3.28)

project(zeus)

# 添加可执行文件
add_executable(zeus main.cpp)

# 添加子目录
add_subdirectory(mathlib)

# 设置包含目录
target_include_directories(zeus PRIVATE ${CMAKE_SOURCE_DIR}/include/mathlib)

# 链接库，假设库名为 mathlib
# 注意：这里我们不需要根据 Debug/Release 设置不同的路径，因为库文件的链接是在运行时解析的
target_link_libraries(zeus PRIVATE mathlib)
