#pragma once
#include<iostream>
using namespace std;

#include "Node.h"

template<typename T>
class LinkedList
{
private:
	//ͷָ�롢βָ��
	Node<T> *front, *back;
	//ǰһ���ڵ㣬��ǰ�ڵ�ָ��
	Node<T> *prevNode, *currNode;
	//�ڵ���
	int size;
	//��ǰָ����ָ�ڵ��λ�ú�
	int position;
	//���뼰�ͷŽڵ��˽�к���
	Node<T> *GetNode(const T& item,Node<T> *pNext=NULL);
	void FreeNode(Node<T> *pNode);
	//��������
	void CopyList(const LinkedList<T>& list);
	
public:
	//���캯��
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	
	//��ֵ���������
	LinkedList<T>& operator=(const LinkedList<T>& list);
	//�������״̬�ĺ���
	int ListSize(void) const;
	bool ListEmpty(void) const;

	//����������
	void ResetPosition(int pos = 0);
	void Next(void);
	bool EndOfList(void) const;
	int CurrentPosition(void) const;

	//���뺯��
	void InsertFront(const T& item);
	void InsertBack(const T& item);
	void InsertAt(const T& item);
	void InsertAfter(const T& item);

	//ɾ������
	T DeleteFront(void);
	T DeleteAt(void);

	//���ʼ��޸ĵ�ǰλ�õ�����
	T& Data(void);

	//��ձ�
	void ClearList(void);

	//����ȫ��
	void CoutLinkedList(void);


	//��������
	~LinkedList();
};





//���캯��
template<typename T>
LinkedList<T>::LinkedList() :front(NULL), back(NULL), prevNode(NULL), currNode(NULL), size(0), position(-1)
{
}



//���ݴ��ڵı���
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	this->CopyList(list);

}

//���ظ�ֵ��
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {
	this->CopyList(list);
	return *this;
}








//�����½ڵ��˽�к���
template<typename T>
Node<T> *LinkedList<T>::GetNode(const T& item, Node<T> *pNext) {
	Node<T> *pNode = new Node<T>(item, pNext);
	return pNode;
}
//�ͷŽڵ��˽�к���
template<typename T>
void LinkedList<T>::FreeNode(Node<T> *pNode) {
	delete	pNode;
}

//�����β++++++++++++++++++++++++++positionʼ����currNodeһ�£�����currNode�����ڵ�֮���λ�á�
template<typename T>
void LinkedList<T>::InsertBack(const T& item) {
	Node<T> *newNode;
	if (this->back == NULL) {
		this->front = newNode = this->GetNode(item, this->front);
		this->currNode = newNode;
		this->position++;
	}
	else {
		this->back->InsertAfter(newNode = this->GetNode(item));

		if (this->prevNode == this->back) {
			this->prevNode = newNode;
			this->position++;
		}
		//back����currNode����currNode��back֮ǰ��position����Ӱ��


	}

	this->back = newNode;
	this->size++;
}
//�����ͷ++++++++++++++++++++++++++positionʼ����currNodeһ�£�����currNode�����ڵ�֮���λ�á�
template<typename T>
void LinkedList<T>::InsertFront(const T& item) {
	Node<T> *newNode;
	this->front = newNode = this->GetNode(item, this->front);
	if (this->prevNode == NULL) {
		if (this->currNode == NULL) {
			this->currNode = this->back = newNode;
			//prevNode����
		}
		else {
			this->prevNode = newNode;//back,currNode����
		}
	}

	this->position++;//�ձ��ǿձ�����1
	this->size++;
}
//���뵱ǰλ��++++++++++++++++++++++++++positionʼ����currNodeһ�£�����currNode�����ڵ�֮���λ�á�
template<typename T>
void LinkedList<T>::InsertAt(const T& item) {
	//�½ڵ�
	Node<T> *newNode;
	// �����λ���Ǳ�ͷ
	if (this->prevNode == NULL) {
		this->front = newNode = this->GetNode(item, this->front);
		if (this->currNode == NULL) {
			this->currNode = this->back = newNode;
			//prevNode����
		}
		else {
			this->prevNode = newNode;//back,currNode����
		}
		this->position++;//�ձ��ǿձ�����1

	}
	else {
		newNode = this->GetNode(item);
		this->prevNode->InsertAfter(newNode);
		if (this->prevNode == this->back) {
			this->back = newNode;
		}
		else {
			this->position++;
		}
		this->prevNode = newNode;//currNode���仯
	}


	this->size++;//�ձ��ǿձ�����1
}
//���뵱ǰλ��֮��++++++++++++++++++++++++++positionʼ����currNodeһ�£�����currNode�����ڵ�֮���λ�á�
template<typename T>
void LinkedList<T>::InsertAfter(const T& item) {
	Node<T> *newNode;
	//��ǰλ��ΪNULL������ǿձ��½ڵ�Ϊ��ͷ��
	//����Ǳ�β�����ڵ�֮�󣩣��½ڵ����ǰһ�ڵ�֮��
	if (this->currNode == NULL) {
		if (this->prevNode == NULL) {
			//�ձ�����
			this->front = newNode = this->GetNode(item, this->front);
			this->currNode = this->back = newNode;
			this->position++;
		}
		else {
			//��β�����
			this->prevNode->InsertAfter(newNode = this->GetNode(item));
			this->prevNode = this->back = newNode;
		}
	}
	else {//���������prevNode,currNode,position����Ӱ��
		this->currNode->InsertAfter(newNode = this->GetNode(item));
		if (this->currNode == this->back) {
			this->back = newNode;//back��Ӱ�죬��������Ӱ�졣
		}
	}

	this->size++;
}





//������---˽�к���
template<typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& list) {
	//��ȡ��һ���ڵ�
	Node<T> *p = list.front;

	//����listÿ���ڵ��ֵ�������µ�����������
	while (p != NULL) {
		this->InsertBack(p->data);
		p = p->NextNode();
	}
	//����ǿձ�ͷ���
	if (this->position == -1) {
		cout << "������ʧ�ܣ�" << endl;
	}



}


//ɾ������
template<typename T>
T LinkedList<T>::DeleteFront(void) {
	//����Ҫɾ���ĵ�
	Node<T> *pNode = this->front;

	//��һ��������ձ�
	if (pNode == NULL) {
		cout << "ɾ�����󣺿ձ��ǰλ��ΪNULL��" << endl;
		exit(1);
	}
	T dataNode = pNode->data;
	//ȥ��Ҫɾ���Ľڵ㣬���°ѱ����Ӻá�
	this->front = pNode->NextNode();

	//��������
	if (pNode->NextNode() == NULL) {
		this->back = this->front;//����back
		this->currNode = this->front;
		this->prevNode = this->front;
		this->position = -1;
	}
	else {//ɾ����ǰ��Ľڵ��Ժ�ʣ�µĽڵ����ٻ���һ�������back����Ӱ��
		if (pNode == this->currNode) {
			//��Ϊɾ��������ǰ�棬��ʱposition,prevNode����Ӱ��
			this->currNode = this->currNode->NextNode();
		}
		else {
			if (pNode == this->prevNode) {//currNode����Ӱ��
				this->prevNode = NULL;

			}
			this->position--;
		}
	}



	//�������������������ݵ�״̬

	this->size--;//������һ���ڵ�



	//�ͷŵ�һ���ڵ㡣
	this->FreeNode(pNode);

	return dataNode;
}
//ɾ������
template<typename T>
T LinkedList<T>::DeleteAt(void) {
	Node<T> *pNode = this->currNode;
	if (pNode == NULL) {
		cout << "ɾ�����󣺿ձ��ǰλ��ΪNULL��" << endl;
		exit(1);
	}
	T dataNode = pNode->data;

	if ((this->size == 1) || (this->prevNode == NULL)) {
		return this->deleteFront();
	}
	else {//prevNode,position����Ӱ��  
		this->prevNode->DeleteAfter();
		if (pNode == this->back) {//����Ӱ��

			this->back = this->prevNode;
			this->currNode = NULL;
		}
		else {
			this->currNode = this->currNode->NextNode();
		}

		this->size--;
		this->FreeNode(pNode);
		return dataNode;
	}












}





//���õ�ǰλ��
template<typename T>
void  LinkedList<T>::ResetPosition(int pos) {
	//�ձ���˳�������ʵ����Ч��Χ��posҲ�˳���
	if (this->front == NULL || pos < 0 || pos >= this->size) {
		cout << "����λ����ֵ���ó�����Ч��Χ��" << endl;

	}
	else {


		//����posѭ����������pos��Ӧ��prevNode��currNode��ֵ��	
		this->prevNode = NULL;
		this->currNode = this->front;//ѭ������ǰ��ָ���һ���ڵ�
		//���pos==0�������ѭ��ֱ�Ӿ��˳��ˡ�����prevNode��currNode�ĳ�ʼ�������ö�Ӧ��
		//�����Ƶ���pos��Ӧ�Ľڵ㡣
		for (this->position = 0;this->position != pos;this->position++) {
			this->prevNode = this->currNode;
			this->currNode = this->currNode->NextNode();
		}
	}
}
//�Ƶ�����һ���ڵ�++++++++++++++++++++++++++OK
template<typename T>
void  LinkedList<T>::Next(void) {
	if (this->currNode != NULL) {
		this->prevNode = this->currNode;
		this->currNode = this->currNode->NextNode();
		this->position++;
	}
}

//�Ƿ��Ѿ���β++++++++++++++++++++++++++OK
template<typename T>
bool  LinkedList<T>::EndOfList(void) const {
	return (this->back == this->prevNode) && (this->currNode == NULL);
}
//��ȡ��ǰλ��++++++++++++++++++++++++++OK
template<typename T>
int  LinkedList<T>::CurrentPosition(void) const {
	return this->position;
}



//�������״̬�ĺ���
//��ȡ���С++++++++++++++++++++++++++OK
template<typename T>
int LinkedList<T>::ListSize(void) const {
	return this->size;
}

//���Ƿ�Ϊ��++++++++++++++++++++++++++OK
template<typename T>
bool LinkedList<T>::ListEmpty(void) const {
	return (this->size == 0);
}

//��ȡ��ǰλ�õ�data++++++++++++++++++++++++++OK
template<typename T>
T& LinkedList<T>::Data(void) {
	//���ձ���ڱ�β���ͳ����˳���
	if (this->size == 0 || this->currNode == NULL) {
		cout << "���󣺿ձ�û���κ����ݣ�" << endl;
		exit(1);
	}
	return this->currNode->data;
}

//��ձ�++++++++++++++++++++++++++OK
template<typename T>
void LinkedList<T>::ClearList(void) {
	Node<T> *currnode, *nextnode;
	//�ձ�ֱ���˳�
	if (this->front != NULL) {

		//���ǿձ���
		currnode = this->front;
		while (currnode != NULL) {
			nextnode = currnode->NextNode();
			this->FreeNode(currnode);
			currnode = nextnode;
		}

		this->front = NULL;
		this->back = NULL;
		this->prevNode = NULL;
		this->currNode = NULL;
		this->size = 0;
		this->position = -1;
		

	}
}


//����ȫ��
template<typename T>
void LinkedList<T>::CoutLinkedList(void) {

	for (Node<T> *tmpNode = this->front;tmpNode != NULL;tmpNode = tmpNode->NextNode()) {
		cout << tmpNode->data << " ";
	}
	cout << endl;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	this->ClearList();
}


