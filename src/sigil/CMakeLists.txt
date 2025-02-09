set(SOURCES
    sigil.cpp
)

add_library(${PROJECT_NAME} STATIC)
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/external/glm/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/external/glad/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/external/glfw/include)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
