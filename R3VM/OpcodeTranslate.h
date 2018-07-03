#pragma once

#include <windows.h>
#include <string>


/*
####��ʱû�д���֧�ֵĲ��֣�
- �쳣
FS:0
FS[0]֮��

- INTx�ж�

- XMM����

*/


class COpcodeTranslate
{
public:
	COpcodeTranslate();
	~COpcodeTranslate();

public:
	/*
	�����ʼ��ջ��
	*/
	void Init();

	void SetIP32(DWORD32)throw(...);
	void SetIP64(DWORD64)throw(...);

	void GetIP32(DWORD32)throw(...);
	void GetIP64(DWORD64)throw(...);

	std::string GetASM();//��ǰIP
	int GetOpCodeLen();//��ǰOpCodeLen

	void WriteMemoryData_BYTE(DWORD32);
	void WriteMemoryData_WORD(DWORD32);
	void WriteMemoryData_DWORD(DWORD32);

	void WriteMemoryData_BYTE(DWORD64);
	void WriteMemoryData_WORD(DWORD64);
	void WriteMemoryData_DWORD(DWORD64);
	void WriteMemoryData_QWORD(DWORD64);

	BYTE ReadMemoryData_BYTE(DWORD32);
	WORD ReadMemoryData_WORD(DWORD32);
	DWORD32 ReadMemoryData_DWORD(DWORD32);
	

	BYTE ReadMemoryData_BYTE(DWORD64);
	WORD ReadMemoryData_WORD(DWORD64);
	DWORD32 ReadMemoryData_DWORD(DWORD64);
	DWORD64 ReadMemoryData_QWORD(DWORD64);

	//--------------------------
	//�Ĵ�����
	//https://blog.csdn.net/jn1158359135/article/details/7761011
	void SetEflags(DWORD32);//64λ������RFALGS
	DWORD32 GetEflags();

	void SetEF_ZF(bool);
	void SetEF_PF(bool);
	void SetEF_AF(bool);
	void SetEF_OF(bool);
	void SetEF_SF(bool);
	void SetEF_DF(bool);
	void SetEF_CF(bool);
	void SetEF_TF(bool);
	void SetEF_IF(bool);

	bool GetEF_ZF(bool);
	bool GetEF_PF(bool);
	bool GetEF_AF(bool);
	bool GetEF_OF(bool);
	bool GetEF_SF(bool);
	bool GetEF_DF(bool);
	bool GetEF_CF(bool);
	bool GetEF_TF(bool);
	bool GetEF_IF(bool);

	/////////////////////////////�μĴ���
	void SetGS(WORD);
	void SetFS(WORD);
	void SetES(WORD);
	void SetDS(WORD);
	void SetCS(WORD);
	void SetSS(WORD);
	
	WORD GetGS();
	WORD GetFS();
	WORD GetES();
	WORD GetDS();
	WORD GetCS();
	WORD GetSS();



	/////////////////////////////ͨ�üĴ�����
	void SetEAX(DWORD32);
	void SetEAX(DWORD64);
	
	void SetEBX(DWORD32);
	void SetEBX(DWORD64);

	void SetECX(DWORD32);
	void SetECX(DWORD64);

	void SetEDX(DWORD32);
	void SetEDX(DWORD64);
	
	void SetESI(DWORD32);
	void SetESI(DWORD64);

	void SetEDI(DWORD32);
	void SetEDI(DWORD64);

	void SetESP(DWORD32);
	void SetESP(DWORD64);

	void SetEBP(DWORD32);
	void SetEBP(DWORD64);
	//////////////////////
	DWORD32 GetEAX(DWORD32);
	DWORD64 GetEAX(DWORD64);

	DWORD32 GetEBX(DWORD32);
	DWORD64 GetEBX(DWORD64);

	DWORD32 GetECX(DWORD32);
	DWORD64 GetECX(DWORD64);

	DWORD32 GetEDX(DWORD32);
	DWORD64 GetEDX(DWORD64);

	DWORD32 GetESI(DWORD32);
	DWORD32 GetESI(DWORD64);

	DWORD64 GetEDI(DWORD32);
	DWORD64 GetEDI(DWORD64);

	DWORD32 GetESP(DWORD32);
	DWORD32 GetESP(DWORD64);

	DWORD64 GetEBP(DWORD32);
	DWORD64 GetEBP(DWORD64);



	//////////////////////////////

	size_t GetRunMode();//32λ����64λ
	void SetRunMode(size_t);

};

