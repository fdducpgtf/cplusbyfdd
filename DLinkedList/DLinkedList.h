#pragma once
#include<iostream>
#include "DNode.h"

using namespace std;


template<typename T>
class DLinkedList {
private:
	//ͷָ��
	DNode<T> *head;
	size_t size;
	size_t position;
	DNode<T> *currDNode;

	//˽�к���
	

	void CopyList(const DLinkedList<T>& dlist);
	DNode<T> *GetDNode(T& item);
	void FreeDNode(DNode<T> *pDNode);
	//�������
	void InsertAscending(T& item);
	void InsertDescending(T& item);
	//����
	void Merge(DNode<T> *leftDNode,DNode<T> *midDNode,DNode<T> *right,bool Ascending=true);
	void Divide(DNode<T> *leftDNode, DNode<T> *rightDNode, bool Ascending=true);
	void MergeSort(bool Ascending = true);
	void QuickSort(bool Ascending = true);
	void ShellInsertSort(bool Ascending = true);
	void InsertSort(bool Ascending = true);
	void SelectSort(bool Ascending = true);
	void ExchangeSort(bool Ascending = true);
	void BubbleSort(bool Ascending = true);//ð������
	//�����жϺ���
	bool GetTrueOrFalse(T left, T right, bool Ascending=true);


public:
	using size_t = unsigned int;
	
	//���캯��
	DLinkedList();
	DLinkedList(const DLinkedList<T>& dlist);

	static const size_t NPOS = -1;

	//���ƺ��������ظ�ֵ�����=
	DLinkedList<T>& operator=(const DLinkedList<T>& dlist);
	//���뺯��
	void InsertOrder(T& item,bool Ascending = true);
	void InsertFront(T& item);//�����ͷ
	void InsertEnd(T& item);//�����β
	void InsertBefore(T& item);//���뵱ǰλ��֮ǰ
	void InsertBack(T& item);//���뵱ǰλ��֮��

	//ɾ������
	void DeleteFront(void);
	void DeleteEnd(void);
	void DeleteAt(void);
	void DeleteBefore(void);
	void DeleteBack(void);
	void ClearDList(void);

	//��״̬����
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

	//�޸ĺ���
	void ResetPos(size_t pos=0);
	void ResetPos(DNode<T> *pDNode);


	//����
	void Sort(bool Ascending = true);

	//��������
	void coutDList(void);
	void coutRDList(void);
	void coutDListFromPos(void);
	void coutDListFromPos(size_t pos);

	//���ߣ��������
	void coutArray(T *a, int size);
	
	
	//��������
	~DLinkedList();
};



//���캯��
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

//���ƺ��������ظ�ֵ�����=
template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& dlist) {
	this->CopyList(dlist);
	return *this;
}

template<typename T>
void DLinkedList<T>::CopyList(const DLinkedList<T>& dlist) {
	//һ����ʼ��ʼ���������Ȼ���ٸ����±�
	if(size>0)
		ClearDList();
	//�±�Ϊ�վͿ�ʼ����Ĳ�����
	if (dlist.GetSize()!=0) {
		//����Ԫ�����Ӧ��ǰλ�ò��С�
		size_t currPos = 0, pos = dlist.GetPos();
		//tmp���ڱ������±��Ӧλ�õĵ�ǰ����Ľڵ�
		DNode<T> *newDNode,*DNodePos=NULL;

		for (DNode<T> *p = dlist.Head()->NextNodeRight();p != dlist.Head();p = p->NextNodeRight()) {
			newDNode= GetDNode(p->data);
			head->InsertLeft(newDNode);//�ڵ�ʼ�ո��Ƶ��±����
			size++;
			//����dlist��position��Ӧ���±�ڵ�
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


	//���뺯��
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
			cout << "�����ڲ����ô��󣺵�ǰλ����λ�úŲ�һ�£�" << endl;
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
			cout << "�����ڲ����ô��󣺵�ǰλ����λ�úŲ�һ�£�" << endl;
		}
	}

	//ɾ������
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

	//����
	template<typename T>
	void DLinkedList<T>::Sort(bool Ascending) {
		//�����Ƕ�position��currDNode��Ӱ��
		
		//ExchangeSort(Ascending);
		//InsertSort(Ascending);
		//BubbleSort(Ascending);
		//SelectSort(Ascending);


		//ShellInsertSort(Ascending);
		//QuickSort(Ascending);
		MergeSort(Ascending);
	}


	//����˽�к���++++++++++++++++++++++++++++++++++++++
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
	//�鲢����ʹ��˫�������ݡ��洢���ݶ���ɡ�
	//�鲢�������ԭ�����õݹ飬��Ҫ��������ݷֳɡ���Ρ�����С�Ķ�Ϊ������Ԫ�ء�һ�飩�ֱ����򣬾�����������
	//֮����������µġ��Ρ����ΰ��������ݻع�ʱԽ��Խ�ࣩ�ﰴ�ն�Ӧλ�ñȽϴ�С��ʣ��ֱ�Ӹ��Ƶķ�������
	//������������֮��ȽϵĴ������١����������ݸ��ƣ�ռ���ڴ�ռ�Ƚ϶ࡣ�������������㷨���˷������ţ�
	template<typename T>
	void DLinkedList<T>::MergeSort(bool Ascending) {


		//�鲢��������ȷ�����ݵ���߽���ұ߽硣
		//�˴�ʹ��������������Ϊ����Ԫ��
		//����Ϊ������Դ洢�κ����͵����ݣ�����˷�����չ��ǿ������ĳЩ�����������͵Ĵ����б�������
		DNode<T> *leftDNode, *rightDNode;
		leftDNode = head->NextNodeRight();
		rightDNode = head->NextNodeLeft();
		//�˳��ݹ�������ǧ��ע�⣡��
		if (leftDNode != rightDNode)
			Divide(leftDNode, rightDNode, Ascending);



	}

	//******************************************************************************************************************
	//�鲢�����еĵݹ麯����ʹ��˫�������ݡ��洢���ݶ���ɡ�
	template<typename T>
	void DLinkedList<T>::Divide(DNode<T> *leftDNode, DNode<T> *rightDNode, bool Ascending) {
		//�ݹ麯����ؼ��ĵط����˳��ݹ��������
		//��Ϊʹ��������ɣ�������������ʽ���в�ͬ���˴����á������ڡ���������ʽ��һ����á�С�ڡ���
		if (leftDNode != rightDNode) {
			//������ɵ���ؼ��ĵط���DLinkedList<T>::GetMidDNode(...)������
				//�����������ڵ��ҵ��м�ڵ㡣�����ұ߽�Ϊ�����ּ��㣨left+right)/2����������һ����ԭ��һ�¡�
			DNode<T> *midDNode = GetMidDNode(leftDNode, rightDNode);//����յ�߽�
			DNode<T> *midplusDNode = midDNode->NextNodeRight();//�ұ߿�ʼ�ڵ�
			//��ߵݹ�
			Divide(leftDNode, midDNode, Ascending);
			//�ұߵݹ�
			Divide(midplusDNode, rightDNode, Ascending);
			//���Һϲ�
			Merge(leftDNode, midDNode, rightDNode, Ascending);
		}
	}


	//******************************************************************************************************************
	//�鲢������ؼ��ĺϲ�������ʹ��˫�������ݡ��洢���ݶ���ɡ�
	template<typename T>
	void DLinkedList<T>::Merge(DNode<T> *leftDNode, DNode<T> *midDNode, DNode<T> *rightDNode, bool Ascending) {

		DNode<T> *tempLeft = leftDNode;//��֧����߽�
		DNode<T> *leftNo =midDNode->NextNodeRight();//��֧���ұ߽�
		DNode<T> *tempRight = leftNo ;//��֧����߽�
		DNode<T> *rightNo = rightDNode->NextNodeRight();//��֧���ұ߽�
		//�洢����������ʱ˫��������������ô��ݽ����ģ���Ҫ������ݡ�
		DLinkedList<T> tempDList; 

		//���м�ڵ�Ϊ�磬������֧�Ƚϡ�����ʱ�Ͱ���С�ڡ��Ƚϣ�����Ͱ����ڱȽϡ�
		while (tempLeft != leftNo && tempRight != rightNo) {
			//DLinkedList<T>::GetTrueOrFalse(...)�������ݲ���Ascending�����ȽϽ��������С�ڻ��Ǵ��ڱȽϣ���
			if (GetTrueOrFalse(tempLeft->data,tempRight->data,Ascending)) {
				//���ȽϽ�������ǰ����ݴ��������ĩβ��
				tempDList.InsertEnd(tempLeft->data);
				//����Ƶ���һ���ڵ�
				tempLeft = tempLeft->NextNodeRight();
			}
			else {
				//���ȽϽ�������ǰ����ݴ��������ĩβ��
				tempDList.InsertEnd(tempRight->data);
				//�ұ��ƶ�����һ���ڵ㡣
				tempRight = tempRight->NextNodeRight();
			}
		}
		//�Ƚ���ɺ�ʣ���������ݿ���������ĩβ��
		while (tempLeft != leftNo) {
			tempDList.InsertEnd(tempLeft->data);
			tempLeft = tempLeft->NextNodeRight();
		}
		//�Ƚ���ɺ�ʣ����ұ����ݿ���������ĩβ��
		while (tempRight != rightNo) {
			tempDList.InsertEnd(tempRight->data);
			tempRight = tempRight->NextNodeRight();
		}

		//�����������Ѿ�����һ����������ݵø��Ƶ�leftDNode��rightDNode֮�䣨�����߽磩�ڵ��ϡ�
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

	//ϣ����������
	template<typename T>
	void DLinkedList<T>::ShellInsertSort(bool Ascending) {
		


	}


	template<typename T>
	void DLinkedList<T>::InsertSort(bool Ascending) {

		//ֱ�Ӳ��뷨����
		//���浱ǰλ�ü��ڵ�
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

		//ѡ������

		
			
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

		//ð������

			
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
		



	





	//����˽�к���++++++++++++++++++++++++++++++++++++++


	//��״̬����
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
		//pos�Ǵ�0----size֮������֡�
		size_t n=0;
		DNode<T> *p = currDNode;
		//���ȱȽϵ�ǰλ��������λ�õľ���
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

		

		//����˫������ĺô���
			//��ͷ�����ʹ�����ͷ��β��Ѱ�ҡ�
			//��β�����ʹӷ��򣨴�β��ͷ��Ѱ�ҡ�
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
				cout << "�ڲ���־���ô���" << endl;
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

	//�޸ĺ���
	template<typename T>
	void DLinkedList<T>::ResetPos(size_t pos){
		if (pos < 0 || pos >= size) {
			cout << "λ�����ò��ɹ�����ǰ����ֵ������Ч��Χ��" << endl;
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


	//��������
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
	

	//��������
	template<typename T>
	DLinkedList<T>::~DLinkedList(){
		ClearDList();
		delete head;

	}

	