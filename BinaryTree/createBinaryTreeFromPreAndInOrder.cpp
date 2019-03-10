
#include<iostream>
#include<vector>
#include "BinaryTree.h"

using namespace std;

//递归模板函数（根据二叉树的前序和中序排列创建唯一的二叉树
template<typename T>
void createBTree(vector<T> preOrder, vector<T> inOrder,BiTNode<T> *root);

int createBinaryTreeFromPreAndInOrder() {

	//设定二叉树节点值的类型
	using elemType = int;
	//二叉树的前序：元素值要保持不等，否则程序查找时会出错。
	vector<elemType> preOrderVector = { 1,2,4,5,6,3,7,8,9 }; //char型也可以。{ 'A','B','C','D','E','F','G' };
	//二叉树的中序：元素值要保持不等，否则程序查找时会出错。
	vector<elemType> inOrderVector = { 4,2,5,6,1,7,3,9,8 };//char型也可以。{ 'C','B','E','D','A','F','G' };

	int size= preOrderVector.size();
	if (size) {
		//创建二叉树根结点BiTNode
		elemType root = preOrderVector[0];
		BiTNode<elemType> *rootBiTNode = new BiTNode<elemType>;
		rootBiTNode->data = root;
		createBTree(preOrderVector, inOrderVector, rootBiTNode);

		BinaryTree<elemType> tree(rootBiTNode);
		tree.DisplayBinaryTree();
	}
	return 0;
}

template<typename T>
void createBTree(vector<T> preOrder, vector<T> inOrder, BiTNode<T> *root) {
	//如果preOrder为空就退出
	if (preOrder.size()) {
		//根（或子树的根）节点已经创建了BiTNode节点（即参数root)，所以在前序里不再需要，删除。
		preOrder.erase(preOrder.begin());
		//删除第一个元素后，如果preOrder为空就退出
		if (preOrder.size()) {
			//preOrder第一个值总是可以看作是子树的根结点。
			T rootVal = root->data;
			
			vector<T> leftPreOrder, leftInOrder, rightPreOrder, rightInOrder;


			//根据根结点值，把中序的元素分成左子树和右子树两部分的节点
			//并分别把左子树和右子树又各自分为：左子树的前序和中序，右子树的前序和中序两部分。

			//leftInOrder,rightInOrder
			
			int size = inOrder.size();
			int i;
			for (i = 0;i < size;i++) {
				if (inOrder[i] != rootVal)
					//根据根结点（或子树的根结点）以及中序（InOrder）得到左子树的新的中序（leftInOrder）。
					leftInOrder.push_back(inOrder[i]);
				else
					break;

			}
			for (i++;i < size;i++) {
				//剩下的就是右子树的新的中序（rightInOrder）。
				rightInOrder.push_back(inOrder[i]);
			}
			//leftPreOrder,rightPreOrder
			size = preOrder.size();
			for (i = 0;i < size;i++) {
				//根据左子树新的中序在之前的前序中查找，从而创建左子树新的前序
				if (std::find(leftInOrder.begin(), leftInOrder.end(), preOrder[i]) != leftInOrder.end())
					leftPreOrder.push_back(preOrder[i]);
				else
					break;

			}

			for (;i < size;i++) {
				//剩下的就是右子树新的前序
				rightPreOrder.push_back(preOrder[i]);
			}

			//leftPreOrder左子树递归循环
			if (leftPreOrder.size()) {
				//创建左子树的根结点，并建立其与父节点之间的关系。
				root->Lchild = new BiTNode<T>;
				root->Lchild->data = leftPreOrder[0];
				createBTree(leftPreOrder, leftInOrder, root->Lchild);
			}
			//rightPreOrder右子树递归循环
			if (rightPreOrder.size()) {
				//创建右子树的根结点，并建立其与父节点之间的关系。
				root->Rchild = new BiTNode<T>;
				root->Rchild->data = rightPreOrder[0];
				createBTree(rightPreOrder, rightInOrder, root->Rchild);
			}




		}



	}
	
	
}


