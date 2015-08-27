#pragma once

#include <vector>
#include <memory>

class DataItemType;
class IDataInput;
class DataItem;
class Entity;
class IDataOutput;

//Size : 16
class SynchedEntityData {
    public:
    char filler1[16];
    
    public:
    SynchedEntityData();
    SynchedEntityData(SynchedEntityData&&);
    ~SynchedEntityData();
    void _createDataItem(DataItemType, unsigned char, IDataInput&);
    void _find(unsigned char) const;
    void _get(unsigned char);
    void _resizeToContain(unsigned char);
    void assignValues(std::vector<std::unique_ptr<DataItem>>*, Entity*);
    void getByte(unsigned char) const;
    void getFloat(unsigned char) const;
    void getInt(unsigned char) const;
    void getInt64(unsigned char) const;
    void getItemInstance(unsigned char);
    void getPos(unsigned char) const;
    void getShort(unsigned char) const;
    void getString(unsigned char) const;
    SynchedEntityData& operator=(SynchedEntityData&&);
    void pack(std::vector<std::unique_ptr<DataItem>> const&, IDataOutput&);
    void packAll() const;
    void packDirty();
    void unpack(IDataInput&);
    void writeDataItem(IDataOutput&, DataItem const&);
};
