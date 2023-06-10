#include "birdLogic.h"
#include "birdStorage.h"
#include <list>
#define WIDTH  800.0
#define HEIGHT 800.0

//This needs to be changed so that the dimension is inherited from parent class Collideable Object
Point dimensions = Point(WIDTH, HEIGHT);

using namespace std;

int random(int min, int max)
{
    assert(min < max);
    int num = (rand() % (max - min)) + min;
    assert(min <= num && num <= max);

    return num;
}

double randomFloat(double min, double max)
{
    assert(min <= max);
    double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
    assert(min <= num && num <= max);
    return num;
}

BirdStorage makeStandard(int level, BirdStorage bird) {
    Point pt = Point();
    Velocity v = Velocity();
    double speed = 7.0;
    double radius = 0.0;
    int points = 0;
    
    //automatic settings for standard bird regardless of game level
    ObjectType type = ObjectType::BIRD_STANDARD;
    pt.setY(randomFloat(dimensions.getY() * 0.25, dimensions.getY() * 0.75));
    pt.setX(0.0);

    //settings for standard bird dependant on game level
    switch (level)
    {

    case 1:
        radius = 30.0;
        points = 10;

        break;

    case 2:
        radius = 25.0;
        points = 12;

        break;

    case 3:
        radius = 20.0;
        speed = 5.0;
        points = 15;

        break;

    case 4:
        radius = 15.0;
        speed = 4.0;
        points = 18;

        break;
    }

    //store data
    bird.setPosition(pt);

    v.setDx(randomFloat(speed - 0.5, speed + 0.5));
    v.setDy(randomFloat(-speed / 5.0, speed / 5.0));

    bird.setVelocity(v);
    bird.setRadius(radius);
    bird.setType(type);
    bird.setPoints(points);

    return bird;
}

BirdStorage makeFloater(int level, BirdStorage bird) {
    Point pt = Point();
    Velocity v = Velocity();
    double speed = 0.0;     
    double radius = 0.0;   
    int points = 0;         

    //automatic settings for floater bird regardless of game level
    ObjectType type = ObjectType::BIRD_FLOATER;
    pt.setY(randomFloat(dimensions.getY() * 0.01, dimensions.getY() * 0.5));
    pt.setX(0.0);

    //settings for floater bird dependant on game level
    switch (level)
    {
    case 3:
        speed = 5.0;
        radius = 20.0;
        points = 15;

        break;

    case 4:
        speed = 4.0;
        radius = 15.0;
        points = 25;

        break;
    }

    //store data
    bird.setPosition(pt);

    v.setDx(randomFloat(speed - 0.5, speed + 0.5));
    v.setDy(randomFloat(0.0, speed / 3.0));

    bird.setVelocity(v);
    bird.setRadius(radius);
    bird.setType(type);
    bird.setPoints(points);

    return bird;
}

BirdStorage makeSinker(int level, BirdStorage bird) {
    Point pt = Point();
    Velocity v = Velocity();
    double speed = 0.0;     //4.5   4   3.5
    double radius = 0.0;    //25    20  15
    int points = 0;         //20    22  25

    //automatic settings for sinker bird regardless of game level
    ObjectType type = ObjectType::BIRD_SINKER;
    pt.setY(randomFloat(dimensions.getY() * 0.50, dimensions.getY() * 0.95));
    pt.setX(0.0);

    //settings for sinker bird dependant on game level
    switch (level)
    {
    case 2:
        speed = 4.5;
        radius = 25.0;
        points = 20;

        break;

    case 3:
        speed = 4.0;
        radius = 20.0;
        points = 22;

        break;

    case 4:
        speed = 3.5;
        radius = 15.0;
        points = 25;

        break;
    }
    //store data
    bird.setPosition(pt);

    v.setDx(randomFloat(speed - 0.5, speed + 0.5));
    v.setDy(randomFloat(-speed / 3.0, 0.0));

    bird.setVelocity(v);
    bird.setRadius(radius);
    bird.setType(type);
    bird.setPoints(points);

    return bird;
}

BirdStorage makeCrazy(int level, BirdStorage bird) {
    Point pt = Point();
    Velocity v = Velocity();

    //automatic settings for crazy bird regardless of game level
    ObjectType type = ObjectType::BIRD_CRAZY;
    double speed = 4.5;
    double radius = 15.0;
    int points = 30;
    pt.setY(randomFloat(dimensions.getY() * 0.25, dimensions.getY() * 0.75));
    pt.setX(0.0);
    v.setDx(randomFloat(speed - 0.5, speed + 0.5));
    v.setDy(randomFloat(-speed / 5.0, speed / 5.0));

    //store data
    bird.setPosition(pt);
    bird.setVelocity(v);
    bird.setRadius(radius);
    bird.setType(type);
    bird.setPoints(points);

    return bird;
}

list<BirdStorage> BirdBaseLogic::factory(int level, int count)
{
    list<BirdStorage> birds;

    BirdStorage bird = BirdStorage();
    bird.setDead(false);

    // spawns when there is nothing on the screen
    if (count == 0 && random(0, 15) == 1) {
        bird = makeStandard(level, bird);
        birds.push_back(bird);
    }

    // spawn every 4 seconds
    if (random(0, 4 * 30) == 1) {
        bird = makeStandard(level, bird);
        birds.push_back(bird);
    }

    switch (level)
    {

    case 2:
        // spawn every 3 seconds
        if (random(0, 3 * 30) == 1) {
            bird = makeSinker(level, bird);
            birds.push_back(bird);
        }

        break;

    case 3:
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
            bird = makeSinker(level, bird);
            birds.push_back(bird);
        }
        
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
            bird = makeFloater(level, bird);
            birds.push_back(bird);
        }
        
        break;

    case 4:
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
            bird = makeSinker(level, bird);
            birds.push_back(bird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
            bird = makeFloater(level, bird);
            birds.push_back(bird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
            bird = makeFloater(level, bird);
            birds.push_back(bird);
        }

        break;
    }

	return birds;
}

void BirdBaseLogic::move(BirdStorage &bird) {
    // inertia
    Point pt = bird.getPosition();
    pt.add(bird.getVelocity());
    bird.setPosition(pt);

    // out of bounds checker
    if (isOutOfBounds(bird))
    {
        kill(bird);
        bird.setPoints(-bird.getPoints()); // points go negative when it is missed!
    }
}

bool BirdBaseLogic::isOutOfBounds(BirdStorage bird)
{
    bool outOfBounds = (bird.getPosition().getX() < -bird.getRadius() || bird.getPosition().getX() >= dimensions.getX() + bird.getRadius() ||
        bird.getPosition().getY() < -bird.getRadius() || bird.getPosition().getY() >= dimensions.getY() + bird.getRadius());

    return outOfBounds;
}

void BirdStandardLogic::advance(BirdStorage &bird)
{
    // small amount of drag
    bird.setVelocity(bird.getVelocity() * 0.995);

    move(bird);
}

void BirdFloaterLogic::advance(BirdStorage &bird)
{
    // large amount of drag
    bird.setVelocity(bird.getVelocity() * 0.990);

    move(bird);

    // anti-gravity
    Velocity v = bird.getVelocity();
    v.addDy(0.05);
    bird.setVelocity(v);

}

void BirdSinkerLogic::advance(BirdStorage &bird)
{
    // gravity
    Velocity v = bird.getVelocity();
    v.addDy(-0.07);
    bird.setVelocity(v);

    move(bird);

    
}

void BirdCrazyLogic::advance(BirdStorage &bird)
{
    // erratic turns every half a second or so
   if (random(0, 15) == 0)
   {
       Velocity v = bird.getVelocity();
       v.addDy(randomFloat(-1.5, 1.5));
       v.addDx(randomFloat(-1.5, 1.5));
       bird.setVelocity(v);
   }

   move(bird);

}
