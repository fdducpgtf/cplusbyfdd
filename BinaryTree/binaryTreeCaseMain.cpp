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


//�����鴴��������
void CreateTree(int *arr,int left,int right, BiTNode<int> *p);



int binaryTreeCaseMain() {
	
	

	////�����������ⴴ��һ��������
	BiTNode<int> *p=new BiTNode<int>;
	const int size = 16 ;
	int a[size];
	for (int i = 0;i < size;i++)
		a[i] = i+10;
	p->data =a[size-1];
	

	CreateTree(a, 0, size - 2, p);


	
	//ͨ�����Ƶķ�ʽ�����µĶ�����
	BinaryTree<int> intTree;
	intTree.CreateTreeBy(p);

	//ʹ�ö������ĳ�Ա�����ͷ�ԭ����ֻ��Data,Lchild,Rchild����Ϣ�Ķ��������ڴ�ռ�
	intTree.DeleteTree(p);

	int parent, left, right;
	 parent = 10;
	 left = 99;
	 right = 98;
	intTree.InsertTwoBiTNode(parent, left,right);

	 parent = 99;
	 right -= 1;
	intTree.InsertBiTNode(parent, right,false);



	//�����½ڵ�֮������������ɶ�������
	intTree.ReCreateTree();


	

	//ͼ��ֱ����ʾ������
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





