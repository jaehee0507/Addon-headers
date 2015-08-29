#pragma once

#include <functional>
#include <string>
#include <vector>

//Size : 224
class Options {
    public:
    class Option {
        public:
        char filler1[8];
        
        public:
        static Options::Option ANIMATE_TEXTURES;
        static Options::Option AUTO_JUMP;
        static Options::Option DESTROY_VIBRATION;
        static Options::Option DIFFICULTY;
        static Options::Option DPAD_SCALE;
        static Options::Option FANCY_SKIES;
        static Options::Option FIELD_OF_VIEW;
        static Options::Option FULLSCREEN;
        static Options::Option GAMEPAD_MAP;
        static Options::Option GAMMA;
        static Options::Option GRAPHICS;
        static Options::Option GUI_SCALE;
        static Options::Option HIDE_GUI;
        static Options::Option INVERT_MOUSE;
        static Options::Option KEYBOARD_LAYOUT;
        static Options::Option LEFT_HANDED;
        static Options::Option LIMIT_FRAMERATE;
        static Options::Option LIMIT_WORLD_SIZE;
        static Options::Option MUSIC;
        static Options::Option NAME;
        static Options::Option RENDER_BOUNDING_BOXES;
        static Options::Option RENDER_GOAL_STATE;
        static Options::Option RENDER_PATHS;
        static Options::Option RESET_CLIENT_ID;
        static Options::Option SENSITIVITY;
        static Options::Option SERVER_VISIBLE;
        static Options::Option SOUND;
        static Options::Option SPLIT_CONTROLS;
        static Options::Option SWAP_JUMP_AND_SNEAK;
        static Options::Option THIRD_PERSON;
        static Options::Option USE_TOUCHSCREEN;
        static Options::Option VIEW_BOBBING;
        static Options::Option VIEW_DISTANCE;
        static Options::Option XBOX_LIVE_VISIBLE;
        
        public:
        ~Option();
    };
    
    public:
    float music;                                    //0
    float sound;                                    //4
    float sensivity;                                //8
    char filler1[4];                                //12
    bool invert_mouse;                              //16
    char filler2[3];                                //17
    int view_distance;                              //20
    bool view_bobbing;                              //24
    bool limit_framerate;                           //25
    bool graphics;                                  //26
    char filler3[2];                                //27
    bool left_handed;                               //29
    bool destroy_vibration;                         //30
    bool auto_jump;                                 //31
    bool fullscreen;                                //32
    char filler4[3];                                //33
    int keyboard_layout;                            //36
    std::string gamepad_map;                        //40
    char filler5[4];                                //44
    int difficulty;                                 //48
    bool hide_gui;                                  //52
    char filler6[3];                                //53
    int third_person;                               //56
    char filler7[4];                                //60
    float gamma;                                    //64
    float field_of_view;                            //68
    char filler8[16];                               //72
    std::string name;                               //88
    char filler9[8];                                //92
    bool server_visible;                            //100
    bool split_control;                             //101
    bool swap_jump_and_sneak;                       //102
    bool use_touchScreen;                           //103
    bool fancy_skies;                               //104
    bool animate_textures;                          //105
    char filler10[18];                              //106
    float dpad_scale;                               //124
    char filler11[7];                               //128
    bool render_boundingBoxes;                      //135
    bool render_paths;                              //136
    bool render_goal_state;                         //137
    bool render_clientId;                           //138
    bool limit_world_size;                          //139
    char filler12[4];                               //140
    bool xbox_live_visible;                         //144
    char filler13[79];                              //145
    
    public:
    static void* debugGl;
    
    public:
    Options(std::string const&);
    ~Options();
    void _renderDistanceLevels();
    void _setDifficulty(int);
    bool canModify(Options::Option const*);
    void checkVersionUpdate();
    void formatDescriptionString(char const*, char const**, int);
    bool getBooleanValue(Options::Option const*);
    std::string getDescription(Options::Option const*, std::string);
    int getIntValue(Options::Option const*);
    std::string getMessage(Options::Option const*);
    float getProgressMax(Options::Option const*);
    float getProgressMin(Options::Option const*);
    float getProgressValue(Options::Option const*);
    std::string getStringValue(Options::Option const*);
    void getValues(Options::Option const*);
    void hideOption(Options::Option const*);
    void initDefaultValues();
    void load();
    void onScreenSizeChanged(int, int);
    void readBool(std::string const&, bool&);
    void readFloat(std::string const&, float&);
    void readInt(std::string const&, int&);
    void registerBoolObserver(void*, Options::Option const&, std::function<void (bool)>);
    void registerFloatObserver(void*, Options::Option const&, std::function<void (float)>);
    void registerIntObserver(void*, Options::Option const&, std::function<void (int)>);
    void registerOptionLock(void*, Options::Option const&, std::function<bool ()>);
    void registerStringObserver(void*, Options::Option const&, std::function<void (std::string)>);
    void save();
    void set(Options::Option const*, bool);
    void set(Options::Option const*, float);
    void set(Options::Option const*, int);
    void set(Options::Option const*, std::string const&);
    void setAdditionalHiddenOptions(std::vector<Options::Option const*> const&);
    void toggle(Options::Option const*, int);
    void unregisterLocks(void*);
    void unregisterObserver(void*);
    void updateGameSensitivity();
};