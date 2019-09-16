#pragma once
#include <string>
#include <iostream>

enum EComponentId {
	COMPONENT_ID_TRANSFORM,
	COMPONENT_ID_VELOCITY,
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
	TransformComponent(float x, float y) { mX = x; mY = y; }

public:
	float mX;
	float mY;

};


inline std::ostream &operator<<(std::ostream &Str, TransformComponent const &v) {
	Str << "TransformComponent: X:" << v.mX << " Y:" << v.mY;
	return Str;
}


class VelocityComponent : public Component {

public:
	virtual EComponentId GetComponentId() override { return COMPONENT_ID_VELOCITY; };
	VelocityComponent(float x, float y) { mX = x; mY = y; }

public:
	float mX;
	float mY;
};


inline std::ostream &operator<<(std::ostream &Str, VelocityComponent const &v) {
	Str << "VelocityComponent: X:" << v.mX << " Y:" << v.mY;
	return Str;
}
