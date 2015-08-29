#pragma once

#include "AppPlatform.h"

class ANativeActivity;
class _JNIEnv;
class _JavaVM;
class ENGINE;

class AppPlatform_android : public AppPlatform {
    public:
    virtual ~AppPlatform_android();
    virtual void getDataUrl() const;
    virtual void getImagePath(std::string const&, bool);
    virtual void loadPNG(ImageData&, std::string const&, bool);
    virtual void loadTGA(ImageData&, std::string const&);
    virtual void getKeyFromKeyCode(int, int, int);
    virtual void showKeyboard(std::string const&, int, bool, UI::ValidCharacterFlag);
    virtual void hideKeyboard();
    virtual void swapBuffers();
    virtual void getSystemRegion() const;
    virtual void getGraphicsVendor();
    virtual void getGraphicsRenderer();
    virtual void getGraphicsVersion();
    virtual void getGraphicsExtensions();
    virtual void pickImage(ImagePickingCallback&);
    virtual void getExternalStoragePath();
    virtual void getInternalStoragePath();
    virtual void showDialog(int);
    virtual void createUserInput();
    virtual void getUserInputStatus();
    virtual void getUserInput();
    virtual void getScreenWidth();
    virtual void getScreenHeight();
    virtual void getPixelsPerMillimeter();
    virtual void openLoginWindow();
    virtual void updateTextBoxText(std::string const&);
    virtual void getLoginInformation();
    virtual void setLoginInformation(LoginInformation const&);
    virtual void clearSessionIDAndRefreshToken();
    virtual void supportsVibration();
    virtual void vibrate(int);
    virtual void readAssetFile(std::string const&);
    virtual void getDateString(int);
    virtual void checkLicense();
    virtual void hasBuyButtonWhenInvalidLicense();
    virtual void uploadPlatformDependentData(int, void*);
    virtual void isNetworkEnabled(bool);
    virtual void isPowerVR();
    virtual void buyGame();
    virtual void finish();
    virtual void getPlatformStringVar(int);
    virtual void getApplicationId();
    virtual void getAvailableMemory();
    virtual void getBroadcastAddresses();
    virtual void getModelName();
    virtual void getDeviceId();
    virtual void createUUID();
    virtual void isFirstSnoopLaunch();
    virtual void hasHardwareInformationChanged();
    virtual void isTablet();
    virtual void initWithActivity(ANativeActivity*);
    void _CallStringMethod(_JNIEnv*, _jmethodID*);
    void convertOpenGlToAndroidPixels(int, int, unsigned int*);
    void getKeyboardHeight();
    void init(_JavaVM*);
    void initConsts(ENGINE*);
    void tick();
};
