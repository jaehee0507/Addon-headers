#pragma once

#include <string>

class ImageData;
namespace UI {
    class ValidCharacterFlag;
}
class ImagePickingCallback;
class LoginInformation;
class UriListener;
class FullscreenMode;

class AppPlatform {
    public:
    class HardwareInformation {
        public:
        char filler1[56];
        
        public:
        HardwareInformation();
    };
    
    public:
    AppPlatform();
    virtual ~AppPlatform();
    virtual void getDataUrl() const = 0;
    virtual void getImagePath(std::string const&, bool) = 0;
    virtual void loadPNG(ImageData&, std::string const&, bool) = 0;
    virtual void loadTGA(ImageData&, std::string const&);
    virtual void savePNG(ImageData const&, std::string const&);
    virtual void getKeyFromKeyCode(int, int, int);
    virtual void showKeyboard(std::string const&, int, bool, UI::ValidCharacterFlag);
    virtual void hideKeyboard();
    virtual void hideMousePointer();
    virtual void showMousePointer();
    virtual void getPointerFocus();
    virtual void setPointerFocus(bool);
    virtual void toggleSimulateTouchWithMouse();
    virtual void captureScreen(int, int, unsigned int, bool);
    virtual void swapBuffers() = 0;
    virtual void getSystemRegion() const = 0;
    virtual void getGraphicsVendor() = 0;
    virtual void getGraphicsRenderer() = 0;
    virtual void getGraphicsVersion() = 0;
    virtual void getGraphicsExtensions() = 0;
    virtual void pickImage(ImagePickingCallback&) = 0;
    virtual void setSleepEnabled(bool);
    virtual void getExternalStoragePath() = 0;
    virtual void getInternalStoragePath() = 0;
    virtual void showDialog(int);
    virtual void createUserInput();
    virtual void getUserInputStatus();
    virtual void getUserInput();
    virtual void _tick();
    virtual void getScreenWidth();
    virtual void getScreenHeight();
    virtual void getPixelsPerMillimeter();
    virtual void openLoginWindow();
    virtual void updateTextBoxText(std::string const&);
    virtual void isKeyboardVisible();
    virtual void getLoginInformation();
    virtual void setLoginInformation(LoginInformation const&);
    virtual void clearSessionIDAndRefreshToken();
    virtual void supportsVibration();
    virtual void vibrate(int);
    virtual void readAssetFile(std::string const&);
    virtual void listAssetFilesIn(std::string const&, std::string const&) const;
    virtual void getDateString(int);
    virtual void checkLicense();
    virtual void hasBuyButtonWhenInvalidLicense();
    virtual void uploadPlatformDependentData(int, void*);
    virtual void isNetworkEnabled(bool);
    virtual void isPowerVR();
    virtual void buyGame();
    virtual void finish();
    virtual void launchUri(std::basic_string<wchar_t, std::char_traits<wchar_t>> const&);
    virtual void useMetadataDrivenScreens() const;
    virtual void useXboxControlHelpers() const;
    virtual void useCenteredGUI() const;
    virtual void hasIDEProfiler();
    virtual void getPlatformStringVar(int);
    virtual void getApplicationId() = 0;
    virtual void getAvailableMemory();
    virtual void getBroadcastAddresses();
    virtual void getModelName();
    virtual void getDeviceId() = 0;
    virtual void createUUID() = 0;
    virtual void isFirstSnoopLaunch() = 0;
    virtual void hasHardwareInformationChanged() = 0;
    virtual void isTablet() = 0;
    virtual void registerUriListener(UriListener&);
    virtual void unregisterUriListener(UriListener&);
    virtual void setFullscreenMode(FullscreenMode);
    virtual void getCaretPosition();
    void _fireAppFocusGained();
    void _fireAppFocusLost();
    void _fireAppResumed();
    void _fireAppSuspended();
    void _fireAppTerminated();
    void _fireLowMemory();
    void getPreloadingHTMLLength();
    void loadImage(ImageData&, std::string const&, bool);
    void loadTexture(std::string const&, bool);
};
