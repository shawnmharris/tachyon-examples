cmake_minimum_required(VERSION 3.8)

project(component-tester)

include_directories(../.. ../include)

add_executable(component-tester src/component-tester.cpp)

target_link_libraries(component-tester ${CMAKE_DL_LIBS})
