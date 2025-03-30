# Main test configuration
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/deps
    ${CMAKE_CURRENT_SOURCE_DIR}/test
)

# Test executable
add_executable(tests
    test/main.cpp
    test/pathfinding_test.cpp 
    test/network_test.cpp
    test/mock_network.hpp
)

target_link_libraries(tests
    PRIVATE
    GTest::GTest GTest::Main
    keeperfx
)

# Enable test folder creation
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bench)
