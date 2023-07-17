# using current cmake version 3.25
# this cmake file will work starting version 3.11
cmake_minimum_required(VERSION 3.25)

# Set project name
set(PROJECT_NAME CPP-Exam)

# Project name
project(${PROJECT_NAME})

# GoogleTest requires at least C++14
# using current cpp and c standards
# change as needed
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# get version 1.13.0 of gtest from github
# update url to current version
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# enable gtest
enable_testing()

# set all project files here
set(
        Headers
        src/Block/Block.hpp
        src/Block/PlayBlock/PlayBlock.hpp
        src/Block/StartBlock/StartBlock.hpp
        src/Board/Board.hpp
        src/Game/Game.hpp
        src/GUI/GUI.hpp
        src/Solver/Solver.hpp
        src/Constants.hpp
)

set(
        Sources
        src/main.cpp
        src/Block/Block.cpp
        src/Block/PlayBlock/PlayBlock.cpp
        src/Block/StartBlock/StartBlock.cpp
        src/Board/Board.cpp
        src/Game/Game.cpp
        src/GUI/GUI.cpp
        src/Solver/Solver.cpp
)

add_library(
        ${PROJECT_NAME}
        STATIC
        ${Headers}
        ${Sources}
)

add_subdirectory(test)

include(GoogleTest)