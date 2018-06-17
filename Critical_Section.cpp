#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;
int x = 0;
int y;
CRITICAL_SECTION cs;
void Metod()
{	while (true)
	{		for (x = 0; x<11; x++)
		{	y = x ^ 3 + 2 * x ^ 2 + 3 * x + 10;
			x = x - 0, 99;
			TryEnterCriticalSection(&cs);
			LeaveCriticalSection(&cs);		}
	}
}
void Pokaz() {
	while (true) {
		TryEnterCriticalSection(&cs);
		cout << "Potok 2" << endl;
		cout << y << endl;
		Sleep(1000);
		LeaveCriticalSection(&cs);	}
}
void main()
{	HANDLE Thread_1, Thread_2;
	DWORD ID;
	DWORD Par = 0;
	Thread_1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Pokaz, (LPVOID)Par, 0,(LPDWORD)&ID);
	Thread_2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Metod, (LPVOID)Par, 0,(LPDWORD)&ID);
	while (true);     }
