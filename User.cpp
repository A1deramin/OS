#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <Windows.h>
#include <iostream>
#include <sstream>

auto main() -> int {
	const char* name = "PROC_TO_KILL";
	const char* value = "calculator.exe";
	char buff[30000];
	SetEnvironmentVariableA(name, value);
	GetEnvironmentVariableA(name, buff, 30000);
	STARTUPINFO s{0};
	PROCESS_INFORMATION p{0};
	CreateProcess(R"(C:\WINDOWS\system32\calc.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	CreateProcess(R"(C:\WINDOWS\system32\notepad.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	std::stringstream ss;
	std::cout << p.dwProcessId;
	ss << "killer.exe --id " << p.dwProcessId;
	CreateProcess(NULL, (LPSTR)ss.str().c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	CloseHandle(p.hProcess);

	CreateProcess(R"(C:\WINDOWS\system32\calc.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	CreateProcess(R"(C:\WINDOWS\system32\notepad.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);

	ss.clear();
	ss << "killer.exe --name calculator.exe";
	CreateProcess(NULL, (LPSTR)ss.str().c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	CloseHandle(p.hProcess);
	SetEnvironmentVariableA(name, NULL);

}
