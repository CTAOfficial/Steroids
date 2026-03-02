#pragma once

#include "GameObject.h"

class Projectile : public GameObject {
public:
	Projectile(Vector2 pos){}

	Vector2 velocity;

	void Update(Game& game, float deltaTime) override;

};