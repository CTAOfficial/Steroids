#pragma once
#include "Inspectors/Inspector.h"

class AsteroidManager;

class AsteroidManagementInspector : public Inspector<AsteroidManager*> {

protected:
	void OnDraw() override;

public:
	AsteroidManagementInspector(AsteroidManager* manager) : Inspector(manager) {
		Title = "Asteroid Manager";
	}
};