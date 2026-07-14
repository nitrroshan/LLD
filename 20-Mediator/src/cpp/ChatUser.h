#pragma once
#include <iostream>
#include "User.h"

// Concrete Colleague — a chat participant. It only implements how it reacts
// to an incoming message; it has no reference to any other user.
class ChatUser : public User {
public:
    ChatUser(ChatMediator* mediator, std::string name)
        : User(mediator, std::move(name)) {}

    void receive(const std::string& message, const std::string& from) override {
        std::cout << "    " << name_ << " received from " << from << ": " << message << "\n";
    }
};
