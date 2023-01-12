#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

int color = 0, i = 0, d = 0, mass[5], color_input[5], count = 0;
bool generator = false, repeat;

void generate()
{
    color = rand() % 9 + 1;
    for (i = 0; i < 5; i++)
    {
        if (color == mass[i])
        {
            repeat = true;
        }
    }
    if (repeat == false)
    {
        mass[d] = color;
        d++;
    }
    if (d == 5)
    {
        generator = true;
    }
    repeat = false;
}

void CoutCentered(std::string text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);
    COORD NewSBSize = lpScreenInfo->dwSize;
    for (int i = 0; i < 14; i++)
        std::cout << std::endl;

    if (NewSBSize.X > text.size())
    {
        int newpos = ((NewSBSize.X - text.size()) / 2);
        for (int i = 0; i < newpos; i++)
            std::cout << " ";
    }
    std::cout << text << std::endl;
}

void color_show(int(x))
{
    switch (x)
    {
    case 1:
        system("cls");
        system("color 65");
        CoutCentered("Red");
        Sleep(500);
        break;
    case 2:
        system("cls");
        system("color 23");
        CoutCentered("Orange");
        Sleep(500);
        break;
    case 3:
        system("cls");
        system("color fc");
        CoutCentered("Yellow");
        Sleep(500);
        break;
    case 4:
        system("cls");
        system("color 4a");
        CoutCentered("Green");
        Sleep(500);
        break;
    case 5:
        system("cls");
        system("color 70");
        CoutCentered("Cyan");
        Sleep(500);
        break;
    case 6:
        system("cls");
        system("color 54");
        CoutCentered("Blue");
        Sleep(500);
        break;
    case 7:
        system("cls");
        system("color 61");
        CoutCentered("Purple");
        Sleep(500);
        break;
    case 8:
        system("cls");
        system("color a8");
        CoutCentered("Pink");
        Sleep(500);
        break;
    case 9:
        system("cls");
        system("color 3d");
        CoutCentered("White");
        Sleep(500);
        break;
    default:
        break;
    }
    system("cls");
    system("color 07");
}

void color_table()
{
    cout << "1 - Red" << endl;
    cout << "2 - Orange" << endl;
    cout << "3 - Yellow" << endl;
    cout << "4 - Green" << endl;
    cout << "5 - Cyan" << endl;
    cout << "6 - Blue" << endl;
    cout << "7 - Purple" << endl;
    cout << "8 - Pink" << endl;
    cout << "9 - White" << endl;
}

void game()
{
    cout << "Remember the colors and enter them in the right order" << endl;
    cout << "If you ready press any key" << endl;
    _getch();
    system("cls");
    d = 0;
    while (d < 5)
    {
        color_show(mass[d]);
        d++;
    }
    color_table();
    cout << "Enter the colors in the right order" << endl;
    d = 0;
    while (d < 5)
    {
        cin >> color_input[d];
        d++;
    }
    for (d = 0; d < 5; d++)
    {
        if (color_input[d] != mass[d])
        {
            count++;
        }
    }
    system("cls");
    cout << "You have " << count << " errors" << endl;
    if (count == 0)
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "right sequence:" << endl;
        for (d = 0; d < 5; d++)
        {
            cout << mass[d] << " ";
        }
        cout << endl;
        cout << "your sequence:" << endl;
        for (d = 0; d < 5; d++)
        {
            cout << color_input[d] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(unsigned(time(nullptr)));
    while (generator == false)
    {
        generate();
    }
    game();
    cout << "Press X to exit" << endl;
switch1:
    switch (_getch())
    {
    case 'x':
        return 0;
        break;
    default:
        goto switch1;
        break;
    }
}