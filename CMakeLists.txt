#cd /d D:/Programming/Git, cmake and linking/project0

cmake_minimum_required(VERSION 3.12)

function(Test_function required_arg)

	#functions and generator expressions (vpn): 
	#https://cliutils.gitlab.io/modern-cmake/chapters/basics/functions.html

	if(CMAKE_BUILD_TYPE STREQUAL Debug)
		set(MESSAGE "Pussy boy build")
	else()
		set(MESSAGE "Gigachad build")
	endif()
	
	message(STATUS "passed argument: ${required_arg}, build_version: ${MESSAGE}")
endfunction()

project(project0 DESCRIPTION "first cmake project" LANGUAGES CXX)

set(TREE_SOURCES Trees/tree.h Trees/tree.cpp)
add_library(Trees STATIC ${TREE_SOURCES})

Test_function("Penis argument")

add_executable(prog main.cpp)
target_link_libraries(prog PUBLIC Trees)

#turn on optimization 3 only for release build
target_compile_options(prog PRIVATE "$<$<CONFIG:Release>:-O3>")


