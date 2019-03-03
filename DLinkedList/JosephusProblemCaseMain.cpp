#include<iostream>
#include "CNode.h"
#include<time.h>	
using namespace std;




//用给定的头结点产生整形环形链表
void CreateList(CNode<int> *head, int n);

//Josephus问题实现
void Josephus(CNode<int> *list, int n, int m);



int JosephusProblemCaseMain() {

	//cout << "JosephusProblemCaseMain!" << endl;
	//链表头
	CNode<int> list;
	//元素个数n，随机数m 1<=m<=n.
	int n, m;
	cout << "请输入链表元素总数：" << endl;
	cin >> n;
	time_t;
	std::srand(time(0));
	m = std::rand() % n + 1;

	CreateList(&list, n);
	Josephus(&list, n, m);


	return 0;
}



//用给定的头结点产生整数的环形链表
void CreateList(CNode<int> *head, int n) {
	CNode<int> *currCNode = head, *newCNode;
	
	//开始往头结点之后插入
	for (int i = 0;i < n;i++) {
		newCNode = new CNode<int>(i);
		currCNode->InsertAfter(newCNode);
		currCNode = newCNode;
	}

}


//Josephus问题实现
void Josephus(CNode<int> *list, int n, int m) {

	CNode<int> *prevCNode = list;
	CNode<int> *currCNode = list->NextCNode();
	CNode<int> *deleteCNode;
	//循环表中元素的n-1次，删除n-1个元素，f剩下唯一的一个元素就是赢家！
	for (int i = 0;i < n - 1;i++) {
		//从当前位置开始，找出第m个元素并删除它
		for (int j = 0;j < m - 1;j++) {
			prevCNode = currCNode;
			currCNode = currCNode->NextCNode();
			if (currCNode == list) {
				prevCNode = currCNode;
				currCNode = currCNode->NextCNode();
			}
		}
		//找到一个删除元素
		deleteCNode = currCNode;
		currCNode = currCNode->NextCNode();
		prevCNode->DeleteAfter();
		cout << "第 " << i + 1 << " 个出局的人是：" << deleteCNode->data << endl;
		delete deleteCNode;

		if (currCNode == list) {
			prevCNode = currCNode;
			currCNode = currCNode->NextCNode();
		}


	}

	cout << "最后的赢家是： " << currCNode->data << endl;
	deleteCNode = currCNode;
	prevCNode->DeleteAfter();
	delete	deleteCNode;
	//也可以这样写
	/*
	deleteCNode = list->DeleteAfter();
	delete deleteCNode;
	*/


}

