#include "Sprite.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Sprite::Sprite()
{

}

Sprite::Sprite(SDL_Texture* texture) : Sprite()
{
    this->texture = texture;
}

Sprite::Sprite(SDL_Renderer* renderer, std::string path) : Sprite()
{
    texture = LoadTexture(renderer, path);
    center = { rect.w * 0.5f, rect.h * 0.5f };
    rect = SDL_FRect{ position.X, position.Y, (float)texture->w * scale.X, (float)texture->h * scale.Y };
}

Sprite::~Sprite()
{
    if (texture){ SDL_DestroyTexture(texture); }
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    centerPos = position + center;

    if (texture != nullptr) {
        rect = SDL_FRect { centerPos.X, centerPos.Y, (float)texture->w * scale.X, (float)texture->h * scale.Y };
        SDL_RenderTextureRotated(renderer, texture, NULL, const_cast<SDL_FRect*>(&rect), rotation, NULL, SDL_FLIP_NONE);
    }
    else {
        rect = SDL_FRect { centerPos.X, centerPos.Y, scale.X, scale.Y };
    }
}

SDL_Texture* Sprite::LoadTexture(SDL_Renderer* renderer, std::string path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr)
    {
        std::cout << "Unable to load image '" << path << "'! SDL_image Error: " << SDL_GetError() << "\n";
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (texture == nullptr)
    {
        std::cout << "Unable to load texture from surface." << SDL_GetError() << "\n";
        return nullptr;
    }
    return texture;
}

bool Sprite::LoadTexture(SDL_Renderer* renderer, std::string path, SDL_Texture& outTexture)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == nullptr) 
    { 
        std::cout << "Unable to load image '" << path << "'! SDL_image Error: " << SDL_GetError() << "\n";
        return false; 
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (texture == nullptr)
    {
        std::cout << "Unable to load texture from surface." << SDL_GetError() << "\n";
        return false;
    }
    
    outTexture = *texture;
    return true;
}
