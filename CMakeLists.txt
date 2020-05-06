cmake_minimum_required(VERSION 3.14)
project(pllfv)

find_library(PCRE_LIBRARY pcre)


set(CMAKE_CXX_STANDARD 11)

add_executable(pllfv main.cpp pllfv.h pllfv.cpp)

target_link_libraries(pllfv ${PCRE_LIBRARY})