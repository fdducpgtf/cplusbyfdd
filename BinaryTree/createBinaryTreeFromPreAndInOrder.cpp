
#include<iostream>
#include<vector>
#include "BinaryTree.h"

using namespace std;

//�ݹ�ģ�庯�������ݶ�������ǰ����������д���Ψһ�Ķ�����
template<typename T>
void createBTree(vector<T> preOrder, vector<T> inOrder,BiTNode<T> *root);

int createBinaryTreeFromPreAndInOrder() {

	//�趨�������ڵ�ֵ������
	using elemType = int;
	//��������ǰ��Ԫ��ֵҪ���ֲ��ȣ�����������ʱ�����
	vector<elemType> preOrderVector = { 1,2,4,5,6,3,7,8,9 }; //char��Ҳ���ԡ�{ 'A','B','C','D','E','F','G' };
	//������������Ԫ��ֵҪ���ֲ��ȣ�����������ʱ�����
	vector<elemType> inOrderVector = { 4,2,5,6,1,7,3,9,8 };//char��Ҳ���ԡ�{ 'C','B','E','D','A','F','G' };

	int size= preOrderVector.size();
	if (size) {
		//���������������BiTNode
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
	//���preOrderΪ�վ��˳�
	if (preOrder.size()) {
		//�����������ĸ����ڵ��Ѿ�������BiTNode�ڵ㣨������root)��������ǰ���ﲻ����Ҫ��ɾ����
		preOrder.erase(preOrder.begin());
		//ɾ����һ��Ԫ�غ����preOrderΪ�վ��˳�
		if (preOrder.size()) {
			//preOrder��һ��ֵ���ǿ��Կ����������ĸ���㡣
			T rootVal = root->data;
			
			vector<T> leftPreOrder, leftInOrder, rightPreOrder, rightInOrder;


			//���ݸ����ֵ���������Ԫ�طֳ��������������������ֵĽڵ�
			//���ֱ�����������������ָ��Է�Ϊ����������ǰ���������������ǰ������������֡�

			//leftInOrder,rightInOrder
			
			int size = inOrder.size();
			int i;
			for (i = 0;i < size;i++) {
				if (inOrder[i] != rootVal)
					//���ݸ���㣨�������ĸ���㣩�Լ�����InOrder���õ����������µ�����leftInOrder����
					leftInOrder.push_back(inOrder[i]);
				else
					break;

			}
			for (i++;i < size;i++) {
				//ʣ�µľ������������µ�����rightInOrder����
				rightInOrder.push_back(inOrder[i]);
			}
			//leftPreOrder,rightPreOrder
			size = preOrder.size();
			for (i = 0;i < size;i++) {
				//�����������µ�������֮ǰ��ǰ���в��ң��Ӷ������������µ�ǰ��
				if (std::find(leftInOrder.begin(), leftInOrder.end(), preOrder[i]) != leftInOrder.end())
					leftPreOrder.push_back(preOrder[i]);
				else
					break;

			}

			for (;i < size;i++) {
				//ʣ�µľ����������µ�ǰ��
				rightPreOrder.push_back(preOrder[i]);
			}

			//leftPreOrder�������ݹ�ѭ��
			if (leftPreOrder.size()) {
				//�����������ĸ���㣬���������븸�ڵ�֮��Ĺ�ϵ��
				root->Lchild = new BiTNode<T>;
				root->Lchild->data = leftPreOrder[0];
				createBTree(leftPreOrder, leftInOrder, root->Lchild);
			}
			//rightPreOrder�������ݹ�ѭ��
			if (rightPreOrder.size()) {
				//�����������ĸ���㣬���������븸�ڵ�֮��Ĺ�ϵ��
				root->Rchild = new BiTNode<T>;
				root->Rchild->data = rightPreOrder[0];
				createBTree(rightPreOrder, rightInOrder, root->Rchild);
			}




		}



	}
	
	
}


