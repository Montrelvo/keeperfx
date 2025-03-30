# KeeperFX Testing Framework

## Running Tests Locally
```bash
# Configure with tests enabled
cmake -B build -DBUILD_TESTING=ON

# Build and run all tests
cmake --build build
ctest --test-dir build --output-on-failure

# Run with coverage (requires gcc/clang)
cmake -B build -DBUILD_TESTING=ON -DENABLE_COVERAGE=ON
cmake --build build
./build/tests
lcov --capture --directory build --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

## Writing Tests
### Test Structure
```cpp
#include "gtest/gtest.h"
#include "module_to_test.h"

class TestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize test data
    }
    
    void TearDown() override {
        // Clean up
    }
};

TEST_F(TestFixture, TestCaseName) {
    EXPECT_EQ(function_to_test(), expected_value);
}
```

## Mock Objects
Example mock usage:
```cpp
#include "mock_network.hpp"

TEST(NetworkTest, MessageTest) {
    auto& net = MockNetwork::instance();
    net.sendDKMessage(0, "test", 4);
    EXPECT_EQ(net.sent_messages.back(), "test");
}
```

## Coverage Reports
- HTML reports in `coverage_report/`
- Codecov integration for PRs
- Minimum coverage goal: 80% (critical modules)