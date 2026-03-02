#include "Player.h"
#include "../Game.h"
#include "../InputManager.h"
#include "Sprite.h"
#include "Projectile.h"
#include <numbers>
#include <iostream>


Player::Player(int index, SDL_Renderer* renderer, Vector2 pos) : GameObject(pos)
{
	sprite = new Sprite{ renderer, "build/images/player.png" };
	sprite->scale = { 0.15f, 0.15f };

	bulletTexture = Sprite::LoadTexture(renderer, "build/images/projectile.png");

	playerIndex = index;
	tag = "Player";
}

void Player::Update(Game& game, float deltaTime)
{
	bool accelerating = false;

	if (InputManager::GetKeyDown(UpKey)) {
		accelerating = true;
	}
	if (InputManager::GetKeyDown(LeftKey)) {
		Rotate(-1, deltaTime);
	}
	if (InputManager::GetKeyDown(RightKey)) {
		Rotate(1, deltaTime);
	}

	if (InputManager::GetKey(SDLK_SPACE)) {
		TryFire();
	}
	
	if (accelerating) {
		acceleration.X += std::cos(angle) * deltaTime * MaxSpeed;
		acceleration.Y += std::sin(angle) * deltaTime * MaxSpeed;

		velocity += acceleration;		
		std::cout << "Velocity: " << velocity.ToString() + "\n";
		std::cout << "Acceleration: " << acceleration.ToString() + "\n";
	}
	else {
		acceleration = Vector2::Zero;
	}

	if (velocity.Magitude() > MaxSpeed) {
		std::cout << velocity.Magitude() << "\n";
		velocity.Normalize();
		velocity *= MaxSpeed;
	}

	if (velocity.Magitude() > 0) 
	{ 
		//TODO: handle deceleration
		velocity *= (1 - deceleration) * deltaTime;
	}
	//std::cout << velocity.ToString();

	position += velocity;
}

void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderLine(renderer, position.X, position.Y, position.X + (velocity.X * 500), position.Y + (velocity.Y * 500));
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderLine(renderer, position.X, position.Y, position.X + (std::cos(angle) * 250), position.Y + (std::sin(angle) * 250));
}

void Player::Rotate(float dir, float deltaTime)
{
	angle += RotationSpeed * dir * deltaTime;

	if (angle < 0) {
		angle = 2 * std::numbers::pi_v<float>;
	}
	else if (angle > 2 * std::numbers::pi_v<float>) {
		angle = 0;
	}

	sprite->rotation = angle * 180 / std::numbers::pi;
}

void Player::SetBounds(Vector2 bounds)
{
	Bounds = bounds;
}

#pragma region Key Setting
void Player::SetUpKey(SDL_Keycode key)
{
	UpKey = key;
}
void Player::SetDownKey(SDL_Keycode key)
{
	DownKey = key;
}
void Player::SetRightKey(SDL_Keycode key)
{
	RightKey = key;
}
void Player::SetLeftKey(SDL_Keycode key)
{
	LeftKey = key;
}
#pragma endregion

#pragma region Shooting
bool Player::CanFire()
{
	return true;
}

bool Player::TryFire(Projectile* ref)
{
	if (!CanFire()) {
		return false;
	}

	ref = &Fire();
	return true;
}
Projectile& Player::Fire()
{
	firePos = position * fireOffset;

	Projectile* bullet = new Projectile {firePos};
	bullet->sprite = new Sprite{ bulletTexture };
	bullet->sprite->scale = Vector2{ 0.25f, 0.25f };
	bullet->velocity = velocity;

	bullets.emplace_back(bullet);

	return *bullet;
}
#pragma endregion

