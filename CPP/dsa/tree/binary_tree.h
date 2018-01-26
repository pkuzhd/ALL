#include <iostream>

template <class T>
class BinaryTreeNode;

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;
private:
	T info;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	BinaryTreeNode<T> *parent;
public:
	BinaryTreeNode();
	BinaryTreeNode(const T& ele);
	BinaryTreeNode(const T& ele,
				BinaryTreeNode<T> *l, 
				BinaryTreeNode<T> *r,
				BinaryTreeNode<T> *p=NULL);
	~BinaryTreeNode();
	T value() const;
	BinaryTreeNode<T> *leftchild() const;
	BinaryTreeNode<T> *rightchild() const;
	void setLeftchild(BinaryTreeNode<T> *);
	void setRightchild(BinaryTreeNode<T> *);
	void setValue(const T& val);
	bool isLeaf() const;
	BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node);
};

template <class T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree() {root=NULL;}
	~BinaryTree() {DeleteBinaryTree(root);}
	bool isEmpty() const;
	BinaryTreeNode<T> *Root() {return root;}
	BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current);
	BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T> *current);
	BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T> *current);
	void CreateTree(const T& info,
				BinaryTree<T>& leftTree,
				BinaryTree<T>& rightTree);
	void PreOrder(BinaryTreeNode<T> *root);
	void PreOrderWithoutRecursion(BinaryTreeNode<T> *root);
	void InOrder(BinaryTreeNode<T> *root);
	void InOrderWithoutRecursion(BinaryTreeNode<T> *root);
	void PostOrder(BinaryTreeNode<T> *root);
	void PostOrderWithoutRecursion(BinaryTreeNode<T> *root);
	void LevelOrder(BinaryTreeNode<T> *root);
	void DeleteBinaryTree(BinaryTreeNode<T> *root);
};


template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele)
{
	info = ele;
	left = NULL;
	right = NULL;
	parent = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele,
				BinaryTreeNode<T> *l, 
				BinaryTreeNode<T> *r,
				BinaryTreeNode<T> *p)
{
	info = ele;
	left = l;
	right = r;
	parent = p;
}
template <class T>
T BinaryTreeNode<T>::value() const
{
	return info;
}
template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::leftchild() const
{
	return left;
}
template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::rightchild() const
{
	return right;
}
template <class T>
void BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T> *l)
{
	left = l;
}
template <class T>
void BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T> *r)
{
	right = r;
}
template <class T>
void BinaryTreeNode<T>::setValue(const T& val)
{
	info = val;
}
template <class T>
bool BinaryTreeNode<T>::isLeaf() const
{
	return left==NULL && right==NULL;
}
template <class T>
BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &Node)
{
	BinaryTreeNode<T> newTreeNode = new BinaryTreeNode(Node.info, Node.left, Node.right, Node.parent);
	return newTreeNode;
}






template <class T>
bool BinaryTree<T>::isEmpty() const
{
	return root==NULL;
}
template <class T>
BinaryTreeNode<T> *BinaryTree<T>::Parent(BinaryTreeNode<T> *current)
{
	return current->parent;
}
template <class T>
BinaryTreeNode<T> *BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *current)
{
	return current->left;
}
template <class T>
BinaryTreeNode<T> *BinaryTree<T>::RightSibling(BinaryTreeNode<T> *current)
{
	return current->right;
}
template <class T>
void BinaryTree<T>::CreateTree(const T& info,
			BinaryTree<T>& leftTree,
			BinaryTree<T>& rightTree)
{

}
template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::PreOrderWithoutRecursion(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::InOrderWithoutRecursion(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::PostOrderWithoutRecursion(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T> *root)
{

}
template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T> *root)
{

}
