#include "trlpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Trail {
	 std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	 std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() { //initialization of the logger
		spdlog::set_pattern("%^[%T] %n: %v%$");//timestamp [%T], name of the logger %n:, message: %v%$
		s_CoreLogger = spdlog::stdout_color_mt("TRAIL");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}