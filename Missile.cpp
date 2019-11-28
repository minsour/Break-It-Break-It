#include "Missile.h"
#include "Colors.h"


Missile::Missile(vec2 pos)
{
	this->pos = pos;
	this->radius = 0.01f;
}


Missile::~Missile()
{
}

void Missile::draw() 
{
	beginTransformation();
	{
		translate(pos);
		drawFilledCircle(color, radius);

		setLineWidth(2.0f);
		drawWiredCircle(Colors::black, radius);
	}
	endTransformation();
}

void Missile::update(const float & dt) 
{
	static const vec2 direction = vec2(0.0f, 3.0f);
	
 	pos += direction *dt;

	if (pos.y - radius >= 1.0f) // ground
	{
		isOutOfMap = true;
	}
}

bool Missile::isRemovable() {
	return isOutOfMap || collision;
}