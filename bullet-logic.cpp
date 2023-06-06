/***********************************************************************
 * Source File:
 *    Bullet
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that kills other things
 ************************************************************************/

#include "bullet.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32



/*********************************************
 * BOMB DEATH
 * Bombs have a tendency to explode!
 *********************************************/
void BombLogic::death(std::list<Bullet*>& bullets)
{
   for (int i = 0; i < 20; i++)
      bullets.push_back(new Shrapnel(*this));
}

 /***************************************************************/
 /***************************************************************/
 /*                             MOVE                            */
 /***************************************************************/
 /***************************************************************/

/*********************************************
 * BULLET MOVE
 * Move the bullet along by one time period
 *********************************************/
void BulletLogic::move(std::list<Effect*> & effects)
{
   // inertia
   pt.add(v);

   // out of bounds checker
   if (isOutOfBounds())
      kill();
}

/*********************************************
 * BOMB MOVE
 * Move the bomb along by one time period
 *********************************************/
void BombLogic::move(std::list<Effect*> & effects)
{
    // kill if it has been around too long
    timeToDie--;
    if (!timeToDie)
        kill();

    // do the inertia thing
    BulletLogic::move(effects);
}

/*********************************************
 * MISSILE MOVE
 * Move the missile along by one time period
 *********************************************/
void Missile::move(std::list<Effect*> & effects)
{
    // kill if it has been around too long
   effects.push_back(new Exhaust(pt, v));

    // do the inertia thing
    BulletLogic::move(effects);
}

/*********************************************
 * SHRAPNEL MOVE
 * Move the shrapnel along by one time period
 *********************************************/
void Shrapnel::move(std::list<Effect*> & effects)
{
    // kill if it has been around too long
    timeToDie--;
    if (!timeToDie)
        kill();

    // add a streek
    effects.push_back(new Streek(pt, v));
    
    // do the usual bullet stuff (like inertia)
    BulletLogic::move(effects);
}

/***************************************************************/
/***************************************************************/
/*                            OUTPUT                           */
/***************************************************************/
/***************************************************************/

/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Point& point)
{
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}


// /******************************************************************
//  * RANDOM
//  * This function generates a random number.
//  ****************************************************************/
// int Bullet::random(int min, int max)
// {
//    assert(min < max);
//    int num = (rand() % (max - min)) + min;
//    assert(min <= num && num <= max);
//    return num;
// }
// double Bullet::random(double min, double max)
// {
//    assert(min <= max);
//    double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
//    assert(min <= num && num <= max);
//    return num;
// }
