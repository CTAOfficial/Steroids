#include "Player.h"
#include "../Game.h"
#include <iostream>
#include "../InputManager.h"

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D(pos, Vector2{ 50, 50 }, rgba)
{
	playerIndex = index;
	tag = "Player";
}

void Player::Update(Game& game, float deltaTime)
{
	if (InputManager::GetKeyDown(UpKey)) {
		if (position.Y <= 0) { position.Y = 0; return; }
		position.Y -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(DownKey)) {
		if (position.Y + rect.h >= Bounds.Y) { position.Y = Bounds.Y - rect.h; return; }
		position.Y += speed * deltaTime;
	}

	if (InputManager::GetKeyDown(LeftKey)) {
		if (position.X <= 0) { position.X = 0; return; }
		position.X -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(RightKey)) {
		if (position.X + rect.w >= Bounds.X) { position.X = Bounds.X - rect.w; return;}
		position.X += speed * deltaTime;
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