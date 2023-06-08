#pragma once

#include "point.h"
#include "birdStorage.h"
#include <cassert>

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

class BirdBaseInterface
{
public:
	virtual void draw(BirdStorage birdStorage) = 0;

protected:
    /************************************************************************
 * DRAW Disk
 * Draw a filled circule at [center] with size [radius]
 *************************************************************************/
    void drawDisk(const Point& center, double radius,
        double red, double green, double blue)
    {
        assert(radius > 1.0);
        const double increment = M_PI / radius;  // bigger the circle, the more increments

        // begin drawing
        glBegin(GL_TRIANGLES);
        glColor3f((GLfloat)red /* red % */, (GLfloat)green /* green % */, (GLfloat)blue /* blue % */);

        // three points: center, pt1, pt2
        Point pt1;
        pt1.setX(center.getX() + (radius * cos(0.0)));
        pt1.setY(center.getY() + (radius * sin(0.0)));
        Point pt2(pt1);

        // go around the circle
        for (double radians = increment;
            radians <= M_PI * 2.0 + .5;
            radians += increment)
        {
            pt2.setX(center.getX() + (radius * cos(radians)));
            pt2.setY(center.getY() + (radius * sin(radians)));

            glVertex2f((GLfloat)center.getX(), (GLfloat)center.getY());
            glVertex2f((GLfloat)pt1.getX(), (GLfloat)pt1.getY());
            glVertex2f((GLfloat)pt2.getX(), (GLfloat)pt2.getY());

            pt1 = pt2;
        }

        // complete drawing
        glEnd();
    }

};

class BirdStandardInterface : public BirdBaseInterface {
public:
	void draw(BirdStorage birdStorage) {
        /*********************************************
     * STANDARD DRAW
     * Draw a standard bird: blue center and white outline
     *********************************************/
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 0.0, 1.0, 1.0, 1.0); // white outline
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 3.0, 0.0, 0.0, 1.0); // blue center
    }
};

class BirdFloaterInterface : public BirdBaseInterface {
public:
    void draw(BirdStorage birdStorage) {
        /*********************************************
     * STANDARD DRAW
     * Draw a standard bird: blue center and white outline
     *********************************************/
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 0.0, 0.0, 0.0, 1.0); // blue outline
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 4.0, 1.0, 1.0, 1.0); // white center
    }
};

class BirdSinkerInterface : public BirdBaseInterface {
public:
    void draw(BirdStorage birdStorage) {
        /*********************************************
     * STANDARD DRAW
     * Draw a standard bird: blue center and white outline
     *********************************************/
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 0.0, 0.0, 0.0, 0.8);
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() - 4.0, 0.0, 0.0, 0.0);
    }
};

class BirdCrazyInterface : public BirdBaseInterface {
public:
    void draw(BirdStorage birdStorage) {
        /*********************************************
     * STANDARD DRAW
     * Draw a standard bird: blue center and white outline
     *********************************************/
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() * 1.0, 0.0, 0.0, 1.0); // bright blue outside
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() * 0.8, 0.2, 0.2, 1.0);
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() * 0.6, 0.4, 0.4, 1.0);
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() * 0.4, 0.6, 0.6, 1.0);
        drawDisk(birdStorage.getPosition(), birdStorage.getRadius() * 0.2, 0.8, 0.8, 1.0); // almost white inside
    }
};
