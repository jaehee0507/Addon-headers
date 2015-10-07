#pragma once

#include <memory>
#include "Screen.h"

typedef int CreateWorldScreenType;

class ImageButton;
namespace Touch {
    class TButton;
    class HeaderButton;
    class THeader;
}
class BlankButton;
class TextBox;
class Label;
class NinePatchLayer;
class MCOServerListItem;
class LevelSummary;
class GameType;
class LevelData;

//Size : 488
class CreateWorldScreen : public Screen {
    public:
    bool _isAdvanced;                                           //212
    bool _isFlat;                                               //213
    char filler1[18];                                           //214
    int gamemode;                                               //232
    int generatorType;                                          //236
    std::vector<std::unique_ptr<ImageButton>> gamemodeBtns;     //240
    std::vector<std::unique_ptr<ImageButton>> worldtypeBtns;    //252
    ImageButton* selectedGamemodeBtn;                           //264
    ImageButton* selectedWorldtypeBtn;                          //268
    Touch::TButton* createWorldBtn;                             //272
    Touch::HeaderButton* backBtn;                               //276
    Touch::THeader* header;                                     //280
    Touch::HeaderButton* deleteOrEditBtn;                       //284
    BlankButton* blankBtn;                                      //288
    char filler4[8];                                            //292
    TextBox* levelNameTextbox;                                  //300
    TextBox* levelSeedTextbox;                                  //304
    Label* levelNameLabel;                                      //308
    Label* levelSeedLabel;                                      //312
    Label* descriptionLabel;                                    //316
    Label* progressLabel;                                       //320
    Label* gamemodeLabel;                                       //324
    char filler5[8];                                            //328
    NinePatchLayer* layer1;                                     //336
    NinePatchLayer* layer2;                                     //340
    NinePatchLayer* layer3;                                     //344
    char filler6[44];                                           //348
    int createType;                                             //392
    char filler7[12];                                           //396
    std::string defaultWorldName;                               //408
    char filler8[76];                                           //412
    
    public:
    CreateWorldScreen(CreateWorldScreenType, MCOServerListItem const&);
    CreateWorldScreen(LevelSummary const&);
    virtual ~CreateWorldScreen();
    virtual void onSetKeyboardHeight(int);
    virtual void tick();
    virtual void handleButtonRelease(MinecraftClient*, short);
    virtual bool handleBackEvent(bool);
    virtual void handleTextChar(std::string const&, bool);
    virtual void setTextboxText(std::string const&);
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void feedMCOEvent(MCOEvent);
    virtual void buttonClicked(Button*);
    virtual void guiElementClicked(GuiElement*);
    virtual void pointerPressed(int, int);
    virtual void pointerReleased(int, int);
    virtual void controllerDirectionChanged(int, StickDirection);
    void _createToggle(bool);
    void _createWorldClicked();
    void _editGameMode(GameType);
    void _getDefaultGenerator() const;
    std::string _getDescription() const;
    int _getGameMode();
    void _getWorldData() const;
    bool _isOneOf(Button*, std::vector<std::unique_ptr<ImageButton>>&, int&) const;
    bool _isOneOfGuiElements(GuiElement*, std::vector<TextBox*>&, int&) const;
    bool _isOneOfGuiElements(GuiElement*, std::vector<std::unique_ptr<ImageButton>>&, int&) const;
    void _levelStorage();
    void _renameLevel();
    void _setWorldData(LevelData const&);
    void closeScreen();
    void createUniqueLevelID(std::string const&) const;
    void generateLocalGame();
    void generateMCOGame(bool);
    std::string getLevelName();
    std::string getSeed();
    bool isAdvanced();
    bool isAlwaysDay() const;
    bool isEditMode();
    bool isFlat();
    bool isWorldLimited();
    void onLevelNameChanged(std::string const&);
    void waitForMCO();
};
