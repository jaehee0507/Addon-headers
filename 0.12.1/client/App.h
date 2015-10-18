#pragma once

#include <string>
#include "AppPlatformListener.h"

class AppContext;
class TextureAtlas;
class AppPlatform_android;

//Size : 28
class App : public AppPlatformListener {
    public:
    char filler1[4];                   //8
    TextureAtlas* textureAtlas;        //12
    char filler2[12];                  //16
    
    public:
    App(int, char**);
    virtual ~App();
    virtual AppPlatform_android* platform();
    virtual void audioEngineOn();
    virtual void audioEngineOff();
    virtual void muteAudio();
    virtual void unMuteAudio();
    virtual void destroy();
    virtual void loadState(void*, int);
    virtual void saveState(void**, int*);
    virtual void useTouchscreen();
    virtual void setTextboxText(std::string const&);
    virtual void draw();
    virtual void update();
    virtual void setSize(int, int, float);
    virtual void quit();
    virtual void wantToQuit();
    virtual void init();
    void changeContext(AppContext&);
    void getCommandLineParameter(std::string const&);
    void init(AppContext&);
};
