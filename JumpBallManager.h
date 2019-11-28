#pragma once
#include<vector>
#include"JumpBall.h"
#include "Missile.h"
#include "Item.h"
#include "Colors.h"

using namespace jm;
using namespace std;
class JumpBallManager
{
private:
	int breakCount = 0;
	float timerCount = 4.5f;
public:
	vector<JumpBall> jumpBalls;
	vector<Item> items;
	JumpBallManager();
	~JumpBallManager();
	
	int calcLife();
	void makeJumpBall(const float & dt);
	void removeJumpBall();
	void draw();
	void update(const float & dt);
	void clear();
	void removeItem(const float & dt);
};

