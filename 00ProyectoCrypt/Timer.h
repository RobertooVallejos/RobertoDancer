#pragma once
#include "SDL.h"
class Timer
{
	float _StartTicks;
	float _Ticks;
	bool _Status;

public:
	Timer();
	~Timer();
	void start();
	void stop();
	float getTime();
};

