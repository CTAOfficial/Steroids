#include "Player.h"
#include "../Game.h"
#include "../InputManager.h"
#include "Projectile.h"
#include "Sprite.h"
#include "Utilities/Timer.h"
#include "Widgets/PlayerWidget.h"
#include <numbers>
#include <iostream>


Player::Player(int index, SDL_Renderer* renderer, Vector2 pos) : VelocityObject(pos)
{
	sprite = new Sprite{ renderer, "build/images/player.png" };
	sprite->scale = { 0.15f, 0.15f };

	bulletTexture = Sprite::LoadTexture(renderer, "build/images/projectile.png");

	playerIndex = index;
	tag = "Player";

	timer = new Timer{ 0, fireCooldown };

	widget = new PlayerWidget{ this };
	widget->Visible = false;
}

Player::~Player()
{
	delete widget;
	delete timer;
}

void Player::Update(Game& game, float deltaTime)
{
	if (InputManager::GetKey(SDLK_TAB)) {
		widget->Toggle();
	}

	timer->Count(deltaTime);

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

	if (InputManager::GetKeyDown(SDLK_SPACE)) {
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
		//std::cout << velocity.Magitude() << "\n";
		velocity.Normalize();
		velocity *= MaxSpeed;
	}

	if (velocity.Magitude() > 0) 
	{ 
		//TODO: handle deceleration
		velocity *= (1 - deceleration) * deltaTime;
		//std::cout << velocity.ToString();
	}

	position += velocity;

	GameObject::Update(game, deltaTime);
}

void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (DebugMode) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderRect(renderer, &sprite->rect);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLine(renderer, position.X, position.Y, position.X + (velocity.X * 500), position.Y + (velocity.Y * 500));
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderLine(renderer, position.X, position.Y, position.X + (std::cos(angle) * 250), position.Y + (std::sin(angle) * 250));
	}
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
	return timer->Complete();
}

bool Player::TryFire(Projectile* ref)
{
	if (!CanFire()) {
		return false;
	}

	ref = &Fire();
	timer->Reset();
	return true;
}
Projectile& Player::Fire()
{
	//firePos = position *fireOffset;

	Projectile* bullet = new Projectile { this, position, new Sprite{ bulletTexture } };
	bullet->sprite->name = "Bullet Sprite";
	bullet->speed = 100;
	bullet->sprite->scale = Vector2{ 0.05f, 0.05f };
	bullet->velocity = Vector2{ std::cos(angle), std::sin(angle) };
	bullet->SetBounds(Bounds);

	bullets.push_back(bullet);

	return *bullet;
}
#pragma endregion

