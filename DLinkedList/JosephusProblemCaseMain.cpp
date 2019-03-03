#include<iostream>
#include "CNode.h"
#include<time.h>	
using namespace std;




//�ø�����ͷ���������λ�������
void CreateList(CNode<int> *head, int n);

//Josephus����ʵ��
void Josephus(CNode<int> *list, int n, int m);



int JosephusProblemCaseMain() {

	//cout << "JosephusProblemCaseMain!" << endl;
	//����ͷ
	CNode<int> list;
	//Ԫ�ظ���n�������m 1<=m<=n.
	int n, m;
	cout << "����������Ԫ��������" << endl;
	cin >> n;
	time_t;
	std::srand(time(0));
	m = std::rand() % n + 1;

	CreateList(&list, n);
	Josephus(&list, n, m);


	return 0;
}



//�ø�����ͷ�����������Ļ�������
void CreateList(CNode<int> *head, int n) {
	CNode<int> *currCNode = head, *newCNode;
	
	//��ʼ��ͷ���֮�����
	for (int i = 0;i < n;i++) {
		newCNode = new CNode<int>(i);
		currCNode->InsertAfter(newCNode);
		currCNode = newCNode;
	}

}


//Josephus����ʵ��
void Josephus(CNode<int> *list, int n, int m) {

	CNode<int> *prevCNode = list;
	CNode<int> *currCNode = list->NextCNode();
	CNode<int> *deleteCNode;
	//ѭ������Ԫ�ص�n-1�Σ�ɾ��n-1��Ԫ�أ�fʣ��Ψһ��һ��Ԫ�ؾ���Ӯ�ң�
	for (int i = 0;i < n - 1;i++) {
		//�ӵ�ǰλ�ÿ�ʼ���ҳ���m��Ԫ�ز�ɾ����
		for (int j = 0;j < m - 1;j++) {
			prevCNode = currCNode;
			currCNode = currCNode->NextCNode();
			if (currCNode == list) {
				prevCNode = currCNode;
				currCNode = currCNode->NextCNode();
			}
		}
		//�ҵ�һ��ɾ��Ԫ��
		deleteCNode = currCNode;
		currCNode = currCNode->NextCNode();
		prevCNode->DeleteAfter();
		cout << "�� " << i + 1 << " �����ֵ����ǣ�" << deleteCNode->data << endl;
		delete deleteCNode;

		if (currCNode == list) {
			prevCNode = currCNode;
			currCNode = currCNode->NextCNode();
		}


	}

	cout << "����Ӯ���ǣ� " << currCNode->data << endl;
	deleteCNode = currCNode;
	prevCNode->DeleteAfter();
	delete	deleteCNode;
	//Ҳ��������д
	/*
	deleteCNode = list->DeleteAfter();
	delete deleteCNode;
	*/


}

