#include <stdio.h>

char change[] = "0123456789ABCDEF";

void itoh(int x, char s[])
{
	int i;
	if (x>=0)
	{
		for (i = 7; i >= 0; --i)
		{
			s[i] = change[x%16];
			x = x/16;
		}
	}
	else
	{
		x = -x-1;
		for (i = 7; i >= 0; --i)
		{
			s[i] = change[15-x%16];
			x = x/16;
		}
	}
}

int main()
{
	int x;
	char s[9] = {0};
	// scanf("%d", &x);
	// itoh(x, s);
	// printf("%s\n", s);
	int i = 0;
	for (i = 0; i!=-1; ++i)
	{
		itoh(i, s);
		printf("%d %s\n", i, s);
	}
	return 0;
}