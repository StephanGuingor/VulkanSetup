#include "vkpch.h"
#include "Log.h"


namespace VKSP
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_DebugLogger;


	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("vksp");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_DebugLogger = spdlog::stdout_color_mt("VLayer");
		s_DebugLogger->set_level(spdlog::level::trace);


	}

}
