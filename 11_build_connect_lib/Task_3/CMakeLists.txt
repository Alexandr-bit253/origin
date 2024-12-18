cmake_minimum_required(VERSION 3.21)
project(LeaverExample)

# Создаем динамическую библиотеку
add_library(leaver SHARED leaver.h leaver.cpp)

# Создаем исполняемый файл
add_executable(main main.cpp)

# Линкуем динамическую библиотеку с исполняемым файлом
target_link_libraries(main leaver)
