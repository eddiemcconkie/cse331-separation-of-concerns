#pragma once

#include "object-type.h"
#include "point.h"

class DrawableObject
{
public:
   ObjectType getType() { return type; }
   Point getPt() { return pt; }

private:
   ObjectType type;
   Point pt;

   static Point dimensions;
};

class CollidableObject : public DrawableObject
{
public:
   double getRadius() { return radius; }
   double isDead() { return dead; }
   void setDead(double dead) { this->dead = dead; }
   int getPoints() { return points; }
   void setPoints(int points) { this->points = points; }

private:
   double radius;
   bool dead;
   int points;
};
