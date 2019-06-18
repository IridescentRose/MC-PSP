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

		float Timer::GetDeltaTime( void )
		{
			sceRtcGetCurrentTick( &timeNow );
			float dt = ( timeNow - timeLastAsk ) / ((float) tickResolution );
			timeLastAsk = timeNow;

			return dt;
		}

	}
}

