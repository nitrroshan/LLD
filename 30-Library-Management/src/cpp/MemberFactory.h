#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include "Member.h"
#include "MemberType.h"
#include "StudentMember.h"
#include "FacultyMember.h"

// Factory Method — creates the right Member subclass from a MemberType token.
class MemberFactory {
public:
    static std::unique_ptr<Member> create(MemberType type, const std::string& id,
                                           const std::string& name) {
        switch (type) {
            case MemberType::Student: return std::make_unique<StudentMember>(id, name);
            case MemberType::Faculty: return std::make_unique<FacultyMember>(id, name);
        }
        throw std::invalid_argument("Unknown member type");
    }
};
