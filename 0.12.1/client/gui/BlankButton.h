#pragma once

#include "Button.h"

//Size : 180
class BlankButton : public Button {
    public:
    BlankButton(int);
    BlankButton(int, int, int, int, int);
    virtual ~BlankButton();
};