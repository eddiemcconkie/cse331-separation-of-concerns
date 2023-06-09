#include "overall-logic.h"

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
