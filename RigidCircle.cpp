#include "RigidCircle.h"

RigidCircle::RigidCircle()
{
}


RigidCircle::~RigidCircle()
{
}

void RigidCircle::draw()
{
	beginTransformation();
	{
		translate(pos);
		drawFilledCircle(color, radius);

		setLineWidth(0.2f);
		drawWiredCircle(Colors::black, radius);
	}
	endTransformation();
}

void RigidCircle::update(const float & dt)
{
	static const vec2 gravity = vec2(0.0f, -9.8f);
	static const float coef_res = 1.0f; // coefficient of restitution
	static const float coef_friction = 0.0f; // friction (not physical)

										  // numerical integration
	vel += gravity *dt;
 	pos += vel *dt;

	// wall collision, friction
	if (1.0f - pos.x <= radius) // right wall
	{
		pos.x = 1.0f - radius;

		if (vel.x >= 0.0f)
			vel.x *= -1.0f * coef_res;
	}

	if (pos.x <= -1.0f + radius) // left wall
	{
		pos.x = -1.0f + radius;

		if (vel.x <= 0.0f)
			vel.x *= -1.0f * coef_res;
	}

	if (pos.y <= -1.0f + radius) // ground
	{
		pos.y = -1.0f + radius;

		if (vel.y <= 0.0f) {
			if (level == 3)
				vel.y = 5;
			else if (level == 2)
				vel.y = 4.5;
			else if (level == 1)
				vel.y = 4;
		}
	}
}
