#pragma once

#include <string>
#include "TextureFile.h"
#include "TextureAtlasTextureItem.h"

namespace Json {
    class Value;
}
class Minecraft;

class TextureAtlas {
    public:
    TextureAtlas(std::string const&, TextureFile);
    void _parseJSON(Json::Value const&);
    TextureAtlasTextureItem getTextureItem(std::string const&) const;
    void load(Minecraft*);
};
