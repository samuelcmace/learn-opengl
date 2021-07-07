cmake_minimum_required(VERSION 2.8.12)
project(learn-opengl)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(include/glew-2.1.0/build/cmake)
add_subdirectory(include/glfw-3.3.4)
add_subdirectory(include/glm-0.9.9.8)

include_directories(include/glew-2.1.0/include)
include_directories(include/glfw-3.3.4/include)
include_directories(include/glm-0.9.9.8/glm)

set(SOURCES
    main.cpp
    window.cpp      window.h
    mesh.cpp        mesh.h
    shader.cpp      shader.h
    camera.cpp      camera.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glew_s glfw glm)
