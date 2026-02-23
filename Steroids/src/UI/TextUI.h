#pragma once

#include "../Entities/Basic2D.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>


class TextUI : public Basic2D {
protected:
	~TextUI();

public:
	TextUI(std::string fontPath, SDL_Renderer* renderer, Vector2 pos, RGBA rgba);

	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	SDL_Color color = { 255, 255, 255, SDL_ALPHA_OPAQUE };
	SDL_Surface* surface = nullptr;
	std::string text;


	void Draw(SDL_Renderer* renderer) override;
	void SetText(std::string text);
	void SetSize(int size);
};