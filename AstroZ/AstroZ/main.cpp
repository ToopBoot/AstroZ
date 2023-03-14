
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <ShObjIdl.h>
using namespace std;
bool GetFor() {
	while (true)
	{
		float powerUsage, gpuUsage, cpuUsage, ramUsage;

		SYSTEM_POWER_STATUS powerStatus;
		GetSystemPowerStatus(&powerStatus);
		powerUsage = (float)powerStatus.BatteryLifePercent;

		gpuUsage = (float)0.0f;

		SYSTEM_INFO systemInfo;
		GetSystemInfo(&systemInfo);
		cpuUsage = (float)systemInfo.dwProcessorType;

		MEMORYSTATUSEX memStatus;
		memStatus.dwLength = sizeof(memStatus);
		GlobalMemoryStatusEx(&memStatus);
		ramUsage = (float)memStatus.dwMemoryLoad;

		cout << "POWER_USAGE: " << powerUsage << "w" << endl;
		cout << "CPU_USAGE: " << cpuUsage << "%" << endl;
		cout << "RAM_USAGE: " << ramUsage << "%" << endl;

		system("cls");
		Sleep(2);
	}
}

int main()
{
   
	GetFor(); //stat the while loop to calculate the process....
	
	return 0;
}