#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Elysium
{
	class ELYSIUM_API Log
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

#define EL_CORE_ERROR(...)	::Elysium::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EL_CORE_WARN(...)	::Elysium::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EL_CORE_TRACE(...)	::Elysium::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EL_CORE_INFO(...)	::Elysium::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EL_CORE_FATAL(...)	::Elysium::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define EL_ERROR(...)	::Elysium::Log::GetClientLogger()->error(__VA_ARGS__)
#define EL_WARN(...)	::Elysium::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EL_TRACE(...)	::Elysium::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EL_INFO(...)	::Elysium::Log::GetClientLogger()->info(__VA_ARGS__)
#define EL_FATAL(...)	::Elysium::Log::GetClientLogger()->fatal(__VA_ARGS__)


