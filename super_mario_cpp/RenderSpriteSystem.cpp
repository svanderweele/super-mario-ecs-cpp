#include "RenderSpriteSystem.h"
#include <iostream>
#include <vector>
#include "SpriteComponent.h"
#include "AnimationComponent.h"
#include "EntityManager.h"
#include <SDL.h>
#include "Texture.h"

RenderSpriteSystem::RenderSpriteSystem(SDL_Renderer *renderer)
{
	mRenderer = renderer;
}

void RenderSpriteSystem::update() {

	std::vector<Entity *> entities = GetEntityManager()->GetEntitiesWithComponents({ COMPONENT_ID_SPRITE , COMPONENT_ID_TRANSFORM });

	SDL_RenderClear(mRenderer);
	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (Entity *entity : entities) {
		TransformComponent *transform = (TransformComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_TRANSFORM);
		SpriteComponent *sprite = (SpriteComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_SPRITE);

		AnimationComponent *animation = (AnimationComponent *)GetEntityManager()->GetComponentFromEntity(entity, COMPONENT_ID_ANIMATION);

		SDL_Rect *clip = NULL;

		if (animation != NULL) {
			clip = &animation->clips[animation->currentFrame / 4];
		}

		sprite->texture->render(mRenderer, transform->x, transform->y, clip, 0, NULL, sprite->direction == -1 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
	}


	SDL_RenderPresent(mRenderer);
}