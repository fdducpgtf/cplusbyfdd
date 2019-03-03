#pragma once
#include<iostream>
using namespace std;


template<typename T>
class CNode {
private:
	//私有成员
	CNode<T> *next;
public:
	//公有成员
	T data;
	//构造函数
	CNode();
	CNode(const T& item);
	//插入或删除节点
	void InsertAfter(CNode<T> *pCNode);
	CNode<T> *DeleteAfter(void);

	CNode<T> *NextCNode(void) const;
	//析构函数
	~CNode();
};



//构造函数
template<typename T>
CNode<T>::CNode()
{
	next = this;
}
template<typename T>
CNode<T>::CNode(const T& item)
{
	next = this;
	data = item;
}

//insert node
template<typename T>
void CNode<T>::InsertAfter(CNode<T> *pCNode) {
	if (pCNode != NULL) {
		pCNode->next = next;
		next = pCNode;
	}
}

//delete node
template<typename T>
CNode<T> *CNode<T>::DeleteAfter(void) {
	CNode<T> *pCNode = next;
	if (pCNode == this)
		return NULL;
	next = pCNode->next;
	return pCNode;
}

//next node
template<typename T>
CNode<T> *CNode<T>::NextCNode(void) const {
	return next;
}



//析构函数
template<typename T>
CNode<T>::~CNode()
{
}

