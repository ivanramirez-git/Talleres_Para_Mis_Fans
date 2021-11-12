cmake_minimum_required(VERSION 3.20)
project(Globos)

set(CMAKE_CXX_STANDARD 14)

include_directories(modelo)

add_executable(Globos
        modelo/Consumo.h
        modelo/Data.h
        modelo/Globo.h
        main.cpp)
