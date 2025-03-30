#include "gtest/gtest.h"
#include "ariadne.h"

class PathfindingTest : public ::testing::Test {
protected:
    void SetUp() override {
        init_navigation();
    }

    void TearDown() override {
        // Clean up if needed
    }
};

TEST_F(PathfindingTest, BasicNavigation) {
    EXPECT_TRUE(triangulation_border_tag());
}

TEST_F(PathfindingTest, TriangleRouting) {
    long route_cost = 0;
    long route = ma_triangle_route(0, 1, &route_cost);
    EXPECT_GT(route_cost, 0);
}

TEST_F(PathfindingTest, NavigationInitialization) {
    long result = init_navigation();
    EXPECT_EQ(result, 1);
}