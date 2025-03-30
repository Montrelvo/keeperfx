#pragma once
#include "bflib_base_tcp.hpp"

class MockNetwork : public TCP_NetBase {
public:
    // Mock implementations of virtual functions
    bool sendDKMessage(unsigned long playerId, const char buffer[], size_t bufferLen) override {
        last_message = std::string(buffer, bufferLen);
        return true;
    }

    std::string last_message;
    static MockNetwork& instance() {
        static MockNetwork inst;
        return inst;
    }
};