#include "gtest/gtest.h"
#include "mock_network.hpp"

class NetworkTest : public ::testing::Test {
protected:
    void SetUp() override {
        MockNetwork::instance().clear();
    }
};

TEST_F(NetworkTest, MessageSending) {
    auto& net = MockNetwork::instance();
    net.sendDKMessage(0, "test", 4);
    ASSERT_EQ(net.sent_messages.size(), 1);
    EXPECT_EQ(net.sent_messages[0], "test");
}

TEST_F(NetworkTest, MultipleMessages) {
    auto& net = MockNetwork::instance();
    net.sendDKMessage(0, "msg1", 4);
    net.sendDKMessage(1, "msg2", 4);
    EXPECT_EQ(net.sent_messages.size(), 2);
    EXPECT_EQ(net.sent_messages[1], "msg2");
}