#include <vector>
#include <cstdlib>

template <class T>
class MinHeap {
private:
	std::vector<T> heapV;                   // 存放堆数据的vector
	void swap(int pos_x, int pos_y);        // 交换位置x和y的元素
	void BuildHeap();                       // 建立堆
public:
	bool isEmpty() {return heapV.empty();}  // 判断堆是否为空
	bool isLeaf(int pos) const ;            // 判断是否为叶节点
	int LeftChild(int pos) const;           // 返回左子节点位置
	int RightChild(int pos) const;          // 返回右子节点位置
	int Parent(int pos) const;              // 返回父节点位置
	bool Remove(int pos, T &node);          // 删除给定下标的元素
	bool Insert(const T& newNode);          // 插入新元素
	T& RemoveMin();                         // 从堆顶删除最小值
	void SiftUp(int position);              // 从position开始向上调整
	void SiftDown(int left);                // 从left开始向下调整
};



template <class T>
void MinHeap<T>::swap(int pos_x, int pos_y) {
	T temp = heapV[pos_x];
	heapV[pos_x] = heapV[pos_y];
	heapV[pos_y] = temp;
}

template <class T>
bool MinHeap<T>::isLeaf(int pos) const {
	int size = heapV.size();
	return (pos >= size/2) && (pos < size);
}

template <class T>
void MinHeap<T>::BuildHeap() {
	for (int i = heapV.size()/2-1; i >= 0; --i)
		SiftDown(i);
}

template <class T>
int MinHeap<T>::LeftChild(int pos) const {
	return 2*pos+1;
}

template <class T>
int MinHeap<T>::RightChild(int pos) const {
	return 2*pos+2;
}

template <class T>
int MinHeap<T>::Parent(int pos) const {
	return (pos-1)/2;
}

template <class T>
bool MinHeap<T>::Insert(const T& newNode) {
	heapV.push_back(newNode);
	SiftUp(heapV.size()-1);
	return true;
}

template <class T>
T& MinHeap<T>::RemoveMin() {
	if (heapV.empty())
		exit(1);
	else {
		swap(0, heapV.size()-1);
		if (heapV.size()>2)
			SiftDown(0);
		T &temp = heapV.back();
		heapV.pop_back();
		return temp;
	}
}

template <class T>
bool MinHeap<T>::Remove(int pos, T& node) {
	if ((pos<0) || (pos >= heapV.size()))
		return false;
	node = heapV[pos];
	heapV[pos] = heapV.back();
	heapV.push_back();
	if (heapV[Parent(pos)] > heapV[pos])
		SiftUp(pos);
	else
		SiftDown(pos);
	return true;
}

template <class T>
void MinHeap<T>::SiftUp(int position) {
	while ((position > 0) && (heapV[Parent(position)] > heapV[position])) {
		swap(position, Parent(position));
		position = Parent(position);
	}
}

template <class T>
void MinHeap<T>::SiftDown(int left) {
	int i = left;
	int j = LeftChild(i);
	T temp = heapV[i];
	while (j < heapV.size()) {
		if ((j<heapV.size()-1) && (heapV[j]>heapV[j+1]))
			++j;
		if (temp > heapV[j]) {
			heapV[i] = heapV[j];
			i = j;
			j = LeftChild(j);
		}
		else
			break;
	}
	heapV[i] = temp;
}
