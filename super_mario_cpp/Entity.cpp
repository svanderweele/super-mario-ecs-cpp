#include "Entity.h"


Entity::Entity() :Entity(-1)
{
}

Entity::Entity(int Id) {
	mId = Id;
	Components = nullptr;
}

int Entity::GetId() {
	return mId;
}