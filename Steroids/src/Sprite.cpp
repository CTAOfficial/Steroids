#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, std::string path) : Sprite()
{
    LoadTexture(renderer, path);
}

Sprite::~Sprite()
{
    if (texture){ SDL_DestroyTexture(texture); }
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    centerPos = position + center;

    rect = SDL_FRect { centerPos.X, centerPos.Y, (float)texture->w * scale.X, (float)texture->h * scale.Y };

    if (texture != nullptr) {
        SDL_RenderTextureRotated(renderer, texture, NULL, const_cast<SDL_FRect*>(&rect), rotation, NULL, SDL_FLIP_NONE);
    }
}

bool Sprite::LoadTexture(SDL_Renderer* renderer, std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) 
    { 
        std::cout << "Unable to load image '" << path << "'! SDL_image Error: " << SDL_GetError() << "\n";
        return false; 
    }

    

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (texture == nullptr)
    {
        std::cout << "Unable to load texture from surface." << SDL_GetError() << "\n";
        return false;
    }

    center = { rect.w * 0.5f, rect.h * 0.5f };
    rect = SDL_FRect{ position.X, position.Y, (float)texture->w * scale.X, (float)texture->h * scale.Y };
    return true;
}
