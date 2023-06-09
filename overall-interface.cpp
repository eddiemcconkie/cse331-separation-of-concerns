#include "overall-interface.h"

DrawableObjectInterface* OverallInterface::getObjectInterface(DrawableObject* storage)
{
	switch (storage->getType())
	{
	case BIRD_STANDARD:
		return &birdStandardInterface;
	case BIRD_FLOATER:
		return &birdFloaterInterface;
	case BIRD_SINKER:
		return &birdSinkerInterface;
	case BIRD_CRAZY:
		return &birdCrazyInterface;
	case BULLET_PELLET:
		return &bulletInterface;
	case BULLET_BOMB:
		return &bombInterface;
	case BULLET_MISSILE:
		return &missileInterface;
	case BULLET_SHRAPNEL:
		return &shrapnelInterface;
	case EFFECT_FRAGMENT:
		return &fragmentInterface;
	case EFFECT_STREEK:
		return &streekInterface;
	case EFFECT_EXHAUST:
		return &exhaustInterface;
	default:
		return nullptr;
	}
}
