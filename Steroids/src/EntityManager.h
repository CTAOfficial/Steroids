#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <SDL3/SDL_render.h>

class Game;
class GameObject;

class EntityManager {
private:
	static std::vector<GameObject*> Entities;
	static std::queue<GameObject*> ConstructionQueue;
	static std::stack<GameObject*> DestroyQueue;
	static void Remove(GameObject* entity);

public:
	static void Add(GameObject* entity);
	static void AddToRemove(GameObject* entity);
	static void Draw(SDL_Renderer* renderer);
	static void Update(Game& game, float deltaTime);
	static void PreUpdate();
	static void Shutdown();

	static std::vector<GameObject*> GetEntities() {
		return Entities;
	}
};