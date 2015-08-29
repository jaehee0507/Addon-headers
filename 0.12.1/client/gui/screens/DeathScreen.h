#pragma once

#include "Screen.h"

//Size : 236
class DeathScreen : public Screen {
    public:
    char filler1[4];                    //212
    Touch::TButton* respawnBtn;         //216
    Touch::TButton* quitBtn;            //220
    char filler2[12];                   //224
    
    public:
    DeathScreen();
    virtual void ~DeathScreen();
    virtual void tick();
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual void renderGameBehind() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void buttonClicked(Button*);
    virtual void controllerDirectionChanged(int, StickDirection);
};