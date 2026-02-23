#pragma once
#include <vector>
#include <stack>
#include <SDL3/SDL_render.h>

class Basic2D;
class Game;

class EntityManager {
private:
	static std::vector<Basic2D*> Entities;
	static std::stack<Basic2D*> DestroyQueue;
	static void Remove(Basic2D* entity);

public:
	static void Add(Basic2D* entity);
	static void AddToRemove(Basic2D* entity);
	static void Draw(SDL_Renderer* renderer);
	static void Update(Game& game, float deltaTime);
	static void PreUpdate();
	static void Shutdown();

	static std::vector<Basic2D*> GetEntities() {
		return Entities;
	}
};