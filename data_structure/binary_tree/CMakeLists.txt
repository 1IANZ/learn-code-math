cmake_minimum_required(VERSION 3.10.0)
project(Demo VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-finput-charset=utf-8)
endif()

file(GLOB_RECURSE  SOURCES "src/*.cpp")
add_executable(Demo ${SOURCES})

target_include_directories(Demo PRIVATE src/include)



