#pragma once
#include <SDL.h>
#include <iostream>
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class Texture
{
public:
	bool loadTextureFromImage(SDL_Renderer *renderer, const char path[], Uint8 r, Uint8 g, Uint8 b);
	void free();
	void render(SDL_Renderer *renderer, float x, float y, SDL_Rect *clip = nullptr, double angle = 0, SDL_Point * centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	SDL_Texture *mTexture;
	int mWidth;
	int mHeight;
};

