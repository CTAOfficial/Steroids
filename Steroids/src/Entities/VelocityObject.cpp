#include "VelocityObject.h"

void VelocityObject::Update(Game& game, float deltaTime)
{
	position += velocity * (speed * deltaTime);
}

void VelocityObject::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (DebugMode) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLine(renderer, position.X, position.Y, position.X + (velocity.X * 25), position.Y + (velocity.Y * 25));
	}
}

