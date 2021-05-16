#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <vector>
#include <tlhelp32.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <execution>
#include <process.h>


int main(int argc, char* argv[]) {

	GetCommandLineA();
	if (argc > 2) {
		if (strcmp(argv[1], "--name") == 0) {
			PROCESSENTRY32 entry;
			entry.dwSize = sizeof(PROCESSENTRY32);
			HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

			if (Process32First(snapshot, &entry) == TRUE) {

				while (Process32Next(snapshot, &entry) == TRUE) {
					wchar_t* wc = new wchar_t[strlen(argv[2]) + 1];
					mbstowcs(wc, argv[2], strlen(argv[2]) + 1);
					if (wcscmp(entry.szExeFile, wc) == 0) {
						HANDLE proc = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
						WaitForSingleObject(proc, INFINITE);
						BOOL succ = TerminateProcess(proc, 0);
						CloseHandle(proc);
						if (!succ)
							std::cerr << "something went wrong";
						else std::cout << entry.szExeFile << " terminated" << std::endl;
					}
				}
			}
		}
		if (strcmp(argv[1], "--id") == 0) {
			int id = std::stoi(std::string(argv[2]));
			HANDLE proc = OpenProcess(PROCESS_TERMINATE, FALSE, id);
			if (proc) {
				BOOL succ = TerminateProcess(proc, 0);
				WaitForSingleObject(proc, INFINITE);
				CloseHandle(proc);
				if (!succ)
					std::cerr << "something went wrong";
				else std::cout << id << " terminated" << std::endl;
			}
		}
	}

	else {
		const char* a = "PROC_TO_KILL";
		char buff[30000];
		GetEnvironmentVariableA(a, buff, 30000);
		if (a[0] == '1') {
			std::string str(a);
			std::replace(std::begin(str), std::end(str), ',', ' ');
			std::vector<std::string> reqs;
			std::stringstream ss(str);
			while (!ss.eof()) {
				std::string tmp;
				ss >> tmp;
				reqs.push_back(tmp);
			}
			//https://stackoverflow.com/questions/865152/how-can-i-get-a-process-handle-by-its-name-in-c
			std::for_each(std::begin(reqs), std::end(reqs), [](std::string& _name) {
				PROCESSENTRY32 entry;
				entry.dwSize = sizeof(PROCESSENTRY32);
				HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
				if (Process32First(snapshot, &entry) == TRUE) {
					while (Process32Next(snapshot, &entry) == TRUE) {
						wchar_t* wc = new wchar_t[strlen(_name.c_str()) + 1];
						mbstowcs(wc, _name.c_str(), strlen(_name.c_str()) + 1);
						if (wcscmp(entry.szExeFile, wc) == 0) {
							HANDLE proc = OpenProcess(PROCESS_TERMINATE, FALSE, entry.th32ProcessID);
							BOOL succ = TerminateProcess(proc, -1);
							WaitForSingleObject(proc, INFINITE);
							CloseHandle(proc);
							if (!succ)
								std::cerr << "something went wrong";
							else std::cout << entry.szExeFile << " terminated" << std::endl;
						}
					}
				}

			});
		}

		std::string str(a);
		std::replace(std::begin(str), std::end(str), ',', ' ');
		std::vector<int> reqs;
		std::stringstream ss(str);
		while (!ss.eof()) {
			std::string tmp;
			reqs.push_back(std::stoi(tmp));
		}

		std::for_each(std::begin(reqs), std::end(reqs), [](int& _pid) {
			HANDLE proc = OpenProcess(PROCESS_TERMINATE, FALSE, _pid);
			if (proc) {
				BOOL succ = TerminateProcess(proc, -1);
				WaitForSingleObject(proc, INFINITE);
				CloseHandle(proc);
				if (!succ)
					std::cerr << "something went wrong";
				else std::cout << _pid << " terminated" << std::endl;
			}
		});
	}
}
