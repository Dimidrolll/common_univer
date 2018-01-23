// logger_lib.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <fstream>
#include "Header.h"

using namespace std;

LOGGER_LIB_API void* open_log(char* logname)
{
	fstream *flog = new fstream;

	flog->open(logname, ios_base::app);
	OutputDebugStringA(logname);

	if (!flog->is_open())
		return nullptr;

	return flog;
}


LOGGER_LIB_API void wr_log(char *s, char *teg, char *level, void *plog)
{
	fstream* flog = (fstream*)plog;
	flog->seekp(0, ios::end);
	*flog << level << "  " << teg << "  " << s << endl;
}


LOGGER_LIB_API void close_log(void *logfile)
{
	fstream* flog = (fstream*)logfile;
	flog->close();
	delete flog;
}