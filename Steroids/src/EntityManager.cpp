#include "EntityManager.h"
#include "Entities/GameObject.h"

std::vector<GameObject*> EntityManager::Entities;
std::stack<GameObject*> EntityManager::DestroyQueue;

void EntityManager::Add(GameObject* entity)
{
	Entities.push_back(entity);
}

void EntityManager::AddToRemove(GameObject* entity) {
	DestroyQueue.push(entity);
}
void EntityManager::Remove(GameObject* entity)
{
	std::erase(Entities, entity);
}

void EntityManager::Draw(SDL_Renderer* renderer)
{
	for (auto& entity : Entities) {
		entity->Draw(renderer);
	}
}

void EntityManager::Update(Game& game, float deltaTime)
{
	for (auto& entity : Entities) {
		entity->Update(game, deltaTime);
	}
}

void EntityManager::PreUpdate()
{
	while (!DestroyQueue.empty()) {
		GameObject* entity = DestroyQueue.top();
		Remove(entity);
		DestroyQueue.pop();
	}
}

void EntityManager::Shutdown() {
	for (GameObject* entity : Entities) {
		delete entity;
	}
}
