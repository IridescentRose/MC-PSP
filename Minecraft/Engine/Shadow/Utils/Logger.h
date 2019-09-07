#pragma once
#include <string>
namespace Shadow::Utils::Logging{
	enum LoggerLevel {
		LOGGER_LEVEL_TRACE = 0,
		LOGGER_LEVEL_DEBUG = 1,
		LOGGER_LEVEL_INFO = 2,
		LOGGER_LEVEL_WARN = 3,
		LOGGER_LEVEL_ERROR = 4,
		LOGGER_LEVEL_FATAL = 5,
	};
	
	
	extern LoggerLevel logging_level;

	void log(std::string msg, LoggerLevel level);
	void trace(std::string msg);
	void debug(std::string msg);
	void info(std::string msg);
	void warn(std::string msg);
	void error(std::string msg);
	void fatal(std::string msg);
	

}
