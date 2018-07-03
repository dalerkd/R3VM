#pragma once
#include "OpcodeTranslate.h"

#include <vector>
using std::vector;
using std::string;

class CCPU
{
public:
	CCPU();
	~CCPU();

public:
	void StartWork();

private:
	COpcodeTranslate * m_POT;
	void SwitchLoop();
	
	vector<string> analysisASMStr(string);

};

