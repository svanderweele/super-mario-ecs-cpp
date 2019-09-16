#pragma once
#include <string>
#include <iostream>

enum EComponentId {
	COMPONENT_ID_TRANSFORM,
	COMPONENT_ID_VELOCITY,
	COMPONENT_ID_SPRITE,
	COMPONENT_ID_ANIMATION,
	COMPONENT_ID_TOTALCOMPONENTS
};


class Component
{
public:
	virtual EComponentId GetComponentId() = 0;
};

inline std::ostream &operator<<(std::ostream &Str, Component const &v) {
	return Str << "Base Component";
}



class TransformComponent : public Component {


public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_TRANSFORM; };
	TransformComponent(float x, float y) { this->x = x; this->y = y; }

public:
	float x;
	float y;

};


inline std::ostream &operator<<(std::ostream &Str, TransformComponent const &v) {
	Str << "TransformComponent: X:" << v.x << " Y:" << v.y;
	return Str;
}


class VelocityComponent : public Component {

public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_VELOCITY; };
	VelocityComponent(float x, float y) { this->x = x; this->y = y; }

public:
	float x;
	float y;
};


inline std::ostream &operator<<(std::ostream &Str, VelocityComponent const &v) {
	Str << "VelocityComponent: X:" << v.x << " Y:" << v.y;
	return Str;
}
