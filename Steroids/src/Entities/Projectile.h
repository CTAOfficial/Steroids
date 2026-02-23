#pragma once

#include "Basic2D.h"

class Projectile : public Basic2D {
public:
	Projectile(Vector2 pos) : Basic2D(pos, RGBA {255, 255, 255, 255}) {

	}
	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
};