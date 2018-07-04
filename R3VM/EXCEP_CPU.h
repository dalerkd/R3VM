#pragma once
#include <exception>

#define MAX_EXECEP_STRING 256

class EXCEP_CPU: public std::exception
{
public:
	EXCEP_CPU(const char* const msg);

	const char * what() const throw ()
	{
		return data;
	}
	const char* const data;
};
/*
//EXCEPTION_PRIV_INSTRUCTION
PI:当前模式下不能执行该命令
某些寄存器写权限不足
UD:未定义命令
AV:访问违例
GP:通用错误:内存引用或保护性检查
*/
class PI:public EXCEP_CPU
{
public:
	PI(const char* const msg);

	PI::PI(const char * const format, ...);

	const char * what() const throw ()
	{
		return data;
	}
	char data[MAX_EXECEP_STRING] = { 0 };
};
class UD:public EXCEP_CPU
{
public:
	UD(const char* const msg);
	UD();

	const char * what() const throw ()
	{
		return data;
	}
	const char* const data;
};
class AV:public EXCEP_CPU
{
public:
	AV(const char* const msg);
	AV();

	const char * what() const throw ()
	{
		return data;
	}
	const char* const data;
};
class GP:public EXCEP_CPU
{
public:
	GP(const char* const msg);
	GP();

	const char * what() const throw ()
	{
		return data;
	}
	const char* const data;
}
