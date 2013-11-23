#define _WIN32_WINNT 0x0500
#define SPAM_INTERVAL 500

#include <stdio.h>
#include <windows.h>

int main( void )
{
    //Structures used to create keyboard input event
    INPUT KeyboardInput;
    INPUT EnterKeyboardInput;

    //Print start message
    printf("Starting Impelled's Spammer ... ");

    //Pause for five seconds
    Sleep(5000);

    //Print start completion message
    printf("Done\n");

    //Set up the generic keyboard event
    KeyboardInput.type = INPUT_KEYBOARD;
    KeyboardInput.ki.wScan = 0;
    KeyboardInput.ki.time = 0;
    KeyboardInput.ki.dwExtraInfo = 0;
    KeyboardInput.ki.wVk = 0x45;
    KeyboardInput.ki.dwFlags = 0;

    //Set up the generic "enter" keyboard event
    EnterKeyboardInput.type = INPUT_KEYBOARD;
    EnterKeyboardInput.ki.wScan = 0;
    EnterKeyboardInput.ki.time = 0;
    EnterKeyboardInput.ki.dwExtraInfo = 0;
    EnterKeyboardInput.ki.wVk = 0x0D;
    EnterKeyboardInput.ki.dwFlags = 0;

    //Print spamming message
    printf("Spamming...\n");

    //Start the spamming
    while(1)
    {
        SendInput(1, &KeyboardInput, sizeof(INPUT));
        SendInput(1, &EnterKeyboardInput, sizeof(INPUT));
        Sleep(SPAM_INTERVAL);
    }

    //Exit the program successfully
    return 0;
}
