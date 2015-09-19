#pragma once

#include <string>
#include <memory>

class Item;
class Tile;
class CompoundTag;
class Entity;
class Mob;
class Player;
class ItemEnchants;
class Level;

//Size : 20
class ItemInstance {
    public:
    char filler1[2];        //0
    short damage;           //2
    char filler2[4];        //4
    Item* item;             //8
    Tile* tile;             //12
    bool _isNull;           //16
    
    public:
    static std::string TAG_DISPLAY;
    static std::string TAG_DISPLAY_NAME;
    static std::string TAG_ENCHANTS;
    static std::string TAG_REPAIR_COST;
    
    public:
    ItemInstance();
    ItemInstance(bool);
    ItemInstance(int, int, int);
    ItemInstance(int, int, int, CompoundTag const*);
    ItemInstance(Item const*);
    ItemInstance(Item const*, int);
    ItemInstance(Item const*, int, int);
    ItemInstance(Item const*, int, int, CompoundTag const*);
    ItemInstance(ItemInstance const&);
    ItemInstance(Tile const*);
    ItemInstance(Tile const*, int);
    ItemInstance(Tile const*, int, int);
    void _getHoverFormattingPrefix() const;
    void _setItem(int);
    void add(int);
    void canDestroySpecial(Tile*);
    ItemInstance* clone(ItemInstance const*);
    ItemInstance* cloneSafe(ItemInstance const*);
    void fromTag(CompoundTag const&);
    int getAttackDamage(Entity*);
    short getAuxValue() const;
    int getBaseRepairCost() const;
    std::string getCustomName() const;
    short getDamageValue() const;
    int getDestroySpeed(Tile*);
    void getEffectName() const;
    void getEnchantsFromUserData() const;
    void getEnchantSlot() const;
    void getEnchantValue() const;
    std::string getFormattedHovertext() const;
    std::string getHoverName() const;
    void getIcon(int, bool) const;
    int getId() const;
    int getIdAux() const;
    int getIdAuxEnchanted() const;
    int getMaxDamage() const;
    int getMaxStackSize() const;
    int getMaxUseDuration() const;
    std::string getName() const;
    void getNetworkUserData() const;
    void getUseAnimation() const;
    void getUserData() const;
    bool hasCustomHoverName() const;
    bool hasSameUserData(ItemInstance const&) const;
    bool hasUserData() const;
    void hurtAndBreak(int, Mob*);
    void hurtEnemy(Mob*, Mob*);
    void init(int, int, int);
    void interactEnemy(Mob*, Player*);
    bool isArmorItem(ItemInstance const*);
    bool isDamageableItem() const;
    bool isDamaged() const;
    bool isEnchanted() const;
    bool isEnchantingBook() const;
    bool isFoil() const;
    bool isFullStack() const;
    bool isItem(ItemInstance const*);
    bool isLiquidClipItem();
    bool isNull() const;
    bool isStackable() const;
    bool isStackable(ItemInstance const*, ItemInstance const*);
    bool isStackedByData() const;
    bool isThrowable() const;
    void load(CompoundTag const&);
    bool matches(ItemInstance const*) const;
    bool matches(ItemInstance const*, ItemInstance const*);
    bool matchesNulls(ItemInstance const*, ItemInstance const*);
    void mineBlock(int, int, int, int, Mob*);
    bool operator!=(ItemInstance const&) const;
    ItemInstance& operator=(ItemInstance const&);
    bool operator==(ItemInstance const&) const;
    void releaseUsing(Player*, int);
    void remove(int);
    void resetHoverName();
    void sameItemAndAux(ItemInstance const*) const;
    void save();
    void saveEnchantsToUserData(ItemEnchants const&);
    void set(int);
    void setAuxValue(short);
    void setCustomName(std::string const&);
    void setDescriptionId(std::string const&);
    void setNull();
    void setRepairCost(int);
    void setUserData(std::unique_ptr<CompoundTag>);
    void snap(Player*);
    std::string toString() const;
    void use(Player&);
    void useAsFuel();
    void useOn(Player*, int, int, int, signed char, float, float, float);
    void useTimeDepleted(Level*, Player*);
};
