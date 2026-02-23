#pragma once

#include "Basic2D.h"
#include "../Vector2.h"


class VelocityObject : public Basic2D {
public:
	Vector2 velocity;

	float angle;
	float radius;
};