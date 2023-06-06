#include "effect.h"
#include <cassert>

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


/************************************************************************
 * FRAGMENT RENDER
 * Draw the fragment on the screen
 *************************************************************************/
void FragmentInterface::render() const
{
    // Do nothing if we are already dead
    if (isDead())
        return;
    
    // Draw this sucker
    glBegin(GL_TRIANGLE_FAN);
    
    // the color is a function of age - fading to black
    glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);
    
    // draw the fragment
    glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() - size));
    glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() - size));
    glVertex2f((GLfloat)(pt.getX() + size), (GLfloat)(pt.getY() + size));
    glVertex2f((GLfloat)(pt.getX() - size), (GLfloat)(pt.getY() + size));
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/************************************************************************
 * STREEK RENDER
 * Draw the shrapnel streek on the screen
 *************************************************************************/
void StreekInterface::render() const
{
    // Do nothing if we are already dead
    if (isDead())
        return;
    
    // Draw this sucker
    glBegin(GL_LINES);
    glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);

    // Draw the actual line
    glVertex2f((GLfloat)pt.getX(), (GLfloat)pt.getY());
    glVertex2f((GLfloat)ptEnd.getX(), (GLfloat)ptEnd.getY());

    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/************************************************************************
 * EXHAUST RENDER
 * Draw a missile exhaust on the screen
 *************************************************************************/
void ExhaustInterface::render() const
{
   // Do nothing if we are already dead
   if (isDead())
       return;
   
   // Draw this sucker
   glBegin(GL_LINES);
   glColor3f((GLfloat)age, (GLfloat)age, (GLfloat)age);

   // Draw the actual line
   glVertex2f((GLfloat)pt.getX(), (GLfloat)pt.getY());
   glVertex2f((GLfloat)ptEnd.getX(), (GLfloat)ptEnd.getY());

   glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
   glEnd();
}