#include <iostream>
#include <windows.h>
#include "game_features.h"


int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    bool gameover{0};
    while (1)
    {
     gameover = mainMenu();
     setup();
     while (gameover)
    {
       solidObjects();
       rendering();
       gameover = controlling();
       physicsGame();
    }
    if (!gameover)
     {
       break;
     }
    }
    return 0;
}
