#include "PlayerInputSystem.h"
#include <iostream>
#include <vector>
#include "EntityManager.h"
#include "PlayerComponent.h"
#include <SDL.h>

void MoveRight(VelocityComponent *velocity, float axisValue) {
	velocity->x = axisValue * 3;
}

bool bIsAKeyDown = false;
bool bIsDKeyDown = false;


void PlayerInputSystem::update() {

	std::vector<Entity *> entities = GetEntityManager()->GetEntitiesWithComponents({ COMPONENT_ID_PLAYER });
	if (entities.size() > 0) {
		Entity *player = entities[0];
		VelocityComponent *velocity = (VelocityComponent *)GetEntityManager()->GetComponentFromEntity(player, COMPONENT_ID_VELOCITY);

		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_a:
					bIsAKeyDown = true;
					break;
				case SDLK_d:
					bIsDKeyDown = true;
					break;
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
				case SDLK_a:
					bIsAKeyDown = false;
					break;
				case SDLK_d:
					bIsDKeyDown = false;
					break;
				}
			}

		}

		if (bIsAKeyDown == false && bIsDKeyDown == false) {
			MoveRight(velocity, 0);
		}
		else {
			if (bIsAKeyDown) {
				MoveRight(velocity, -1);
			}

			if (bIsDKeyDown) {
				MoveRight(velocity, 1);
			}

		}

	}
}