#include "Player.h"
#include "../Game.h"
#include <iostream>
#include "../InputManager.h"

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D(pos, Vector2{ 75, 15 }, rgba)
{
	playerIndex = index;
	tag = "Player";
}

void Player::Update(Game& game, float deltaTime)
{
	

	if (InputManager::GetKeyDown(LeftKey)) {
		if ((position.X + rect.w) <= 0) { position.X = Bounds.X - 1; }
		position.X -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(RightKey)) {
		if ((position.X - 1) >= Bounds.X) { position.X = 0 - rect.w; }
		position.X += speed * deltaTime;
	}
}

void Player::SetBounds(Vector2 bounds)
{
	Bounds = bounds;
}