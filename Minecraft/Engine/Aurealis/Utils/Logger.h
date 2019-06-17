#ifndef Aurealis_LOGGER_H
#define Aurealis_LOGGER_H

namespace Aurealis
{
	namespace Utils
	{

		class Logger
		{
		private:

			static Logger m_Logger;

		public:

			static Logger* Instance()
			{
				return &m_Logger;
			}

			void LogMessage(const char *message, ...);

		};
	}
}

#endif
