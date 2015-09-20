#pragma once

#include <string>

class Attribute {
    public:
    float defaultValue;            //0
    float minValue;                //4
    float maxValue;                //8
    bool clientSyncable;           //12
    char filler1[3];               //13
    std::string name;              //16
    char filler2[4];               //20
    
    public:
    Attribute(std::string const&, float, float, float, bool);
    void getByName(std::string const&);
    float getDefaultValue() const;
    float getMaxValue() const;
    float getMinValue() const;
    std::string getName() const;
    bool isClientSyncable() const;
};
