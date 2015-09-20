#pragma once

class ImageData;
namespace mce {
    class Texture;
}

class TextureData {
    public:
    int width;                     //0
    int height;                    //4
    char* pixels;                  //8
    bool idk;                      //20
    //mce::Texture texture;        //24
    char filler1[64];              //24
    
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
