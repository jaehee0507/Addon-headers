#pragma once

#include "ImageData.h"

namespace mce {
    class Texture;
}

//Size : 88
class TextureData {
    public:
    bool idk;                          //20
    //mce::Texture texture;
    char filler1[55];                  //21
    std::vector<ImageData> imgVec;     //76
    
    public:
    TextureData();
    TextureData(int, int, bool);
    TextureData(TextureData&&);
    ~TextureData();
    void _loadMipmap(ImageData&);
    void _loadTexData(mce::Texture&, bool, bool);
    void bind(unsigned int) const;
    void clear();
    void load();
    void loadMipmap(ImageData&);
    TextureData&& operator=(TextureData&&);
    void setData(std::string const&);
    void sync();
    void unbind(unsigned int);
    void unload();
};
