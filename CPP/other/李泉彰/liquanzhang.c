#include <stdio.h>



struct node
{
	int height;
	bool is_self;
	int value;
	int v;
	node *ob[20];
	int x, y;
};

int qipan[19][19];

// 落子在(x, y)的value
int getvalue(int x, int y, bool is_self);

// 判断能否落子
bool judge(int x, int y);


node *root = new node;
root->height = 0;
root->value = 0;
root->is_self = false;
for (int i = 0; i < 20; ++i)
{
	root->ob[i] = NULL;
}

void play(node *root)
{
	if (root->height == 2)
		return;
	int k = 0;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (k>=20)
				return;
			if (judge(i, j))
			{
				int value = getvalue(i, j, !root->is_self);
				qipan[i][j] = root->is_self?2:1;
				ob[k] = new node;
				ob[k]->height = root->height;
				ob[k]->value = value;
				ob[k]->is_self = !root->is_self;
				ob[k]->x = i;
				ob[k]->y = j;
				for (int i = 0; i < 20; ++i)
				{
					ob[k]->ob[i] = NULL;
				}
				play(ob[k]);
				qipan[i][j] = 0;
				k++;
			}
		}
	}
}

void calc_value(node *root)
{
	if (root->ob[0] == NULL)
	{
		root->v = root->value;
		return;
	}
	int max_value = MIN_INT;
	for (int i = 0; i < 20; ++i)
	{
		calc_value(root->ob[i]);
		if (root->ob[i]->v > max_value)
		{
			max_value = root->ob[i]->v;
		}
	}
	root->v = root->value - max_value;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}