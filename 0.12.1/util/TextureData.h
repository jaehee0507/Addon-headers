#pragma once

class ImageData;
namespace mce {
    class Texture;
}

//Size : 88
class TextureData {
    public:
    int width;                     //0
    int height;                    //4
    char* pixels;                  //8
    char filler1[8];               //12
    bool idk;                      //20
    char filler2[3];               //21
    //mce::Texture texture;        //24
    //std::vector<ImageData>;      //76
    char filler3[64];              //24
    
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
