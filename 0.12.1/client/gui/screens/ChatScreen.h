#pragma once

#include <deque>
#include "Screen.h"

namespace Touch {
    class HeaderButton;
}
class BlankButton;
class ImageWithBackground;

//Size : 256
class ChatScreen : public Screen {
    public:
    std::string text;                      //212
    char filler1[4];                       //216
    Touch::HeaderButton* backBtn;          //220
    Touch::HeaderButton* hideBtn;          //224
    BlankButton* backgroundBtn;            //228
    ImageWithBackground* chatBtn;          //232
    ImageWithBackground* sendBtn;          //236
    char filler2[16];                      //240
    
    public:
    static std::deque<std::string> sentMessages;
    
    public:
    ChatScreen(bool);
    virtual ~ChatScreen();
    virtual void onSetKeyboardHeight(int);
    virtual void removed();
    virtual void tick();
    virtual void handleButtonPress(MinecraftClient*, short);
    virtual void handleBackEvent(bool);
    virtual void handleTextChar(std::string const&, bool);
    virtual void setTextboxText(std::string const&);
    virtual void renderGameBehind() const;
    virtual void closeOnPlayerHurt() const;
    virtual void render(int, int, float);
    virtual void init();
    virtual void setupPositions();
    virtual void buttonClicked(Button*);
    void closeWindow();
    void drawChatMessages(int);
    void getKeyboardHeight();
    void guiMessagesUpdated();
    void sendChatMessage();
    void updateGuiMessages();
    void updateKeyboardVisibility();
    void updateToggleKeyboardButton();
};