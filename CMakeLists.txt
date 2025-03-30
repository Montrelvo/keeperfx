# Add this near the top of CMakeLists.txt
include(CTest)
find_package(GTest REQUIRED)
enable_testing()

# Add this after your main target definitions
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(tests
    test/main.cpp
    test/pathfinding_test.cpp
)

target_link_libraries(tests
    PRIVATE
    GTest::GTest GTest::Main
    keeperfx
)

add_test(NAME pathfinding_tests COMMAND tests)
