#pragma once
#include "Object.h"
#include "IDrawable.h"
#include "IUpdateable.h"
#include <Vector2.h>
#include <SDL3/SDL_render.h>

class Game;
class Sprite;

class GameObject : public Object, public IDrawable, public IUpdateable {
protected:
	using Object::Object;
	GameObject();
public:
	virtual ~GameObject() = default;

	GameObject(Vector2 pos) : GameObject()  {
		position = pos;
	}
	GameObject(Sprite* sprite, Vector2 pos);

	bool DebugMode = false;

	Sprite* sprite = nullptr;
	Vector2 position = Vector2::Zero;
	std::string tag;
	Vector2 Bounds;
	void SetBounds(Vector2 bounds) {
		Bounds = bounds;
	}


	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;

	static void Destroy(GameObject& entity);
};