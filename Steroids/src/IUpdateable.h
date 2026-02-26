#pragma once

class Game;

class IUpdateable {
public:
	virtual ~IUpdateable() {}
	virtual void Update(Game& game, float deltaTime) {}
};