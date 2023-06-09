#pragma once
/***********************************************************************
 * Header File:
 *    BulletInterface
 * Author:
 *    Jared Tart and Elyssa Hancock
 ************************************************************************/

#pragma once
#include "point.h"
#include "effect.h"
#include <list>
#include <cassert>

 /*********************************************
  * BULLET
  * Something to shoot something else
  *********************************************/
class BulletBaseInterface : public DrawableObjectInterface
{
public:
   virtual void output() = 0;

protected:
   void drawLine(const Point& begin, const Point& end,
      double red = 1.0, double green = 1.0, double blue = 1.0) const;

   void drawDot(const Point& point, double radius = 2.0,
      double red = 1.0, double green = 1.0, double blue = 1.0) const;
};

/*********************
 * PELLET
 * Small little bullet
 **********************/
class PelletInterface : public BulletBaseInterface
{
public:
   void output(Point pt, double radius);
};

/*********************
 * BOMB
 * Things that go "boom"
 **********************/
class BombInterface : public BulletBaseInterface
{
public:
   void output(Point pt, double radius);
};

/*********************
 * Shrapnel
 * A piece that broke off of a bomb
 **********************/
class ShrapnelInterface : public BulletBaseInterface
{
public:
   void output(Point pt, double radius);
};


/*********************
 * MISSILE
 * Guided missiles
 **********************/
class MissileInterface : public BulletBaseInterface
{
public:
   void output(Point pt, Velocity v);
};
