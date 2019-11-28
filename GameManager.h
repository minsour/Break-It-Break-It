#pragma once
#include "GeometricObject.h"
#include "JumpBallManager.h"
#include "Missile.h"
#include "StarShip.h"
#include "Fmod.h"
#include "item.h"
#include <vector>

using namespace std;
using namespace jm;

namespace spark {
	class GameManager : public Game2D
	{
	private:
		JumpBallManager jumpBallManager;
		vector<Missile> missiles;
		vector<ParticleSystem> psList;
		Fmod bomb, shot, itemsound;
		StarShip player;
		float missileDt;
		float speed = 0.1;
		int missilePower = 1;
		bool isPlaying = true;
	public:
		GameManager();
		~GameManager();
		void update() override;
	};
}