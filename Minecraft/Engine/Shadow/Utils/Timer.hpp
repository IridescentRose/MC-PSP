#pragma once


#include <psptypes.h>
#include <stdio.h>
#include <psprtc.h>

namespace Shadow::Utils{
class Timer {
public:
	Timer();
	virtual ~Timer();

	float deltaTime(void);

	float elapsed();
	void reset();

private:
	double dt;
	double total;

	u64 timeCurrent;
	u64 timeLast;

	u32 tickResolution;
};
}