#include "AsteroidManager.h"
#include "Entities/Asteroid.h"
#include "Sprite.h"
#include "util.h"
#include <InputManager.h>
#include <format>

void AsteroidManager::Load(SDL_Renderer* renderer)
{
    // Load Sprites
    
    Sprite* small = new Sprite{ renderer, "build/images/asteroid_small.png" };
    small->scale = Vector2{ 0.05f, 0.05f };

    //Sprite* medium = new Sprite{ renderer, "build/images/asteroid_medium.png" };
    //Sprite* large = new Sprite{ renderer, "build/images/asteroid_large.png" };

    std::pair<Size, Sprite*> smallPair = { Size::Small, small };
    sprites.insert(smallPair);
}

void AsteroidManager::Update()
{
    if (InputManager::GetKey(SDLK_F1)) {
        widget->Toggle();
    }
}

bool AsteroidManager::CanCreate()
{
    if (asteroids.size() >= Limit && UseLimit) {
        return false;
    }

    return true;
}

bool AsteroidManager::RequestAsteroid(Asteroid* asteroid)
{
    if (CanCreate()) {
        asteroid = &CreateAsteroid();
        return true;
    }

    return false;
}

Asteroid& AsteroidManager::CreateAsteroid()
{
    Asteroid* steroid = new Asteroid{ RandomPosition(), Size::Small };
    steroid->sprite = SpriteFromSize(steroid->size);
    AssignVelocity(*steroid);
    steroid->tag = std::format("Asteroid #{}", index++);

    asteroids.push_back(steroid);
    return *steroid;
}

bool AsteroidManager::RemoveAsteroid(Asteroid* asteroid)
{
    if (std::erase(asteroids, asteroid)) {
        return true;
    }
    return false;
}

Vector2 AsteroidManager::RandomPosition()
{
    // Integer random is different than float
    int x = util::GetRandom((int)-50, (int)bounds.X + 50);
    int y = util::GetRandom((int)-50, (int)bounds.Y + 50);

    return Vector2{ x, y };
}

Vector2& AsteroidManager::AssignVelocity(Asteroid& asteroid)
{
    Vector2 pos = asteroid.position;
    Vector2 center = bounds * 0.5f;
    Vector2 velocity = (center - pos) * 0.01f;

    asteroid.velocity = velocity;
    return velocity;
}

Sprite* AsteroidManager::SpriteFromSize(Size size)
{
    Sprite* sprite = sprites.at(size);
    if (sprite) { return sprite; };

    return Sprite::MissingSprite;
}


