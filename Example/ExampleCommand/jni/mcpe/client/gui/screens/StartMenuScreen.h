#pragma once

#include <vector>
#include "Screen.h"
#include "../TButton.h"

class ImageWithBackground;

namespace Touch {
    
    //Size : 632
    class StartMenuScreen : public Screen {
        public:
        Touch::TButton playButton;            //212
        Touch::TButton realmButton;           //400
        ImageWithBackground* optionButton;    //588
        ImageWithBackground* languageButton;  //592
        char filler2[36];
        
        public:
        static int currentSplash;
        static std::vector<std::string> mSplashes;
        
        public:
        StartMenuScreen(void);
        virtual ~StartMenuScreen();
        virtual void tick();
        virtual bool handleBackEvent(bool);
        virtual void render(int, int, float);
        virtual void init();
        virtual void setupPositions();
        virtual void buttonClicked(Button*);
        virtual void controllerDirectionChanged(int, StickDirection);
        void _updateLicense();
        void chooseRandomSplash();
        void setupPlayButtons(bool);
    };
    
}
