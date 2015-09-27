#pragma once

#include <memory>
#include <vector>
#include "NamedTag.h"

class ListTag;
class TagMemoryChunk;

//Size : 32
class CompoundTag : public NamedTag {
    public:
    char filler1[28];
    
    public:
    CompoundTag(CompoundTag&&);
    CompoundTag(std::string const&);
    CompoundTag();
    virtual ~CompoundTag();
    virtual void write(IDataOutput&) const;
    virtual void load(IDataInput&);
    virtual std::string toString() const;
    virtual int getId() const;
    virtual bool equals(Tag const&);
    virtual void print(std::string const&, PrintStream&);
    virtual Tag* copy() const;
    CompoundTag* clone() const;
    bool contains(std::string const&) const;
    bool contains(std::string const&, int) const;
    void get(std::string const&) const;
    void getAllTags(std::vector<Tag*>&) const;
    bool getBoolean(std::string const&) const;
    char getByte(std::string const&) const;
    char* getByteArray(std::string const&) const;
    void getCompound(std::string const&) const;
    float getDouble(std::string const&) const;
    float getFloat(std::string const&) const;
    int getInt(std::string const&) const;
    long long getInt64(std::string const&) const;
    int* getIntArray(std::string const&) const;
    ListTag* getList(std::string const&) const;
    short getShort(std::string const&) const;
    std::string& getString(std::string const&) const;
    bool isEmpty() const;
    CompoundTag& operator=(CompoundTag&&);
    void put(std::string const&, std::unique_ptr<Tag>);
    void putBoolean(std::string const&, bool);
    void putByte(std::string const&, char);
    void putByteArray(std::string const&, TagMemoryChunk);
    void putCompound(std::string const&, std::unique_ptr<CompoundTag>);
    void putDouble(std::string const&, float);
    void putFloat(std::string const&, float);
    void putInt(std::string const&, int);
    void putInt64(std::string const&, long long);
    void putShort(std::string const&, short);
    void putString(std::string const&, std::string const&);
    void rawView() const;
    void remove(std::string const&);
    CompoundTag* uniqueClone() const;
};
