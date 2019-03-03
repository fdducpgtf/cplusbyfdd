#pragma once
#include<iostream>
using namespace std;


template<typename T>
class Node {
private:
	Node<T> *next;
public:
	T data;
	Node(const T& item, Node<T> *ptrNext = NULL);
	~Node();

	void InsertAfter(Node<T> *pNode);
	Node<T> *DeleteAfter(void);

	Node<T> *NextNode(void) const;


};



//构造函数
template<typename T>
Node<T>::Node(const T& item, Node<T> *ptrNext) :data(item), next(ptrNext)
{

}

//insert node
template<typename T>
void Node<T>::InsertAfter(Node<T> *pNode) {
	if (pNode != NULL) {
		pNode->next = this->next;
		this->next = pNode;
	}
}

//delete node
template<typename T>
Node<T> *Node<T>::DeleteAfter(void) {
	Node<T> *p = this->next;
	if (p == NULL)
		return NULL;
	this->next = p->next;
	return p;
}

//next node
template<typename T>
Node<T> *Node<T>::NextNode(void) const {
	return next;
}



//析构函数
template<typename T>
Node<T>::~Node()
{
}

