#include "SetSpriteToFaceMovingDirectionSystem.h"
#include <iostream>
#include <vector>
#include "SpriteComponent.h"
#include "EntityManager.h"

void SetSpriteToFaceMovingDirectionSystem::update() {

	std::vector<Entity *> entities = GetEntityManager()->GetEntitiesWithComponents({ COMPONENT_ID_TRANSFORM, COMPONENT_ID_VELOCITY });

	for (Entity *entity : entities) {
		SpriteComponent *sprite = (SpriteComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_SPRITE);
		VelocityComponent *velocity = (VelocityComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_VELOCITY);
		int dir = velocity->x < 0 ? 1 : -1;
		sprite->direction = dir;
	}
}