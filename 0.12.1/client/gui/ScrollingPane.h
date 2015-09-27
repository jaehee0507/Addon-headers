#pragma once

#include <vector>
#include "GuiElement.h"
#include "ScrollBar.h"

class Vec3;
class IntRectangle;

//Size : 788
class ScrollingPane : public GuiElement {
    public:
    class GridItem {};
    
    public:
    char filler1[4];                        //120
    int columns;                            //124
    int rows;                               //128
    int itemsNum;                           //132
    char filler2[404];                      //136
    int selectedItemId;                     //540
    char filler3[4];                        //544
    ScrollBar verticleScroll;               //548
    ScrollBar scroll2;                      //632
    char filler4[64];                       //636
    bool refresh;                           //780
    bool renderSelected;                    //781
    char filler5[6];                        //782
    
    public:
    ScrollingPane(int, IntRectangle const&, IntRectangle const&, int, int, float, IntRectangle const&);
    virtual ~ScrollingPane();
    virtual void renderBatch(std::vector<ScrollingPane::GridItem>&, float, float, float);
    virtual void renderItem(ScrollingPane::GridItem&, float);
    virtual void didEndDragging();
    virtual void didEndDecelerating();
    virtual void willBeginDecelerating();
    virtual void willBeginDragging();
    virtual void onSelect(int, bool);
    virtual void refreshItems();
    int _getAdditionalScrollBarWidth();
    void _handleMouseInput(float, bool);
    void _onSelect(int);
    void addDeltaPos(float, float, float, int);
    void addFlag(int);
    void adjustContentSize();
    void beginTracking(float, float, int);
    void calculateAndSetCurrentMouseScrollT();
    void contentOffset();
    int getAdditionalScrollBarWidth() const;
    int getAdditionalScrollBarWidth(MinecraftClient*);
    int getColumns();
    void getContentOffset();
    void getGridItemFor_slow(int, ScrollingPane::GridItem&);
    void getItemForPos(float, float, bool);
    int getNumItems();
    int getRows();
    float getScrollT() const;
    int getSelectedItemId();
    ScrollBar getVerticleScrollBar();
    void handleMouseInput(float);
    void handleUserInput(bool);
    void hideScrollIndicators();
    void onHoldItem();
    void onNavigate(int);
    void queryHoldTime(int*, int*);
    void recalculateRows(int);
    void refreshPane();
    void render(int, int, float, MinecraftClient*);
    void scrollDownBy(float);
    void scrollUpBy(float);
    void setContentOffset(float, float);
    void setContentOffset(Vec3);
    void setContentOffsetWithAnimation(Vec3, bool);
    void setNumItems(int);
    void setRenderSelected(bool);
    void setScrollT(float);
    void setSelected(int, bool);
    bool shouldRenderSelected();
    bool shouldUseMouseScrollbarLayout(MinecraftClient*);
    void snapContentOffsetToBounds(bool);
    void startDecelerationAnimation(bool);
    void stepThroughDecelerationAnimation(bool);
    void stopDecelerationAnimation();
    void thereAreMoreItemsToDisplay(); const
    void thereAreMoreItemsToDisplay(int, int, int);
    void tick();
    void touchesBegan(float, float, int);
    void touchesCancelled(float, float, int);
    void touchesEnded(float, float, int);
    void touchesMoved(float, float, int);
    void translate(float, float);
    void UpdateHighlightItem(float, float);
    void updateHorizontalScrollIndicator();
    void updateScrollBarScale(int, int, int, int);
    void updateScrollBoxSize(float);
    void updateScrollFade(ScrollBar&);
    void updateVerticalScrollIndicator();
};

