# We are inside the `editor/` folder.

# ---------------------------
# Editor library
# ---------------------------
add_library(editor_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Editor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntityTree.cpp
)

target_include_directories(editor_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(editor_lib
    PUBLIC
        ImGui-SFML::ImGui-SFML
        nlohmann_json
        spdlog
)

# ---------------------------
# Editor executable
# ---------------------------
add_executable(editor
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(editor PRIVATE
    editor_lib
)

target_include_directories(editor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
