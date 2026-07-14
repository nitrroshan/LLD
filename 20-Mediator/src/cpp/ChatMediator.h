#pragma once
#include <string>

class User;  // forward declaration — mediator refers to users by pointer

// Mediator — declares how colleagues communicate.
class ChatMediator {
public:
    virtual ~ChatMediator() = default;
    virtual void send_message(const std::string& message, User* sender) = 0;
    virtual void add_user(User* user) = 0;
};
