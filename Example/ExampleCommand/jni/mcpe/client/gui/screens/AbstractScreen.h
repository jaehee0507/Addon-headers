#pragma once

#include "../GuiComponent.h"

namespace UI {
    class GameEventNotification;
}
class MinecraftClient;
class TilePos;
class UIRenderContext;
class InputMode;
class DirectionId;

class AbstractScreen : public GuiComponent {
    public:
    virtual ~AbstractScreen();
    virtual void _init(MinecraftClient&, int, int) = 0;
    virtual void setSize(int, int) = 0;
    virtual void onSetKeyboardHeight(int) = 0;
    virtual void setAssociatedTilePos(TilePos const&) = 0;
    virtual void lostFocus() = 0;
    virtual void removed() = 0;
    virtual void onInternetUpdate() = 0;
    virtual void onFocusGained();
    virtual void onGameEventNotification(UI::GameEventNotification);
    virtual void tick() = 0;
    virtual void updateEvents() = 0;
    virtual void render(UIRenderContext&, int, int, float) = 0;
    virtual void handleInputModeChanged(InputMode) = 0;
    virtual void handleButtonPress(MinecraftClient*, short) = 0;
    virtual void handleButtonRelease(MinecraftClient*, short) = 0;
    virtual void handlePointerLocation(short, short) = 0;
    virtual void handlePointerPressed(bool) = 0;
    virtual void handleDirection(DirectionId, float, float) = 0;
    virtual bool handleBackEvent(bool) = 0;
    virtual void handleTextChar(std::string const&, bool) = 0;
    virtual void setTextboxText(std::string const&) = 0;
    virtual void handleLicenseChanged() = 0;
    virtual bool renderGameBehind() const = 0;
    virtual bool closeOnPlayerHurt() const = 0;
    virtual bool isModal() const;
    virtual bool isShowingMenu() const;
    virtual bool shouldStealMouse() const;
    virtual void getFocusedControl();
    virtual void exit();
    virtual bool isPauseScreen() const;
};
