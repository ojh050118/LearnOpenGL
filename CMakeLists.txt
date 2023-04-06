cmake_minimum_required(VERSION 3.23)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 14)
set(GLFW glfw)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit")
    # -framework OpenGL -framework CoreVideo
    add_compile_definitions(GL_SILENCE_DEPRECATION)
    set(GLFW glfw3)

endif()

add_subdirectory(dependency/glfw)
include_directories(include)
link_directories(lib)
add_executable(LearnOpenGL main.cpp glad.c shader.h)
target_link_libraries(LearnOpenGL ${GLFW})