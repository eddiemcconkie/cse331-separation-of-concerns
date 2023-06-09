#pragma once

#include "overall-logic.h"
#include "birdInterface.h"
#include "bullet-interface.h"
#include "effect-interface.h"
#include "gun-interface.h"

class OverallInterface
{
public:
   DrawableObjectInterface* getObjectInterface(DrawableObject* storage);
   void tick();

private:
   void draw();

   OverallLogic logic;
   // Bird interface
   BirdStandardInterface birdStandardInterface;
   BirdFloaterInterface birdFloaterInterface;
   BirdSinkerInterface birdSinkerInterface;
   BirdCrazyInterface birdCrazyInterface;
   // Bullet interface
   BulletBaseInterface bulletInterface;
   BombInterface bombInterface;
   ShrapnelInterface shrapnelInterface;
   MissileInterface missileInterface;
   // Effect interface
   FragmentInterface fragmentInterface;
   StreekInterface streekInterface;
   ExhaustInterface exhaustInterface;
   // Other interface
   GunInterface gunInterface;
   ScoreInterface scoreInterface;
   HitRatioInterface hitRatioInterface;
};
