#include "gtest/gtest.h"
#include "mock_network.hpp"

class NetworkTest : public ::testing::Test {
protected:
    void SetUp() override {
        MockNetwork::instance().clear();
    }
};

TEST_F(NetworkTest, MessageFragmentation) {
    auto& net = MockNetwork::instance();
    std::string big_msg(1024*1024, 'x');
    net.sendDKMessage(0, big_msg.c_str(), big_msg.size());
    EXPECT_EQ(net.sent_messages[0].size(), big_msg.size());
}

TEST_F(NetworkTest, MultipleClients) {
    auto& net = MockNetwork::instance();
    net.sendDKMessage(0, "Client1", 7);
    net.sendDKMessage(1, "Client2", 7);
    EXPECT_EQ(net.sent_messages.size(), 2);
}

TEST_F(NetworkTest, InvalidInputs) {
    auto& net = MockNetwork::instance();
    EXPECT_FALSE(net.sendDKMessage(0, nullptr, 10)); // Null buffer
    EXPECT_TRUE(net.sendDKMessage(0, "", 0)); // Empty message
}

TEST_F(NetworkTest, MessageOrder) {
    auto& net = MockNetwork::instance();
    net.sendDKMessage(0, "Msg1", 4);
    net.sendDKMessage(0, "Msg2", 4);
    EXPECT_EQ(net.sent_messages[0], "Msg1");
    EXPECT_EQ(net.sent_messages[1], "Msg2");
}