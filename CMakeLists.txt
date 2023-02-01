cmake_minimum_required(VERSION 3.18)

project(branch_bound LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/BranchAndBound.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Exception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Matrix.h
    )

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BranchAndBound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )

add_executable(branch_bound ${SOURCES} ${HEADERS})