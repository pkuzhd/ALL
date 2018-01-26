// ����ϲ�
// pkuzhd
// 2018.01.04
#include <iostream>

using namespace std;

struct LinkNode
{
	int data;
	LinkNode *next;
	LinkNode() { data = 0, next = NULL; }
};

// ��������: �ӱ�׼�����ȡ���ݣ��������������ش���������ͷ
LinkNode *CreateLinkList();

// �ϲ��������������������ͷָ�룬���غϲ��������ͷָ�롣�ϲ����������Ȼ����
LinkNode *MergeLinkList(LinkNode *a, LinkNode *b);

// ��������ʾ�ϲ���������Ԫ�ء�
void DisplayLinkList(LinkNode *linklist);

// �ͷ�����ռ䣺���CreateLinkList��ʹ����new����ռ䣬����ѭ��ʹ��delete�ͷ�
void DestroyLinkList(LinkNode *linklist);

int amain(int argc, char *argv[])
{
	LinkNode *root1 = CreateLinkList(); // ������һ������
	LinkNode *root2 = CreateLinkList(); // �����ڶ�������
	LinkNode *root = MergeLinkList(root1, root2); // �ϲ���������
	root1 = root2 = NULL; // ָ����Ϊ��
	DisplayLinkList(root); 
	DestroyLinkList(root);
	root = NULL;
	return 0;
}

LinkNode * CreateLinkList()
{
	int n;
	cin >> n;
	LinkNode *root = new LinkNode;
	cin >> root->data;
	root->next = NULL;
	LinkNode *curNode = root;
	for (int i = 1; i < n; ++i)
	{
		curNode->next = new LinkNode;
		curNode = curNode->next;
		cin >> curNode->data;
		curNode->next = NULL;
	}
	return root;
}

LinkNode * MergeLinkList(LinkNode * a, LinkNode * b)
{
	LinkNode *root = NULL;
	if (a->data < b->data)
	{
		root = a;
		a = a->next;
		root->next = NULL;
	}
	else
	{
		root = b;
		b = b->next;
		root->next = NULL;
	}
	LinkNode *curNode = root;
	while (a != NULL || b != NULL)
	{
		if (a != NULL && a->data < b->data)
		{
			curNode->next = a;
			a = a->next;
			curNode = curNode->next;
			while (a != NULL && a->data < b->data)
			{
				curNode = curNode->next;
				a = a->next;
			}
			curNode->next = NULL;
		}
		else
		{
			curNode->next = b;
			b = b->next;
			curNode = curNode->next;
			while (b != NULL && a->data < b->data)
			{
				curNode = curNode->next;
				b = b->next;
			}
			curNode->next = NULL;
		}
	}
	return root;
}

void DisplayLinkList(LinkNode * linklist)
{
	if (linklist != NULL)
	{
		cout << linklist->data;
		linklist = linklist->next;
	}
	while (linklist != NULL)
	{
		cout << " " << linklist->data;
		linklist = linklist->next;
	}
	cout << endl;
}

void DestroyLinkList(LinkNode * linklist)
{
	LinkNode *preNode = linklist;
	LinkNode *curNode = linklist->next;
	while (curNode->next != NULL)
	{
		delete preNode;
		preNode = curNode;
		curNode = curNode->next;
	}
	delete preNode;
	preNode = NULL;
}
