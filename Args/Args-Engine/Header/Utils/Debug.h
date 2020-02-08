#pragma once
#include <stdio.h>
#include <time.h>

#ifdef _DEBUG
#include <string>
#include <Utils/Defaults.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Args
{
	static HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static HANDLE hConsoleErr = GetStdHandle(STD_ERROR_HANDLE);

	static int defTextCol = DEBUG_WHITE;
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
			SET_DEBUG_COLOR(hConsoleOut, printMode, Args::defSuccessCol)\
			break;														\
		case ERROR:														\
			SET_DEBUG_COLOR(hConsoleErr, printMode, Args::defErrCol)	\
			break;														\
		case WARNING:													\
			SET_DEBUG_COLOR(hConsoleOut, printMode, Args::defWarnCol)	\
			break;														\
	}																	\

#define CREATE_MESSAGE(data, debugMessage)																														\
	std::string(std::string("[") + data.file + std::string("]\tline ") + data.line + std::string(": ") + std::string(debugMessage) + std::string("\n")).c_str()	\

#define PRINT_MESSAGE(data, debugMessage, tempTextCol, inserts)				\
{																			\
	SET_DEBUG_COLOR(Args::hConsoleOut, TEMP, tempTextCol)					\
	std::fprintf(stdout, CREATE_MESSAGE(data, debugMessage), inserts...);	\
	RESET_DEBUG_COLOR(TEMP)													\
}

#define PRINT_SUCCESS(data, debugMessage, inserts)							\
	PRINT_MESSAGE(data, debugMessage, Args::successCol, inserts);			\

#define PRINT_ERR(data, errorMessage, inserts)								\
{																			\
	SetConsoleTextAttribute(hConsoleErr, Args::errCol);						\
	std::fprintf(stderr, CREATE_MESSAGE(data, errorMessage), inserts...);	\
}

#define PRINT_WARN(data, warningMessage, inserts)						\
	PRINT_MESSAGE(data, warningMessage, Args::warnCol, inserts);		\

#define PRINT(printMode, data, message, inserts)						\
	switch (printMode)													\
	{																	\
		case SUCCESS:													\
			PRINT_SUCCESS(data, message, inserts)						\
			break;														\
		case ERROR:														\
			PRINT_ERR(data, message, inserts)							\
			break;														\
		case WARNING:													\
			PRINT_WARN(data, message, inserts)							\
			break;														\
		case DEFAULT:													\
			PRINT_MESSAGE(data, message, Args::defTextCol, inserts)		\
			break;														\
		default:														\
			PRINT_MESSAGE(data, message, printMode, inserts)			\
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

#define DebugInfo Args::Debug::DebugData(__FILE__, __LINE__)


namespace Args
{
	class Debug
	{
	private:
		static std::string startDate;
		static FILE* outFile;
	public:
		struct DebugData
		{
		public:
			std::string file;
			std::string line;

			DebugData(const char* fileName, int lineNumber) : file(fileName), line(std::to_string(lineNumber))
			{
				file = file.substr(file.find_last_of("\\") + 1);
			}
		};

		static std::string GetDateTime()
		{
			time_t rawtime;
			struct tm timeinfo;
			char buffer[80];

			time(&rawtime);
			localtime_s(&timeinfo, &rawtime);

			strftime(buffer, sizeof(buffer), "%d-%m-%Y %H-%M", &timeinfo);

			return std::string(buffer);
		}

		FORCEINLINE static void CloseOutputFile()
		{
			fclose(outFile);
			outFile = nullptr;
		}

		FORCEINLINE static void OpenOutputFile()
		{
			fopen_s(&outFile, (std::string("../Logs/output ") + startDate + std::string(".log")).c_str(), "w");
		}

		FORCEINLINE static void SetColor(int type, int color)
		{
			if (type == ERROR)
				SET_DEBUG_COLOR(hConsoleErr, type, color)
			else
				SET_DEBUG_COLOR(hConsoleOut, type, color)
		}

		FORCEINLINE static void SetColor(int type, bool r, bool g, bool b, bool intensify)
		{
			int color = (r ? 0x0001 : 0x0) | (g ? 0x0010 : 0x0) | (b ? 0x0100 : 0x0) | (intensify ? 0x1000 : 0x0);

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
		FORCEINLINE static void Log(int color, DebugData data, const char* message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message), inserts...);

			PRINT_MESSAGE(data, message, color, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(int color, DebugData data, std::string message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message.c_str()), inserts...);

			PRINT_MESSAGE(data, message.c_str(), color, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(DebugData data, const char* message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message), inserts...);

			PRINT(DEFAULT, data, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Log(DebugData data, std::string message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message.c_str()), inserts...);

			PRINT(DEFAULT, data, message.c_str(), inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Success(DebugData data, const char* message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message), inserts...);

			PRINT(SUCCESS, data, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Success(DebugData data, std::string message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, CREATE_MESSAGE(data, message.c_str()), inserts...);

			PRINT(SUCCESS, data, message.c_str(), inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Error(DebugData data, const char* message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, "<[ERROR]> ");
			std::fprintf(outFile, CREATE_MESSAGE(data, message), inserts...);

			PRINT(ERROR, data, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Error(DebugData data, std::string message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, "<[ERROR]> ");
			std::fprintf(outFile, CREATE_MESSAGE(data, message.c_str()), inserts...);

			PRINT(ERROR, data, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Warning(DebugData data, const char* message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, "<[WARNING]> ");
			std::fprintf(outFile, CREATE_MESSAGE(data, message), inserts...);

			PRINT(WARNING, data, message, inserts)
		}

		template<typename... InsertTypes>
		FORCEINLINE static void Warning(DebugData data, std::string message, InsertTypes... inserts)
		{
			if (!outFile)
				OpenOutputFile();

			std::fprintf(outFile, "<[WARNING]> ");
			std::fprintf(outFile, CREATE_MESSAGE(data, message.c_str()), inserts...);

			PRINT(WARNING, data, message, inserts)
		}
	};
}