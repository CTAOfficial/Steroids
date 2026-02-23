#include "CollisionSystem.h"
#include "Entities/Basic2D.h"
#include <iostream>

void CollisionSystem::Update(std::vector<Basic2D*> entities)
{
	/*for (auto& entity1 : entities) {
		for (auto& entity2 : entities) {
			if (entity1 == entity2) { continue; }

			if (entity1->IsOverlapping(*entity2)) {
				entity1->OnContact(*entity2);
				std::cout << entity1->tag << entity1->position.ToString() << " - " << entity2->tag << entity1->position.ToString() << "\n";
			}
		}
	}*/
}
