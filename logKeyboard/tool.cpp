#pragma once
#include "pch.h"
#include <string>
#include <windows.h>
using namespace std;
class tool {
public:
	static HANDLE h;
	static 	string GBKToUTF8(char charGBK[])
	{
		string strOutUTF8 = "";
		WCHAR * str1;
		int n = MultiByteToWideChar(CP_ACP, 0, charGBK, -1, NULL, 0);
		str1 = new WCHAR[n];
		MultiByteToWideChar(CP_ACP, 0, charGBK, -1, str1, n);
		n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
		char * str2 = new char[n];
		WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
		strOutUTF8 = str2;
		delete str1;
		str1 = NULL;
		delete str2;
		str2 = NULL;
		return strOutUTF8;
	}


	static string UTF8ToGBK(const char* strUTF8)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
		wchar_t* wszGBK = new wchar_t[len + 1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
		char* szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
		string strTemp(szGBK);
		if (wszGBK) delete wszGBK;
		if (szGBK) delete szGBK;
		return strTemp;
	}

};