#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <Windows.h>
#include <iostream>
#include <sstream>

auto main() -> int {
	const char* name = "PROC_TO_KILL";
	const char* value = "notepad.exe,calculator.exe";
	SetEnvironmentVariableA(name, value);
	STARTUPINFO s{0};
	
	PROCESS_INFORMATION p{0};
	std::stringstream ss;

	ss << "killer.exe";
	std::cout << ss.str() << std::endl;
	CreateProcess(NULL, (LPSTR)ss.str().c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	CloseHandle(p.hProcess);

	CreateProcess(R"(C:\WINDOWS\system32\cmd.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	ss.str("");
	ss << "killer.exe --name cmd.exe";
	std::cout << ss.str() <<std::endl;
	CreateProcess(NULL, (LPSTR)ss.str().c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	ss.str("");
	CreateProcess(R"(C:\WINDOWS\system32\notepad.exe)", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	ss << "killer.exe --id " << p.dwProcessId;
	std::cout << ss.str() << std::endl;
	CreateProcess(NULL, (LPSTR)ss.str().c_str(), NULL, NULL, FALSE, NULL, NULL, NULL, &s, &p);
	WaitForSingleObject(p.hProcess, INFINITE);
	CloseHandle(p.hProcess);
	SetEnvironmentVariableA(name, NULL);
}
