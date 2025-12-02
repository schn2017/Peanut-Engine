include_directories(include)

# ---------------------------
# Engine / shared logic
# ---------------------------

add_library(PeanutEngine
    src/Editor.cpp
    src/Node.cpp
)

target_include_directories(PeanutEngine
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(PeanutEngine
    PUBLIC
        ImGui-SFML::ImGui-SFML
        nlohmann_json
        spdlog
)

# ---------------------------
# Main executable
# ---------------------------

add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Link the executable to your engine logic
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        PeanutEngine
)
