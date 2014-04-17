// DiabloBot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputEvents.h"

#define D3_SKILL_BUTTON_4 0x34
#define D3_TELEPORT_BUTTON 0x54

void moveMouseClickAndWait(int x, int y, int sleepTime)
{
	MouseMoveAbsolute(x, y);
	MouseClick();
	Sleep(sleepTime);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetupMouse();
	SetupKeyboard();

	Sleep(10000); // After bot launch we need some time to switch to the game

	while (true) // Main run loop. Each loop = one quest run
	{
		// Click on "Resume game" button and wait until game loads
		moveMouseClickAndWait(274, 510, 20000);

		// Click on portal
		moveMouseClickAndWait(100, 40, 10000);

		// Use "Falling sword" skill to teleport upstairs
		MouseMoveAbsolute(1533, 0);
		KeyboardKeyPress(D3_SKILL_BUTTON_4);
		Sleep(3000);

		// Go to the alchemist
		moveMouseClickAndWait(1919, 836, 2000);
		moveMouseClickAndWait(1693, 930, 2000);

		// Click on the alchemist
		moveMouseClickAndWait(1177, 960, 2000);

		// Go up to the descent
		moveMouseClickAndWait(333, 0, 3000);
		moveMouseClickAndWait(220, 96, 3000);

		// Go down by the stairs
		moveMouseClickAndWait(84, 970, 3000);
		moveMouseClickAndWait(595, 875, 2000);
		moveMouseClickAndWait(983, 927, 2000);
		moveMouseClickAndWait(1667, 978, 3000);

		// Should be near the hermit. He is moving, so trying to click on him
		moveMouseClickAndWait(1183, 463, 1000);
		moveMouseClickAndWait(1020, 454, 1000);
		moveMouseClickAndWait(970, 454, 1000);
		moveMouseClickAndWait(1005, 511, 1000);
		moveMouseClickAndWait(900, 487, 1000);
		moveMouseClickAndWait(996, 481, 1000);
		moveMouseClickAndWait(800, 560, 1000);
		moveMouseClickAndWait(900, 480, 1000);
		moveMouseClickAndWait(1000, 560, 1000);
		moveMouseClickAndWait(970, 481, 1000);

		// Suppose, that we clicked on him. Should teleport to the city now
		KeyboardKeyPress(D3_TELEPORT_BUTTON);
		Sleep(20000);

		// Open the menu
		KeyboardKeyPress(VK_ESCAPE);
		Sleep(2000);

		// Press "Leave game" button
		moveMouseClickAndWait(279, 483, 20000);
	}

    return 0;
}

