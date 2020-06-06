cmake_minimum_required(VERSION 3.16)
project(Task_8)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_8 main.cpp entities/Brink.cpp entities/Brink.h entities/Chunk.cpp entities/Chunk.h entities/CubeRubi.cpp entities/CubeRubi.h solveUtil/Automaton.cpp solveUtil/Automaton.h solveUtil/Solver.cpp solveUtil/Solver.h)

target_link_libraries(Task_8 -lOpenGL32 -lfreeGLUT -lGLU -lGL)