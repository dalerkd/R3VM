#include "stdafx.h"
#include "EXCEP_CPU.h"

#include <stdarg.h>

EXCEP_CPU::EXCEP_CPU(const char* const msg = 0)
	:data(msg)
{
}


PI::PI(const char * const format, ...)
{
	va_list ap;
	va_start(ap, format);
	vsnprintf(data, MAX_EXECEP_STRING, format, ap);
}
