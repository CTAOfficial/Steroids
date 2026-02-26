#pragma once
#include <SDL3/SDL_render.h>

class IDrawable {
public:
	virtual ~IDrawable(){}
	virtual void Draw(SDL_Renderer* renderer){}
};