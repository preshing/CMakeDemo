cmake_minimum_required(VERSION 3.1)
project(CMakeDemo)

# Write demo-config.h
message("Generating header file: ${CMAKE_BINARY_DIR}/demo-config.h")
set(DEMO_ENABLE_MULTISAMPLE 0 CACHE BOOL "Enable multisample anti-aliasing")
configure_file(demo-config.h.in "${CMAKE_BINARY_DIR}/demo-config.h")

# Find SDL2 and OpenGL
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
find_package(SDL2 REQUIRED COMPONENTS main)
if(NOT WIN32)
    find_package(OpenGL REQUIRED)
endif()

# Define executable target
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2main_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${CMAKE_BINARY_DIR})
add_executable(CMakeDemo Main.cpp gl2/Context.cpp)
target_link_libraries(CMakeDemo ${SDL2_LIBS} ${OPENGL_LIBRARIES})

# Copy SDL2 DLLs to output folder on Windows
if(WIN32)
    foreach(DLL ${SDL2_DLLS})
        add_custom_command(TARGET CMakeDemo POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy_if_different ${DLL} $<TARGET_FILE_DIR:CMakeDemo>)
    endforeach()
endif()
