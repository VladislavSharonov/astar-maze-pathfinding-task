cmake_minimum_required(VERSION 3.27)
project(Maze)

set(CMAKE_CXX_STANDARD 11)

add_executable(Maze main.cpp
        AStarGraph.cpp
        AStarGraph.h
        Point.cpp
        Point.h
        Maze.cpp
        Maze.h
        AStarNode.cpp
        AStarNode.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
