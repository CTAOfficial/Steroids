#include "VelocityObject.h"

void VelocityObject::Update(Game& game, float deltaTime)
{
	position += velocity * (speed * deltaTime);

	if (position.X + 20 > Bounds.X || position.X - 20 < 0) {
		position = -Bounds.X;
	}
}

void VelocityObject::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (DebugMode) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLine(renderer, position.X, position.Y, position.X + (velocity.X * 25), position.Y + (velocity.Y * 25));
	}
}

