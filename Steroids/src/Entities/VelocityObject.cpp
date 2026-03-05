#include "VelocityObject.h"

void VelocityObject::Update(Game& game, float deltaTime)
{
	position += velocity * (speed * deltaTime);
}
