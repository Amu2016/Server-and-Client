#pragma once
#ifndef STDAFX_H
#define STDAFX_H

#include<vector>
#include"math.h"
#include<random>
#include<map>

//#pragma execution_character_set("utf-8")


using namespace std;

#define PI 3.1415926
#define SOCKET_READ_BUFFER_SIZE 8192

typedef std::mt19937 RngT;

enum GameSceneObjType{
	MONSTER,
	PLAYER,
	MAINPLAYER
};



inline float getRandomFloat(RngT& rng, const float min, const float max) {
	return std::uniform_real_distribution<float>(min, max)(rng);
}

inline int getMyRandomInt(RngT& rng, const int min, const int max) {
	return std::uniform_int_distribution<int>(min, max)(rng);
}

inline float randomClamped(RngT& rng) {
	return std::uniform_real_distribution<float>(-1.0f, 1.0f)(rng);
}


//-------------------
#endif STDAFX_H