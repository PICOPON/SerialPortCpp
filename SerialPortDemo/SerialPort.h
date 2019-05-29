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
		LPCSTR serialName;//串口
		DWORD dwDesiredAccess;//访问类型，可选
		DWORD dwShareMode;//共享属性必须为0
		LPSECURITY_ATTRIBUTES lpSecurityAttributes;//引用安全性属性
		DWORD dwCreationDistribution;//必须置为OPEN_EXISTING
		DWORD dwFlagsAndAttributes;//属性描述，可选同步或者不同步
		HANDLE hTemplateFile;//必须为NULL
	} spSettingInfo;
	
public:
	SerialPort();
	bool InitSerialPort(const char* portname,int BaudRate, char parity,char databit,char stopbit, AccessMethod accessMethod, FlagsAndAttributes flagsAndAtrributes);
	bool unInitSerialPort();
	int WriteToPort(const void * buf, int len);
	int ReadFromPort(void * buf, int len);
	~SerialPort();
};

