#pragma once

#include "mcpe/gui/Screen.h"

namespace Touch {
    class TButton;
    class THeader;
}
class Button;

class MyScreen : public Screen {
    public:
    Touch::TButton* myBtn;
    Touch::THeader* myHdr;
    
    public:
    MyScreen();
    virtual ~MyScreen();
    virtual bool handleBackEvent(bool);
    virtual bool renderGameBehind() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void buttonClicked(Button*);
    void closeScreen();
};
