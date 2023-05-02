cmake_minimum_required(VERSION 3.14)
project(Platformer_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Player.cpp Player.h Tile.cpp Tile.h TileMap.cpp TileMap.h Abstract_entity.h stdafx.cpp Enemy.cpp Enemy.h)
add_executable(Platformer_project ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Platformer_project sfml-system sfml-window sfml-graphics sfml-audio sfml-network)