#include "EffectLogic.h"

void FragmentLogic::fly(Point pt, Velocity v, double age, double size)
{
   // move it forward with inertia (no gravity)
   pt += v;

   // increase the age so it fades away
   age -= 0.02;
   size *= 0.95;
}

/************************************************************************
 * STREEK FLY
 * The streek will just fade away
 *************************************************************************/
void StreekLogic::fly(double age)
{
   // increase the age so it fades away
   age -= 0.10;
}

/************************************************************************
 * EXHAUST FLY
 * The exhaust will just fade away
 *************************************************************************/
void ExhaustLogic::fly(double age)
{
   // increase the age so it fades away
   age -= 0.025;
}