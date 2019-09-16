#include "ApplyVelocityToPositionSystem.h"
#include <iostream>
#include <vector>
#include "EntityManager.h"

void ApplyVelocityToPositionSystem::update() {

	std::vector<Entity *> entities = GetEntityManager()->GetEntitiesWithComponents({ COMPONENT_ID_TRANSFORM, COMPONENT_ID_VELOCITY });

	for (Entity *entity : entities) {
		TransformComponent *transform = (TransformComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_TRANSFORM);
		VelocityComponent *velocity = (VelocityComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_VELOCITY);
		transform->mX += velocity->mX;
		transform->mY += velocity->mY;
	}
}