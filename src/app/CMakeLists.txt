set(SOURCES
    app.cpp
)

target_sources(${APP_NAME} PRIVATE ${SOURCES})
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/external/glm/include)
target_link_libraries(${APP_NAME} ${PROJECT_NAME})
target_include_directories(${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/sigil)

