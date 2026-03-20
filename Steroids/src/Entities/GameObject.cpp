#include "GameObject.h"
#include "Sprite.h"
#include <EntityManager.h>


GameObject::GameObject() : Object()
{
	EntityManager::Add(this);
}

GameObject::GameObject(Sprite* sprite, Vector2 pos) : GameObject(pos)
{
	this->sprite = sprite;
	this->sprite->position = position;
	this->sprite->rect.x = position.X;
	this->sprite->rect.y = position.Y;
}
void GameObject::Update(Game& game, float deltaTime) {
	if (sprite) {
		sprite->position = position;
		sprite->rect.x = position.X;
		sprite->rect.y = position.Y;
	}
}
void GameObject::Draw(SDL_Renderer* renderer)
{
	if (sprite) {
		//sprite->position = position; // for some reason only the most recent asteroid draws if removed?????????
		sprite->Draw(renderer);
	}
}

void GameObject::Destroy(GameObject& entity) {
	EntityManager::AddToRemove(&entity);
}