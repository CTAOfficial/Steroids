#include "Projectile.h"
#include "AsteroidManager.h"
#include "Asteroid.h"
#include "Game.h"
#include "Sprite.h"
#include "Utilities/Timer.h"
#include <vector>
#include "Player.h"


Projectile::~Projectile()
{
	player->RemoveBullet(this);
	delete timer;
}

Projectile::Projectile(Player* player, Vector2 pos) : VelocityObject(pos)
{
	this->player = player;
	name = "Bullet";
	timer = new Timer{ lifeTime, lifeTime };
}

Projectile::Projectile(Player* player, Vector2 pos, Sprite* sprite) : Projectile(player, pos)
{
	this->sprite = sprite;
}

Projectile::Projectile(Player* player, Vector2 pos, float speed) : Projectile(player, pos)
{
	this->speed = speed;
}

void Projectile::Update(Game& game, float deltaTime)
{
	if (timer->Count(deltaTime)) {
		Destroy(*this);
		return;
	}

	VelocityObject::Update(game, deltaTime);

	
	//position *= velocity;

	// BUG: For some reason, it was trigger a collision with rects which are not close to each other
	std::vector asteroids = game.SteroidManager->GetAsteroids();
	for (auto& asteroid : asteroids) {
		if (SDL_HasRectIntersectionFloat(const_cast<SDL_FRect*>(&sprite->rect), const_cast<SDL_FRect*>(&asteroid->sprite->rect))) {
			Destroy(*asteroid);
			Destroy(*this);
		}
	}
}

void Projectile::Draw(SDL_Renderer* renderer)
{
	VelocityObject::Draw(renderer);
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderRect(renderer, &sprite->rect);
}
