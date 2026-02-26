#pragma once
#include "IDrawable.h"
#include "IUpdateable.h"
#include <Vector2.h>
#include <SDL3/SDL_render.h>

class Game;
class Sprite;

class GameObject : IDrawable, IUpdateable {
protected:
	GameObject();
public:
	virtual ~GameObject() = default;

	GameObject(Vector2 pos) : GameObject() {
		position = pos;
	}
	GameObject(Sprite* sprite, Vector2 pos) : GameObject(pos) {
		this->sprite = sprite;
	}

	Sprite* sprite = nullptr;
	Vector2 position = Vector2::Zero;
	std::string tag;

	void Update(Game& game, float deltaTime) override {}
	void Draw(SDL_Renderer* renderer) override;

	static void Destroy(GameObject& entity);
};