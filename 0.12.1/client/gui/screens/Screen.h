#pragma once

#include <vector>
#include "AbstractScreen.h"

class MinecraftClient;
class TilePos;
class UIRenderContext;
class InputMode;
class DirectionId;
class MCOEvent;
class MojangConnectionStatus;
class Button;
class GuiElement;
class StickDirection;
class Font;
class TextBox;

//Size : 212
class Screen : public AbstractScreen {
    public:
    char filler1[4];                        //76
    int width;                              //80
    int height;                             //84
    MinecraftClient* mc;                    //88
    std::vector<Button*> buttonList;        //92
    std::vector<TextBox*> textBoxList;      //104
    char filler2[24];                       //104
    std::vector<GuiElement*> elementList;   //140
    char filler3[12];                       //152
    Font* fontObj;                          //164
    Button* selectedButton;                 //168
    char filler4[28];                       //172
    mce::MaterialPtr ui_cubemap;            //200
    
    public:
    Screen();
    virtual ~Screen();
    virtual void _init(MinecraftClient&, int, int);
    virtual void setSize(int, int);
    virtual void onSetKeyboardHeight(int);
    virtual void setAssociatedTilePos(TilePos const&);
    virtual void lostFocus();
    virtual void removed();
    virtual void onInternetUpdate();
    virtual void tick();
    virtual void updateEvents();
    virtual void render(UIRenderContext&, int, int, float);
    virtual void handleInputModeChanged(InputMode);
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual void handleButtonRelease(MinecraftClient*, short);
    virtual void handlePointerLocation(short, short);
    virtual void handlePointerPressed(bool);
    virtual void handleDirection(DirectionId, float, float);
    virtual bool handleBackEvent(bool);
    virtual void handleTextChar(std::string const&, bool);
    virtual void setTextboxText(std::string const&);
    virtual void handleLicenseChanged();
    virtual bool renderGameBehind() const;
    virtual bool closeOnPlayerHurt() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void checkForPointerEvent();
    virtual void controllerEvent();
    virtual void renderBackground(int);
    virtual void renderDirtBackground();
    virtual void renderMenuBackground(float);
    virtual void confirmResult(bool, int);
    virtual void toGUICoordinate(int&, int&);
    virtual void feedMCOEvent(MCOEvent);
    virtual bool supppressedBySubWindow();
    virtual void onTextBoxUpdated(int);
    virtual void onMojangConnectorStatus(MojangConnectionStatus);
    virtual void handleScrollWheel(float);
    virtual void handlePointerAction(int, int, bool);
    virtual void updateTabButtonSelection();
    virtual void buttonClicked(Button*);
    virtual void guiElementClicked(GuiElement*);
    virtual void pointerPressed(int, int);
    virtual void pointerReleased(int, int);
    virtual void controllerDirectionChanged(int, StickDirection);
    virtual void controllerDirectionHeld(int, StickDirection);
    void tabNext();
    void tabPrev();
    void renderProgressBar(float) const;
    void processControllerDirection(int);
    void getCursorMoveThrottle();
};
