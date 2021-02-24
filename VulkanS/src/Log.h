#pragma once


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace VKSP
{
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetDebugLogger() { return s_DebugLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_DebugLogger;
	};
}

// Sould Wrap in another macro (CORE)

#define VK_TRACE(...) ::VKSP::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VK_INFO(...) ::VKSP::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VK_WARN(...) ::VKSP::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VK_ERROR(...) ::VKSP::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VK_FATAL(...) ::VKSP::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define VK_D_TRACE(...) ::VKSP::Log::GetDebugLogger()->trace(__VA_ARGS__)
#define VK_D_INFO(...) ::VKSP::Log::GetDebugLogger()->info(__VA_ARGS__)
#define VK_D_WARN(...) ::VKSP::Log::GetDebugLogger()->warn(__VA_ARGS__)
#define VK_D_ERROR(...) ::VKSP::Log::GetDebugLogger()->error(__VA_ARGS__)
#define VK_D_FATAL(...) ::VKSP::Log::GetDebugLogger()->fatal(__VA_ARGS__)