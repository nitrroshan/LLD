#pragma once
#include <vector>
#include "ChatMediator.h"
#include "User.h"

// Concrete Mediator — holds the colleagues (non-owning) and owns the
// coordination logic: broadcast to everyone except the sender.
class ChatRoom : public ChatMediator {
    std::vector<User*> users_;

public:
    void add_user(User* user) override {
        users_.push_back(user);
    }

    void send_message(const std::string& message, User* sender) override {
        for (User* user : users_) {
            if (user != sender) {
                user->receive(message, sender->name());
            }
        }
    }
};
