#include "overall-logic.h"

using namespace std;

BirdBaseLogic* OverallLogic::getObjectLogic(BirdStorage* storage)
{
	switch (storage->getType())
	{
	case BIRD_STANDARD:
		return &birdStandardLogic;
	case BIRD_FLOATER:
		return &birdFloaterLogic;
	case BIRD_SINKER:
		return &birdSinkerLogic;
	case BIRD_CRAZY:
		return &birdCrazyLogic;
	}
}

BulletLogic* OverallLogic::getObjectLogic(BulletStorage* storage)
{
	switch (storage->getType())
	{
	case BULLET_PELLET:
		return &bulletLogic;
	case BULLET_BOMB:
		return &bombLogic;
	case BULLET_MISSILE:
		return &missileLogic;
	case BULLET_SHRAPNEL:
		return &shrapnelLogic;
	default:
		return nullptr;
	}
}

EffectBaseLogic* OverallLogic::getObjectLogic(EffectStorage* storage)
{
	switch (storage->getType())
	{
	case EFFECT_FRAGMENT:
		return &fragmentLogic;
	case EFFECT_STREEK:
		return &streekLogic;
	case EFFECT_EXHAUST:
		return &exhaustLogic;
	default:
		return nullptr;
	}
}

list<DrawableObject*> OverallLogic::getDrawableObjects()
{
	auto birds = storage.getBirds();
	auto bullets = storage.getBullets();
	auto effects = storage.getEffects();
	auto gun = storage.getGun();
	list<DrawableObject*> drawableObjects;
	drawableObjects.insert(drawableObjects.end(), birds.begin(), birds.end());
	drawableObjects.insert(drawableObjects.end(), bullets.begin(), bullets.end());
	drawableObjects.insert(drawableObjects.end(), effects.begin(), effects.end());
	drawableObjects.push_back(gun);
}

void OverallLogic::move()
{
	auto birds = storage.getBirds();
	auto bullets = storage.getBullets();
	auto effects = storage.getEffects();

	for (auto& bird : birds)
	{
		auto logic = getObjectLogic(bird);
		logic->advance(bird);
		if (logic->isOutOfBounds(bird))
			logic->kill(bird);
	}
	for (auto& bullet : bullets)
	{
		auto logic = getObjectLogic(bullet);
		logic->move(bullet);
		if (logic->isOutOfBounds(bullet))
			logic->kill(bullet);
	}
	for (auto& effect : effects)
	{
		auto logic = getObjectLogic(effect);
		logic->fly(effect);
		//if (logic->isOutOfBounds(effect))
			//logic->kill(effect);
	}
}

void OverallLogic::collide()
{
	auto birds = storage.getBirds();
	auto bullets = storage.getBullets();

	for (auto& bird : birds)
	{
		auto birdLogic = getObjectLogic(bird);

		for (auto& bullet : bullets)
		{
			auto bulletLogic = getObjectLogic(bullet);

			auto birdPt = bird->getPt();
			auto bulletPt = bullet->getPt();
			auto diffX = birdPt.getX() - bulletPt.getX();
			auto diffY = birdPt.getY() - bulletPt.getY();

			auto distance = sqrt((diffX * diffX) + (diffY * diffY));
			if (distance <= bird->getRadius() + bullet->getRadius())
			{
				birdLogic->kill(bird);
				bulletLogic->kill(bullet);
			}
		}
	}
}
