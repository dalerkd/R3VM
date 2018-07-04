// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_(char const* str)
{
	hash_t ret{ basis };

	while (*str) {
		ret ^= *str;
		ret *= prime;
		str++;
	}

	return ret;
}

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}
constexpr unsigned long long operator "" _hash(char const* p, size_t)
{
	return hash_compile_time(p);
}

void test1()
{
	std::string asmStrs("jmp");
	switch (hash_(asmStrs.c_str())) {
	case "jmp"_hash:break;
	case "xor"_hash:break;
	case "mov"_hash:break;
	case "cmp"_hash:break;
	case "test"_hash:break;
	case "add"_hash:break;
	case "clc"_hash:break;
	case "inc"_hash:break;
	case "stc"_hash:break;
	case "ror"_hash:break;
	case "cmc"_hash:break;
	case "sub"_hash:break;
	case "lea"_hash:break;
	case "not"_hash:break;
	case "rol"_hash:break;
	case "push"_hash:break;
	case "ret"_hash:break;
	case "movzx"_hash:break;
	case "ja"_hash:break;
	case "btr"_hash:break;
	case "bt"_hash:break;
	case "rep"_hash:break;
	case "btc"_hash:break;
	case "sbb"_hash:break;
	case "bts"_hash:break;
	case "and"_hash:break;
	case "shl"_hash:break;
	case "rcl"_hash:break;
	case "pop"_hash:break;
	case "shr"_hash:break;
	case "pushfd"_hash:break;
	case "adc"_hash:break;
	case "movsx"_hash:break;
	case "sar"_hash:break;
	case "rcr"_hash:break;
	case "or"_hash:break;
	case "xchg"_hash:break;
	case "neg"_hash:break;
	case "bsf"_hash:break;
	case "xadd"_hash:break;
	case "bswap"_hash:break;
	case "shrd"_hash:break;
	case "cmovo"_hash:break;
	case "cmovns"_hash:break;
	case "lahf"_hash:break;
	case "dec"_hash:break;
	case "shld"_hash:break;
	case "setp"_hash:break;
	case "cmove"_hash:break;
	case "cbw"_hash:break;
	case "bsr"_hash:break;
	case "setnp"_hash:break;
	case "seta"_hash:break;
	case "nop"_hash:break;
	case "je"_hash:break;
	case "cwde"_hash:break;
	case "jb"_hash:break;
	case "cmovno"_hash:break;
	case "popfd"_hash:break;
	case "cmova"_hash:break;
	case "cld"_hash:break;
	case "call"_hash:break;
	case "setl"_hash:break;
	case "jne"_hash:break;
	case "sets"_hash:break;
	case "setg"_hash:break;
	case "cmovnp"_hash:break;
	case "cmovge"_hash:break;
	case "cmovg"_hash:break;
	case "cmovbe"_hash:break;
	case "cmovb"_hash:break;

	default:

		break;
	}

}

/*
//EXCEPTION_PRIV_INSTRUCTION
PI:当前模式下不能执行该命令
某些寄存器写权限不足
UD:未定义命令
AV:访问违例
GP:通用错误:内存引用或保护性检查
*/

#include <stdarg.h>

class CH
{
public:
	//vsnprintf(char *str, size_t size, const char *format, va_list ap) ?。
	CH(const char*  format,...)
	{
		va_list ap;
		va_start(ap, format);
		char temp[256] = { 0 };

		vsnprintf(temp, 256, format, ap);
		printf("%s",temp);
	}
protected:
private:
};

int main()
{
	CH* p = new CH("Hi");
	delete p;


	
    return 0;
}

