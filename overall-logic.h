#pragma once

#include "overall-storage.h"
#include "birdLogic.h"
#include "bullet-logic.h"
#include "effect-logic.h"
#include "gun-logic.h"

class OverallLogic
{
public:
   BirdBaseLogic* getObjectLogic(BirdStorage* storage);
   BulletLogic* getObjectLogic(BulletStorage* storage);
   EffectBaseLogic* getObjectLogic(EffectStorage* storage);

private:
   OverallStorage storage;
   // Bird logic
   BirdStandardLogic birdStandardLogic;
   BirdFloaterLogic birdFloaterLogic;
   BirdSinkerLogic birdSinkerLogic;
   BirdCrazyLogic birdCrazyLogic;
   // Bullet logic
   BulletLogic bulletLogic;
   BombLogic bombLogic;
   ShrapnelLogic shrapnelLogic;
   MissileLogic missileLogic;
   // Effect logic
   FragmentLogic fragmentLogic;
   StreekLogic streekLogic;
   ExhaustLogic exhaustLogic;
   // Other logic
   GunLogic gunLogic;
   ScoreLogic scoreLogic;
   HitRatioLogic hitRatioLogic;
};
