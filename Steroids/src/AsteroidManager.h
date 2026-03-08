#pragma once
#include <map>
#include <vector>
#include <SDL3/SDL_render.h>
#include "Size.h"
#include "Vector2.h"
#include <Widgets/AsteroidManagementInspector.h>

class Sprite;
class Asteroid;

class AsteroidManager {
private:
	std::vector<Asteroid*> asteroids;
	AsteroidManagementInspector* widget;
	int index = 0;
	Vector2 bounds;

	Asteroid& CreateAsteroid();
	Vector2 RandomPosition();
	Vector2& AssignVelocity(Asteroid& asteroid);
	Sprite* SpriteFromSize(Size size);

public:
	AsteroidManager(Vector2 bounds) {
		widget = new AsteroidManagementInspector(this);
		this->bounds = bounds;
	}

	bool UseLimit = true;
	int Limit = 10;

	std::map<Size, Sprite*> sprites;

	void Load(SDL_Renderer* renderer);
	void Update();

	bool CanCreate();
	bool RemoveAsteroid(Asteroid* asteroid);
	bool RequestAsteroid(Asteroid* asteroid = nullptr);
	std::vector<Asteroid*>& GetAsteroids() {
		return asteroids;
	}
	Asteroid& ForceCreate() {
		return CreateAsteroid();
	}
};