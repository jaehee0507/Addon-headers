#pragma once

#include <string>
#include <memory>
#include <functional>

class Options;
class AppPlatform;
class TextureData;
class TickingTexture;
class DynamicTexture;

class Textures {
    public:
    Textures(Options*, AppPlatform*);
    ~Textures();
    void addManualTexture(TextureData&);
    void addTickingTexture(std::unique_ptr<TickingTexture>);
    void bindDynamicTexture(DynamicTexture, int);
    void bindTexture(std::string const&, int, bool);
    void clear();
    void findOrLoadTexture(std::string const&);
    void getDynamicTextureData(DynamicTexture) const;
    void getDynamicTextureDataModify(DynamicTexture);
    void getTexture(std::string const&);
    void getTextureData(std::string const&);
    void loadDynamicTextures();
    void loadList(std::string const&, std::function<void ()>);
    void loadTexture(std::string const&, bool, bool, bool);
    void reloadAll();
    void removeManualTextureData(TextureData&);
    void tick(bool);
    void unloadAll();
    void uploadTexture(std::string const&, TextureData&);
};
