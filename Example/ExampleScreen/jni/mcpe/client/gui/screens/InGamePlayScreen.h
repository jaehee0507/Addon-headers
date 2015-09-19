#pragma once

#include "Screen.h"

class InGamePlayScreen : public Screen {
    public:
    InGamePlayScreen();
    virtual ~InGamePlayScreen();
    virtual void tick();
    virtual void handleDirection(DirectionId, float, float);
    virtual bool renderGameBehind() const;
    virtual bool isModal() const;
    virtual bool isShowingMenu() const;
    virtual bool shouldStealMouse() const;
    virtual void render(int, int, float);
};