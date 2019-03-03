#pragma once
#include<iostream>
using namespace std;

#include "Node.h"

template<typename T>
class LinkedList
{
private:
	//头指针、尾指针
	Node<T> *front, *back;
	//前一个节点，当前节点指针
	Node<T> *prevNode, *currNode;
	//节点数
	int size;
	//当前指针所指节点的位置号
	int position;
	//申请及释放节点的私有函数
	Node<T> *GetNode(const T& item,Node<T> *pNext=NULL);
	void FreeNode(Node<T> *pNode);
	//拷贝链表
	void CopyList(const LinkedList<T>& list);
	
public:
	//构造函数
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	
	//赋值运算符重载
	LinkedList<T>& operator=(const LinkedList<T>& list);
	//检查链表状态的函数
	int ListSize(void) const;
	bool ListEmpty(void) const;

	//遍历链表函数
	void ResetPosition(int pos = 0);
	void Next(void);
	bool EndOfList(void) const;
	int CurrentPosition(void) const;

	//插入函数
	void InsertFront(const T& item);
	void InsertBack(const T& item);
	void InsertAt(const T& item);
	void InsertAfter(const T& item);

	//删除函数
	T DeleteFront(void);
	T DeleteAt(void);

	//访问及修改当前位置的数据
	T& Data(void);

	//清空表
	void ClearList(void);

	//遍历全表
	void CoutLinkedList(void);


	//析构函数
	~LinkedList();
};





//构造函数
template<typename T>
LinkedList<T>::LinkedList() :front(NULL), back(NULL), prevNode(NULL), currNode(NULL), size(0), position(-1)
{
}



//根据存在的表创建
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	this->CopyList(list);

}

//重载赋值符
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) {
	this->CopyList(list);
	return *this;
}








//申请新节点的私有函数
template<typename T>
Node<T> *LinkedList<T>::GetNode(const T& item, Node<T> *pNext) {
	Node<T> *pNode = new Node<T>(item, pNext);
	return pNode;
}
//释放节点的私有函数
template<typename T>
void LinkedList<T>::FreeNode(Node<T> *pNode) {
	delete	pNode;
}

//插入表尾++++++++++++++++++++++++++position始终与currNode一致，包括currNode是最后节点之后的位置。
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
		//back等于currNode或者currNode在back之前，position不受影响


	}

	this->back = newNode;
	this->size++;
}
//插入表头++++++++++++++++++++++++++position始终与currNode一致，包括currNode是最后节点之后的位置。
template<typename T>
void LinkedList<T>::InsertFront(const T& item) {
	Node<T> *newNode;
	this->front = newNode = this->GetNode(item, this->front);
	if (this->prevNode == NULL) {
		if (this->currNode == NULL) {
			this->currNode = this->back = newNode;
			//prevNode不变
		}
		else {
			this->prevNode = newNode;//back,currNode不变
		}
	}

	this->position++;//空表或非空表，都加1
	this->size++;
}
//插入当前位置++++++++++++++++++++++++++position始终与currNode一致，包括currNode是最后节点之后的位置。
template<typename T>
void LinkedList<T>::InsertAt(const T& item) {
	//新节点
	Node<T> *newNode;
	// 插入的位置是表头
	if (this->prevNode == NULL) {
		this->front = newNode = this->GetNode(item, this->front);
		if (this->currNode == NULL) {
			this->currNode = this->back = newNode;
			//prevNode不变
		}
		else {
			this->prevNode = newNode;//back,currNode不变
		}
		this->position++;//空表或非空表，都加1

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
		this->prevNode = newNode;//currNode不变化
	}


	this->size++;//空表或非空表，都加1
}
//插入当前位置之后++++++++++++++++++++++++++position始终与currNode一致，包括currNode是最后节点之后的位置。
template<typename T>
void LinkedList<T>::InsertAfter(const T& item) {
	Node<T> *newNode;
	//当前位置为NULL，如果是空表，新节点为表头；
	//如果是表尾（最后节点之后），新节点放在前一节点之后
	if (this->currNode == NULL) {
		if (this->prevNode == NULL) {
			//空表的情况
			this->front = newNode = this->GetNode(item, this->front);
			this->currNode = this->back = newNode;
			this->position++;
		}
		else {
			//表尾的情况
			this->prevNode->InsertAfter(newNode = this->GetNode(item));
			this->prevNode = this->back = newNode;
		}
	}
	else {//这种情况，prevNode,currNode,position不受影响
		this->currNode->InsertAfter(newNode = this->GetNode(item));
		if (this->currNode == this->back) {
			this->back = newNode;//back受影响，其它不受影响。
		}
	}

	this->size++;
}





//拷贝表---私有函数
template<typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& list) {
	//获取第一个节点
	Node<T> *p = list.front;

	//根据list每个节点的值，创建新的链表（拷贝表）
	while (p != NULL) {
		this->InsertBack(p->data);
		p = p->NextNode();
	}
	//如果是空表就返回
	if (this->position == -1) {
		cout << "链表复制失败！" << endl;
	}



}


//删除函数
template<typename T>
T LinkedList<T>::DeleteFront(void) {
	//保存要删除的点
	Node<T> *pNode = this->front;

	//第一种情况：空表！
	if (pNode == NULL) {
		cout << "删除错误：空表或当前位置为NULL！" << endl;
		exit(1);
	}
	T dataNode = pNode->data;
	//去掉要删除的节点，重新把表链接好。
	this->front = pNode->NextNode();

	//更新数据
	if (pNode->NextNode() == NULL) {
		this->back = this->front;//更新back
		this->currNode = this->front;
		this->prevNode = this->front;
		this->position = -1;
	}
	else {//删除最前面的节点以后，剩下的节点至少还有一个，因此back不受影响
		if (pNode == this->currNode) {
			//因为删除的是最前面，此时position,prevNode不受影响
			this->currNode = this->currNode->NextNode();
		}
		else {
			if (pNode == this->prevNode) {//currNode不受影响
				this->prevNode = NULL;

			}
			this->position--;
		}
	}



	//更新其它表中其它数据的状态

	this->size--;//减少了一个节点



	//释放第一个节点。
	this->FreeNode(pNode);

	return dataNode;
}
//删除函数
template<typename T>
T LinkedList<T>::DeleteAt(void) {
	Node<T> *pNode = this->currNode;
	if (pNode == NULL) {
		cout << "删除错误：空表或当前位置为NULL！" << endl;
		exit(1);
	}
	T dataNode = pNode->data;

	if ((this->size == 1) || (this->prevNode == NULL)) {
		return this->deleteFront();
	}
	else {//prevNode,position不受影响  
		this->prevNode->DeleteAfter();
		if (pNode == this->back) {//不受影响

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





//重置当前位置
template<typename T>
void  LinkedList<T>::ResetPosition(int pos) {
	//空表就退出，超出实际有效范围的pos也退出。
	if (this->front == NULL || pos < 0 || pos >= this->size) {
		cout << "错误：位置数值设置超出有效范围！" << endl;

	}
	else {


		//根据pos循环链表，设置pos对应的prevNode和currNode的值。	
		this->prevNode = NULL;
		this->currNode = this->front;//循环链表前，指向第一个节点
		//如果pos==0，下面的循环直接就退出了。上面prevNode和currNode的初始设置正好对应。
		//否则，移到与pos对应的节点。
		for (this->position = 0;this->position != pos;this->position++) {
			this->prevNode = this->currNode;
			this->currNode = this->currNode->NextNode();
		}
	}
}
//移到到下一个节点++++++++++++++++++++++++++OK
template<typename T>
void  LinkedList<T>::Next(void) {
	if (this->currNode != NULL) {
		this->prevNode = this->currNode;
		this->currNode = this->currNode->NextNode();
		this->position++;
	}
}

//是否已经表尾++++++++++++++++++++++++++OK
template<typename T>
bool  LinkedList<T>::EndOfList(void) const {
	return (this->back == this->prevNode) && (this->currNode == NULL);
}
//获取当前位置++++++++++++++++++++++++++OK
template<typename T>
int  LinkedList<T>::CurrentPosition(void) const {
	return this->position;
}



//检查链表状态的函数
//获取表大小++++++++++++++++++++++++++OK
template<typename T>
int LinkedList<T>::ListSize(void) const {
	return this->size;
}

//表是否为空++++++++++++++++++++++++++OK
template<typename T>
bool LinkedList<T>::ListEmpty(void) const {
	return (this->size == 0);
}

//获取当前位置的data++++++++++++++++++++++++++OK
template<typename T>
T& LinkedList<T>::Data(void) {
	//若空表或处于表尾，就出错退出。
	if (this->size == 0 || this->currNode == NULL) {
		cout << "错误：空表，没有任何数据！" << endl;
		exit(1);
	}
	return this->currNode->data;
}

//清空表++++++++++++++++++++++++++OK
template<typename T>
void LinkedList<T>::ClearList(void) {
	Node<T> *currnode, *nextnode;
	//空表直接退出
	if (this->front != NULL) {

		//不是空表，则：
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


//遍历全表
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


