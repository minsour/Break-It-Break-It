#pragma once
#include "CollisionObject.h"
class Missile : public CollisionObject
{
private:
	bool isOutOfMap = false;
	RGB color;
public:
	Missile(vec2 pos);
	~Missile();
	void draw();
	void update(const float & dt);
	bool isRemovable();
};

