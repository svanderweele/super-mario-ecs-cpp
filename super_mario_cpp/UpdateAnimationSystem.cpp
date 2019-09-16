#include "UpdateAnimationSystem.h"
#include <iostream>
#include <vector>
#include "EntityManager.h"
#include "AnimationComponent.h"

void UpdateAnimationSystem::update() {

	std::vector<Entity *> entities = GetEntityManager()->GetEntitiesWithComponents({ COMPONENT_ID_ANIMATION });

	for (Entity *entity : entities) {
		AnimationComponent *animation = (AnimationComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_ANIMATION);

		animation->currentFrame ++;

		if (animation->currentFrame / 4 == animation->totalFrames) {
			animation->currentFrame = 0;
		}
	}
}