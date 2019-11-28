#include "RigidStar.h"

RigidStar::RigidStar()
{
	radius = 0.075f;
	inner_radius = 0.05f;
}


RigidStar::~RigidStar()
{
}

void RigidStar::draw()
{
	beginTransformation();
	{
		translate(pos);
		drawFilledStar(Colors::skyblue, radius, inner_radius);
	}
	endTransformation();
}

void RigidStar::update(const float & dt)
{
	static const vec2 gravity = vec2(0.0f, -9.8f);
	static const float coef_res = 1.0f; // coefficient of restitution
	static const float coef_friction = 0.0f; // friction (not physical)

										  // numerical integration
	vel += gravity * dt;
	pos += vel * dt;

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
			vel.y = 4;
		}
	}
}
