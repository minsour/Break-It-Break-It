#include "JumpBallManager.h"
int JumpBallManager::calcLife() {
	return (rand()%5)+2;
}

JumpBallManager::JumpBallManager()
{
}


JumpBallManager::~JumpBallManager()
{
}

void JumpBallManager::makeJumpBall(const float & dt) {
	if (timerCount >= 4.5f) {
		timerCount = 0;
		vec2 pos = vec2{ 0.8f, 0.8f };
		if (rand() % 2 == 0) {
			pos.x *= -1;
		}

		jumpBalls.push_back(JumpBall(calcLife(), calcLife(), 3, pos));
		jumpBalls[jumpBalls.size() - 1].color = Colors::green;
	}
	timerCount += dt;
}
void JumpBallManager::removeJumpBall() {
	vector<JumpBall> filterJumpBalls;

	for (auto jumpBall:jumpBalls) {
		if (jumpBall.getLife() == 0) {
			breakCount++;
			if (jumpBall.getLevel() > 1) {
				float velX = (rand() % 30)/10.0;
				JumpBall newJumpBall = JumpBall(calcLife(), calcLife(), jumpBall.getLevel() - 1, jumpBall.getPos(), vec2{ velX, 0 });
				if (newJumpBall.getLevel() == 2) newJumpBall.color = Colors::yellow;
				else if (newJumpBall.getLevel() == 1) newJumpBall.color = Colors::red;
				filterJumpBalls.push_back(newJumpBall);
				newJumpBall.vel.x *= -1;
				filterJumpBalls.push_back(newJumpBall);
			}
			if (rand() % 4 == 1) {
				int type = rand() % 2;
				items.push_back(Item(type, 350, jumpBall.getPos()));
			}
		}
		else {
			filterJumpBalls.push_back(jumpBall);
		}
	}
	
	jumpBalls = filterJumpBalls;
}

void JumpBallManager::removeItem(const float & dt) {
	vector<Item> filteredItem;
	for (auto &item : items) {
		item.age -= dt;
	}

	for (auto item : items) {
		if (item.age > 0) {
			filteredItem.push_back(item);
		}
	}

	items = filteredItem;
}

void JumpBallManager::draw() {
	for (auto &jumpBall : jumpBalls) {
		jumpBall.draw();
		
		beginTransformation();
		{
			translate(jumpBall.getPos());
			if (jumpBall.getLevel() == 3) {
				scale(0.38, 0.38);
			}
			else if (jumpBall.getLevel() == 2) {
				scale(0.27, 0.27);
			}
			else {
				scale(0.17, 0.17);
			}
			jumpBall.getDigit().draw();
		}
		endTransformation();
	}

	for (auto &item : items) {
		item.draw();
		beginTransformation();
		{
			translate(item.getPos());
			scale(0.13, 0.13);
			item.getIcon().draw();
		}
		endTransformation();
	}
}
void JumpBallManager::update(const float & dt) {
	removeJumpBall();
	removeItem(dt);
	for (auto &jumpBall : jumpBalls) {
		jumpBall.update(dt);
	}
	for (auto &item : items) {
		item.update(dt);
	}
	draw();
}

void JumpBallManager::clear() {
	timerCount = 4.5f;
	breakCount = 0;
	jumpBalls.clear();
	items.clear();
}
