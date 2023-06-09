#pragma once
#include "point.h"

class EffectBaseLogic
{
public:
   // move it forward with regards to inertia. Let it age
   virtual void fly(EffectStorage* effect) = 0;
};

/**********************
 * FRAGMENT
 * Pieces that fly off a dead bird
 **********************/
class FragmentLogic : public EffectBaseLogic
{
   // move it forward with regards to inertia. Let it age
   void fly(Point pt, Velocity v, double age, double size);
};

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class StreekLogic : public EffectBaseLogic
{
   // move it forward with regards to inertia. Let it age
   void fly(double age);
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class ExhaustLogic : public EffectBaseLogic
{
   // move it forward with regards to inertia. Let it age
   void fly(double age);
};
