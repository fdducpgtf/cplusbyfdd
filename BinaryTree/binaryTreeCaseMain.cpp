//*****************************************************************************************

#include<iostream>
#include<sstream>
#include "BiTNode.h"
#include "BinaryTree.h"
#include "../Queue/Queue.h"
#include "PrintLine.h"
#include<fstream>
#include "../DLinkedList/DLinkedList.h"

using namespace std;

//*****************************************************************************************





int binaryTreeCaseMain() {
	
	
	
	
	////�����������ⴴ��һ��������
	//BiTNode<int> *p=new BiTNode<int>;
	const int size = 21 ;
	int a[size];
	for (int i = 0;i < size;i++)
		a[i] = i;


	
	//ͨ������ķ�ʽ�����µĶ�����
	BinaryTree<int> intTree;
	intTree.CreateTreeFrom(a,size);

	//ͼ��ֱ����ʾ������
	intTree.DisplayBinaryTree();

	//��������Ķ�����
	intTree.BinaryTreeSort();
	//ͼ��ֱ����ʾ������
	intTree.DisplayBinaryTree();
	         
	
	return 0;
}







