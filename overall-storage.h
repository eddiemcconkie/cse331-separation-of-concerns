#pragma once

#include <list>
#include "birdStorage.h"
#include "bullet-storage.h"
#include "effect-storage.h"
#include "gun-storage.h"
#include "time.h"

class OverallStorage
{
public:
   void add(BirdStorage* bird);
   void add(BulletStorage* bird);
   void add(EffectStorage* bird);
   void remove(BirdStorage* bird);
   void remove(BulletStorage* bird);
   void remove(EffectStorage* bird);
   std::list<BirdStorage*> getBirds() { return birds; }
   std::list<BulletStorage*> getBullets() { return bullets; }
   std::list<EffectStorage*> getEffects() { return effects; }
   GunStorage* getGun() { return &gun; }
   ScoreStorage* getScore() { return &score; }
   HitRatioStorage* getHitRatio() { return &hitRatio; }
   const Point* getDimensions() { return &dimensions; }

private:
   std::list<BirdStorage*> birds;
   std::list<BulletStorage*> bullets;
   std::list<EffectStorage*> effects;
   GunStorage gun;
   Time time;
   ScoreStorage score;
   HitRatioStorage hitRatio;
   Point dimensions;
};
