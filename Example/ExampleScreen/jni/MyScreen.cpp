#include "MyScreen.h"
#include "mcpe/gui/TButton.h"
#include "mcpe/gui/THeader.h"
#include "mcpe/gui/ScreenChooser.h"
#include "mcpe/gui/Color.h"

MyScreen::MyScreen() {
    //Make variables be NULL
    myBtn = NULL;
    myHdr = NULL;
}

MyScreen::~MyScreen() {
    //Freeing memory
    delete myBtn;
    delete myHdr;
}

bool MyScreen::handleBackEvent(bool a) {
    if(!a) {
        closeScreen();
    }
    return true;
}

bool MyScreen::renderGameBehind() const {
    return false;
}

void MyScreen::render(int a, int b, float c) {
    Screen::renderMenuBackground(c);
    screenRenderer.drawString(fontObj, "Drawing String", 4, 80, Color::YELLOW);
    Screen::render(a, b, c);
}

void MyScreen::init() {
    myBtn = new Touch::TButton(0, "7357", mc, false, 0x7FFFFFFF);
    buttonList.push_back(myBtn);
    
    myHdr = new Touch::THeader(1, "THeader");
    elementList.push_back(myHdr);
}

void MyScreen::setupPositions() {
    myBtn->xPosition = 0;
    myBtn->yPosition = 32;
    myBtn->width = 40;
    myBtn->height = 40;
    
    myHdr->xPosition = 0;
    myHdr->yPosition = 0;
    myHdr->width = width; //Screen's width
    myHdr->height = 28;
}

void MyScreen::buttonClicked(Button* btn) {
    if(btn->id == myBtn->id) {
        closeScreen();
    }
}

void MyScreen::closeScreen() {
    ScreenChooser* sc = *(ScreenChooser**)(((uintptr_t) mc)+112);
    //Didn't make MinecraftClient header yet :P
    sc->setStartMenuScreen();
}
