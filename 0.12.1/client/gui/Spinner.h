#pragma once

#include "GuiElement.h"

class Spinner : public GuiElement {
    public:
    Spinner();
    virtual ~Spinner();
    virtual void render(MinecraftClient*, int, int);
};
