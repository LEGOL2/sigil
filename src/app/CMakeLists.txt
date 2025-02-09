set(SOURCES
    app.cpp
)
target_sources(${APP_NAME} PRIVATE ${SOURCES})

target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/external/glm/include)
target_link_libraries(${APP_NAME} PRIVATE glm::glm)

target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/external/glad/include)
target_link_libraries(${APP_NAME} PRIVATE glad)

target_link_libraries(${APP_NAME} PRIVATE ${PROJECT_NAME})
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/sigil)

