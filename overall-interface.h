#pragma once

#include "overall-storage.h"
#include "birdInterface.h"
#include "bullet-interface.h"
#include "effect-interface.h"
#include "gun-interface.h"

class OverallInterface
{
public:
   DrawableObjectInterface* getObjectInterface(DrawableObject* storage);

private:
   OverallStorage storage;
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
