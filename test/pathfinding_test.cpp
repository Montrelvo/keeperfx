#include "gtest/gtest.h"
#include "../src/ariadne.h"

class PathfindingTest : public ::testing::Test {
protected:
    void SetUp() override {
        init_navigation();
        // Create test map with obstacles
        fill_rectangle_f(0, 0, 10, 10, 1, "test");
    }
};

// Existing tests...

TEST_F(PathfindingTest, EdgeCase_NoPath) {
    // Block all paths
    border_lock(0, 0, 10, 10);
    
    long cost = 0;
    long route = ma_triangle_route(0, 1, &cost);
    EXPECT_EQ(route, -1) << "Should return -1 when no path exists";
}

TEST_F(PathfindingTest, EdgeCase_LargeMap) {
    // Test with larger map size
    fill_rectangle_f(0, 0, 100, 100, 1, "large_map");
    
    long cost = 0;
    long route = ma_triangle_route(0, 99, &cost);
    EXPECT_GT(cost, 0) << "Should find path in large maps";
}

TEST_F(PathfindingTest, EdgeCase_ComplexTerrain) {
    // Create maze-like pattern
    for(int x=0; x<10; x+=2) {
        fill_rectangle_f(x, 0, x+1, 9, 0, "maze");
    }
    
    long cost = 0;
    long route = ma_triangle_route(0, 9, &cost);
    EXPECT_GT(cost, 20) << "Should navigate complex terrain";
}