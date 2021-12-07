#pragma once
#include"Common.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<stdarg.h>
#include<Windows.h>
#include<ctime>

using namespace std;
namespace E3D {
	extern std::ofstream* GLogStream;
	bool InitLog(const EString& fileName);
	void Log(const EChar *string, ...);
	void CloseLog();
	inline EString InToString(EFloat num) {
		stringstream ss;
		ss << num;
		EString re;
		ss >> re;
		return re;
	}
	inline EInt RandomInt(EInt from = 0, EInt to = 10) {
		EInt ran = rand() % (to - from + 1) + from;
		return ran;
	}
	inline EInt StringToInt(const EString& str) {
		return atoi(str.c_str());
	}
	inline EFloat StringToFloat(const EString& str) {
		return (EFloat)atof(str.c_str());
	}
	inline EWString ToEWString(const EString& str) {
		int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), NULL, 0);
		WCHAR* tString = new WCHAR[wcsLen + 1];
		::MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), tString, wcsLen);
		tString[wcsLen] = '\0';
		return EWString(tString);
	}
}