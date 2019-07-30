cmake_minimum_required(VERSION 2.6)
project(config)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(config_io SHARED src/config_io.cpp)

add_executable(config test/main.cpp)

target_link_libraries(config config_io)



