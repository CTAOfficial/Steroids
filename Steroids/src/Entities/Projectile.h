#pragma once

#include "VelocityObject.h"

class Projectile : public VelocityObject {
public:
	Projectile(Vector2 pos) : VelocityObject(pos) { }
	Projectile(Vector2 pos, float speed) : VelocityObject(pos) { this->speed = speed; }
};