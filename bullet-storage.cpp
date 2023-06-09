#include "bullet-storage.h"

BulletStorage::BulletStorage(double angle, double speed, double radius, int value) :
   dead(false), radius(radius), value(value)
{
   // set the initial position
   pt.setX(dimensions.getX() - 1.0);
   pt.setY(1.0);
   assert(pt.getX() > 100.0);

   // set the initial velocity
   v.setDx(-speed * cos(angle));
   v.setDy(speed * sin(angle));
   assert(v.getDx() <= 0.0);
   assert(v.getDy() >= 0.0);
}

int BulletStorage::random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}
double BulletStorage::random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}