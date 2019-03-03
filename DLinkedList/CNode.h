#pragma once
#include<iostream>
using namespace std;


template<typename T>
class CNode {
private:
	//˽�г�Ա
	CNode<T> *next;
public:
	//���г�Ա
	T data;
	//���캯��
	CNode();
	CNode(const T& item);
	//�����ɾ���ڵ�
	void InsertAfter(CNode<T> *pCNode);
	CNode<T> *DeleteAfter(void);

	CNode<T> *NextCNode(void) const;
	//��������
	~CNode();
};



//���캯��
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



//��������
template<typename T>
CNode<T>::~CNode()
{
}

