#include <Shadow/Utils/Logger.h>

#include <pspkernel.h>
#include <string>
#include <fstream>


namespace Shadow::Utils::Logging{
	
	void log(std::string msg, LoggerLevel level) {
		switch (level) {
		case LOGGER_LEVEL_TRACE: {
			trace(msg);
			break;
		}
		case LOGGER_LEVEL_DEBUG: {
			debug(msg);
			break;
		}
		case LOGGER_LEVEL_INFO: {
			info(msg);
			break;
		}
		case LOGGER_LEVEL_WARN: {
			warn(msg);
			break;
		}
		case LOGGER_LEVEL_ERROR: {
			error(msg);
			break;
		}
		case LOGGER_LEVEL_FATAL: {
			fatal(msg);
			break;
		}

		}
	}
	void trace(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_TRACE) {
			std::ofstream file("log.log");
			file << "[TRACE]: " << msg << std::endl;
			file.close();
		}
	}
	void debug(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_DEBUG) {

			std::ofstream file("log.log");
			file << "[DEBUG]: " << msg << std::endl;
			file.close();
		}
	}
	void info(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_INFO) {
			std::ofstream file("log.log");
			file << "[INFO]: " << msg << std::endl;
			file.close();
		}
	}
	void warn(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_WARN) {
			std::ofstream file("log.log");
			file << "[WARN]: " << msg << std::endl;
			file.close();
		}
	}
	void error(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_ERROR) {
			std::ofstream file("log.log");
			file << "[ERROR]: " << msg << std::endl;
			file.close();
		}
	}
	void fatal(std::string msg) {
		if (logging_level <= LOGGER_LEVEL_FATAL) {
			std::ofstream file("log.log");
			file << "[FATAL]: " << msg << std::endl;
			file.close();
		}
	}

	LoggerLevel logging_level = LoggerLevel::LOGGER_LEVEL_DEBUG;
}
