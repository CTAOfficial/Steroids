#pragma once
#include "VelocityObject.h"
#include "Size.h"

class Asteroid : public VelocityObject {
public:
	Asteroid(Vector2 pos, Size size) : VelocityObject(pos) { tag = "Asteroid"; this->size = size; }

	Size size;

	//void Update(Game& game, float deltaTime) override;

};