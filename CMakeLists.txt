cmake_minimum_required(VERSION 3.23)

project(2048)

add_subdirectory(src)
add_subdirectory(test)

add_executable(2048_main main.cc)

target_link_directories(2048_main PRIVATE core_lib)