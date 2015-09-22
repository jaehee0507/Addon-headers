#pragma once

#include "SkinInfoData.h"

class ClientSkinInfoData : public SkinInfoData {
    public:
    TextureData* textureData;          //8
    
    public:
    static void* textures;
    
    public:
    ClientSkinInfoData(bool);
    virtual ~ClientSkinInfoData();
    virtual void updateSkin(std::string const&);
    virtual TextureData* getTextureData();
    virtual char* getData();
    virtual int getDataLength();
    virtual bool hasValidTexture();
};
