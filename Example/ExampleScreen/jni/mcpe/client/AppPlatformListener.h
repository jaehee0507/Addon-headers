#pragma once

//Size : 8
class AppPlatformListener {
    public:
    //void** vtable;            //0
    int filler1;                //4
    
    public:
    AppPlatformListener();
    AppPlatformListener(bool);
    virtual~AppPlatformListener();
    virtual void onLowMemory();
    virtual void onAppSuspended();
    virtual void onAppResumed();
    virtual void onAppFocusLost();
    virtual void onAppFocusGained();
    virtual void onAppTerminated();
    void initListener(float);
    void terminate();
};