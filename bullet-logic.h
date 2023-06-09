#pragma once
#include "point.h"
#include "effect.h"
#include <list>
#include <cassert>


class BulletLogic
{

public:
   virtual void death(std::list<Bullet*>& bullets) {}
   virtual void input(bool isUp, bool isDown, bool isB) {}
   //virtual void move(std::list<Effect*>& effects);
   virtual void move(BulletStorage* bullet);
   void kill(BulletStorage* bullet) { bullet->setDead(true); }

   bool isOutOfBounds(BulletStorage* bullet) const
   {
      //return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
         //pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

protected:
};


/*********************
 * BOMB
 * Things that go "boom"
 **********************/
class BombLogic : public BulletLogic
{
private:
   int timeToDie;
public:
   BombLogic(double angle, double speed = 10.0) : Bullet(angle, speed, 4.0, 4), timeToDie(60) {} //?
   
   void move(std::list<Effect*> & effects);
   void death(std::list<Bullet *> & bullets);
};

/*********************
 * Shrapnel
 * A piece that broke off of a bomb
 **********************/
class ShrapnelLogic : public BulletLogic
{
private:
   int timeToDie;
public: 
   void move(std::list<Effect*> & effects);
};


/*********************
 * MISSILE
 * Guided missiles
 **********************/
class MissileLogic : public BulletLogic
{
public:

   void input(bool isUp, bool isDown, bool isB)
   {
      if (isUp)
         v.turn(0.04);
      if (isDown)
         v.turn(-0.04);
   }
   void move(std::list<Effect*> & effects);
};
