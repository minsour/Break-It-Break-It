#pragma once
#include "fmod.hpp"
#include <iostream>
#include <conio.h>

using namespace std;
class Fmod {
private :
	FMOD::System  *system;
	FMOD::Sound   *sound;
	FMOD::Channel *channel;
	FMOD_RESULT   result;
	unsigned int  version;
	void          *extradriverdata;
public :
	Fmod() {
		//*system = nullptr;
	}
	int init(string path, int loop) {
		result = FMOD::System_Create(&system);
		if (result != FMOD_OK) return -1;

		result = system->getVersion(&version);
		if (result != FMOD_OK) return -1;
		else printf("FMOD version %08x\n", version);

		result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
		if (result != FMOD_OK) return -1;

		if (loop) {
			result = system->createSound(path.c_str(), FMOD_LOOP_NORMAL, 0, &sound);
		}
		else {
			result = system->createSound(path.c_str(), FMOD_LOOP_OFF, 0, &sound); // .mp3 files work!
		}
		if (result != FMOD_OK) return -1;

		
		if (result != FMOD_OK) return -1;

//		if (result != FMOD_OK) return -1;
	}

	void play() {
		result = system->playSound(sound, 0, false, &channel);
	}
	bool update() {

		result = system->update();
		if (channel)
		{
			bool playing = false;
			result = channel->isPlaying(&playing);
			if (!playing) {
				system->release();
				return true;
			}
		}
		return false;
	}
};