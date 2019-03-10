//*****************************************************************************************

#include<iostream>
#include<sstream>
#include<vector>
#include "BiTNode.h"
#include "BinaryTree.h"
#include "../Queue/Queue.h"
#include "PrintLine.h"
#include<fstream>
#include "../DLinkedList/DLinkedList.h"

using namespace std;




//--------------------------------------------------------------------------------------
int binaryTreeCaseMain() {

	

	
	
	//�������鴴��һ��������
	const int size = 31 ;
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







