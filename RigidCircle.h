#pragma once
#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "CollisionObject.h"
#include <vector>
#include <memory>
using namespace jm;

class RigidCircle : public CollisionObject
{
private:
	float prevY = 0.0f;
protected:
	int level;
public:
	RGB color;
	vec2 vel;
	RigidCircle();
	~RigidCircle();
	void draw();
	void update(const float & dt);
};