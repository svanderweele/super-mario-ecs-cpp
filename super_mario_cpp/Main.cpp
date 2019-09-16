#include "Main.h"

//Core
#include <SDL.h>
#include <SDL_image.h>

//ECS
#include "EntityManager.h"
#include "Entity.h"
#include "Component.h"

//Components
#include "SpriteComponent.h"
#include "PlayerComponent.h"
#include "AnimationComponent.h"

//Systems
#include "ApplyVelocityToPositionSystem.h"
#include "RenderSpriteSystem.h"
#include "UpdateAnimationSystem.h"
#include "SetSpriteToFaceMovingDirectionSystem.h"
#include "PlayerInputSystem.h"

//Utilities
#include "Texture.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int Main::EntityIndex = 0;

EntityManager entityManager;
SDL_Window *gWindow;
SDL_Renderer *gRenderer;

bool initSdl();
SDL_Rect GetClipByIndex(int index, int w, int h, int xOffset);


int main(int argc, char *argv[]) {

	if (initSdl()) {

		entityManager = EntityManager();

		entityManager.RegisterSystem(new RenderSpriteSystem(gRenderer));
		entityManager.RegisterSystem(new UpdateAnimationSystem());
		entityManager.RegisterSystem(new PlayerInputSystem());
		entityManager.RegisterSystem(new ApplyVelocityToPositionSystem());
		entityManager.RegisterSystem(new SetSpriteToFaceMovingDirectionSystem());

		entityManager.CreateEntity();
		Entity *mario = entityManager.GetEntityWithId(0);
		entityManager.AddComponentToEntity(mario, new TransformComponent(320, 240));
		entityManager.AddComponentToEntity(mario, new VelocityComponent(0, 0));
		entityManager.AddComponentToEntity(mario, new PlayerComponent());

		Texture *marioTexture = new Texture();
		marioTexture->loadTextureFromImage(gRenderer, "Content/Sprites/mario_walk.png", 0, 0xFF, 0);
		SpriteComponent *spriteComponent = (SpriteComponent *)entityManager.AddComponentToEntity(mario, new SpriteComponent(marioTexture));

		std::vector<SDL_Rect> idleClips = std::vector<SDL_Rect>(1);
		idleClips[0] = GetClipByIndex(10, 27, 16, 6);

		std::vector<SDL_Rect> runClips = std::vector<SDL_Rect>(2);
		runClips[0] = { 0, 0, 16, 24 };
		runClips[1] = { 17, 0, 16, 24 };

		entityManager.AddComponentToEntity(mario, new AnimationComponent(runClips, 0, runClips.size()));

		bool bIsQuit = false;
		SDL_Event e;
		while (!bIsQuit)
		{
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					bIsQuit = true;
				}
			}
			entityManager.UpdateSystems();
		}
	}

	SDL_Delay(20000);

	return 0;
}

SDL_Rect GetClipByIndex(int index, int w, int h, int xOffset) {
	SDL_Rect rect;
	rect.x = (w + xOffset) * index;
	rect.y = 0;
	rect.w = w;
	rect.h = h;
	return rect;
}


bool initSdl() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	}
	else {
		gWindow = SDL_CreateWindow("Super Mario Bros Cpp :: ECS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL_Error:%s\n", SDL_GetError());
				success = false;
			}
			else {
				bool imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) && imgFlags)) {
					printf("IMG could not be initialize! IMG_Error:%s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

