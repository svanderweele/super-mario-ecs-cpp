#pragma once
#include "System.h"

struct SDL_Renderer;

class RenderSpriteSystem : public System
{
public:
	RenderSpriteSystem(SDL_Renderer *renderer);

public:
	void update() override;
private:
	SDL_Renderer *mRenderer;
};

