#pragma once
#include "../RGBA.h"
#include <SDL3/SDL_render.h>
#include "../Vector2.h"
#include <string>

class Game;

class Basic2D {
protected:
	Basic2D();

public:
	virtual ~Basic2D() = default;

	Basic2D(Vector2 pos, RGBA rgba) : Basic2D() {
		position = pos;
		colour = rgba;
		rect = { (float)pos.X, (float)pos.Y, 0, 0 };
		center = { rect.w * 0.5f, rect.h * 0.5f };
		centerPos = Vector2{ position.X + center.X, position.Y + center.Y };
	}
	Basic2D(Vector2 pos, Vector2 dims, RGBA rgba) : Basic2D(pos, rgba) {
		rect.w = dims.X;
		rect.h = dims.Y;
		center = { rect.w * 0.5f, rect.h * 0.5f };
		centerPos = Vector2{ position.X + center.X, position.Y + center.Y };
	}

	Vector2 position;
	RGBA colour{ 0, 0, 0, 0 };
	SDL_FRect rect;
	Vector2 center;
	Vector2 centerPos;
	std::string tag;

	virtual void Draw(SDL_Renderer* renderer);
	virtual void Update(Game& game, float deltaTime) {};
	bool IsOverlapping(Basic2D& other);
	static void Destroy(Basic2D& entity);
	virtual void OnContact(Basic2D& contact) {};
};