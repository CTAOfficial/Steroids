#include "EntityManager.h"
#include "Entities/Basic2D.h"

std::vector<Basic2D*> EntityManager::Entities;
std::stack<Basic2D*> EntityManager::DestroyQueue;

void EntityManager::Add(Basic2D* entity)
{
	Entities.push_back(entity);
}

void EntityManager::AddToRemove(Basic2D* entity) {
	DestroyQueue.push(entity);
}
void EntityManager::Remove(Basic2D* entity)
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
		Basic2D* entity = DestroyQueue.top();
		Remove(entity);
		DestroyQueue.pop();
	}
}

void EntityManager::Shutdown() {
	for (Basic2D* entity : Entities) {
		delete entity;
	}
}
