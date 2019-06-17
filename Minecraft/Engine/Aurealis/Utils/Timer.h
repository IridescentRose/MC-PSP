#ifndef Aurealis_TIMER_H
#define Aurealis_TIMER_H

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
				virtual ~Timer();

				double GetDeltaTime( void );	// Returns the delta time

			private:
				double dt;

				u64 timeNow;
				u64 timeLastAsk;
				u32 tickResolution;
		};

	}
}

#endif /* TIMER_H_ */
