#include "Timer.h"

Timer::Timer()
{
	_StartTicks = 0;
	_Ticks = 0;
	_Status = false;
}

Timer::~Timer()
{
}

void Timer::start()
{
	_StartTicks = SDL_GetTicks();
	_Ticks = 0;
	_Status = true;
}

void Timer::stop()
{
	if (_Status)
	{
		_Status = false;
		_Ticks += SDL_GetTicks() - _StartTicks;
	}
}

float Timer::getTime()
{
	return SDL_GetTicks();
}
