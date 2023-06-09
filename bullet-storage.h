#pragma once

#include "object.h"
#include "point.h"
#include "effect.h"
#include <list>
#include <cassert>

class BulletStorage : public CollidableObject
{
protected:
   static Point dimensions;   // size of the screen
   Point pt;                  // position of the bullet
   Velocity v;                // velocity of the bullet
   double radius;             // the size (radius) of the bullet
   bool dead;                 // is this bullet dead?
   int value;                 // how many points does this cost?

public:
   BulletStorage(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1);

   // setters
   void kill() { dead = true; }

   // getters
   bool isDead()           const { return dead; }
   Point getPosition()     const { return pt; }
   Velocity getVelocity()  const { return v; }
   double getRadius()      const { return radius; }
   int getValue()          const { return value; }

protected:
   int    random(int    min, int    max);
   double random(double min, double max);
};
