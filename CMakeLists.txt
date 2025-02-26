cmake_minimum_required(VERSION 4.0 FATAL_ERROR)

# Set experimental flag to enable `import std` support from CMake.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  "a9e1cf81-9932-4810-974b-6eccaf14e457")

project(basecpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)

set(CMAKE_CXX_MODULE_STD 1)

add_subdirectory(src bin)

