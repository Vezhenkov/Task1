cmake_minimum_required(VERSION 3.27)
project(Task1)

find_package(Boost REQUIRED COMPONENTS program_options)

set(CMAKE_CXX_STANDARD 17)
add_executable(Task1 main.cpp)

target_link_libraries(Task1 Boost::headers Boost::program_options)
