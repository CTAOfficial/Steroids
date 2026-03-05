#pragma once
#include "VelocityObject.h"
#include "Projectile.h"
#include <SDL3/SDL_render.h>
#include <vector>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;
class PlayerWidget;

class Player : public VelocityObject {

private:
	PlayerWidget* widget;

	Vector2 Bounds;
	Vector2 firePos;
	float fireOffset = 2;
	SDL_Keycode UpKey = NULL;
	SDL_Keycode DownKey = NULL;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	Vector2 velocity;
	Vector2 acceleration;
	float RotationSpeed = 4;
	float MaxSpeed = 100;
	float deceleration = 0.5f;
	SDL_Texture* bulletTexture = nullptr;

	std::vector<Projectile*> bullets;

	bool CanFire();
	Projectile& Fire();

public:
	Player(int index, SDL_Renderer* renderer, Vector2 pos);
	~Player();

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

	bool TryFire(Projectile* ref = nullptr);

	Projectile& ForceFire() {
		return Fire();
	}
};