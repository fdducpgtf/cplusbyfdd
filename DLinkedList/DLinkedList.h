#pragma once
#include<iostream>
#include "DNode.h"

using namespace std;


template<typename T>
class DLinkedList {
private:
	//头指针
	DNode<T> *head;
	size_t size;
	size_t position;
	DNode<T> *currDNode;

	//私有函数
	

	void CopyList(const DLinkedList<T>& dlist);
	DNode<T> *GetDNode(T& item);
	void FreeDNode(DNode<T> *pDNode);
	//有序插入
	void InsertAscending(T& item);
	void InsertDescending(T& item);
	//排序法
	void Merge(DNode<T> *leftDNode,DNode<T> *midDNode,DNode<T> *right,bool Ascending=true);
	void Divide(DNode<T> *leftDNode, DNode<T> *rightDNode, bool Ascending=true);
	void MergeSort(bool Ascending = true);
	void QuickSort(bool Ascending = true);
	void ShellInsertSort(bool Ascending = true);
	void InsertSort(bool Ascending = true);
	void SelectSort(bool Ascending = true);
	void ExchangeSort(bool Ascending = true);
	void BubbleSort(bool Ascending = true);//冒泡排序
	//排序判断函数
	bool GetTrueOrFalse(T left, T right, bool Ascending=true);


public:
	using size_t = unsigned int;
	
	//构造函数
	DLinkedList();
	DLinkedList(const DLinkedList<T>& dlist);

	static const size_t NPOS = -1;

	//复制函数：重载赋值运算符=
	DLinkedList<T>& operator=(const DLinkedList<T>& dlist);
	//插入函数
	void InsertOrder(T& item,bool Ascending = true);
	void InsertFront(T& item);//插入表头
	void InsertEnd(T& item);//插入表尾
	void InsertBefore(T& item);//插入当前位置之前
	void InsertBack(T& item);//插入当前位置之后

	//删除函数
	void DeleteFront(void);
	void DeleteEnd(void);
	void DeleteAt(void);
	void DeleteBefore(void);
	void DeleteBack(void);
	void ClearDList(void);

	//表状态函数
	DNode<T> *Head(void) const;
	T& GetCurrDNodeData(void);
	size_t GetSize(void) const;
	size_t GetPos(void) const;
	DNode<T> *GetCurrDNode(void) const;
	DNode<T> *NextDNodeBefore(void) const;
	DNode<T> *NextDNodeBack(void) const;
	DNode<T> *GetDNodeFromPos(size_t pos) const;
	DNode<T> *GetMidDNode(DNode<T> *left, DNode<T> *right) const;

	bool IsEmpty(void);
	bool isEnd(void);
	bool isBegin(void);

	//修改函数
	void ResetPos(size_t pos=0);
	void ResetPos(DNode<T> *pDNode);


	//排序
	void Sort(bool Ascending = true);

	//遍历函数
	void coutDList(void);
	void coutRDList(void);
	void coutDListFromPos(void);
	void coutDListFromPos(size_t pos);

	//工具，输出数组
	void coutArray(T *a, int size);
	
	
	//析构函数
	~DLinkedList();
};



//构造函数
template<typename T>
DLinkedList<T>::DLinkedList() {
	head = new  DNode<T>();
	currDNode = head;
	size = 0;
	position =DLinkedList::NPOS ;
}
template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& dlist) {
	head= new  DNode<T>();
	this->CopyList(dlist);
	
}

//复制函数：重载赋值运算符=
template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& dlist) {
	this->CopyList(dlist);
	return *this;
}

template<typename T>
void DLinkedList<T>::CopyList(const DLinkedList<T>& dlist) {
	//一旦开始，始终清空链表。然后再复制新表。
	if(size>0)
		ClearDList();
	//新表不为空就开始下面的操作。
	if (dlist.GetSize()!=0) {
		//复制元素与对应当前位置并行。
		size_t currPos = 0, pos = dlist.GetPos();
		//tmp用于保存与新表对应位置的当前链表的节点
		DNode<T> *newDNode,*DNodePos=NULL;

		for (DNode<T> *p = dlist.Head()->NextNodeRight();p != dlist.Head();p = p->NextNodeRight()) {
			newDNode= GetDNode(p->data);
			head->InsertLeft(newDNode);//节点始终复制到新表最后
			size++;
			//保存dlist的position对应的新表节点
			if (currPos == pos)
				DNodePos = newDNode;
			currPos++;
			
		}
		if (DNodePos != NULL) {
			position = pos;
			this->currDNode = DNodePos;
		}

	}
}

template<typename T>
DNode<T> *DLinkedList<T>::GetDNode(T& item) {
	return new DNode<T>(item);
}
template<typename T>
void DLinkedList<T>::FreeDNode(DNode<T> *pDNode) {
	delete pDNode;
}


	//插入函数
template<typename T>
void DLinkedList<T>::InsertAscending(T& item) {
	
		DNode<T> *p = currDNode,*newDNode;

		if (p == head) {
			p->InsertRight(newDNode = GetDNode(item));
			currDNode = newDNode;
			position++;
		}
		else {


			if (p->data < item) {
				p = p->NextNodeRight();
				while ((p != head) && (p->data < item))
					p = p->NextNodeRight();
				p->InsertLeft(newDNode = GetDNode(item));

			}
			else {
				p = p->NextNodeLeft();
				while ((p != head) && (p->data >= item))
					p = p->NextNodeLeft();
				p->InsertRight(newDNode = GetDNode(item));

			}

			
			if (currDNode->data >= item) {
				position++;
			}


		}
		size++;


		
}
template<typename T>
void DLinkedList<T>::InsertDescending(T& item) {
	DNode<T> *p = currDNode, *newDNode;
	if (p == head) {
		p->InsertRight(newDNode = GetDNode(item));
		currDNode = newDNode;
		position++;
	}
	else {


		if (p->data > item) {
			p = p->NextNodeRight();
			while ((p != head) && (p->data > item))
				p = p->NextNodeRight();
			p->InsertLeft(newDNode = GetDNode(item));

		}
		else {
			p = p->NextNodeLeft();
			while ((p != head) && (p->data <= item))
				p = p->NextNodeLeft();
			p->InsertRight(newDNode = GetDNode(item));
		}

		if (currDNode->data <= item)
			position++;

	}

	size++;
}
	template<typename T>
	void DLinkedList<T>::InsertOrder(T& item, bool Ascending) {
		if (Ascending) {
			InsertAscending(item);
		}
		else {
			InsertDescending(item);
		}

	}



	template<typename T>
	void DLinkedList<T>::InsertFront(T& item) {
		DNode<T> *pDNode = GetDNode(item);
		head->InsertRight(pDNode);
		if (currDNode == head) {
			currDNode = pDNode;			
		}			
		
		position++;
		size++;
	}
	template<typename T>
	void DLinkedList<T>::InsertEnd(T& item) {
		DNode<T> *pDNode = GetDNode(item);
		head->InsertLeft(pDNode);
		if (currDNode == head) {
			currDNode = pDNode;
			position++;
		}

		size++;
	}
	
	template<typename T>
	void DLinkedList<T>::InsertBefore(T& item) {
		DNode<T> *pDNode = GetDNode(item);
		if (((position == DLinkedList<T>::NPOS) && (currDNode == head)) || ((position != DLinkedList<T>::NPOS) && (currDNode != head))) {
			currDNode->InsertLeft(pDNode);
			if (currDNode == head) {
				currDNode = pDNode;				
			}
			
			position++;
			size++;
		}
		else {
			cout << "链表内部设置错误：当前位置与位置号不一致！" << endl;
		}
	}
	template<typename T>
	void DLinkedList<T>::InsertBack(T& item) {
		DNode<T> *pDNode = GetDNode(item);
		if (((position == DLinkedList<T>::NPOS) && (currDNode == head)) || ((position != DLinkedList<T>::NPOS) && (currDNode != head))) {
			currDNode->InsertRight(pDNode);
			if (currDNode == head) {
				currDNode = pDNode;
				position++;
			}
			size++;
		}
		else {
			cout << "链表内部设置错误：当前位置与位置号不一致！" << endl;
		}
	}

	//删除函数
	template<typename T>
	void DLinkedList<T>::DeleteFront(void) {
		
		DNode<T> *p = head->NextNodeRight();
		
		if (p != head) {
			if (currDNode == p) {
				currDNode = p->NextNodeRight();
				if (currDNode == head)
					position--;
			}
			else {
				position--;
			}
			FreeDNode(p->DeleteDNode());
			size--;
		}
		
			
		

	}
	template<typename T>
	void DLinkedList<T>::DeleteEnd(void) {
		DNode<T> *p = head->NextNodeLeft();
		if (p != head) {
			if (currDNode == p) {
				currDNode = currDNode->NextNodeLeft();
				position--;
			}
			FreeDNode(p->DeleteDNode());
			size--;
		}
		
	}
	template<typename T>
	void DLinkedList<T>::DeleteAt(void) {
		DNode<T> *p = currDNode;
		if (p != head) {
			if (size == 1) {
				position--;
			}
			else {
				if (currDNode->NextNodeRight() == head) {
					currDNode = currDNode->NextNodeLeft();
					position--;
				}
				else
					currDNode = currDNode->NextNodeRight();
			}
			FreeDNode(p->DeleteDNode());
			size--;
			
		}
	}
	template<typename T>
	void DLinkedList<T>::DeleteBefore(void) {
		if (currDNode->NextNodeLeft() != head) {
			FreeDNode(currDNode->NextNodeLeft()->DeleteDNode());
			position--;
			size--;
		}
	}
	template<typename T>
	void DLinkedList<T>::DeleteBack(void) {
		if (currDNode->NextNodeRight() != head) {

			FreeDNode(currDNode->NextNodeRight()->DeleteDNode());
			size--;
		}
	}
	template<typename T>
	void DLinkedList<T>::ClearDList(void) {
		for (DNode<T> *p = head->NextNodeRight();p != head;) {
			DNode<T> *deledDNode = p->DeleteDNode();
			p = p->NextNodeRight();
			FreeDNode(deledDNode);
		}
		size = 0;
		position = DLinkedList<T>::NPOS;
		currDNode = head;
	}

	//排序
	template<typename T>
	void DLinkedList<T>::Sort(bool Ascending) {
		//不考虑对position和currDNode的影响
		
		//ExchangeSort(Ascending);
		//InsertSort(Ascending);
		//BubbleSort(Ascending);
		//SelectSort(Ascending);


		//ShellInsertSort(Ascending);
		//QuickSort(Ascending);
		MergeSort(Ascending);
	}


	//排序法私有函数++++++++++++++++++++++++++++++++++++++
	template<typename T>
	bool DLinkedList<T>::GetTrueOrFalse(T left, T right, bool Ascending) {
		if (Ascending)
			return left < right;
		else
			return left > right;

	}
	template<typename T>
	void DLinkedList<T>::coutArray(T *a, int size) {
		for (int i = 0;i < size;i++)
			cout << a[i] << " ";
		cout << endl;
	}


	//******************************************************************************************************************
	//归并排序，使用双向链表传递、存储数据而完成。
	//归并排序基本原理：利用递归，把要排序的数据分成“多段”（最小的段为“两个元素”一组）分别排序，经过各自排序
	//之后的数据在新的“段”（段包含的数据回归时越来越多）里按照对应位置比较大小，剩余直接复制的方法排序。
	//这种排序数据之间比较的次数最少。但用于数据复制，占用内存空间比较多。不过，单纯讲算法，此方法最优！
	template<typename T>
	void DLinkedList<T>::MergeSort(bool Ascending) {


		//归并排序，首先确定数据的左边界和右边界。
		//此处使用链表，左右两边为链表元素
		//（因为链表可以存储任何类型的数据，因而此方法扩展性强，对于某些特殊数据类型的处理有便利）。
		DNode<T> *leftDNode, *rightDNode;
		leftDNode = head->NextNodeRight();
		rightDNode = head->NextNodeLeft();
		//退出递归条件（千万注意！）
		if (leftDNode != rightDNode)
			Divide(leftDNode, rightDNode, Ascending);



	}

	//******************************************************************************************************************
	//归并排序中的递归函数。使用双向链表传递、存储数据而完成。
	template<typename T>
	void DLinkedList<T>::Divide(DNode<T> *leftDNode, DNode<T> *rightDNode, bool Ascending) {
		//递归函数最关键的地方：退出递归的条件。
		//因为使用链表完成，条件与其它方式略有不同。此处采用“不等于”。其它方式，一般采用“小于”。
		if (leftDNode != rightDNode) {
			//链表完成的最关键的地方：DLinkedList<T>::GetMidDNode(...)函数：
				//根据左右两节点找到中间节点。与左右边界为纯数字计算（left+right)/2方法有所不一样。原理一致。
			DNode<T> *midDNode = GetMidDNode(leftDNode, rightDNode);//左边终点边界
			DNode<T> *midplusDNode = midDNode->NextNodeRight();//右边开始节点
			//左边递归
			Divide(leftDNode, midDNode, Ascending);
			//右边递归
			Divide(midplusDNode, rightDNode, Ascending);
			//左右合并
			Merge(leftDNode, midDNode, rightDNode, Ascending);
		}
	}


	//******************************************************************************************************************
	//归并排序最关键的合并函数。使用双向链表传递、存储数据而完成。
	template<typename T>
	void DLinkedList<T>::Merge(DNode<T> *leftDNode, DNode<T> *midDNode, DNode<T> *rightDNode, bool Ascending) {

		DNode<T> *tempLeft = leftDNode;//左支的左边界
		DNode<T> *leftNo =midDNode->NextNodeRight();//左支的右边界
		DNode<T> *tempRight = leftNo ;//右支的左边界
		DNode<T> *rightNo = rightDNode->NextNodeRight();//右支的右边界
		//存储排序结果的临时双向链表。如果是引用传递进来的，就要清空数据。
		DLinkedList<T> tempDList; 

		//以中间节点为界，左右两支比较。升序时就按“小于”比较，降序就按大于比较。
		while (tempLeft != leftNo && tempRight != rightNo) {
			//DLinkedList<T>::GetTrueOrFalse(...)函数根据参数Ascending决定比较结果（即按小于还是大于比较）。
			if (GetTrueOrFalse(tempLeft->data,tempRight->data,Ascending)) {
				//按比较结果，总是把数据存入链表的末尾。
				tempDList.InsertEnd(tempLeft->data);
				//左边移到下一个节点
				tempLeft = tempLeft->NextNodeRight();
			}
			else {
				//按比较结果，总是把数据存入链表的末尾。
				tempDList.InsertEnd(tempRight->data);
				//右边移动到下一个节点。
				tempRight = tempRight->NextNodeRight();
			}
		}
		//比较完成后，剩余的左边数据拷贝到链表末尾。
		while (tempLeft != leftNo) {
			tempDList.InsertEnd(tempLeft->data);
			tempLeft = tempLeft->NextNodeRight();
		}
		//比较完成后，剩余的右边数据拷贝到链表末尾。
		while (tempRight != rightNo) {
			tempDList.InsertEnd(tempRight->data);
			tempRight = tempRight->NextNodeRight();
		}

		//根据链表里已经经过一定排序的数据得复制到leftDNode到rightDNode之间（包括边界）节点上。
		DNode<T> *temp = tempDList.Head()->NextNodeRight();
		while (leftDNode != rightNo) {
			leftDNode->data = temp->data;
			leftDNode = leftDNode->NextNodeRight();
			temp = temp->NextNodeRight();

		}



	}

	





	template<typename T>
	void DLinkedList<T>::QuickSort(bool Ascending) {
		

	}

	//希尔插入排序法
	template<typename T>
	void DLinkedList<T>::ShellInsertSort(bool Ascending) {
		


	}


	template<typename T>
	void DLinkedList<T>::InsertSort(bool Ascending) {

		//直接插入法排序
		//保存当前位置及节点
		size_t pos = position;

		DNode<T> *compareDNode = NULL, *beforeDNode = NULL,*backDNode;
		T compareData;
		
		
			for (int i = 1;i < size;i++) {
				
				if (i == 1) {
					ResetPos(i);
					compareDNode = currDNode;
				}
				else {
					compareDNode = compareDNode->NextNodeRight();
				}
				compareData = compareDNode->data;
				beforeDNode = compareDNode->NextNodeLeft();
				backDNode = compareDNode;

				int tmpPos = i - 1;
				while ((tmpPos >= 0) && (GetTrueOrFalse(compareData,beforeDNode->data,Ascending))) {
					backDNode->data = beforeDNode->data;
					backDNode = beforeDNode;
					beforeDNode = beforeDNode->NextNodeLeft();
					tmpPos--;
				}

				backDNode->data = compareData;

				
			}
		
		


		ResetPos(pos);
		
	}




	template<typename T>
	void DLinkedList<T>::SelectSort(bool Ascending){ 

		//选择排序法

		
			
			for (DNode<T> *p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
				T temp = p->data;
				DNode<T> *swapDNode = NULL;
				for (DNode<T> *b = head->NextNodeLeft();b != p;b = b->NextNodeLeft()) {
					if(GetTrueOrFalse(b->data,temp,Ascending)){
					
						temp = b->data;
						swapDNode = b;
					}
				}
				if (swapDNode != NULL) {
					swapDNode->data = p->data;
					p->data = temp;
				}
				
			}
		


	}
	template<typename T>
	void DLinkedList<T>::ExchangeSort(bool Ascending){ 
		for (DNode<T> *p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
			for (DNode<T> *b = p->NextNodeRight();b != head;b = b->NextNodeRight()) {
				T temp;
				if (GetTrueOrFalse(b->data, p->data, Ascending)) {
					temp = b->data;
					b->data = p->data;
					p->data = temp;
				}
			}

		}

	}



	template<typename T>
	void DLinkedList<T>::BubbleSort(bool Ascending) {

		//冒泡排序法

			
		for (DNode<T> *p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
			for (DNode<T> *b = head->NextNodeLeft();b != p;b = b->NextNodeLeft()) {
				T temp;
				if (GetTrueOrFalse(b->data, b->NextNodeLeft()->data, Ascending)) {

					temp = b->data;
					b->data = b->NextNodeLeft()->data;
					b->NextNodeLeft()->data = temp;
				}
				coutDList();
			}


		}
	}
		



	





	//排序法私有函数++++++++++++++++++++++++++++++++++++++


	//表状态函数
	template<typename T>
	DNode<T> *DLinkedList<T>::Head(void) const {
		return head;
	}
	template<typename T>
	T& DLinkedList<T>::GetCurrDNodeData(void) {
		
		return currDNode->data;
	}
	template<typename T>
	size_t DLinkedList<T>::GetSize(void) const{
		return size;
	}
	template<typename T>
	size_t DLinkedList<T>::GetPos(void) const {
		return position;
	}
	template<typename T>
	DNode<T> *DLinkedList<T>::GetCurrDNode(void) const{
		return currDNode;
	}


	template<typename T>
	DNode<T> *DLinkedList<T>::GetDNodeFromPos(size_t pos) const {
		//pos是从0----size之间的数字。
		size_t n=0;
		DNode<T> *p = currDNode;
		//首先比较当前位置与设置位置的距离
		int delta = position - pos;
		delta = (delta < 0) ? (-delta) : delta;

		if (delta<(size/2-2)) {
			cout << "current." << endl;
			if (position > pos) {
				while(p != head) {
					if (n == delta)
						break;
					n++;
					p = p->NextNodeLeft();
				}
				
					
			}
			else {
				while (p != head) {
					if (n == delta)
						break;
					n++;
					p = p->NextNodeRight();
				}
			}
			return p;
				
		}

		

		//这是双向链表的好处。
			//离头近，就从正向（头到尾）寻找。
			//离尾近，就从反向（从尾到头）寻找。
		if (pos < size / 2) {
			cout << "qi";
			for (DNode<T> *p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
				if (n == pos)
					return p;
				n++;
			}
		}
		else {
			pos = size - pos-1;
			for (DNode<T> *p = head->NextNodeLeft();p != head;p = p->NextNodeLeft()) {
				if (n == pos)
					return p;
				n++;
			}
		}
	
	
	
	}


	template<typename T>
	DNode<T> *DLinkedList<T>::GetMidDNode(DNode<T> *left, DNode<T> *right) const {
		if(left!=right){
			while (left->NextNodeRight() != right) {
				left = left->NextNodeRight();
				right = right->NextNodeLeft();
				if (left == right)
					break;
			}
			return left;
		}
		else
			return left;
	}


	template<typename T>
	DNode<T> *DLinkedList<T>::NextDNodeBefore(void) const{
		return currDNode->NextNodeLeft();
	}
	template<typename T>
	DNode<T> *DLinkedList<T>::NextDNodeBack(void) const{
		return currDNode->NextNodeRight();
	}

	template<typename T>
	bool DLinkedList<T>::IsEmpty(void){
		if (size == 0) {
			if ((position == DLinkedList<T>::NPOS) && (currDNode == head)) {
				return true;
			}
			else {
				cout << "内部标志设置错误！" << endl;
				return false;
			}
		}
		return false;
	}
	template<typename T>
	bool DLinkedList<T>::isEnd(void){
		return currDNode->NextNodeRight() == head;
	}
	template<typename T>
	bool DLinkedList<T>::isBegin(void){
		return currDNode->NextNodeLeft() == head;
	}

	//修改函数
	template<typename T>
	void DLinkedList<T>::ResetPos(size_t pos){
		if (pos < 0 || pos >= size) {
			cout << "位置设置不成功！当前设置值超出有效范围。" << endl;
		}
		else {
			DLinkedList<T>::size_t n = 0;

			DNode<T> *p;
			if (pos < size / 2) {
				for (p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
					if (n == pos) {
						currDNode = p;
						position = pos;
						break;
					}

					n++;
				}
			}
			else {
				pos = size - pos - 1;
				for (p = head->NextNodeLeft();p != head;p = p->NextNodeLeft()) {
					if (n == pos) {
						currDNode = p;
						position = pos;
						break;
					}

					n++;
				}

			}

		}
	}
	template<typename T>
	void DLinkedList<T>::ResetPos(DNode<T> *pDNode) {
		int i = 0;
		for (DNode<T> *p = head->NextNodeRight();p != head;p = p->NextNodeRight()) {
			if (p == pDNode) {
				currDNode = p;
				position = i;
				break;
			}
			i++;
		}
	}


	//遍历函数
	template<typename T>
	void DLinkedList<T>::coutDList(void){
		for (DNode<T> *p = head->NextNodeRight();p != head;p=p->NextNodeRight()) {
			cout << p->data << " ";
		}
		cout << endl;
	}
	template<typename T>
	void DLinkedList<T>::coutRDList(void){
		for (DNode<T> *p = head->NextNodeLeft();p != head;p = p->NextNodeLeft) {
			cout << p->data << " ";
		}
		cout << endl;

	}
	template<typename T>
	void DLinkedList<T>::coutDListFromPos(void){
		DNode<T> *p = currDNode;
		if (p == head)
			p = p->NextNodeRight();
		if (p == currDNode) {
			cout << currDNode->data << " ";
			p = p->NextNodeRight();
		}
		for (;p!=currDNode;p = p->NextNodeRight()) {
			if (p != head)
				cout << p->data << " ";
		}
		cout << endl;

	}
	template<typename T>
	void DLinkedList<T>::coutDListFromPos(size_t pos){
		ResetPos(pos);
		coutDListFromPos();
	}
	

	//析构函数
	template<typename T>
	DLinkedList<T>::~DLinkedList(){
		ClearDList();
		delete head;

	}

	