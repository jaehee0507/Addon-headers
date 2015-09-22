#pragma once

#include <string>

class TextureData;

class SkinInfoData {
    public:
    //void** vtable;                //0
    bool _isSlim;                    //4
    
    public:
    SkinInfoData(bool);
    virtual ~SkinInfoData();
    virtual void updateSkin(std::string const&) = 0;
    virtual TextureData* getTextureData();
    virtual char* getData() = 0;
    virtual int getDataLength() = 0;
    virtual bool hasValidTexture() = 0;
    virtual void validataAndResizeSkinData(std::string&);
    void copySkinPart(std::string&, int, int, int, int, int, int, int, int);
    bool isSlim();
    void setForceAlpha(std::string&, int, int, int, int);
    void setNoAlpha(std::string&, int, int, int, int);
};
