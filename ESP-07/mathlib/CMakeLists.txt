cmake_minimum_required(VERSION 3.28)

project(mathlib)

# 添加库，默认生成的是静态库
add_library(mathlib adder.h adder.cpp)

# 使用 GLOB_RECURSE 来自动收集所有头文件
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

# 遍历所有头文件并拷贝
foreach(HEADER ${HEADER_FILES})
    file(RELATIVE_PATH REL_HEADER ${CMAKE_CURRENT_SOURCE_DIR} ${HEADER})
    get_filename_component(DIR ${REL_HEADER} DIRECTORY)
    set(DEST_DIR ${CMAKE_SOURCE_DIR}/include/mathlib/${DIR})
    file(MAKE_DIRECTORY ${DEST_DIR})
    add_custom_command(TARGET mathlib PRE_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${HEADER} ${DEST_DIR})
endforeach()

# 这种方式不支持按目录结构进行安装，所有文件都会放在同一个目录下
#install(FILES 
#    ${HEADER_FILES}
#    DESTINATION ${CMAKE_BINARY_DIR}/include/mathlib)

# 可以按照原来的目录结构，安装到指定路径下
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${CMAKE_BINARY_DIR}/include/mathlib
    FILES_MATCHING PATTERN "*.h"
)

# 根据构建类型动态设置目标目录并拷贝库文件
add_custom_command(TARGET mathlib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying mathlib to ${CMAKE_SOURCE_DIR}/lib/mathlib/$<CONFIG>"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/lib/mathlib/$<CONFIG>"
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:mathlib> "${CMAKE_SOURCE_DIR}/lib/mathlib/$<CONFIG>"
    COMMENT "Copying mathlib to ${CMAKE_SOURCE_DIR}/lib/mathlib/$<CONFIG> based on build type.")