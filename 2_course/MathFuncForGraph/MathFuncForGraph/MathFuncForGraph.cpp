// MathFuncForGraph.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <cmath>

#ifdef MATHFUNCFORGRAPH_EXPORTS
#define MATHFUNCFORGRAPH_API __declspec(dllexport) 
#else
#define MATHFUNCFORGRAPH_API __declspec(dllimport) 
#endif

using namespace std;

static bool log_ok = false;
static HMODULE dll_log = NULL;

typedef void*(__cdecl *open_logger)(char*);
typedef void(__cdecl *close_logger)(void *);
typedef void(__cdecl *wr_logger)(char *, char*, char*, void *);

open_logger open_log;
close_logger close_log;
wr_logger wr_log;

char * StringToChar(string s)
{
	char *cstr = new char[s.length() + 1];
	strcpy(cstr, s.c_str());
		
	return cstr;
}

void * file;
static void check_log()
{
	log_ok = false;
	dll_log = nullptr;
	dll_log = ::LoadLibrary(L"logger_lib.dll");
	if (dll_log != nullptr)
	{

		open_log = (open_logger)GetProcAddress(dll_log, "open_log");
		close_log = (close_logger)GetProcAddress(dll_log, "close_log");
		wr_log = (wr_logger)GetProcAddress(dll_log, "wr_log");
		if (wr_log && close_log && open_log)
			log_ok = true;//checked!!!!!!!!!


		char * name = StringToChar("log_math.txt");
		if (log_ok)
			file = open_log(name);
		delete[] name;
	}
}

void log_init()
{
	check_log();
}

void log_exit()
{
	if (log_ok)
	{
		close_log(file);
		FreeLibrary(dll_log);
	}
	dll_log = nullptr;
	log_ok = false;
}

namespace MyMath
{
	const double step = 0.05;
	const double beg = -10.0;
	const int count = 400;

//	MATHFUNCFORGRAPH_API void destroy_array(void *array)
//	{
//
//		delete[]array;
//
//		log_init();
//		if (log_ok)
//		{
//			string s = "Удален массив";
//			char * message = StringToChar(s);
//			wr_log(message, "<delete>", "[INFO]", file);
//			delete[] message;
//		}
//		log_exit();
//	}

	MATHFUNCFORGRAPH_API double* SinUp(double a, double b, double c)
	{
		log_init();

		if (log_ok)
		{
			string s = " SinUp -> " + to_string(a) + " " + to_string(b) + " " + to_string(c);
			char * mes = StringToChar(s);
			wr_log(mes, "<sinup>", "[INFO]", file);
			delete[] mes;
		}

		double *result = new double[count];
		for (int i = 0; i < count; ++i) {
			result[i] = beg + step * i;
			result[i + 1] = a * sin(b * result[i]) + c;
			++i;
		}
		log_exit();
		return result;
	}

	MATHFUNCFORGRAPH_API double* Squarity(double a, double b, double c)
	{
		log_init();

		if (log_ok)
		{
			string s = " Squarity -> " + to_string(a) + " " + to_string(b) + " " + to_string(c);
			char * mes = StringToChar(s);
			wr_log(mes, "<sqr>", "[INFO]", file);
			delete[] mes;
		}

		double *result = new double[count];
		for (int i = 0; i < count; ++i) {
			result[i] = beg + step * i;
			result[i+1] = a * result[i] * result[i] + b * result[i] + c;
			++i;
		}
		log_exit();
		return result;
	}

	MATHFUNCFORGRAPH_API double* SinDown(double a, double b, double c)
	{
		log_init();

		if (log_ok)
		{
			string s = " SinDown -> " + to_string(a) + " " + to_string(b) + " " + to_string(c);
			char * mes = StringToChar(s);
			wr_log(mes, "<sindown>", "[INFO]", file);
			delete[] mes;
		}

		double *result = new double[count];
		for (int i = 0; i < count; ++i) {
			result[i + 1] = beg + step * i;
			result[i] = a * sin(b * result[i + 1]) + c;
			++i;
		}
		log_exit();
		return result;
	}

	MATHFUNCFORGRAPH_API double* Triple(double a, double b, double c)
	{
		log_init();

		if (log_ok)
		{
			string s = " Triple -> " + to_string(a) + " " + to_string(b) + " " + to_string(c);
			char * mes = StringToChar(s);
			wr_log(mes, "<tri>", "[INFO]", file);
			delete[] mes;
		}

		double *result = new double[count];
		for (int i = 0; i < count; ++i) {
			result[i] = beg + step * i;
			result[i+1] = a * result[i] * result[i] * result[i] + b * result[i] + c;
			++i;
		}
		log_exit();
		return result;
	}

	MATHFUNCFORGRAPH_API double* ConstABC(double a, double b, double c)
	{
		log_init();

		if (log_ok)
		{
			string s = " ConstABC -> " + to_string(a) + " " + to_string(b) + " " + to_string(c);
			char * mes = StringToChar(s);
			wr_log(mes, "<const>", "[INFO]", file);
			delete[] mes;
		}

		double *result = new double[count];
		for (int i = 0; i < count; ++i) {
			result[i] = beg + step * i;
			result[i+1] = a + b + c;
			++i;
		}
		log_exit();
		return result;
	}

	extern "C"
	{
		MATHFUNCFORGRAPH_API void destroy_array(double *array)
		{
			delete[]array;
		}
		MATHFUNCFORGRAPH_API double *get_sin_up(double a, double b, double c)
		{
			return SinUp(a,b,c);
		}
		MATHFUNCFORGRAPH_API double *get_squarity(double a, double b, double c)
		{
			return Squarity(a, b, c);
		}
		MATHFUNCFORGRAPH_API double *get_sin_down(double a, double b, double c)
		{
			return SinDown(a, b, c);
		}
		MATHFUNCFORGRAPH_API double *get_triple(double a, double b, double c)
		{
			return Triple(a, b, c);
		}
		MATHFUNCFORGRAPH_API double *get_const_abc(double a, double b, double c)
		{
			return ConstABC(a, b, c);
		}
	
	}
}