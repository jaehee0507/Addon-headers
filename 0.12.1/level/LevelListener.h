#pragma once

#include <string>
#include "TileSourceListener.h"

class ParticleType;
class Vec3;
class Entity;
class Player;
class LevelChunk;
class LevelEvent;

class LevelListener : public TileSourceListener {
    public:
    virtual ~LevelListener();
    virtual void allChanged();
    virtual void addParticle(ParticleType, Vec3 const&, Vec3 const&, int);
    virtual void playSound(std::string const&, float, float, float, float, float);
    virtual void playMusic(std::string const&, float, float, float, float);
    virtual void playStreamingMusic(std::string const&, int, int, int);
    virtual void onEntityAdded(Entity&);
    virtual void onEntityRemoved(Entity&);
    virtual void onNewChunkFor(Player&, LevelChunk&);
    virtual void levelEvent(LevelEvent, Vec3 const&, int);
};
