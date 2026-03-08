#pragma once
#include "Inspectors/Inspector.h"

class Asteroid;
class AsteroidManager;

class AsteroidManagementInspector : public Inspector<AsteroidManager*> {

protected:
	void OnDraw() override;

public:
	AsteroidManagementInspector(AsteroidManager* manager) : Inspector(manager) {
		Title = "Asteroid Manager";
	}
};