#include "JumpBall.h"

JumpBall::JumpBall(int life, int point, int level, vec2 pos):RigidCircle()
{			
	this->life = life;
	this->point = point;
	this->level = level;
	this->lifePath = to_string(life) + ".png";
	digit.init(lifePath, 225, 255, 255);

	if (level == 3) {
		radius = 0.2f;
	}
	else if (level == 2) {
		radius = 0.14f;
	}
	else if (level == 1) {
		radius = 0.07f;
	}
	this->pos = pos;
	float velX = (rand() % 30) / 10.0;
	if ((rand()%10) <= 5)
		velX *= -1;

	vel = vec2{ velX, 0.0f };
}
JumpBall::JumpBall(int life, int point, int level, vec2 pos, vec2 vel) :RigidCircle()
{
	this->life = life;
	this->point = point;
	this->level = level;
	this->lifePath = to_string(life) + ".png";
	digit.init(lifePath, 225, 255, 255);

	if (level == 3) {
		radius = 0.2f;
	}
	else if (level == 2) {
		radius = 0.14f;
	}
	else if (level == 1) {
		radius = 0.07f;
	}
	this->pos = pos;
	this->vel = vel;
}


JumpBall::~JumpBall()
{
}

int JumpBall::getPoint() {
	return point;
}
int JumpBall::getLife() {
	return life;
}
void JumpBall::setLife(int life) {
	this->life = life;
}
int JumpBall::getLevel() {
	return level;
}
vec2 JumpBall::getPos() {
	return pos;
}

string & JumpBall::getPath() {
	return lifePath;
}

ImageObject& JumpBall::getDigit() {
	return digit;
}
