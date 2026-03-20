#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Game.h"
#include "Player.h"
#include "Sprite.h"

Asteroid::~Asteroid()
{
	manager->RemoveAsteroid(this);
}

Asteroid::Asteroid(AsteroidManager* manager, Vector2 pos, Size size) : VelocityObject(pos)
{
	this->manager = manager;
	tag = "Asteroid";
	this->size = size;
}

void Asteroid::Update(Game& game, float deltaTime)
{
	VelocityObject::Update(game, deltaTime);

	if (SDL_HasRectIntersectionFloat(const_cast<SDL_FRect*>(&sprite->rect), const_cast<SDL_FRect*>(&game.player->sprite->rect))) {
		Destroy(*this);
	}
}

void Asteroid::Draw(SDL_Renderer* renderer)
{
	VelocityObject::Draw(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderRect(renderer, &sprite->rect);
}
