#include "overall-logic.h"

BirdBaseLogic* OverallLogic::getObjectLogic(BirdType type)
{
	switch (type)
	{
	case STANDARD:
		return &birdStandardLogic;
	case FLOATER:
		return &birdFloaterLogic;
	case SINKER:
		return &birdSinkerLogic;
	case CRAZY:
		return &birdCrazyLogic;
	}
}

BulletLogic* OverallLogic::getObjectLogic(BulletType type)
{
	switch (type)
	{
	case PELLET:
		return &bulletLogic;
	case BOMB:
		return &bombLogic;
	case MISSILE:
		return &missileLogic;
	case SHRAPNEL:
		return &shrapnelLogic;
	}
}

EffectBaseLogic* OverallLogic::getObjectLogic(EffectType type)
{
	switch (type)
	{
	case FRAGMENT:
		return &fragmentLogic;
	case STREEK:
		return &streekLogic;
	case EXHAUST:
		return &exhaustLogic;
	}
}
