#pragma once

#include "Screen.h"
#include "../../../level/LevelListener.h"

//Size : 296
class PauseScreen : public Screen, public LevelListener {
    public:
    char filler1[20];                               //212
    std::string trialMessage;                       //232
    Touch::TButton* returnGameBtn;                  //236
    Touch::TButton* quitBtn;                        //240
    Touch::TButton* optionBtn;                      //244
    Touch::TButton* inviteBtn;                      //248
    Touch::TButton* buyBtn;                         //252
    Label* header;                                  //256
    Label* label;                                   //260
    PackedScrollContainer* playerList;              //264
    char filler2[28];                               //268
    
    public:
    PauseScreen(bool, bool);
    virtual ~PauseScreen();
    virtual void tick();
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual bool handleBackEvent(bool);
    virtual bool renderGameBehind() const;
    virtual bool isPauseScreen() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void buttonClicked(Button*);
    virtual void pointerPressed(int, int);
    virtual void pointerReleased(int, int);
    virtual void controllerDirectionChanged(int, StickDirection);
    virtual void controllerDirectionHeld(int, StickDirection);
    virtual void onEntityAdded(Entity&);
    virtual void onEntityRemoved(Entity&);
    void _changeFocus();
    void _selectNextPlayer();
    void _selectPlayer(int);
    void _selectPreviousPlayer();
    void rebuildPlayerList();
};
