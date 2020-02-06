#pragma once

#ifdef _DEBUG
#include <string>
#include <stdio.h>
#include <Utils/Defaults.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Args
{
	static HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static HANDLE hConsoleErr = GetStdHandle(STD_ERROR_HANDLE);

	static int defTextCol = DEBUG_GREY;
	static const int defErrCol = DEBUG_RED;
	static const int defWarnCol = DEBUG_YELLOW;
	static const int defSuccessCol = DEBUG_GREEN;
	static int textCol = defTextCol;
	static int errCol = defErrCol;
	static int warnCol = defWarnCol;
	static int successCol = defSuccessCol;
}

#define SET_DEBUG_COLOR(consoleHandle, printMode, textColor)			\
	switch (printMode)													\
	{																	\
		case DEFAULT:													\
			SetConsoleTextAttribute(consoleHandle, textColor);			\
			Args::defTextCol = textColor;								\
			break;														\
		case TEMP:														\
			SetConsoleTextAttribute(consoleHandle, textColor);			\
			Args::textCol = textColor;									\
		case SUCCESS:													\
			Args::successCol = textColor;								\
			break;														\
		case ERROR:														\
			SetConsoleTextAttribute(consoleHandle, textColor);			\
			Args::errCol = textColor;									\
			break;														\
		case WARNING:													\
			Args::warnCol = textColor;									\
			break;														\
	}																	\

#define RESET_DEBUG_COLOR(printMode)									\
	switch (printMode)													\
	{																	\
		case DEFAULT:													\
			SET_DEBUG_COLOR(hConsoleOut, printMode, Args::defTextCol)	\
			break;														\
		case TEMP:														\
			SET_DEBUG_COLOR(hConsoleOut, printMode, Args::defTextCol)	\
			break;														\
		case SUCCESS:													\
			SET_DEBUG_COLOR(hConsoleErr, printMode, Args::defSuccessCol)\
			break;														\
		case ERROR:														\
			SET_DEBUG_COLOR(hConsoleErr, printMode, Args::defErrCol)	\
			break;														\
		case WARNING:													\
			SET_DEBUG_COLOR(hConsoleOut, printMode, Args::defWarnCol)	\
			break;														\
	}																	\

#define CREATE_MESSAGE(debugMessage)																																		\
	std::string(std::string("[") + fileDir + std::string("] line ") + std::to_string(__LINE__) + std::string(": ") + std::string(debugMessage) + std::string("\n")).c_str()	\

#define GET_FILENAME													\
	std::string fileDir = std::string(__FILE__);						\
	fileDir = fileDir.substr(fileDir.find_last_of("\\") + 1);			\

#define PRINT_MESSAGE(debugMessage, tempTextCol, inserts)				\
{																		\
	GET_FILENAME														\
	SET_DEBUG_COLOR(Args::hConsoleOut, TEMP, tempTextCol)				\
	fprintf(stdout, CREATE_MESSAGE(debugMessage), inserts...);			\
	RESET_DEBUG_COLOR(TEMP)												\
}

#define PRINT_SUCCESS(debugMessage, inserts)							\
	PRINT_MESSAGE(debugMessage, Args::successCol, inserts);				\

#define PRINT_ERR(errorMessage, inserts)								\
{																		\
	GET_FILENAME														\
	fprintf(stderr, CREATE_MESSAGE(errorMessage), inserts...);			\
}

#define PRINT_WARN(warningMessage, inserts)								\
	PRINT_MESSAGE(warningMessage, Args::warnCol, inserts);				\

#define PRINT(printMode, message, inserts)								\
	switch (printMode)													\
	{																	\
		case SUCCESS:													\
			PRINT_SUCCESS(message, inserts)								\
			break;														\
		case ERROR:														\
			PRINT_ERR(message, inserts)									\
			break;														\
		case WARNING:													\
			PRINT_WARN(message, inserts)								\
			break;														\
		case DEFAULT:													\
			PRINT_MESSAGE(message, Args::defTextCol, inserts)			\
			break;														\
		default:														\
			PRINT_MESSAGE(message, printMode, inserts)					\
	}																	\

#else

#define SET_DEBUG_COLOR(consoleHandle, printMode, textColor)
#define RESET_DEBUG_COLOR(printMode)
#define CREATE_MESSAGE(debugMessage)
#define GET_FILENAME
#define PRINT_MESSAGE(debugMessage, tempTextCol, ...)
#define PRINT_SUCCESS(debugMessage, ...)
#define PRINT_ERR(errorMessage, ...)
#define PRINT_WARN(warningMessage, ...)
#define PRINT(printMode, message, ...)
#endif // DEBUG
namespace Args
{
	class Debug
	{
	public:
		FORCEINLINE static void SetColor(int type, int color)
		{
			if (type == ERROR)
				SET_DEBUG_COLOR(hConsoleErr, type, color)
			else
				SET_DEBUG_COLOR(hConsoleOut, type, color)
		}

		FORCEINLINE static void ResetColor(int type)
		{
			RESET_DEBUG_COLOR(type)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(int color, const char* message, InsertTypes... inserts)
		{
			PRINT_MESSAGE(message, color, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(int color, std::string message, InsertTypes... inserts)
		{
			PRINT_MESSAGE(message.c_str(), color, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(const char* message, InsertTypes... inserts)
		{
			PRINT(DEFAULT, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(std::string message, InsertTypes... inserts)
		{
			PRINT(DEFAULT, message.c_str(), inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Success(const char* message, InsertTypes... inserts)
		{
			PRINT(SUCCESS, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Success(std::string message, InsertTypes... inserts)
		{
			PRINT(SUCCESS, message.c_str(), inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Error(const char* message, InsertTypes... inserts)
		{
			PRINT(ERROR, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Error(std::string message, InsertTypes... inserts)
		{
			PRINT(ERROR, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Warning(const char* message, InsertTypes... inserts)
		{
			PRINT(WARNING, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Warning(std::string message, InsertTypes... inserts)
		{
			PRINT(WARNING, message, inserts)
		}
	};
}