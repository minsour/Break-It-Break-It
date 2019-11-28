#pragma once
#include "CollisionObject.h"
#include "RigidCircle.h"
#include "ParticleSystem.h"
#include "ImageObject.h"
using namespace jm;
class JumpBall :public RigidCircle
{
private:
	int life;
	int point;
	string lifePath;
	ImageObject digit;

public:
	ParticleSystem ps;
	JumpBall(int life, int point, int level, vec2 pos);
	JumpBall(int life, int point, int level, vec2 pos, vec2 vel);
	~JumpBall();
	int getPoint();
	int getLife();
	void setLife(int life);
	int getLevel();
	vec2 getPos();
	string& getPath();
	ImageObject& getDigit();
};