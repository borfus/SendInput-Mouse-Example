#include <stdio.h>
#include <Windows.h>

#define max_coord 65535

int main()
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
    input.mi.time = 0;
    
    for(int i = 0;; i++)
    {
        if (i > 3)
            i = 0;

        if (i == 0)
        {
            input.mi.dx = max_coord * 0.2f;
            input.mi.dy = max_coord * 0.2f;
        }
        else if (i == 1)
        {
            input.mi.dx = max_coord * 0.8f;
            input.mi.dy = max_coord * 0.2f;
        }
        else if (i == 2)
        {
            input.mi.dx = max_coord * 0.8f;
            input.mi.dy = max_coord * 0.8f;
        }
        else if (i == 3)
        {
            input.mi.dx = max_coord * 0.2f;
            input.mi.dy = max_coord * 0.8f;
        }

        SendInput(1, &input, sizeof(INPUT));

        Sleep(1000);
    }

    return 0;
}
