// SerialPortDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "SerialPort.h"

int main()
{
	SerialPort sPort;
	if (sPort.InitSerialPort("COM2", 9600, 0, 8, 1, ReadAndWrite, Synchronous))//串口模式和参数设置
	{
		sPort.WriteToPort("helloworld", 10);//写入串口数据
		{
			char buf[1024];
			memset(buf, 0, 1024);
			while (true)
			{
				memset(buf, 0, 1024);
				sPort.ReadFromPort(buf, 1024);
				std::cout << buf;
			};//读出串口的数据
		}
	}
	std::cout << "~finished\n";
}
