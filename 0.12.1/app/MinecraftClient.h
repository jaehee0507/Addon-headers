#pragma once

#include "Minecraft.h"

class ScreenChooser;
class LevelRenderer;
class GameRenderer;
class ParticleEngine;
class ExternalServerFile;
class Textures;
class Font;
class LocalPlayer;
class MinecraftInputHandler;
class Gui;
class UIDefinitionStore;
class Options;
class MusicManager;
class MobEffectsLayout;
class GameStore;
class SkinRepository;
namespace Social {
    class UserManager;
    class MultiPlayer;
}
class MinecraftTelemetry;
class BuildActionIntention;
class DirectionId;
class InputMode;
class Side;
namespace UI {
    class GameEventNotification;
}
class AbstractScreen;
class Screen;
class Dimension;

//Size : 448
class MinecraftClient : public Minecraft {
    public:
    Vibration* vibration;                //108
    ScreenChooser* screenChooser;        //112
    char filler1[28];                    //116
    int width;                           //144
    int height;                          //148
    LevelRenderer* levelRenderer;        //152
    GameRenderer* gameRenderer;          //156
    ParticleEngine* particleEngine;      //160
    ExternalServerFile* serverFile;      //164
    Textures* textures;                  //168
    Font* font;                          //172
    char filler2[108];                   //176
    LocalPlayer* player;                 //284
    MinecraftInputHandler* inputHandler; //288
    Gui* gui;                            //292
    UIDefinitionStore* defStore;         //296
    Options* options;                    //300
    SoundEngine* soundEngine;            //304
    MusicManager* musicManager;          //308
    char filler3[12];                    //312
    MobEffectsLayout* mobEffectLayout;   //324
    GameStore* gameStore;                //328
    SkinRepository* skinRepo;            //332
    Social::UserManager* userManager;    //336
    Social::MultiPlayer* multiPlayer;    //340
    char filler4[56];                    //344
    float dpadScale;                     //380
    char filler5[48];                    //384
    int keyboardHeight;                  //432
    MinecraftTelemetry* mcTelemetry;     //436
    char filler6[8];                     //440
    
    public:
    static int _hasInitedStatics;
    static void* INTERACTION_FREQ_MS;
    
    public:
    MinecraftClient(int, char**);
    virtual ~MinecraftClient();
    virtual void onLowMemory();
    virtual void onAppSuspended();
    virtual void onAppResumed();
    virtual void onAppFocusLost();
    virtual void onAppFocusGained();
    virtual void audioEngineOn();
    virtual void audioEngineOff();
    virtual void muteAudio();
    virtual void unMuteAudio();
    virtual void useTouchscreen();
    virtual void setTextboxText(std::string const&);
    virtual void setSize(int, int, float);
    virtual void init();
    virtual void teardown();
    virtual void setGameMode(GameType);
    virtual void startFrame();
    virtual void updateGraphics(Timer const&);
    virtual void endFrame();
    virtual void tick(int, int);
    virtual void leaveGame(bool);
    virtual void setupCommandParser(ServerCommandParser&);
    virtual void play(std::string const&, float, float, float, float, float);
    virtual void playUI(std::string const&, float, float);
    virtual bool isServerVisible();
    virtual void sendLocalMessage(std::string const&, std::string const&);
    virtual Player* getPlayer();
    virtual void onInternetUpdate();
    virtual void onPrepChangeDimension(Player&);
    virtual void onDimensionChanged(Player&);
    virtual void createLocalClientNetworkHandler();
    virtual Vibration* getVibration();
    virtual void createSkin(bool);
    virtual SoundEngine* getSoundPlayer();
    virtual void handleBack(bool);
    virtual void handleBack();
    virtual LocalPlayer* getLocalPlayer();
    virtual void vibrate(int);
    void _reloadFancy(bool);
    void _reloadLanguages();
    void allowPicking() const;
    void cancelLocateMultiplayer();
    void freeResources(bool);
    float getDpadScale();
    Gui* getGui();
    MinecraftInputHandler* getInput();
    int getKeyboardHeight();
    Social::MultiPlayer* getMultiplayer() const;
    Options* getOptions();
    Screen* getScreen();
    Screen* getScreen() const;
    void getSituationalMusic();
    SkinRepository* getSkinRepository();
    UIDefinitionStore* getUIDefStore();
    Social::UserManager* getUserManager() const;
    void grabMouse();
    void handleAttackActionButtonRelease();
    void handleBackNoReturn();
    void handleBiomeDisplayButtonPress();
    void handleBuildAction(BuildActionIntention&);
    void handleBuildActionButtonRelease();
    void handleBuildOrAttackButtonPress();
    void handleBuildOrInteractButtonPress();
    void handleChatButtonPress();
    void handleConsoleButtonPress();
    void handleCraftingButtonPress();
    void handleDecreaseRenderDistanceButtonPress();
    void handleDecrementMaxCullingStepsButtonPress();
    void handleDestoryOrAttackButtonPress();
    void handleDestroyOrInteractButtonPress();
    void handleDirection(DirectionId, float, float);
    void handleDismountButtonPress();
    void handleDropAllButtonPress();
    void handleDropAllItemsButtonPress();
    void handleDropButtonPress();
    void handleHideGuiButtonPress();
    void handleIncreaseRenderDistanceButtonPress();
    void handleIncrementMaxCullingStepsButtonPress();
    void handleInputModeChanged(InputMode);
    void handleInteractButtonPress();
    void handleInventoryButtonPress();
    void handleInventoryMoveButtonPress(int);
    void handleInvite();
    void handleLicenseChanged();
    void handleLowMemoryWarningButtonPress();
    void handleMemoryStatsButtonPress();
    void handleMenuButtonPress(short);
    void handleMenuButtonRelease(short);
    void handleMobEffectsButtonPress();
    void handleNextAVCStatButtonPress();
    void handleNextAVCStatButtonRelease();
    void handlePaddleButtonPress(Side);
    void handlePaddleButtonRelease(Side);
    void handlePauseButtonPress();
    void handlePointerLocation(short, short);
    void handlePointerPressedButtonPress();
    void handlePointerPressedButtonRelease();
    void handleReloadUIDefinitions();
    void handleRenderDebugButtonPress();
    void handleSetSpawnPositionButtonPress();
    void handleShowUpsellScreen(bool);
    void handleSlotSelectButtonPress(int);
    void handleSuspendResumeButtonPress();
    void handleTextChar(std::string const&, bool);
    void handleTimeStepForwardButtonPress();
    void handleToggleAdvancedCullingButtonPress();
    void handleToggleDayCycleActiveButtonPress();
    void handleToggleEnableNewScreensButtonPress();
    void handleToggleEnableNewScreensDebugButtonPress();
    void handleToggleFlyFlastButtonPress();
    void handleToggleFrameTimerDisplayButtonPress();
    void handleToggleGameModeButtonPress();
    void handleToggleNoClipButtonPress();
    void handleTogglePlayerUpdateMobsButtonPress();
    void handleToggleShowChunkMapButtonPress();
    void handleToggleSimulateTouchButtonPress();
    void handleToggleThirdPersonViewButtonPress();
    void initFoliageAndTileTextureTessellator();
    void initializeTrialWorld(Player*);
    void initOptionObservers();
    void initSnoopClient();
    void isKindleFire(int);
    void isScreenReplaceable() const;
    void isShowingMenu();
    void joinLiveGame(std::string const&);
    void joinMultiplayer(char const*, int, bool);
    void locateMultiplayer();
    void onClientStartedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
    void onGameEventNotification(UI::GameEventNotification);
    void onMobEffectsChange();
    void onPlayerLoaded(Player&);
    void onUserSignin();
    void onUserSignout();
    void popScreen();
    void pushScreen(std::shared_ptr<AbstractScreen>, bool);
    void rebuildLevel();
    void refocusMouse();
    void releaseMouse();
    void ResetBai(int);
    void resetInput();
    void restartServer();
    void sendHardwareSnoopEvent();
    void setDpadScale(float);
    void setKeyboardHeight(int);
    void setupLevelRendering(Level*, Dimension*, Mob*);
    void setupRenderer();
    void startLocalServer(std::string, std::string, LevelSettings);
    void teardownRenderer();
    void tickBuildAction();
    void tickInput();
    void transformResolution(int*, int*);
    void updateScheduledScreen();
    void updateStats();
    void useController();
};
