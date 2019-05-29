#pragma once
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <cstring>

enum AccessMethod { ORead, OWrite, ReadAndWrite };
enum FlagsAndAttributes { Synchronous, Asynchronous };

class SerialPort
{
private:
	HANDLE hCom;
	struct serialSettingInfo
	{
		LPCSTR serialName;//����
		DWORD dwDesiredAccess;//�������ͣ���ѡ
		DWORD dwShareMode;//�������Ա���Ϊ0
		LPSECURITY_ATTRIBUTES lpSecurityAttributes;//���ð�ȫ������
		DWORD dwCreationDistribution;//������ΪOPEN_EXISTING
		DWORD dwFlagsAndAttributes;//������������ѡͬ�����߲�ͬ��
		HANDLE hTemplateFile;//����ΪNULL
	} spSettingInfo;
	
public:
	SerialPort();
	bool InitSerialPort(const char* portname,int BaudRate, char parity,char databit,char stopbit, AccessMethod accessMethod, FlagsAndAttributes flagsAndAtrributes);
	bool unInitSerialPort();
	int WriteToPort(const void * buf, int len);
	int ReadFromPort(void * buf, int len);
	~SerialPort();
};

