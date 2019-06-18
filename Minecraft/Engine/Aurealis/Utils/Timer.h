#pragma once

#include <psptypes.h>
#include <stdio.h>
#include <psprtc.h>

namespace Aurealis
{
	namespace Utils
	{
		class Timer
		{
			public:
				Timer();

				float GetDeltaTime( void );	// Returns the delta time

			private:
				float dt;

				u64 timeNow;
				u64 timeLastAsk;
				u32 tickResolution;
		};

	}
}