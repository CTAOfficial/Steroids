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
	void Draw(SDL_Renderer* renderer) override;

	void CheckBounds() {
		if (position.X < 0 || position.X > Bounds.X) {
			velocity.X = -velocity.X;
		}
		if (position.Y < 0) {
			position.Y = 0;
			velocity.Y = -velocity.Y;
		}
	}
};