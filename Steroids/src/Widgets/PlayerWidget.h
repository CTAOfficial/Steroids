#pragma once
#include "Inspectors/Inspector.h"
#include "Entities/Player.h"
#include <format>

class PlayerWidget : public Inspector<Player*> {

protected:
	void OnDraw() override;

public:
	PlayerWidget(Player* player) : Inspector(player) {
		Title = std::format("Player '{}' Inspector", player->playerIndex);
	}
};