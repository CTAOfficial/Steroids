#pragma once
#include <vector>

class Basic2D;

struct Collision {
	Basic2D& collision;
};

class CollisionSystem {
public:
	static void Update(std::vector<Basic2D*> entities);
};