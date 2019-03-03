#pragma once
#include<iostream>
using namespace std;

template<typename T>
class DNode {
private:
	DNode<T> *left, *right;

public:
	T data;

	DNode();
	DNode(const T& item);

	void InsertLeft(DNode<T> *pDNode);
	void InsertRight(DNode<T> *pDNode);
	DNode<T> *DeleteDNode(void);

	DNode<T> *NextNodeLeft(void) const;
	DNode<T> *NextNodeRight(void) const;

	~DNode();

};


//构造函数
template<typename T>
DNode<T>::DNode() {
	left = this;
	right = this;
}

template<typename T>
DNode<T>::DNode(const T& item) {
	left = this;
	right = this;
	data = item;
}

//左边插入
template<typename T>
void DNode<T>::InsertLeft(DNode<T> *pDNode) {

	//左插入受影响的：
	//1.新节点的左右指针要改变；
	//2.当前节点的左指针受影响，右指针指向自己（没有右节点）时受影响
	//3.当前节点的左节点有时，左节点的右指针受影响。
		//没有左节点时，左指针指向当前节点，左指针所指的右指针相当于当前节点的右指针。也要指向新节点。


	//新节点的右指针指向当前节点
	pDNode->right = this;
	//新节点的左指针指向当前节点的左节点
	pDNode->left = left;
	//如果当前节点的左边有节点，就让当前节点的左节点的右指针指向新节点
	//如果当前节点的左边没有节点，当前节点的左指针指向自己，自己的右指针也应该指向新节点
	if (left != this)//a
		left->right = pDNode;
	//当前节点的左指针指向新节点
	left = pDNode;
	//如果当前节点右边没有节点（当前节点右指针指向自己表明右边没有节点）
	//让当前节点的右指针指向新节点
	if (right == this)//b
		right = pDNode;
	//上面a,b不同时发生，判断条件只有其中一个成立


}

//右边插入
template<typename T>
void DNode<T>::InsertRight(DNode<T> *pDNode) {
	//新节点左指针指向当前节点，新节点右指针指向当前节点原来右指针所指的节点
	pDNode->left = this;
	pDNode->right = right;
	//如果当前节点右边有节点（右指针不指向自己，指向自己表明右边没有节点），
	//应该修改当前节点的右节点的左指针，让它指向新节点。
	if (right != this)
		right->left = pDNode;
	//当前节点的右指针指向新节点
	right = pDNode;
	//如果当前节点的左指针指向自己，即左边没有节点，
	//就让当前节点的左指针指向新节点。
	if (left == this)
		left = pDNode;
	

}

//删除当前节点
template<typename T>
DNode<T> *DNode<T>::DeleteDNode(void) {
	if ((left == this) && (right == this)) {
		return NULL;
	}
	else {
		this->left->right = this->right;
		this->right->left = this->left;
		return this;
	}
}

template<typename T>
DNode<T> *DNode<T>::NextNodeLeft(void) const {
	return left;
}

template<typename T>
DNode<T> *DNode<T>::NextNodeRight(void) const {
	return right;
}




template<typename T>
DNode<T>::~DNode() {
	
}

