#pragma once

#include <vector>
#include "Container.h"

class ListTag;

//Size : 32
class FillingContainer : public Container {
    public:
    char filler1[24];           //4
    Player* player;             //28
    
    public:
    FillingContainer(Player*, int, int, int);
    virtual ~FillingContainer();
    virtual ItemInstance* getItem(int) const;
    virtual void setItem(int, ItemInstance*);
    virtual void removeItem(int, int);
    virtual std::string getName() const;
    virtual int getContainerSize() const = 0;
    virtual int getMaxStackSize() const;
    virtual void startOpen(Player&);
    virtual void stopOpen(Player&);
    virtual void add(ItemInstance*);
    virtual bool canAdd(ItemInstance const*) const;
    virtual void clearSlot(int);
    virtual void doDrop(ItemInstance*, bool);
    virtual void getEmptySlotsCount() const;
    void addItem(ItemInstance*);
    void addResource(ItemInstance const&);
    void clearInventory(int);
    void compressLinkedSlotList(int);
    void contains(ItemInstance*) const;
    void dropAll(bool);
    void dropSlot(int, bool, bool, bool);
    void fixBackwardCompabilityItem(ItemInstance&);
    void getFreeSlot() const;
    void getLinked(int) const;
    void getLinkedSlot(int) const;
    void getLinkedSlotsCount() const;
    void getSlot(int) const;
    void getSlot(int, int) const;
    void getSlotWithItem(ItemInstance const&, bool, bool) const;
    void getSlotWithRemainingSpace(ItemInstance const&) const;
    void hasResource(int);
    void isCreative() const;
    void linkEmptySlot(int);
    void linkSlot(int, int);
    void load(ListTag const*);
    void release(int);
    void removeResource(int);
    void removeResource(ItemInstance const&);
    void removeResource(ItemInstance const&, bool);
    void replace(std::vector<ItemInstance>, int);
    void replaceSlot(int, ItemInstance*);
    void save();
    void setContainerChanged();
    void swapSlots(int, int);
    void unlinkSlot(int);
};
