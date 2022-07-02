cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)
project(treedude)

add_executable(treedude src/treedude/main.cpp src/treedude/treedude.cpp src/treedude/treesegment.cpp src/treedude/tree.cpp src/treedude/util.cpp)
target_link_libraries(treedude ncurses)