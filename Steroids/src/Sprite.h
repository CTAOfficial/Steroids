#pragma once
#include "Entities/Object.h"
#include "Vector2.h"
#include <SDL3/SDL_render.h>
#include <string>

class Sprite : public Object {
public:
	static Sprite* MissingSprite;

	using Object::Object;
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(SDL_Renderer* renderer, std::string path);
	~Sprite();

	Vector2 position;
	Vector2 centerPos;
	Vector2 scale = Vector2::One;
	float rotation = 0;

	Vector2 center;
	SDL_Texture* texture = nullptr;
	SDL_FRect rect;

	void Draw(SDL_Renderer* renderer);
	static bool LoadTexture(SDL_Renderer* renderer, std::string path, SDL_Texture& outTexture);
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path);
};