
include_directories(include)

set(SOURCES
  ./src/main.cpp
  ./src/Editor.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE 
  ImGui-SFML::ImGui-SFML
  nlohmann_json
  spdlog
)