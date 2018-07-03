#include "stdafx.h"
#include "CPU.h"


CCPU::CCPU() :m_POT(nullptr)
{

}


CCPU::~CCPU()
{
}

void CCPU::StartWork()
{
	m_POT = new COpcodeTranslate();

	m_POT->Init();
	m_POT->SetIP32(0x1000);

	SwitchLoop();
	/*


	*/



}

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


void CCPU::SwitchLoop()
{

	while (true)
	{

		string  strASM = m_POT->GetASM();
		auto oplen = m_POT->GetOpCodeLen();

		vector<string> asmStrs = analysisASMStr(strASM);

		auto asmNumber = asmStrs.size();

		if (0 == asmNumber)
		{
			throw("44");
		}
		else if (3 > asmNumber)
		{
			throw("48");
		}

		std::string commandStr = asmStrs[0];

		if (asmNumber == 1)
		{
			switch (hash_(commandStr.c_str())) {
			case "nop"_hash:

				break;
			default:
				throw("不支持的asmStr88");
				break;
			}

		}
		else if (asmNumber == 2)
		{
			switch (hash_(commandStr.c_str())) {
			default:
				break;
			}
		}
		else if (asmNumber == 3)
		{
			switch (hash_(commandStr.c_str())) {
			case "add"_hash:
			{
				break;;
			}

			default:
				break;
			}
		}



	}

}
