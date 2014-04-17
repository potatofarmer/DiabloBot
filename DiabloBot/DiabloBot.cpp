// DiabloBot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void MouseSetup(INPUT *buffer)
{
    buffer->type = INPUT_MOUSE;
    buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.mouseData = 0;
    buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
    buffer->mi.time = 0;
    buffer->mi.dwExtraInfo = 0;
}

void KeyboardSetup(INPUT *buffer)
{
	buffer->type = INPUT_KEYBOARD;
	buffer->ki.time = 0;
	buffer->ki.dwExtraInfo = 0;
	buffer->ki.dwFlags = 0;
}

void KeyboardKeyPress(INPUT *buffer, WORD vKey)
{
	buffer->ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	buffer->ki.wVk = vKey;
	buffer->ki.dwFlags = 0; // there is no KEYEVENTF_KEYDOWN
	SendInput(1, buffer, sizeof(INPUT));

	Sleep(10);

	buffer->ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, buffer, sizeof(INPUT));
}

void MouseMoveAbsolute(INPUT *buffer, int x, int y)
{
    buffer->mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
    buffer->mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
	
    SendInput(1, buffer, sizeof(INPUT));

	Sleep(1000);
}


void MouseClick(INPUT *buffer)
{
    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, buffer, sizeof(INPUT));

    Sleep(10);

    buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, buffer, sizeof(INPUT));
}

void SleepSec(int sec)
{
	Sleep(sec * 1000);
}

int _tmain(int argc, _TCHAR* argv[])
{
	INPUT buffer;
	INPUT keyboardBuffer;

    MouseSetup(&buffer);
	KeyboardSetup(&keyboardBuffer);

	SleepSec(10);

	while (true)
	{
		MouseMoveAbsolute(&buffer, 274, 510);
		MouseClick(&buffer);
		SleepSec(20);

		MouseMoveAbsolute(&buffer, 100, 40);
		MouseClick(&buffer);
		SleepSec(10);

		MouseMoveAbsolute(&buffer, 1533, 0);
		KeyboardKeyPress(&keyboardBuffer, 0x34);
		SleepSec(3);

		MouseMoveAbsolute(&buffer, 1919, 836);
		MouseClick(&buffer);
		SleepSec(2);

		MouseMoveAbsolute(&buffer, 1693, 930);
		MouseClick(&buffer);
		SleepSec(2);

		MouseMoveAbsolute(&buffer, 1177, 960);
		MouseClick(&buffer);
		SleepSec(2);

		//MouseMoveAbsolute(&buffer, 984, 572);
		//MouseClick(&buffer);
		//SleepSec(3);

		MouseMoveAbsolute(&buffer, 333, 0);
		MouseClick(&buffer);
		SleepSec(3);

		MouseMoveAbsolute(&buffer, 220, 96);
		MouseClick(&buffer);
		SleepSec(3);

		MouseMoveAbsolute(&buffer, 84, 970);
		MouseClick(&buffer);
		SleepSec(3);

		MouseMoveAbsolute(&buffer, 595, 875);
		MouseClick(&buffer);
		SleepSec(2);

		MouseMoveAbsolute(&buffer, 983, 927);
		MouseClick(&buffer);
		SleepSec(2);

		MouseMoveAbsolute(&buffer, 1667, 978);
		MouseClick(&buffer);
		SleepSec(3);

		MouseMoveAbsolute(&buffer, 1183, 463);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 1020, 454);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 970, 454);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 1005, 511);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 900, 487);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 996, 481);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 800, 560);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 900, 480);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 1000, 560);
		MouseClick(&buffer);
		SleepSec(1);

		MouseMoveAbsolute(&buffer, 970, 481);
		MouseClick(&buffer);
		SleepSec(1);

		KeyboardKeyPress(&keyboardBuffer, 0x54);
		SleepSec(20);

		KeyboardKeyPress(&keyboardBuffer, VK_ESCAPE);
		SleepSec(2);

		MouseMoveAbsolute(&buffer, 279, 483);
		MouseClick(&buffer);
		SleepSec(20);
	}

    return 0;
}

