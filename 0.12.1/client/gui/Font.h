#pragma once

#include <string>
#include <vector>
#include <functional>
#include "../AppPlatformListener.h"

class Textures;
class Color;
class Options;
class Tessellator;
namespace mce {
    class MaterialPtr;
}

class Font : public AppPlatformListener {
    public:
    class GlyphQuad {
        public:
        void append(Tessellator&) const;
    };
    class TextObject {
        public:
        void render(mce::MaterialPtr const&) const;
    };
    
    public:
    Font(Options*, std::string const&, Textures*);
    virtual ~Font();
    virtual void onAppSuspended();
    void _buildChar(std::vector<GlyphQuad>&, int, Color const&, bool, float, float, bool);
    void _makeTextObject(std::string const&, Color const&);
    void clearCache();
    bool containsUnicodeChar(std::string const&) const;
    bool containsWideChar(std::string const&) const;
    void draw(std::string const&, float, float, Color const&);
    void draw(std::string const&, float, float, Color const&, bool);
    void drawCached(std::string const&, float, float, Color const&, bool, mce::MaterialPtr*);
    void drawTransformed(std::string const&, float, float, Color const&, float, float, bool, float);
    void drawWordWrap(std::string const&, float, float, float, Color const&, bool, bool);
    int getCharWidth(int, bool) const;
    void getColorCode(char, float);
    int getLineLength(std::string const&) const;
    void getParagraphs(std::string const&);
    bool hasFormattingCodes(std::string const&);
    int height(std::string const&, int);
    void init(Options*);
    void resetFormat(Color const&);
    void setDefaultTexture();
    void setUnicodeTexture(int);
    void splitLinesInBox(std::string const&, int, std::function<void (std::string const&, int)>) const;
};
