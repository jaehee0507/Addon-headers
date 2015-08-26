#pragma once

#include <memory>

class TileSource;
class TilePos;
class FullTile;
class TileEntity;

class TileSourceListener {
    public:
    //void** vtable;            //0
    
    public:
    virtual ~TileSourceListener();
    virtual void onSourceCreated(TileSource*);
    virtual void onSourceDestroyed(TileSource*);
    virtual void onTilesDirty(TileSource*, int, int, int, int, int, int);
    virtual void onAreaChanged(TileSource&, TilePos const&, TilePos const&);
    virtual void onTileChanged(TileSource*, TilePos const&, FullTile, FullTile, int);
    virtual void onBrightnessChanged(TileSource&, TilePos const&);
    virtual void onTileEntityChanged(TileSource&, TileEntity&);
    virtual void onTileEntityRemoved(TileSource&, std::unique_ptr<TileEntity>);
    virtual void onTileEvent(TileSource*, int, int, int, int, int);
};
