#pragma once

namespace Aurealis
{
	namespace Utils
	{
		class Logger
		{
		public:
			void LogMessage(const char *message, ...);
		};

		extern Logger g_Logger;
	}
}
