add_executable(RacingSimulator main.cpp)

target_link_libraries(RacingSimulator PRIVATE RacingLib)
target_include_directories(RacingSimulator PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)