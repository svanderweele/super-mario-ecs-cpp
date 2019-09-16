#pragma once
#include "System.h"
class Entity;
class SetSpriteToFaceMovingDirectionSystem : public System
{
public:
	virtual void update() override;
};

