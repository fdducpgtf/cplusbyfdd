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

	

	
	
	//根据数组创建一个二叉树
	const int size = 31 ;
	int a[size];
	for (int i = 0;i < size;i++)
		a[i] = i;


	
	//通过数组的方式创建新的二叉树
	BinaryTree<int> intTree;
	intTree.CreateTreeFrom(a,size);

	//图形直观显示二叉树
	intTree.DisplayBinaryTree();

	//建立有序的二叉树
	intTree.BinaryTreeSort();
	//图形直观显示二叉树
	intTree.DisplayBinaryTree();
	         
	
	return 0;
}







