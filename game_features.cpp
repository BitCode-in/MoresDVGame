#include <iostream>
#include <conio.h>
#include <windows.h>

static int weight;// ������
static int height;// ������
static int xplayer, yplayer, healthplayer;// ���������� ��������
static int xclouds, yclouds;//���������� �������
static int xenemy, yenemy, healthenemy;
static int leftRightButtonJump;// ��� ������� ������;
static int leftRightButtonDraw;
static int leftRightEnemy;

enum ConsoleColor {
Black = 0,
Blue = 1,
Green = 2,
Cyan = 3,
Red = 4,
Magenta = 5,
Brown = 6,
LightGray = 7,
DarkGray = 8,
LightBlue = 9,
LightGreen = 10,
LightCyan = 11,
LightRed = 12,
LightMagenta = 13,
Yellow = 14,
White = 15
};

int mainMenu()
{
  while (1)
  {
  char temp;
  system("mode con cols=51 lines=26");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  system("color Ef");
  SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | LightBlue));
  std::cout << "\n\n\n\n\n\n\n\n\n\n          ����� ���������� � MoresDVGame!";
  SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | LightMagenta));
  std::cout << "\n         ������� Enter ���� ������ ������";
  SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | LightGreen));
  std::cout << "\n                        ���";
  SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Magenta));
  std::cout << "\n               Esc ���� ������ �����!" << std::endl;
  std::cout << "                         ";
  SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
  std::cout << "\n\n\n\n\n\n\n\n\nAutor by Molot21\n(������ �� github.com ������� 1)\nCorrections by Molotov.Dmitry\n(������ �� github.com ������� 2)";
  CONSOLE_CURSOR_INFO structCursorInfo;
  GetConsoleCursorInfo(hConsole,&structCursorInfo);
  structCursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(hConsole, &structCursorInfo );
  if (temp = getch())
  {
      if (static_cast<int>(temp) == 27)
        return 0;
      else if (static_cast<int>(temp) == 13)
        return 1;
      else if (temp == '1')
        system("start iexplore.exe https://github.com/molotov-dmitry?tab=repositories");
      else if (temp == '2')
        system("start iexplore.exe https://github.com/molotov-dmitry?tab=repositories");
  }
  }

}

void setup() // ��������� ����
{
	weight = 50;
	height = 25;
	xplayer = weight/2;
	yplayer = height - 1;
	xclouds = weight + 9;
	yclouds = 5;
	xenemy = weight;
	yenemy = height - 1;
	leftRightButtonJump = 0;
	leftRightButtonDraw = 1;
	leftRightEnemy = 0;
	healthplayer = 5;
}

int heath()
{
    if(healthplayer == 0)
    {
        return 0;
    }
}

char timePressButton() // ������� ������� ������� ��� ������������ ������
{
    int k{0};
    char b;
    while(!_kbhit()) // �������� �������
    {
        ++k;
        Sleep(50);
        if (k == 5)
        {
          b = '$';
          return b;
        }
    }
    return _getch(); //����������� �� ������ � ������� _kbhit()
 }

void artificialIntimacy()
{
   if (xenemy > xplayer)
   {
     if ((xenemy - xplayer) >= 6)
        xenemy--;
     else
        xenemy += 1;
     leftRightEnemy = 1;
   }
   else if(xenemy < xplayer)
   {
       if ((xplayer - xenemy) >= 6)
        xenemy++;
     else
        xenemy -= 1;
     leftRightEnemy = 0;
   }
   else if (xenemy == xplayer)
    xenemy += 2;
}
void solidObjects () // ������� �������� � ������� ����
{
	if (xplayer > weight - 3)
	{
		xplayer -= 3;
	}
	if (xplayer < 2)
	{
		xplayer += 3;
	}
	if (xclouds == 0)
    {
        xclouds = weight + 9;
    }
}

void physicsGame() //������ ����
{
	while (yplayer < 24)
	{
		yplayer += 1;
	}
}

void rendering() // ����� ���������
{
	system("mode con cols=51 lines=26"); // ��������� �������
	int space;
	artificialIntimacy();
	solidObjects();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Yellow));
	for (int i = 1; i < weight + 2; ++i) // ��� ���������� ���� �� ������
	{
	    SetConsoleTextAttribute(hConsole, (WORD) ((LightCyan << 4) | LightCyan));
        std::cout << " ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Yellow));
	}
	std::cout << std::endl;
	for (int i = 1; i < height; ++i)
	{
		for (int j = 1; j < weight; ++j)
		{
			if (j == 1 || j == weight - 1)
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((LightBlue << 4) | LightBlue));
               if (i > 10)
               {
                  SetConsoleTextAttribute(hConsole, (WORD) ((Red << 4) | Red));
                  std::cout << " ";
               }
               else
                std::cout << " ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Yellow));
            }
            if ((yclouds == i || yclouds == i - 1 || yclouds == i + 1) && (xclouds == j || xclouds == j + 1 || xclouds == j + 2 || xclouds == j + 3 || xclouds == j + 4 || xclouds == j + 5 || xclouds == j + 6 || xclouds == j + 7 || xclouds == j + 8 || xclouds == j + 9 || xclouds == j + 10))
		    {
            SetConsoleTextAttribute(hConsole, (WORD) ((White << 4) | White));
		       std::cout << " ";
		       if (xclouds > 0)
                xclouds--;
            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightMagenta));
		    }
		    else if (i <= 10)
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((LightBlue << 4) | LightBlue));
                std::cout << " ";
                SetConsoleTextAttribute(hConsole, (WORD) ((Yellow<< 4) | Yellow));
            }
		    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | LightMagenta));
			if (yplayer == i + 1 && xplayer == j)
			{
				std::cout << "|";
			}
			else if (yplayer == i + 2 && xplayer == j)
			{
				std::cout << "|";
			}
			else if (yplayer == i && xplayer == j + 1)
			{
				std::cout << "/";
			}
			else if (yplayer == i && xplayer == j - 1)
			{
				std::cout << "\\";
			}
			else if (yplayer == i + 3 && xplayer == j)
			{
				std::cout << "0";
			}
			else if (yplayer == i + 2 && xplayer == j - 1 && leftRightButtonDraw == 1)
			{
				std::cout << "/";
			}
			else if (yplayer == i + 2 && xplayer == j + 1 && leftRightButtonDraw == 1)
			{
				std::cout << "{";
			}
			else if (yplayer == i + 2 && xplayer == j + 2 && leftRightButtonDraw == 1)
			{
				std::cout << "-";
			}
			else if (yplayer == i + 2 && xplayer == j + 1 && leftRightButtonDraw == 0)
			{
				std::cout << "\\";
			}
			else if (yplayer == i + 2 && xplayer == j - 1 && leftRightButtonDraw == 0)
			{
				std::cout << "}";
			}
			else if (yplayer == i + 2 && xplayer == j - 2 && leftRightButtonDraw == 0)
			{
				std::cout << "-";
			}
			else if (yplayer == i + 4 && (xplayer == j - 1 || xplayer == j - 2 || xplayer == j || xplayer == j + 1 || xplayer == j + 2))
			{
			    if ((xplayer == j - 2 || xplayer == j - 1 || xplayer == j || xplayer == j + 1 || xplayer == j + 2) && healthplayer == 5)
                {
                   SetConsoleTextAttribute(hConsole, (WORD) ((LightGreen << 4) | Black));
                   std::cout << " ";
                }
			    else if ((xplayer == j - 1 || xplayer == j || xplayer == j + 1 || xplayer == j + 2) && healthplayer == 4)
			    {
                   SetConsoleTextAttribute(hConsole, (WORD) ((LightGreen << 4) | Black));
			       std::cout << " ";
			    }
                else if ((xplayer == j || xplayer == j + 1 || xplayer == j + 2) && healthplayer == 3)
                {
                   SetConsoleTextAttribute(hConsole, (WORD) ((Brown << 4) | Black));
                   std::cout << " ";
                }
                else if ((xplayer == j - 2 || xplayer == j - 1) && healthplayer == 2)
                {
                   SetConsoleTextAttribute(hConsole, (WORD) ((Brown << 4) | Black));
                   std::cout << " ";
                }
                else if ((xplayer == j - 2) && healthplayer == 1)
                {
                   SetConsoleTextAttribute(hConsole, (WORD) ((Red << 4) | Black));
                   std::cout << " ";
                }
                else
                {
                   SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
                   std::cout << " ";
                }
			}
			else if (yenemy == i + 1 && xenemy == j)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "|";
			}
			else if (yenemy == i + 2 && xenemy == j)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "|";
			}
			else if (yenemy == i && xenemy == j + 1)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "/";
			}
			else if (yenemy == i && xenemy == j - 1)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "\\";
			}
			else if (yenemy == i + 3 && xenemy == j)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "0";
			}
			else if (yenemy == i + 2 && xenemy == j - 1 && leftRightEnemy == 1)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "/";
			}
			else if (yenemy == i + 2 && xenemy == j + 1 && leftRightEnemy == 1)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "{";
			}
			else if (yenemy == i + 2 && xenemy == j + 2 && leftRightEnemy == 1)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "-";
			}
			else if (yenemy == i + 2 && xenemy == j + 1 && leftRightEnemy == 0)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "\\";
			}
			else if (yenemy == i + 2 && xenemy == j - 1 && leftRightEnemy == 0)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "}";
			}
			else if (yenemy == i + 2 && xenemy == j - 2 && leftRightEnemy == 0)
			{
			    SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Black));
				std::cout << "-";
			}
			else if (i > 10)
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Yellow));
                std::cout << " ";
            }
		}
		std::cout << std::endl;
	}
		for (int i = 1; i < weight + 2; ++i)
    {
        if (i == 1 || i == weight || i == weight + 1)
        {
            SetConsoleTextAttribute(hConsole, (WORD) ((Red << 4) | Red));
            std::cout << " ";
        }
        else
        {
          SetConsoleTextAttribute(hConsole, (WORD) ((LightGray << 4) | LightGray));
          std::cout << " ";
        }
        SetConsoleTextAttribute(hConsole, (WORD) ((Yellow << 4) | Yellow));
    }
}

bool controlling()
{
	char buttons{timePressButton()};
	if (buttons != '$')
	{
        if (buttons == 'a' || buttons == '�' || 75 == static_cast<int>(buttons)) // �������� ���� �����
        {
        	xplayer -= 3;
        	leftRightButtonJump = 1;
        	leftRightButtonDraw = 1;
        }
        else if (buttons == 'd' || buttons == '�' || 77 == static_cast<int>(buttons)) // �������� ���� ������
        {
        	xplayer += 3;
        	leftRightButtonJump = 2;
        	leftRightButtonDraw = 0;
        }
        else if ((buttons == ' ' || 72 == static_cast<int>(buttons)) && leftRightButtonJump == 0) //������ �����
        {
        	yplayer -= 1;
        	rendering();
        	yplayer -= 1;
        	rendering();
        	yplayer -= 1;
        	rendering();
        	yplayer -= 1;
        	rendering();
        }
        else if ((buttons == ' ' || 72 == static_cast<int>(buttons)) && leftRightButtonJump == 1) //������ �����
        {
        	xplayer -= 1;
        	solidObjects();
        	yplayer -= 1;
        	rendering();
        	yplayer -= 1;
        	xplayer -= 1;
        	solidObjects();
        	rendering();
        	xplayer -= 1;
        	solidObjects();
        	rendering();
        	xplayer -= 1;
        	solidObjects();
        	rendering();
        	yplayer += 1;
        	xplayer -= 1;
        	solidObjects();
        	rendering();
        	yplayer += 1;
        	xplayer -= 1;
        	solidObjects();
        	leftRightButtonJump = 0;
        }
        else if (buttons == ' ' && leftRightButtonJump == 2) //������ �����
        {
        	xplayer += 1;
        	solidObjects();
        	yplayer -= 1;
        	rendering();
        	yplayer -= 1;
        	xplayer += 1;
        	solidObjects();
        	rendering();
        	xplayer += 1;
        	solidObjects();
        	rendering();
        	xplayer += 1;
        	solidObjects();
        	rendering();
        	yplayer += 1;
        	xplayer += 1;
        	solidObjects();
        	rendering();
        	yplayer += 1;
        	xplayer += 1;
        	solidObjects();
        	leftRightButtonJump = 0;
        }
        else if (static_cast<int>(buttons) == 27)
        {
        	return false;
        }
        else if (buttons == '-')
        {
            healthplayer -= 1;
        }
        return heath();
    }
    return true;
}




