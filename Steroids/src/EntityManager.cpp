#include "EntityManager.h"
#include "Entities/GameObject.h"

std::vector<GameObject*> EntityManager::Entities;
std::queue<GameObject*> EntityManager::ConstructionQueue;
std::stack<GameObject*> EntityManager::DestroyQueue;

void EntityManager::Add(GameObject* entity)
{
	ConstructionQueue.push(entity);
}

void EntityManager::AddToRemove(GameObject* entity) {
	std::stack check(DestroyQueue);
	
	// hate this, never do this (especially for large destroy queues
	while (!check.empty()) {
		if (check.top() == entity) {
			return;
		}
		check.pop();
	}

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
		delete entity;
	}

	while (!ConstructionQueue.empty()) {
		GameObject* entity = ConstructionQueue.front();
		Entities.push_back(entity);
		ConstructionQueue.pop();
	}
}

void EntityManager::Shutdown() {
	for (GameObject* entity : Entities) {
		delete entity;
	}
}
