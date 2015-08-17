#pragma once

namespace UI {
	class GameEventNotification;
}

class AbstractScreen {   
	virtual ~AbstractScreen();   
	virtual void onFocusGained();
	virtual void onGameEventNotification(UI::GameEventNotification);
	virtual bool isModal() const;
	virtual bool isShowingMenu() const;
	virtual bool shouldStealMouse() const;
	virtual void getFocusedControl();
	virtual void exit();
	virtual bool isPauseScreen() const;
};
