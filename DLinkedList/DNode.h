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


//���캯��
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

//��߲���
template<typename T>
void DNode<T>::InsertLeft(DNode<T> *pDNode) {

	//�������Ӱ��ģ�
	//1.�½ڵ������ָ��Ҫ�ı䣻
	//2.��ǰ�ڵ����ָ����Ӱ�죬��ָ��ָ���Լ���û���ҽڵ㣩ʱ��Ӱ��
	//3.��ǰ�ڵ����ڵ���ʱ����ڵ����ָ����Ӱ�졣
		//û����ڵ�ʱ����ָ��ָ��ǰ�ڵ㣬��ָ����ָ����ָ���൱�ڵ�ǰ�ڵ����ָ�롣ҲҪָ���½ڵ㡣


	//�½ڵ����ָ��ָ��ǰ�ڵ�
	pDNode->right = this;
	//�½ڵ����ָ��ָ��ǰ�ڵ����ڵ�
	pDNode->left = left;
	//�����ǰ�ڵ������нڵ㣬���õ�ǰ�ڵ����ڵ����ָ��ָ���½ڵ�
	//�����ǰ�ڵ�����û�нڵ㣬��ǰ�ڵ����ָ��ָ���Լ����Լ�����ָ��ҲӦ��ָ���½ڵ�
	if (left != this)//a
		left->right = pDNode;
	//��ǰ�ڵ����ָ��ָ���½ڵ�
	left = pDNode;
	//�����ǰ�ڵ��ұ�û�нڵ㣨��ǰ�ڵ���ָ��ָ���Լ������ұ�û�нڵ㣩
	//�õ�ǰ�ڵ����ָ��ָ���½ڵ�
	if (right == this)//b
		right = pDNode;
	//����a,b��ͬʱ�������ж�����ֻ������һ������


}

//�ұ߲���
template<typename T>
void DNode<T>::InsertRight(DNode<T> *pDNode) {
	//�½ڵ���ָ��ָ��ǰ�ڵ㣬�½ڵ���ָ��ָ��ǰ�ڵ�ԭ����ָ����ָ�Ľڵ�
	pDNode->left = this;
	pDNode->right = right;
	//�����ǰ�ڵ��ұ��нڵ㣨��ָ�벻ָ���Լ���ָ���Լ������ұ�û�нڵ㣩��
	//Ӧ���޸ĵ�ǰ�ڵ���ҽڵ����ָ�룬����ָ���½ڵ㡣
	if (right != this)
		right->left = pDNode;
	//��ǰ�ڵ����ָ��ָ���½ڵ�
	right = pDNode;
	//�����ǰ�ڵ����ָ��ָ���Լ��������û�нڵ㣬
	//���õ�ǰ�ڵ����ָ��ָ���½ڵ㡣
	if (left == this)
		left = pDNode;
	

}

//ɾ����ǰ�ڵ�
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

