#pragma once
#include "Core/Log/LogSystem.h"
#define LOG_HELPER(LOG_LEVEL, ...) \
    LogSystem::getInstance().log(LOG_LEVEL, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER(LogSystem::LogLevel::debug, __VA_ARGS__);

#define LOG_INFO(...) LOG_HELPER(LogSystem::LogLevel::info, __VA_ARGS__);

#define LOG_WARN(...) LOG_HELPER(LogSystem::LogLevel::warn, __VA_ARGS__);

#define LOG_ERROR(...) LOG_HELPER(LogSystem::LogLevel::error, __VA_ARGS__);

#define LOG_FATAL(...) LOG_HELPER(LogSystem::LogLevel::fatal, __VA_ARGS__);


#ifndef NDEBUG
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define DEBUGBREAK() __debugbreak()
//#else
//#define DEBUGBREAK()
#endif
#else
#define DEBUGBREAK()
#endif // !NDEBUG

#define ASSERT(checked, ...) { if(!(checked)) { LOG_ERROR(__VA_ARGS__); DEBUGBREAK(); } }

#define PublicSingletonInstance(SingleClass) PublicSingleton<SingleClass>::getInstance()

//结点的掩码，显示与隐藏
#define NODE_SHOW ~0x0
#define NODE_HIDE 0x0