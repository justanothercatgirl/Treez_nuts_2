cmake_minimum_required(VERSION 3.12)

project(project0 DESCRIPTION "first cmake project" LANGUAGES CXX)

add_library(Trees STATIC "Trees/tree.cpp" "Trees/tree.h")

add_executable(prog main.cpp)
target_link_libraries(prog PUBLIC Trees)
