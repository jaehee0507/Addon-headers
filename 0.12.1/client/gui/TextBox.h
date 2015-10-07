#pragma once

#include "GuiElement.h"
#include "../settings/Options.h"

namespace Touch {
    class TButton;
}
class Screen;

//Size : 180
class TextBox : public GuiElement {
    public:
    int key;                           //120
    Touch::TButton* doneButton;        //124
    char filler1[12];                  //128
    std::string text;                  //140
    std::string name;                  //144
    bool focus;                        //148
    char filler2[11];                  //149
    std::string validChars;            //160
    char filler3[16];                  //164
    
    public:
    static char* extendedASCII;
    static char* numberChars;
    static char* identifierChars;
    
    public:
    TextBox(MinecraftClient&, Options::Option const*, std::string const&, std::string const&);
    TextBox(MinecraftClient&, std::string const&, int, std::string const&, Screen*, void (Screen::*)(int), int, bool);
    virtual ~TextBox();
    virtual void tick(MinecraftClient*);
    virtual void render(MinecraftClient*, int, int);
    virtual void topRender(MinecraftClient*, int, int);
    virtual void pointerPressed(MinecraftClient*, int, int);
    virtual void pointerReleased(MinecraftClient*, int, int);
    virtual void focusedMouseClicked(MinecraftClient*, int, int);
    virtual void focusedMouseReleased(MinecraftClient*, int, int);
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual void handleTextChar(MinecraftClient*, std::string const&, bool);
    virtual bool backPressed(MinecraftClient*, bool);
    virtual bool suppressOtherGUI();
    virtual void setTextboxText(std::string const&);
    virtual bool hasFocus() const;
    virtual void setFocus(MinecraftClient*);
    virtual void loseFocus(MinecraftClient*);
    std::string _getClippedString(MinecraftClient*) const;
    int getKey();
    std::string& getText() const;
    bool isValidCharacter(std::string const&);
    void setName(std::string const&);
    void setText(std::string const&);
    void setValidChars(std::string const&);
    void updateText(MinecraftClient*);
};
