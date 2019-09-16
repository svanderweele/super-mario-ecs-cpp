#pragma once
#include "Component.h"

class Texture;

class SpriteComponent : public Component
{
public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_SPRITE; };
	SpriteComponent(Texture *texture) { this->texture = texture; }

public:
	SpriteComponent();
	Texture *texture;
	int direction;
};


inline std::ostream &operator<<(std::ostream &Str, SpriteComponent const &v) {
	Str << "SpriteComponent: Sprite:" << v.texture;
	return Str;
}
