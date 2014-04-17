#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "InputEvents.h"

static INPUT mouseBuffer;
static INPUT keyboardBuffer;

void SetupMouse()
{
    mouseBuffer.type = INPUT_MOUSE;
    mouseBuffer.mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
    mouseBuffer.mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
    mouseBuffer.mi.mouseData = 0;
    mouseBuffer.mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
    mouseBuffer.mi.time = 0;
    mouseBuffer.mi.dwExtraInfo = 0;
}

void SetupKeyboard()
{
	keyboardBuffer.type = INPUT_KEYBOARD;
	keyboardBuffer.ki.time = 0;
	keyboardBuffer.ki.dwExtraInfo = 0;
	keyboardBuffer.ki.dwFlags = 0;
}

void KeyboardKeyPress(WORD vKey)
{
	keyboardBuffer.ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	keyboardBuffer.ki.wVk = vKey;
	keyboardBuffer.ki.dwFlags = 0;
	SendInput(1, &keyboardBuffer, sizeof(INPUT));

	Sleep(10);

	keyboardBuffer.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &keyboardBuffer, sizeof(INPUT));
}

void MouseMoveAbsolute(int x, int y)
{
	mouseBuffer.mi.dx = (x * (0xFFFF / SCREEN_WIDTH));
    mouseBuffer.mi.dy = (y * (0xFFFF / SCREEN_HEIGHT));
    mouseBuffer.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
	
    SendInput(1, &mouseBuffer, sizeof(INPUT));
}

void MouseClick()
{
    mouseBuffer.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
    SendInput(1, &mouseBuffer, sizeof(INPUT));

    Sleep(10);

    mouseBuffer.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
    SendInput(1, &mouseBuffer, sizeof(INPUT));
}