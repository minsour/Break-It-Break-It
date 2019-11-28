#include "Item.h"



Item::Item(int type, int age, vec2 pos) :RigidStar()
{
	this->type = type;
	this->age = age;
	this->pos = pos;
	
	float velX = (rand() % 2);
	if ((rand() % 10) <= 5)
		velX *= -1;

	vel = vec2{ velX, 0.0f };

	switch (type) {
	case 0:
		path = "item1.png"; break;
	case 1:
		path = "item2.png"; break;
	}
	icon.init(path, 255, 255, 255);
}


Item::~Item()
{
}

vec2 Item::getPos() {
	return pos;
}

ImageObject Item::getIcon() {
	return icon;
}

int Item::getType() {
	return type;
}
