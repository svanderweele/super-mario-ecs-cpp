#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>

bool Texture::loadTextureFromImage(SDL_Renderer *renderer, const char path[], Uint8 r, Uint8 g, Uint8 b)
{
	free();

	bool success = true;

	SDL_Surface *surface = IMG_Load(path);
	if (surface == NULL) {
		printf("Failed to load image. IMG_Error: %s\n", IMG_GetError());
		success = false;
	}
	else {

		if (SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b)) < 0)
		{
			printf("Failed to set color key. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}

		mTexture = SDL_CreateTextureFromSurface(renderer, surface);
		if (mTexture == NULL) {
			printf("Failed to create texture. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			mWidth = surface->w;
			mHeight = surface->h;
		}

		SDL_FreeSurface(surface);
		surface = NULL;
	}

	return success;
}

void Texture::render(SDL_Renderer *renderer, float x, float y, SDL_Rect *clip, double angle, SDL_Point *centre, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, centre, flip);
}


void Texture::free() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mWidth = 0;
		mHeight = 0;
	}
}