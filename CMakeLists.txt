cmake_minimum_required(VERSION 3.21)

project(engine LANGUAGES CXX)

add_subdirectory(dependencies)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(editor)