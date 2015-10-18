#pragma once

#include "Screen.h"

namespace Touch {
    class TButton;
}

//Size : 236
class DeathScreen : public Screen {
    public:
    char filler1[4];                    //212
    Touch::TButton* respawnBtn;         //216
    Touch::TButton* quitBtn;            //220
    char filler2[12];                   //224
    
    public:
    DeathScreen();
    virtual ~DeathScreen();
    virtual void tick();
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual bool renderGameBehind() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void buttonClicked(Button*);
    virtual void controllerDirectionChanged(int, StickDirection);
};
