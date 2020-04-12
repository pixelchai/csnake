cmake_minimum_required(VERSION 3.15)
project(csnake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

find_package(SDL2 REQUIRED)
include_directories(csnake ${SDL2_INCLUDE_DIRS})

add_executable(csnake main.cpp Game.cpp Game.h Field.cpp Field.h)
target_link_libraries(csnake SDL2::SDL2) # not sure why SDL2::SDL2, but it works (${SDL2_LIBRARIES} did not work)