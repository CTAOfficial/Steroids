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
class Timer;

class Player : public VelocityObject {

private:
	friend class PlayerWidget;

	PlayerWidget* widget;

	Vector2 firePos;
	float fireOffset = 2;
	SDL_Keycode UpKey = NULL;
	SDL_Keycode DownKey = NULL;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	Timer* timer = nullptr;

	Vector2 velocity;
	Vector2 acceleration;
	float RotationSpeed = 4;
	float MaxSpeed = 100;
	float deceleration = 0.5f;
	float fireCooldown = 0.5f;
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

	void RemoveBullet(Projectile* projectile) {
		if (bullets.empty()) { return; }
		std::erase(bullets, projectile);
	}

	void SetUpKey(SDL_Keycode key);
	void SetDownKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);

	bool TryFire(Projectile* ref = nullptr);

	Projectile& ForceFire() {
		return Fire();
	}
};