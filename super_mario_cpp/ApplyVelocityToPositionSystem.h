#pragma once
#include "System.h"
class Entity;
class ApplyVelocityToPositionSystem : public System
{
public:
	virtual void update() override;
};

