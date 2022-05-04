cmake_minimum_required(VERSION 3.22)

project(rebound VERSION 3.19.3 LANGUAGES C)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")

add_subdirectory("src")
