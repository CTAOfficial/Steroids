#include "VelocityObject.h"
#include "Sprite.h"

void VelocityObject::Update(Game& game, float deltaTime)
{
	// check bounds
	SDL_FRect rect = sprite->rect;
	if ((position.Y + rect.h) <= 0) { position.Y = Bounds.Y - 1; }
	if ((position.Y - 1) >= Bounds.Y) { position.Y = 0; }
	
	position += velocity * speed * deltaTime;
	GameObject::Update(game, deltaTime);
}

void VelocityObject::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (DebugMode) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLine(renderer, position.X, position.Y, position.X + (velocity.X * 25), position.Y + (velocity.Y * 25));
	}
}

