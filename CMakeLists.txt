cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME sigil)
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GLFW
add_subdirectory(src/external/glfw)

# GLAD
add_subdirectory(src/external/glad)

# GLM
add_subdirectory(src/external/glm)
target_compile_definitions(glm PRIVATE GLM_BUILD_TESTS=OFF BUILD_SHARED_LIBS=OFF)

# sigil executable
add_executable(${PROJECT_NAME})
add_subdirectory(src)
