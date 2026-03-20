#include "AsteroidManager.h"
#include "Entities/Asteroid.h"
#include "Sprite.h"
#include "util.h"
#include <InputManager.h>
#include <format>
#include "Utilities/Timer.h"
#include <Utilities/Assets.h>


AsteroidManager::AsteroidManager(Vector2 bounds)
{
    widget = new AsteroidManagementInspector(this);
    this->bounds = bounds;
    timer = new Timer{ 0, 3.5f };
}

void AsteroidManager::Load(SDL_Renderer* renderer)
{
    // Load Sprites
    
    Sprite* small = new Sprite{ renderer, "build/images/asteroid_small.png" };
    small->scale = Vector2{ 0.05f, 0.05f };
    std::pair<Size, Sprite*> smallPair = { Size::Small, small };
    sprites.insert(smallPair);

    Sprite* medium = new Sprite{ renderer, "build/images/asteroid_medium.png" };
    medium->scale = Vector2{ 4, 4 };
    std::pair<Size, Sprite*> mediumPair = { Size::Medium, medium };
    sprites.insert(mediumPair);

    Sprite* large = new Sprite{ renderer, "build/images/asteroid_large.png" };
    large->scale = Vector2{ 8, 8 };
    std::pair<Size, Sprite*> largePair = { Size::Large, large };
    sprites.insert(largePair);
}

void AsteroidManager::Update(float deltaTime)
{
    if (InputManager::GetKey(SDLK_F1)) {
        widget->Toggle();
    }

    timer->Count(deltaTime);
    if (timer->Complete() && RequestAsteroid()) {
        timer->Reset();
    }
}

bool AsteroidManager::CanCreate()
{
    if (asteroids.size() >= Limit && UseLimit) {
        return false;
    }
    if (!timer->Complete()) {
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
    Asteroid* steroid = new Asteroid{ this, RandomPosition(), RandomSize() };
    steroid->name = std::format("Asteroid #{}", index++);
    steroid->sprite = SpriteFromSize(steroid->size);
    steroid->SetBounds(bounds);
    AssignVelocity(*steroid);

    asteroids.push_back(steroid);
    return *steroid;
}

Size AsteroidManager::RandomSize()
{
    int rand = util::GetRandom(0, 1); // small and medium currently

    switch (rand) {
    case 0:
        return Size::Small;
    case 1:
        return Size::Medium;
    case 2:
        return Size::Large;
    }
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
    if (sprite) { return new Sprite{ *sprite }; };

    return new Sprite{ *Sprite::MissingSprite };
}

