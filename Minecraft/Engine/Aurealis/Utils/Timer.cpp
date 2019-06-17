#include <Aurealis/Utils/Timer.h>

namespace Aurealis
{
	namespace Utils
	{

		Timer::Timer()
		{
			sceRtcGetCurrentTick( &timeLastAsk );
			tickResolution = sceRtcGetTickResolution();
		}

		Timer::~Timer()
		{

		}

		double Timer::GetDeltaTime( void )
		{
			sceRtcGetCurrentTick( &timeNow );
			double dt = ( timeNow - timeLastAsk ) / ((float) tickResolution );
			timeLastAsk = timeNow;

			return dt;
		}

	}
}

