#pragma once

#include "VelocityObject.h"

class Projectile : public VelocityObject {
public:
	Projectile(Vector2 pos) : VelocityObject(pos){}

	//void Update(Game& game, float deltaTime) override;
};