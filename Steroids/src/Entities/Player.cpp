#include "Player.h"
#include "../Game.h"
#include "../InputManager.h"
#include <numbers>
#include <iostream>

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D(pos, Vector2{ 50, 50 }, rgba)
{
	playerIndex = index;
	tag = "Player";
}

void Player::Update(Game& game, float deltaTime)
{
	bool accelerating = false;

	if (InputManager::GetKeyDown(UpKey)) {
		if (position.Y <= 0) { position.Y = 0; return; }
		position.Y -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(DownKey)) {
		if (position.Y + rect.h >= Bounds.Y) { position.Y = Bounds.Y - rect.h; return; }
		position.Y += speed * deltaTime;
	}

	if (InputManager::GetKeyDown(LeftKey)) {
		/*if (position.X <= 0) { position.X = 0; return; }
		position.X -= speed * deltaTime;*/

		acceleration.X = -1000 * deltaTime;
		accelerating = true;
		//Rotate(-1);
	}
	if (InputManager::GetKeyDown(RightKey)) {
		/*if (position.X + rect.w >= Bounds.X) { position.X = Bounds.X - rect.w; return; }
		position.X += speed * deltaTime;*/

		acceleration.X = 1000 * deltaTime;
		accelerating = true;
		//Rotate(1);
	}
	if (accelerating) {
		//velocity.X += std::cos(angle) * MaxSpeed;
		//velocity.Y += std::sin(angle) * MaxSpeed;

		velocity += acceleration;		
		std::cout << "Velocity: " << velocity.ToString() + "\n";
		std::cout << "Acceleration: " << acceleration.ToString() + "\n";
	}

	if (velocity.Magitude() > MaxSpeed) {
		velocity.Normalize();
		velocity *= MaxSpeed;
	}

	velocity *= deceleration;
	//std::cout << velocity.ToString();

	position += velocity;
}

void Player::Rotate(float dir)
{
	angle += RotationSpeed * dir;

	if (angle < 0) {
		angle = 2 * std::numbers::pi;
	}
	if (angle > 2 * std::numbers::pi) {
		angle = 0;
	}
}

void Player::SetBounds(Vector2 bounds)
{
	Bounds = bounds;
}

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