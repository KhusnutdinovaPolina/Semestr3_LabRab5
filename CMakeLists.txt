cmake_minimum_required(VERSION 3.15)
project(LabRab5_sem3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(LabRab5_sem3
        main.cpp
        src/Move.cpp
        src/Rules.cpp
        src/HumanPlayer.cpp
        src/BotPlayer.cpp
        src/SmartBot.cpp
        src/PlayerFactory.cpp
        src/Game.cpp
        src/ConsoleUI.cpp
)