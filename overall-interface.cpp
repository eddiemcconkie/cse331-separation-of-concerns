#include "overall-interface.h"

BirdBaseInterface* OverallInterface::getObjectInterface(BirdType type)
{
	switch (type)
	{
	case STANDARD:
		return &birdStandardInterface;
	case FLOATER:
		return &birdFloaterInterface;
	case SINKER:
		return &birdSinkerInterface;
	case CRAZY:
		return &birdCrazyInterface;
	}
}

BulletBaseInterface* OverallInterface::getObjectInterface(BulletType type)
{
	switch (type)
	{
	case PELLET:
		return &bulletInterface;
	case BOMB:
		return &bombInterface;
	case MISSILE:
		return &missileInterface;
	case SHRAPNEL:
		return &shrapnelInterface;
	}
}

EffectInterface* OverallInterface::getObjectInterface(EffectType type)
{
	switch (type)
	{
	case FRAGMENT:
		return &fragmentInterface;
	case STREEK:
		return &streekInterface;
	case EXHAUST:
		return &exhaustInterface;
	}
}
