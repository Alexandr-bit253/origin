file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_library(RacingLib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_compile_definitions(RacingLib PRIVATE RACINGLIBRARY_EXPORTS)

if(MSVC)
    target_compile_options(RacingLib PRIVATE "/Zc:wchar_t-")
endif()

target_include_directories(RacingLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)