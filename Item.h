#pragma once
#include "RigidStar.h"

class Item : public RigidStar
{
private:
	int type;
	string path;
	ImageObject icon;

public:
	int age;
	Item(int type, int age, vec2 pos);
	~Item();
	vec2 getPos();
	ImageObject getIcon();
	int getType();
	bool isRemovable() {
		return collision;
	}
};