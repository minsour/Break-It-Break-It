#pragma once
#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "CollisionObject.h"
#include "ImageObject.h"
#include <vector>
#include <memory>
using namespace jm;

class RigidStar : public CollisionObject
{
private:
	float prevY = 0.0f;
	float inner_radius;
public:
	RGB color;
	vec2 vel;
	RigidStar();
	~RigidStar();
	void draw();
	void update(const float & dt);
};