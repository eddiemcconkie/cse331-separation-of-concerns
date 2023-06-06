#include "BulletInterface.h"

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

/*************************************************************************
 * GL VERTEXT POINT
 * Just a more convenient format of glVertext2f
 *************************************************************************/
inline void glVertexPoint(const Point& point)
{
   glVertex2f((GLfloat)point.getX(), (GLfloat)point.getY());
}

/************************************************************************
 * DRAW LINE
 * Draw a line on the screen from the beginning to the end.
 *************************************************************************/
void BulletBaseInterface::drawLine(const Point& begin, const Point& end,
   double red, double green, double blue) const
{
   // Get ready...
   glBegin(GL_LINES);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);

   // Draw the actual line
   glVertexPoint(begin);
   glVertexPoint(end);

   // Complete drawing
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/************************************************************************
 * DRAW DOT
 * Draw a single point (square actually on the screen, r pixels by r pixels
 *************************************************************************/
void BulletBaseInterface::drawDot(const Point& point, double radius,
   double red, double green, double blue) const
{
   // Get ready, get set...
   glBegin(GL_TRIANGLE_FAN);
   glColor3f((GLfloat)red, (GLfloat)green, (GLfloat)blue);
   double r = radius / 2.0;

   // Go...
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() - r));
   glVertex2f((GLfloat)(point.getX() + r), (GLfloat)(point.getY() + r));
   glVertex2f((GLfloat)(point.getX() - r), (GLfloat)(point.getY() + r));

   // Done!  OK, that was a bit too dramatic
   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}

/*********************************************
 * PELLET OUTPUT
 * Draw a pellet - just a 3-pixel dot
 *********************************************/
void PelletInterface::output(Point pt, double radius)
{
   drawDot(pt, 3.0, 1.0, 1.0, 0.0);
}

/*********************************************
 * BOMB OUTPUT
 * Draw a bomb - many dots to make it have a soft edge
 *********************************************/
void BombInterface::output(Point pt, double radius)
{
   // Bomb actually has a gradient to cut out the harsh edges
   drawDot(pt, radius + 2.0, 0.50, 0.50, 0.00);
   drawDot(pt, radius + 1.0, 0.75, 0.75, 0.00);
   drawDot(pt, radius + 0.0, 0.87, 0.87, 0.00);
   drawDot(pt, radius - 1.0, 1.00, 1.00, 0.00);
}

/*********************************************
 * SHRAPNEL OUTPUT
 * Draw a fragment - a bright yellow dot
 *********************************************/
void ShrapnelInterface::output(Point pt, double radius)
{
   drawDot(pt, radius, 1.0, 1.0, 0.0);
}

/*********************************************
 * MISSILE OUTPUT
 * Draw a missile - a line and a dot for the fins
 *********************************************/
void MissileInterface::output(Point pt, Velocity v)
{
   
   // missile is a line with a dot at the end so it looks like fins.
   Point ptNext(pt);
   ptNext.add(v);
   drawLine(pt, ptNext, 1.0, 1.0, 0.0);
   drawDot(pt, 3.0, 1.0, 1.0, 1.0);
  
}