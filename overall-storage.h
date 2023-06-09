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
   std::list<BirdStorage*> getBirds();
   std::list<BulletStorage*> getBullets();
   std::list<EffectStorage*> getEffects();
   GunStorage* getGun();
   ScoreStorage* getScore();
   HitRatioStorage* getHitRatio();
   Point* getDimensions();

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
