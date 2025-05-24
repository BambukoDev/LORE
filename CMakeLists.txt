macro(c_b arg state)
    set(${arg} ${state} CACHE BOOL "" FORCE)
endmacro()

cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0048 NEW)

# set the project name
project(LORE VERSION 0.0.1 LANGUAGES CXX C)

# setup C++17
set(CMAKE_CXX_STANDARD_DEFAULT 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_CXX_EXTENSIONS 0)

c_b(BUILD_SHARED_LIBS 0)

c_b(SDL2_DISABLE_INSTALL 1)
c_b(SDL2_DISABLE_UNINSTALL 1)
c_b(SDL_SHARED 0)
add_subdirectory(extern/SDL)

set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(
    LORE
    main.cpp
)
target_compile_features(LORE INTERFACE cxx_std_17)
target_link_libraries(LORE SDL3::SDL3-static)
target_include_directories(
    LORE
    PUBLIC extern/SDL/include/SDL3
    PUBLIC source
)
