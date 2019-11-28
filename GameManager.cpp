#include "GameManager.h"

namespace spark {

	GameManager::GameManager()
	{
		bomb.init("bomb.wav", 0);
		shot.init("shot.wav", 0);
		itemsound.init("item.wav", 0);
	}


	GameManager::~GameManager()
	{
	}

	void drawWall()
	{
		setLineWidth(5.0f);
		drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { 1.0f, -1.0f });
		drawLine(Colors::blue, { 1.0f, -1.0f }, Colors::blue, { 1.0f, 1.0f });
		drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { -1.0f, 1.0f });
	}
	
	void GameManager::update()
	{
		drawWall();

		if (isPlaying) {
			float dt = getTimeStep() * 0.5;
			player.update(getCursorPos().x);
			if (isMouseButtonPressed(0) && missileDt <= 0) {
				if (missilePower == 1) {
					Missile missile = Missile(player.getPos());
					missiles.push_back(missile);
					missileDt = speed;
					shot.play();
				}
				else if (missilePower == 2) {
					Missile missile = Missile(vec2(player.getPos().x - 0.03, player.getPos().y));
					missiles.push_back(missile);
					missile = Missile(vec2(player.getPos().x + 0.03, player.getPos().y));
					missiles.push_back(missile);
					missileDt = speed;
					shot.play();
				}
				else {
					Missile missile = Missile(vec2(player.getPos().x - 0.05, player.getPos().y));
					missiles.push_back(missile);
					missile = Missile(vec2(player.getPos().x + 0.05, player.getPos().y));
					missiles.push_back(missile);
					missile = Missile(vec2(player.getPos().x, player.getPos().y));
					missiles.push_back(missile);
					missileDt = speed;
					shot.play();
				}
			}
			else {
				missileDt -= dt;
			}

			jumpBallManager.makeJumpBall(dt);

			vector<Missile> newMissiles;
			for (auto &item : jumpBallManager.items) {
				if (player.checkCollision(item)) {
					itemsound.play();
					switch (item.getType()) {
					case 0:
						if (missilePower <= 3) missilePower += 1;
						break;
					case 1:
						if (speed >= 0.05f) speed -= 0.03f;
					}
				}
			}
			for (auto &jumpBall : jumpBallManager.jumpBalls)
			{
				/*for (int i = 0; i < 3; i++) {*/
					for (auto &missile : missiles) {
						if (jumpBall.getLife() > 0 && jumpBall.checkCollision(missile)) {
							jumpBall.setLife(jumpBall.getLife() - 1);
							jumpBall.getPath() = to_string(jumpBall.getLife()) + ".png";
							jumpBall.getDigit().init(jumpBall.getPath(), 255, 255, 255);
						}
					}
				
				if (jumpBall.getLife() <= 0) {
					ParticleSystem ps;
					ps.reset(jumpBall.getPos());
					psList.push_back(ps);

					player.score += jumpBall.getPoint();
					bomb.play();
				}
				else if (jumpBall.checkCollision(player)) {
					isPlaying = false;
					cout << "Á¡¼ö : " << player.score << endl;
					cout << "speed : " << speed << endl;
				}
			}
			
			for (auto &ps : psList) {
				ps.update(dt);
				ps.draw();
			}
			/*for (int i = 0; i < 3; i++) {*/
				for (auto missile : missiles) {
					if (missile.isRemovable() == false) {
						newMissiles.push_back(missile);
					}
				}
				missiles = newMissiles;
				for (auto &missile : missiles) {
					missile.update(dt);
					missile.draw();
				}
			
			vector<Item> newItems;
			for (auto& item : jumpBallManager.items) {
				if (item.isRemovable() == false) {
					newItems.push_back(item);
				}
			}
			jumpBallManager.items = newItems;
			for (auto &item : jumpBallManager.items) {
				item.update(dt);
				item.draw();
			}
			jumpBallManager.update(dt);

			for (auto &obj : player.starship) {
				obj->draw();
			}
			if (isKeyPressedAndReleased(GLFW_KEY_P)) {
				bool timer = true;
				while (timer) {
					if (isKeyPressedAndReleased(GLFW_KEY_P)) { timer = false; }
				}
			}
		}
		else if (isKeyPressedAndReleased(GLFW_KEY_R)) {
			isPlaying = true;
			jumpBallManager.clear();
			psList.clear();
			missiles.clear();
			speed = 0.1;
			missilePower = 1;
			player.score = 0;
		}
	}
}