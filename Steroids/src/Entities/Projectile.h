#pragma once

#include "GameObject.h"

class Projectile : public GameObject {
public:
	Projectile(Vector2 pos) : GameObject(pos){}
	Projectile(Sprite* sprite, Vector2 pos) : GameObject(sprite, pos){}

	void Update(Game& game, float deltaTime) override;
};