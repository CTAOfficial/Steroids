#pragma once
#include "VelocityObject.h"
#include "Size.h"

class AsteroidManager;

class Asteroid : public VelocityObject {

protected:
	~Asteroid();

	AsteroidManager* manager;

public:
	Asteroid(AsteroidManager* manager, Vector2 pos, Size size);

	Size size;

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

};