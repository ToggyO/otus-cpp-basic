cmake_minimum_required(VERSION 3.5)

project(03.homework)

# Add the variables we need
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# Specify the configuration file from which the header file will be generated
configure_file(config.h.in ${CMAKE_CURRENT_BINARY_DIR}/src/config.h @ONLY)

# Add app sources
add_subdirectory(src)

