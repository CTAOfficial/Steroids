#pragma once

#include "GameObject.h"

class VelocityObject : public GameObject {
public:
	VelocityObject(Vector2 pos) : GameObject(pos){}

	Vector2 velocity;
	float angle = 0;
	//float radius;
	float speed = 10;

	void Update(Game& game, float deltaTime) override;
};