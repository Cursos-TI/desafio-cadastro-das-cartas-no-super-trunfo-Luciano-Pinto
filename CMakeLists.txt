cmake_minimum_required(VERSION 3.10)
project(SuperTrunfo C)

set(CMAKE_C_STANDARD 11)

# Include headers from the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Automatically find all .c files in the 'src' directory
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false "${CMAKE_SOURCE_DIR}/src/*.c")

# Ensure CMake regenerates when new files are added
configure_file(
        ${CMAKE_SOURCE_DIR}/CMakeLists.txt
        ${CMAKE_BINARY_DIR}/CMakeLists.txt.copy
        COPYONLY
)

# Add the found source files to the executable
add_executable(super_trunfo ${SOURCES})

set_target_properties(super_trunfo PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Enable compile_commands.json for tools like clangd or SonarQube
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set Debug as the default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

if(NOT CMAKE_C_FLAGS_DEBUG)
    set(CMAKE_C_FLAGS_DEBUG "-g")
endif()
