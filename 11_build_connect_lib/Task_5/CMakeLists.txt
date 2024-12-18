cmake_minimum_required(VERSION 3.21)
project(FigureConsoleExe)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(GeometricFigure SHARED 
    equilateral_triangle.cpp 
    figure.cpp 
    isosceles_triangle.cpp 
    parallelogram.cpp 
    quadrilateral.cpp 
    rectangle.cpp
    rhombus.cpp 
    right_triangle.cpp 
    square.cpp 
    triangle.cpp 
    geometricFigureDll.h)

add_executable(FigureConsoleExe main.cpp)

target_link_libraries(FigureConsoleExe GeometricFigure)