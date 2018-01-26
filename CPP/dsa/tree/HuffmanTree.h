#include <iostream>
#include "MinHeap.h"
#include <vector>


template <class T>
class HuffmanTreeNode;
template <class T>
class HuffmanTree;


template <class T>
class HuffmanTreeNode {
	friend class HuffmanTree<T>;	
private:
	
	HuffmanTreeNode<T> *parent;
	HuffmanTreeNode<T> *left;
	HuffmanTreeNode<T> *right;
public:
	T info;
	void DeleteTreeNode();
};

template <class T>
bool operator>(const HuffmanTreeNode<T> &h1, const HuffmanTreeNode<T> &h2) {
	return h1.info > h2.info;
}

template <class T>
bool operator<(const HuffmanTreeNode<T> &h1, const HuffmanTreeNode<T> &h2) {
	return h1.info < h2.info;
}


template <class T>
class HuffmanTree {
private:
	HuffmanTreeNode<T> *root;
	void MergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T> *parent);
	void DeleteTree(HuffmanTreeNode<T> *root);
public:
	HuffmanTree(T weight[], int n);
	~HuffmanTree() {DeleteTree(root);}
};

template <class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n) {
	MinHeap<HuffmanTreeNode<T> > heap;
	HuffmanTreeNode<T> *parent, firstchild, secondchild;
	HuffmanTreeNode<T> *NodeList = new HuffmanTreeNode<T>[n];
	for (int i = 0; i < n; ++i) {
		NodeList[i].info = weight[i];
		NodeList[i].parent = NULL;
		NodeList[i].left = NULL;
		NodeList[i].right = NULL;
		heap.Insert(NodeList[i]);
	}
	for (int i = 0; i < n-1; ++i) {
		parent = new HuffmanTreeNode<T>;
		firstchild = heap.RemoveMin();
		secondchild = heap.RemoveMin();
		MergeTree(firstchild, secondchild, parent);
		heap.Insert(*parent);
		root = parent;
	}
	delete [] NodeList;
}

template <class T>
void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> &ht1,
							HuffmanTreeNode<T> &ht2,
							HuffmanTreeNode<T> *parent) {
	parent->left = &ht1;
	parent->right = &ht2;
	parent->info = ht1.info + ht2.info;
	ht1.parent = parent;
	ht2.parent = parent;
}

template <class T>
void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T> *root) {
	// root->DeleteTreeNode();
	return;
}

template <class T>
void HuffmanTreeNode<T>::DeleteTreeNode() {
	if (this->left != NULL)
		this->left->DeleteTreeNode();
	if (this->right != NULL)
		this->right->DeleteTreeNode();
	delete this;
}
