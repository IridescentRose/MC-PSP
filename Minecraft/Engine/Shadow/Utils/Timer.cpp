#include "Timer.hpp"

namespace Shadow::Utils{
Timer::Timer()
{
	sceRtcGetCurrentTick(&timeLast);
	tickResolution = sceRtcGetTickResolution();
	total = 0;
}

Timer::~Timer()
{

}

float Timer::deltaTime(void)
{
	sceRtcGetCurrentTick(&timeCurrent);
	float dt = (timeCurrent - timeLast) / ((float)tickResolution);
	timeLast = timeCurrent;

	total += dt;

	return dt;
}

float Timer::elapsed() {
	return total;
}

void Timer::reset() {
	total = 0;
}

}