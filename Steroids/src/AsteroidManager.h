#pragma once
#include <map>
#include <vector>
#include <SDL3/SDL_render.h>
#include "Size.h"
#include "Vector2.h"
#include <Widgets/AsteroidManagementInspector.h>

class Asteroid;
class Sprite;
class Timer;

class AsteroidManager {
private:
	std::vector<Asteroid*> asteroids;
	AsteroidManagementInspector* widget;
	int index = 0;
	Vector2 bounds;
	Timer* timer = nullptr;

	Asteroid& CreateAsteroid();
	Size RandomSize();
	Vector2 RandomPosition();
	Vector2& AssignVelocity(Asteroid& asteroid);
	Sprite* SpriteFromSize(Size size);

public:
	AsteroidManager(Vector2 bounds);

	bool UseLimit = true;
	int Limit = 10;

	std::map<Size, Sprite*> sprites;

	void Load(SDL_Renderer* renderer);
	void Update(float deltatime);

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