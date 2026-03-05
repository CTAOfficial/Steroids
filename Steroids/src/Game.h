#pragma once

#include "Windowing/Window.h"
#include "Vector2.h"
#include "UI/TextUI.h"
#include <string>
#include <AsteroidManager.h>


class Player;

class Game : public Window {
private:
	
	Vector2 Bounds;
	Vector2 PlayerBounds;
	TextUI* ui = nullptr;

	void LoadIcon();

public:
	Game(std::string& title, Vector2 size);
	~Game();

	Vector2 screenCenter;

	Player* player = nullptr;
	AsteroidManager* SteroidManager = nullptr;

	void Run() override;
	void Start() override;
	void Update() override;
	void OnClose() override;
};