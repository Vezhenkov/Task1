cmake_minimum_required(VERSION 3.27)
project(Task1)

set(CMAKE_CXX_STANDARD 17)
add_executable(Task1 main.cpp)

find_package(Boost COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(Task1 ${Boost_LIBRARIES})
else(Boost_FOUND)
    message("\nBoost not found\n")
endif(Boost_FOUND)
