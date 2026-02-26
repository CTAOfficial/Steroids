#pragma once
#include "GameObject.h"
#include <SDL3/SDL_render.h>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;

class Player : public GameObject {

private:
	Vector2 Bounds;
	SDL_Keycode UpKey = NULL;
	SDL_Keycode DownKey = NULL;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	Vector2 velocity;
	Vector2 acceleration;
	float angle = 0;
	float RotationSpeed = 4;
	float MaxSpeed = 100;
	float deceleration = 0.4f;

public:
	Player(int index, SDL_Renderer* renderer, Vector2 pos);

	int playerIndex = 0;
	float speed = 10;

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Rotate(float dir, float deltaTime);

	void SetBounds(Vector2 bounds);

	void SetUpKey(SDL_Keycode key);
	void SetDownKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);
};