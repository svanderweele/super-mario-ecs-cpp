#pragma once
#include "System.h"
class Entity;
class PlayerInputSystem : public System
{
public:
	virtual void update() override;
};

