#pragma once

#include <string>

class ItemInstance;
class Player;

class Container {
    public:
    //void** vtable;
    
    public:
    virtual ~Container();
    virtual ItemInstance* getItem(int) const = 0;
    virtual void setItem(int, ItemInstance*) = 0;
    virtual void removeItem(int, int) = 0;
    virtual std::string getName() const = 0;
    virtual int getContainerSize() const = 0;
    virtual int getMaxStackSize() const = 0;
    virtual void startOpen(Player&) = 0;
    virtual void stopOpen(Player&) = 0;
    virtual void getSlotCopies() const;
    virtual void getSlots();
    virtual void getItemCount(int);
};
