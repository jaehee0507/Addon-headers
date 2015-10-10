#pragma once

#include <string>
#include <vector>
#include "TextureUVCoordinateSet.h"

class TextureAtlasTextureItem {
    public:
    TextureAtlasTextureItem(TextureAtlasTextureItem const&);
    TextureAtlasTextureItem(std::string const&, std::vector<TextureUVCoordinateSet> const&);
    std::string getName() const;
    TextureUVCoordinateSet operator[](int) const;
    int uvCount() const;
};
