cmake_minimum_required(VERSION 3.8)

include_directories(include ../include ../..)

add_definitions(-DBUILD_SHARED)

add_library(component2 SHARED
	src/testcomponent2.cpp)

 set_target_properties(component2 PROPERTIES OUTPUT_NAME "component2")
