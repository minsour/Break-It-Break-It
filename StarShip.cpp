#include "StarShip.h"


StarShip::StarShip()
{
	starship.push_back(GeometricObject::makeTriangle(Colors::yellow, vec2{ 0.0f, -0.955f }, 0.075));
	starship.push_back(GeometricObject::makeStar(Colors::red, vec2{ 0.0f, -0.96f }, 0.039, 0.022));
	starship.push_back(GeometricObject::makeBox(Colors::silver, vec2{ 0.0f, -0.915f }, 0.075, 0.1));
	starship.push_back(GeometricObject::makeTriangle(Colors::silver, vec2{ -0.03f, -0.89f }, 0.08));
	starship.push_back(GeometricObject::makeTriangle(Colors::silver, vec2{ 0.03f, -0.89f }, 0.08));
	pos = vec2{ 0.0f, -0.915f };
	radius = 0.065f;
}


StarShip::~StarShip()
{
}

void StarShip::draw() {


}

void StarShip::update(float posX) {
	if (posX <= -1.0f + 0.06f) return;
	if (posX >= 1.0f - 0.06f) return;
	for (auto &object : starship) {
		object->pos.x = posX;
	}
	starship[3]->pos.x -= 0.03f;
	starship[4]->pos.x += 0.03f;
	pos.x = posX;
}

vec2 StarShip::getPos() {
	return pos;
}