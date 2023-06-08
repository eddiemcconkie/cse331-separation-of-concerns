#pragma once

#include "point.h"
#include "typeEnum.h"

// TODO: uncomment the inheritance 

class BirdStorage //: public CollideableObject
{
public:
	Point getPosition() { return pt; }
	void setPosition(Point pt) { this->pt = pt; }

	Velocity getVelocity() { return v; }
	void setVelocity(Velocity v) { this->v = v; }
	
	double getRadius() { return radius; }
	void setRadius(double radius) { this->radius = radius; }

	ObjectType getType() { return type; }
	void setType(ObjectType type) { this->type = type; }

	bool getDead() { return dead; }
	void setDead(bool status) { dead = status; }

	int getPoints() { return points; }
	void setPoints(int points) { this->points = points; }

private:
	Point pt;
	Velocity v;
	double radius;
	ObjectType type;
	bool dead;
	int points;
};

