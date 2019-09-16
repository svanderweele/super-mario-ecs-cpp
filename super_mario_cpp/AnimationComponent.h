#pragma once
#include "Component.h"
#include <SDL.h>
#include <vector>

class Texture;
struct SDL_Rect;

class AnimationComponent : public Component
{
public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_ANIMATION; };
	AnimationComponent(std::vector<SDL_Rect> clips, int currentFrame, int totalFrames) { this->clips = clips; this->currentFrame = currentFrame; this->totalFrames = totalFrames; }

public:
	int currentFrame;
	int totalFrames;
	std::vector<SDL_Rect> clips;
};


inline std::ostream &operator<<(std::ostream &Str, AnimationComponent const &v) {
	Str << "AnimationComponent: ";
	return Str;
}
