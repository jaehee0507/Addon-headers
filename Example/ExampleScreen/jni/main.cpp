#include <dlfcn.h>
#include <jni.h>
#include <string>
#include <memory>
#include <android/log.h>
#include "mcpelauncher.h"

#include "mcpe/gui/StartMenuScreen.h"
#include "mcpe/gui/TButton.h"
#include "mcpe/gui/ScreenChooser.h"
#include "MyScreen.h"
#include "MyScreen.cpp"

using namespace std;

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "affoaddon", __VA_ARGS__)
inline void HOOK(const char* sym, void* hook, void** org) {
    void* symb = dlsym(RTLD_DEFAULT, sym);
    mcpelauncher_hook(symb, hook, org);
}

class MinecraftClient;

Touch::TButton* myBtn;

void (*start_init)(Touch::StartMenuScreen*);
void start_init_hook(Touch::StartMenuScreen* thiz) {
    myBtn = new Touch::TButton(9034, "7357", thiz->mc, false, 0x7FFFFFFF);
    myBtn->xPosition = 0;
    myBtn->yPosition = 0;
    myBtn->width = 30;
    myBtn->height = 30;
    //I was lazy to hook setupPositions
    thiz->buttonList.push_back(myBtn);
    
    start_init(thiz);
}

void (*start_decon)(Touch::StartMenuScreen*);
void start_decon_hook(Touch::StartMenuScreen* thiz) {
    delete myBtn;
    
    start_decon(thiz);
}

void (*start_btn)(Touch::StartMenuScreen*, Button*);
void start_btn_hook(Touch::StartMenuScreen* thiz, Button* btn) {
    if(btn->id == myBtn->id) {
        ScreenChooser* sc = *(ScreenChooser**)(((uintptr_t) thiz->mc)+112);
        //Bcuz I didn't make MinecraftClient header :P
        
        shared_ptr<MyScreen> myscr(new MyScreen());
        sc->pushScreen(myscr, true);
    }
    start_btn(thiz, btn);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    
    HOOK("_ZN5Touch15StartMenuScreen4initEv", (void*) &start_init_hook, (void**) &start_init);
    HOOK("_ZN5Touch15StartMenuScreenD1Ev", (void*) &start_decon_hook, (void**) &start_decon);
    HOOK("_ZN5Touch15StartMenuScreen13buttonClickedEP6Button", (void*) &start_btn_hook, (void**) &start_btn);
        
	return JNI_VERSION_1_2;
}
