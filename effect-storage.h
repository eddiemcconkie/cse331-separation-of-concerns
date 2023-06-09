#pragma once
/***********************************************************************
 * Header File:
 *    Fragment : Pieces that fly off a dead bird
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Pieces that fly off a dead bird
 ************************************************************************/

#pragma once
#include "object.h"
#include "point.h"

 /**********************
  * Effect: stuff that is not interactive
  **********************/
class EffectStorage : public DrawableObject
{
protected:
   Point pt;      // location of the effect
   double age;    // 1.0 = new, 0.0 = dead
public:
   // create a fragment based on the velocity and position of the bullet
   EffectStorage(const Point& pt) : pt(pt), age(0.5) {}

   // it is dead when age goes to 0.0
   bool isDead() const { return age <= 0.0; }
};