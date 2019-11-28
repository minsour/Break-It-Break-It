#pragma once
#include "GeometricObject.h"
#include <vector>
#include "CollisionObject.h"
using namespace jm;
using namespace std;

class StarShip : public CollisionObject
{
public:
	int score = 0;
	StarShip();
	~StarShip();
	vector<GeometricObject*> starship;

	void draw();
	void update(float posX);
	vec2 getPos();
};