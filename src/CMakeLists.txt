cmake_minimum_required(VERSION 3.5)

project(03.homework.src CXX)

add_subdirectory(libs)

add_definitions(-DDEBUG_BUILD)

set(SOURCES
    main.cpp
	game/run_game.cpp
	game_settings/game_settings.cpp
	debugger/debugger.cpp
)

set(HEADERS
	main.h
	debugger.h
	game/game.h
	game_settings/game_settings.hpp
	debugger/debugger.hpp
)

add_executable(game ${SOURCES} ${HEADERS})

set_target_properties(game PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	game
	PRIVATE
	${CMAKE_SOURCE_DIR}/libs
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_BINARY_DIR}/src
)

target_link_libraries(game PRIVATE
	randomizer
	scores_manager
	value_checker
	stdc++fs
#	c++experimental
)