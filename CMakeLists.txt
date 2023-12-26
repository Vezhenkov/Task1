cmake_minimum_required(VERSION 3.5)
project(Task1)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(Task1 main.cpp)

target_compile_features(Task1 PUBLIC cxx_std_17)
target_link_libraries(Task1 Boost::headers Boost::program_options)
