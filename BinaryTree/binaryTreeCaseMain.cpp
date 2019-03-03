//*****************************************************************************************

#include<iostream>
#include<sstream>
#include "BiTNode.h"
#include "BinaryTree.h"
#include "../Queue/Queue.h"
#include "PrintLine.h"
#include<fstream>
using namespace std;

//*****************************************************************************************


//用数组创建二叉树
void CreateTree(int *arr,int left,int right, BiTNode<int> *p);



int binaryTreeCaseMain() {
	
	

	////根据数组随意创建一个二叉树
	BiTNode<int> *p=new BiTNode<int>;
	const int size = 16 ;
	int a[size];
	for (int i = 0;i < size;i++)
		a[i] = i+10;
	p->data =a[size-1];
	

	CreateTree(a, 0, size - 2, p);


	
	//通过复制的方式创建新的二叉树
	BinaryTree<int> intTree;
	intTree.CreateTreeBy(p);

	//使用二叉树的成员函数释放原来的只有Data,Lchild,Rchild简单信息的二叉树的内存空间
	intTree.DeleteTree(p);

	int parent, left, right;
	 parent = 10;
	 left = 99;
	 right = 98;
	intTree.InsertTwoBiTNode(parent, left,right);

	 parent = 99;
	 right -= 1;
	intTree.InsertBiTNode(parent, right,false);



	//插入新节点之后必须重新生成二叉树。
	intTree.ReCreateTree();


	

	//图形直观显示二叉树
	intTree.DisplayBinaryTree();

	

	
	return 0;
}






void CreateTree(int *arr, int left, int right,BiTNode<int> *p) {
	
	if (p) {
		
		if (left == right) {
			BiTNode<int> *newnode=new BiTNode<int>;
			newnode->data = arr[left];
			if (!p->Lchild)
				p->Lchild = newnode;
			else if (!p->Rchild)
				p->Rchild = newnode;
		}
		if (left < right) {
			int mid = (left + right) / 2;

			if(p->Lchild)
				CreateTree(arr, left, mid, p->Lchild);
			else
				CreateTree(arr, left, mid, p);

			if(p->Rchild)
				CreateTree(arr, mid + 1, right, p->Rchild);
			else
				CreateTree(arr, mid + 1, right, p);
		}

		


	}
	

}





