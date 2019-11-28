#pragma once
#include "DrawFunctions.h"
using namespace jm;
class CollisionObject
{
protected:
	vec2 pos;
	float radius = 0.1f;
	bool collision = false;
public:
	CollisionObject();
	~CollisionObject();
	bool checkCollision(CollisionObject& object);
};

