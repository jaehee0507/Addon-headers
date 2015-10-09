#pragma once

#include <vector>
#include <string>
#include "GuiComponent.h"
#include "../AppPlatformListener.h"
#include "../renderer/MaterialPtr.h"

class ControllerButtonRenderer;
class Config;
class Tessellator;
class RectangleArea;
class MobEffectsLayout;
class InputMode;
class ItemInstance;

//Size : 3048
class Gui : public GuiComponent, public AppPlatformListener {
    public:
    char filler1[16];                                     //84
    short pointX;                                         //100
    short pointY;                                         //102
    char filler2[2544];                                   //104
    MinecraftClient* mc;                                  //2648
    char filler3[40];                                     //2652
    std::string nowPlaying;                               //2692
    int playingFor;                                       //2696
    bool isPlaying;                                       //2700
    char filler4[31];                                     //2701
    int numSlots;                                         //2732
    char filler5[244];                                    //2736
    std::string tipMessage;                               //2980
    float tipMessageAlpha;                                //2984
    int tipMessageLength;                                 //2988
    char filler6[4];                                      //2992
    ControllerButtonRenderer* ctrlBtnRenderer;            //2996
    mce::MaterialPtr material1;                           //3000
    mce::MaterialPtr material2;                           //3012
    char filler7[24];                                     //3024
    
    public:
    static float BUTTONS_TRANSPARENCY;
    static float DropTicks;
    static float GuiScale;
    static float InvGuiScale;
    
    public:
    Gui(MinecraftClient&);
    virtual ~Gui();
    virtual void onAppSuspended();
    virtual void onConfigChanged(Config const&);
    void _buildFeedbackCircle();
    void _buildInnerFeedbackCircle(int, float);
    void _buildOuterFeedbackCircle(int, float, float);
    void _updateHudPositions();
    void addMessage(std::string const&, std::string const&, int, bool);
    void clearMessages();
    void cubeSmoothStep(float, float, float);
    void displayChatMessage(std::string const&, std::string const&);
    void displayClientMessage(std::string const&);
    void displayLocalizableMessage(std::string const&, std::vector<std::string> const&);
    void displaySystemMessage(std::string const&);
    void drawRectangleArea(Tessellator&, RectangleArea const*, int, int, float);
    void drawRectangleArea(Tessellator&, RectangleArea const*, int, int, float, float);
    void flashSlot(int);
    void floorAlignToScreenPixel(float);
    void forceMuteChat();
    int getNumSlots() const;
    void getSlotIdAt(int, int) const;
    void getSlotPos(int, int&, int&);
    void handleClick();
    void inventoryUpdated();
    bool isInside(int, int);
    void itemCountItoa(char*, int);
    void onLevelGenerated();
    void onMobEffectsChanged(MobEffectsLayout const&);
    void postError(int);
    void render(float, bool, int, int);
    void renderBubbles();
    void renderChatMessages(int, int, unsigned int, bool, Font*);
    void renderExperience();
    void renderHearts();
    void renderHunger();
    void renderOnSelectItemNameText(int, Font*, int);
    void renderPortalOverlay(float, int, int);
    void renderProgressIndicator(InputMode, int, int, float);
    void renderSleepAnimation(int, int);
    void renderSlot(int, int, int, float);
    void renderSlotText(ItemInstance const*, float, float, bool, bool, bool);
    void renderToolBar(float, float);
    void renderVignette(float, int, int);
    void setNowPlaying(std::string const&);
    void setShowProgress(bool);
    void setTouchToolbarArea(RectangleArea const&);
    void showPopupNotice(std::string const&, std::string const&);
    void showTipMessage(std::string const&);
    void tick();
    void tickItemDrop();
    void toggleMuteChat();
    void updatePointerLocation(short, short);
    bool wasToolbarClicked() const;
};

