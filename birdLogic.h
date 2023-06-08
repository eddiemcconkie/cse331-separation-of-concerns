#pragma once

#include "point.h"
#include "birdStorage.h"
#include <cassert>
#include <list>

using namespace std;

class BirdBaseLogic
{
public:
    list<BirdStorage> factory(int level, int count);
    void kill(BirdStorage &bird) { bird.setDead(true); };
    bool isOutOfBounds(BirdStorage bird);

    virtual void advance(BirdStorage &bird) = 0;

protected:
    void move(BirdStorage &bird);
};

class BirdStandardLogic : public BirdBaseLogic {
public:
    void advance(BirdStorage &bird);
};

class BirdFloaterLogic : public BirdBaseLogic {
public:
    void advance(BirdStorage &bird);
};

class BirdSinkerLogic : public BirdBaseLogic {
public:
    void advance(BirdStorage &bird);
};

class BirdCrazyLogic : public BirdBaseLogic {
public:
    void advance(BirdStorage &bird);
};
