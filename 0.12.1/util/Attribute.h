#pragma once

#include <string>

class Attribute {
    public:
    float defaultValue;
    float minValue;
    float maxValue;
    bool clientSyncable;
    std::string name;
    
    public:
    Attribute(std::string const&, float, float, float, bool);
    void getByName(std::string const&);
    float getDefaultValue() const;
    float getMaxValue() const;
    float getMinValue() const;
    std::string getName() const;
    bool isClientSyncable() const;
};
