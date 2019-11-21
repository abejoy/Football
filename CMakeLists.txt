cmake_minimum_required(VERSION 3.15)
project(Football)

set(CMAKE_CXX_STANDARD 14)

add_executable(Football main.cpp Football.cpp Football.h FootballTester.cpp FootballTester.h FootballTesterMain.cpp TesterBase.cpp TesterBase.h)