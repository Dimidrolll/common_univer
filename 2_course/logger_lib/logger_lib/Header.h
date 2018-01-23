#pragma once

#include <string>
#ifdef LOGGER_LIB_EXPORTS
#define LOGGER_LIB_API __declspec(dllexport)
#else
#define LOGGER_LIB_API __declspec(dllimport)
#endif
#include <fstream>

extern "C" {
	LOGGER_LIB_API void __cdecl wr_log(char *s, char *teg, char *level, void *plog);
	LOGGER_LIB_API void * __cdecl open_log(char* logname);
	LOGGER_LIB_API void __cdecl close_log(void *);
}

//extern "C" {
	
	//LOGGER_LIB_EXPORTS void __cdecl log_string(char *s, char *teg, int level, void *);//вывести сообщение
//}