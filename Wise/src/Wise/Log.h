#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Wise {
	class WISE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros

#define WS_CORE_TRACE(...)   ::Wise::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WS_CORE_INFO(...)    ::Wise::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WS_CORE_WARN(...)    ::Wise::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WS_CORE_ERROR(...)   ::Wise::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WS_CORE_FATAL(...)   ::Wise::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros

#define WS_INFO(...)    ::Wise::Log::GetClientLogger()->info(__VA_ARGS__)
#define WS_TRACE(...)   ::Wise::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WS_WARN(...)    ::Wise::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WS_ERROR(...)   ::Wise::Log::GetClientLogger()->error(__VA_ARGS__)
#define WS_FATAL(...)   ::Wise::Log::GetClientLogger()->fatal(__VA_ARGS__)