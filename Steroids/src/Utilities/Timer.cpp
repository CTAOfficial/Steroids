#include "Timer.h"

Timer::Timer(float time, float reset, float speed) : Time{ time }, TimeReset{ reset }, speed{ speed }
{

}

bool Timer::Count(float deltaTime)
{
	if (isComplete) { return true; }
	Time -= (speed * deltaTime);

	if (Time <= 0) {
		isComplete = true;
	}

	return isComplete;
}

bool Timer::Complete() const
{
	return isComplete;
}

void Timer::Reset()
{
	isComplete = false;
	Time = TimeReset;
}
