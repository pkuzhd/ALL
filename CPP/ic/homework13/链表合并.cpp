// 链表合并
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

// 建立链表: 从标准输入读取数据，并创建链表，返回创建的链表头
LinkNode *CreateLinkList();

// 合并链表：参数是两个链表的头指针，返回合并后链表的头指针。合并后的链表仍然有序
LinkNode *MergeLinkList(LinkNode *a, LinkNode *b);

// 遍历并显示合并后的链表的元素。
void DisplayLinkList(LinkNode *linklist);

// 释放链表空间：如果CreateLinkList中使用了new分配空间，这里循环使用delete释放
void DestroyLinkList(LinkNode *linklist);

int amain(int argc, char *argv[])
{
	LinkNode *root1 = CreateLinkList(); // 创建第一个链表
	LinkNode *root2 = CreateLinkList(); // 创建第二个链表
	LinkNode *root = MergeLinkList(root1, root2); // 合并两个链表
	root1 = root2 = NULL; // 指针设为空
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
