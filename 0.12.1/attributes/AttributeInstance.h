#pragma once

#include <memory>
#include <vector>
#include <string>

class Attribute;
class BaseAttributeMap;
class AttributeBuff;
class AttributeModifier;
class AttributeInstanceDelegate;
namespace mce {
    class UUID;
}

class AttributeInstance {
    public:
    //void** vtable;                        //0
    char filler1[4];                        //4
    Attribute* attribute;                   //8
    char filler2[44];                       //12
    float defaultValue;                     //56
    char filler3[8];                        //60
    float minValue;                         //68
    float maxValue;                         //72
    float currentValue;                     //76
    
    public:
    AttributeInstance();
    AttributeInstance(BaseAttributeMap*, Attribute const*);
    virtual ~AttributeInstance();;
    virtual void tick();
    void _calculateValue();
    void _calculateValue(AttributeBuff const&);
    void _getAppliedModifiers(int);
    void _sanitizeValue(float);
    void _setDirty();
    void addBuff(AttributeBuff const&);
    void addBuff(std::shared_ptr<AttributeBuff>);
    void addModifier(AttributeModifier const&);
    void addModifier(std::shared_ptr<AttributeModifier>);
    void addModifiers(std::vector<std::shared_ptr<AttributeModifier>>*);
    Attribute* getAttribute() const;
    void getBuffs() const;
    float getCurrentValue() const;
    float getDefaultValue(int) const;
    void getHandle() const;
    void getListeners() const;
    float getMaxValue() const;
    float getMinValue() const;
    void getModifier(mce::UUID const&) const;
    void getModifiers() const;
    void getModifiers(int) const;
    void getModifiers(std::string const&) const;
    bool hasModifier(AttributeModifier const&) const;
    bool hasModifier(std::shared_ptr<AttributeModifier>) const;
    bool hasTemporalBuffs() const;
    void notify(long long);
    void registerListener(AttributeInstance const&);
    void removeBuff(AttributeBuff const&);
    void removeBuff(std::shared_ptr<AttributeBuff>);
    void removeBuffs();
    void removeModifier(AttributeModifier const&);
    void removeModifier(std::shared_ptr<AttributeModifier>);
    void removeModifiers();
    void removeModifiers(std::string const&);
    void resetToDefaultValue(int);
    void resetToMaxValue();
    void resetToMinValue();
    void serializationSetRange(float, float, float);
    void serializationSetValue(float, int);
    void setDefaultValue(float, int);
    void setDelegate(std::shared_ptr<AttributeInstanceDelegate>);
    void setMaxValue(float);
    void setMinValue(float);
    void setRange(float, float, float);
};
