set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)
project(main)
#Add additional files to set with a space 
set(SOURCE main.cpp Card.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})