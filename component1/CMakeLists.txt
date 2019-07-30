cmake_minimum_required(VERSION 3.8)

include_directories(include ../include ../..)

add_definitions(-DBUILD_SHARED)

add_library(component1 SHARED
	src/testcomponent1.cpp)

 set_target_properties(component1 PROPERTIES OUTPUT_NAME "component1")
