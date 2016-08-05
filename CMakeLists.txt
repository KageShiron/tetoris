# cmake_minimum_required(VERSION <specify CMake version here>)
project(tetoris)

find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIR})


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -lncurses")

set(SOURCE_FILES main.c ui.c ui.h tetorimino.c tetorimino.h board.c board.h game.c game.h debug.c debug.h)
add_executable(tetoris ${SOURCE_FILES})
target_link_libraries(tetoris ${CURSES_LIBRARIES})
add_custom_target (copy_resources
        COMMAND
        ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/tetoriminos.dat
        ${CMAKE_BINARY_DIR}/tetoriminos.dat)
add_dependencies(tetoris copy_resources)