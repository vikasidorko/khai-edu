cmake_minimum_required(VERSION 3.20)
project(khai_edu)

set(CMAKE_CXX_STANDARD 20)

# Кодування для коректного відображення кирилиці в консолі CLion під Windows
if (WIN32)
    add_compile_options("-fexec-charset=windows-1251")
endif()

add_executable(khai_edu main.cpp)
