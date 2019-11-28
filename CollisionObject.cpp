#include "CollisionObject.h"



CollisionObject::CollisionObject()
{
}


CollisionObject::~CollisionObject()
{
}

bool CollisionObject::checkCollision(CollisionObject& object) {
	if (sqrt((pos.x - object.pos.x)*(pos.x - object.pos.x) + (pos.y - object.pos.y)*(pos.y - object.pos.y)) <= radius + object.radius) {
		collision = true;
		object.collision = true;
		return true;
	}
	return false;
}