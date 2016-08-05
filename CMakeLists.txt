# cmake_minimum_required(VERSION <specify CMake version here>)
project(tetoris)

find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIR})


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -lncurses")

set(SOURCE_FILES main.c ui.c ui.h tetorimino.c tetorimino.h board.c board.h game.c game.h debug.c debug.h)
add_executable(tetoris ${SOURCE_FILES})
target_link_libraries(tetoris ${CURSES_LIBRARIES})
install(tetoriminos.dat .)
