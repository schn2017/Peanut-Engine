message(STATUS "Fetching SFML...")

# No need to build network odules
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)