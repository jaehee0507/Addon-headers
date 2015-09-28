#pragma once

#include "FillingContainer.h"

//Size : 36
class Inventory : public FillingContainer {
    public:
    char filler1[4];                //32
    
    public:
    Inventory(Player*);
    virtual ~Inventory();
    virtual int getContainerSize() const;
    virtual void add(ItemInstance*);
    virtual bool canAdd(ItemInstance const*) const;
    virtual void clearSlot(int);
    virtual void doDrop(ItemInstance*, bool);
    virtual void getEmptySlotsCount() const;
    virtual void setContainerSize(int);
    void canDestroy(Tile*);
    void clearInventoryWithDefault(bool);
    void getAttackDamage(Entity*);
    void getDestroySpeed(Tile*);
    void getLinkedSlotForExactItem(ItemInstance const&) const;
    void getLinkedSlotForItem(int);
    void getLinkedSlotForItemIdAndAux(int, int);
    void getSelectedItem() const;
    void getSelectedSlot() const;
    void getSelectionSize();
    void moveToEmptySelectionSlot(int);
    void moveToSelectedSlot(int);
    void moveToSelectionSlot(int, int);
    void removeItemInstance(ItemInstance const*);
    void selectSlot(int);
    void setupDefault();
};
