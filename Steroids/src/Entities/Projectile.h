#pragma once

#include "VelocityObject.h"

class Timer;
class Player;

class Projectile : public VelocityObject {
private:
	Timer* timer = nullptr;
	float lifeTime = 5;
	Player* player;

protected:
	~Projectile();

public:
	Projectile(Player* player, Vector2 pos);
	Projectile(Player* player, Vector2 pos, Sprite* sprite);
	Projectile(Player* player, Vector2 pos, float speed);

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
};