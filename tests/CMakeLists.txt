file(GLOB TEST_SOURCES "*.cpp")

add_executable(engine_tests ${TEST_SOURCES})

target_link_libraries(engine_tests PRIVATE
    PeanutEngine
    Catch2::Catch2WithMain
)

#catch_discover_tests(engine_tests)
