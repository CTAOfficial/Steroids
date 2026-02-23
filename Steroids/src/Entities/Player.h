#pragma once
#include "Basic2D.h"
#include <SDL3/SDL_render.h>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;

class Player : public Basic2D {

private:
	Vector2 Bounds;
	SDL_Keycode UpKey = NULL;
	SDL_Keycode DownKey = NULL;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	Vector2 velocity;
	Vector2 acceleration;
	float angle = 0;
	float RotationSpeed = 5;
	float MaxSpeed = 5;
	float deceleration = 0.9f;

public:
	Player(int index, Vector2 pos, RGBA rgba);

	int playerIndex = 0;
	float speed = 500;

	void Update(Game& game, float deltaTime) override;
	void Rotate(float dir);

	void SetBounds(Vector2 bounds);

	void SetUpKey(SDL_Keycode key);
	void SetDownKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);
};