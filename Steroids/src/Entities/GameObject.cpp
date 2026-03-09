#include "GameObject.h"
#include "Sprite.h"
#include <EntityManager.h>


GameObject::GameObject() : Object()
{
	EntityManager::Add(this);
}

void GameObject::Draw(SDL_Renderer* renderer)
{
	if (sprite != nullptr) {
		sprite->position = position;
		sprite->Draw(renderer);
	}
}

void GameObject::Destroy(GameObject& entity) {
	EntityManager::AddToRemove(&entity);
}