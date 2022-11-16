cmake_minimum_required(VERSION 3.23)
project(untitled35)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled35 XO_App.cpp
        XO_GameManager.cpp
            XO_Classes.hpp
        XO_Player.cpp
            XO_RandomPlayer.cpp
        XO_Board.cpp
        XO_ComputerPlayer.cpp)
