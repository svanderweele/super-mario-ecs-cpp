#pragma once
#include "Component.h"
#include <SDL.h>
#include <vector>

class Texture;
struct SDL_Rect;

class PlayerComponent : public Component
{
public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_PLAYER; };
	PlayerComponent() {  }

public:
};


inline std::ostream &operator<<(std::ostream &Str, PlayerComponent const &v) {
	Str << "PlayerComponent: ";
	return Str;
}
