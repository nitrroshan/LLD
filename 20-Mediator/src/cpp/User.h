#pragma once
#include <string>
#include <iostream>
#include "ChatMediator.h"

// Colleague — knows ONLY the mediator (a non-owning back-pointer).
class User {
protected:
    ChatMediator* mediator_;
    std::string name_;

public:
    User(ChatMediator* mediator, std::string name)
        : mediator_(mediator), name_(std::move(name)) {}
    virtual ~User() = default;

    const std::string& name() const { return name_; }

    // Send a message — routed through the mediator, not to peers directly.
    void send(const std::string& message) {
        std::cout << name_ << " sends: " << message << "\n";
        mediator_->send_message(message, this);
    }

    virtual void receive(const std::string& message, const std::string& from) = 0;
};
