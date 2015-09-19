#pragma once

#include "Tag.h"

class NamedTag : public Tag {
    public:
    virtual ~NamedTag();
    virtual void setName(std::string const&);
    virtual std::string getName() const;
};