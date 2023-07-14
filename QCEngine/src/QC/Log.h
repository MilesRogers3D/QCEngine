#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace QC
{
	class QC_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& 
			GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>&
			GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define QC_CORE_TRACE(...)   ::QC::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QC_CORE_INFO(...)    ::QC::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QC_CORE_WARN(...)    ::QC::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QC_CORE_ERROR(...)   ::QC::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QC_CORE_FATAL(...)   ::QC::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define QC_TRACE(...)        ::QC::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QC_INFO(...)         ::QC::Log::GetClientLogger()->info(__VA_ARGS__)
#define QC_WARN(...)         ::QC::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QC_ERROR(...)        ::QC::Log::GetClientLogger()->error(__VA_ARGS__)
#define QC_FATAL(...)        ::QC::Log::GetClientLogger()->critical(__VA_ARGS__)

// TODO (Miles): If dist build, do not include any logging
