cmake_minimum_required(VERSION 3.5)

project(03.homework.src CXX)

add_subdirectory(libs)

set(SOURCES
    main.cpp
	game/run_game.cpp
	parser/game_options_parser.cpp
)

set(HEADERS
	main.h
	game/game.h
	parser/game_options_parser.h
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