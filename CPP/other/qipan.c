#include <stdio.h>
#include <windows.h>

char a[10][4] = {" ","©°","©Ð","©´","©À","©à","©È","©¸","©Ø","©¼"};
int map[9][9]={
	{1, 2, 2, 2, 2, 2, 2, 2, 3},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{4, 5, 5, 5, 5, 5, 5, 5, 6},
	{7, 8, 8, 8, 8, 8, 8, 8, 9},
	};

void print(int pieces[9][9], int m, int n, int color)
{
	int i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(i==m&&j==n)
			{
				if(color == 1)
					printf("¡ñ");
				else
					printf("¡ð");
			}
			else
			{
				if(pieces[i][j]==0)
					printf("%s", a[map[i][j]]);
				else if(pieces[i][j]==1)
					printf("¡ñ");
				else
					printf("¡ð");
			}

		}
			printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	int i, j;
	int m=4, n=4, color=1;
	int pieces[9][9]={
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	system("cls");
	print(pieces, m, n, color);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut,&cci);

	while(1)
	{
		char ch = getch();
		switch(ch)
		{
			case 'w':
			case 72:
			    if(m>0)
                {
                    m--;
                    system("cls");
                    print(pieces, m, n, color);
                }
                break;
			case 's':
			case 80:
			    if(m<8)
				{
				    m++;
                    system("cls");
                    print(pieces, m, n, color);
				}
				break;
			case 'a':
			case 75:
			    if(n>0)
                {
                    n--;
                    system("cls");
                    print(pieces, m, n, color);
                }
				break;
			case 'd':
			case 77:
			    if(n<8)
                {
                    n++;
                    system("cls");
                    print(pieces, m, n, color);
			    }
				break;
			case 27:
				return 0;
			case 32:
			    if (pieces[m][n]==0)
                {
                    pieces[m][n] = color;
                    color ^= 3;
                    system("cls");
                    print(pieces, m, n, color);
                }
                break;
			case 'r':
				system("cls");
				memset(pieces, 0, sizeof(pieces));
				m=4, n=4, color=1;
				print(pieces, m, n, color);
				break;

		}
	}



	return 0;
}
