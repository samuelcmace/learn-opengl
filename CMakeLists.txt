cmake_minimum_required(VERSION 3.5)
project(learn-opengl)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the required packages
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

configure_file(shaders/shader.vert shaders/shader.vert COPYONLY)
configure_file(shaders/shader.frag shaders/shader.frag COPYONLY)

set(SOURCES
    main.cpp
    window.cpp      window.h
    mesh.cpp        mesh.h
    shader.cpp      shader.h
    camera.cpp      camera.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw 
    GLEW::GLEW 
    glm::glm
)
