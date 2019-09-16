#pragma once
#include "EntityManager.h"

class Component;

class Entity
{
	friend Entity *EntityManager::CreateEntity();

public:
	int GetId();

private:

private:
	Component **Components;
	int mId;

private:
	Entity();
	Entity(int Id);


};

