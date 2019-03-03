#pragma once
#include<iostream>
#include<sstream>
#include "BiTNode.h"
#include "../Queue/Queue.h"
#include "PrintLine.h"

using namespace std;



template<typename T>
class BinaryTree {
private:

	BiTNode<T> *root;

	void PreOrder(BiTNode<T> *root);
	void InOrder(BiTNode<T> *root);
	void PostOrder(BiTNode<T> *root);

	int CountDepth(BiTNode<T> *root);
	int CountLeaf(BiTNode<T> *root);


	void AddInfoToBiTNode(BiTNode<T> *p,bool isNew=true);
	void CreateTree(BiTNode<T> *root,bool isNew=true);
	void ManualCreate(BiTNode<T> *p);

	


public:
	BinaryTree();
	BinaryTree(BiTNode<T> *root);
	~BinaryTree();

	bool InsertBiTNode(T& parentitem, T& childitem, bool IsLeft = true);
	bool InsertTwoBiTNode(T& parentitem, T& leftchilditem, T& rightchilditem);
	void ReCreateTree(void);
	void CreateTreeBy(BiTNode<T> *p);
	void DeleteTree(BiTNode<T> *root);

	int GetDepth();
	int GetLeafNum(void);

	void PreOrderListTree(void);
	void LayerOrderListTree(void);
	void InOrderListTree(void);
	void PostOrderListTree(void);

	void ManualCreateTree(void);

	void DisplayBinaryTree(void);

	BiTNode<T> *GetRootBiTNode(void)const;
	BiTNode<T> *GetBiTNode(T& item);
	BiTNode<T> *GetBiTNodeByParent(T& parentitem,bool isLeft=true);



};





template<typename T>
void BinaryTree<T>::AddInfoToBiTNode(BiTNode<T> *p,bool isNew) {

	//����pΪ���������������BiTNode��ر�����Ϣ��
	Queue<BiTNode<T> *> qbit;
	BiTNode<T> *bitNode,*childNode;
	if (p) {
		//����㸴��
		if (isNew)
			root = new BiTNode<T>;
		else
			root = p;

		root->data = p->data;
		root->depth = 1;
		//orderoΪ�ڵ���š��ڵ���ű���ԭ�򣺴�0��ʼ���սڵ�ҲҪռ����Ӧλ�á���ʵ�ʽڵ���š�
		root->order = 0;
		root->Lchild = p->Lchild;
		root->Rchild = p->Rchild;

		qbit.QInsert(root);
		//�����ڵ�ĸ���ѭ�������ö����Ƚ��ȳ��ص㣬�����������нڵ㡣
		while (!qbit.QEmpty()) {
			bitNode = qbit.QDelete();
			//���ݸ���㣬�������ӽڵ㲢��������Ϣ��
			if (bitNode->Lchild) {
				if (isNew)
					childNode = new BiTNode<T>;
				else
					childNode = bitNode->Lchild;


				childNode->data = bitNode->Lchild->data;
				childNode->depth = bitNode->depth + 1;
				childNode->parent = bitNode;
				//���ݸ��ڵ�����ȷ����һ��Ԫ�صĸ������Ӷ�����ȷ����ǰ�ڵ��ڵ�ǰ�����š�
				//��ż���Ҫ����������в����ڵ�������ӽڵ����������Ų���ָʵ�ʴ��ڵ�ͬ��ڵ����š�
				childNode->order = childNode->parent->order * 2 ;
				childNode->Lchild = bitNode->Lchild->Lchild;

				childNode->Rchild = bitNode->Lchild->Rchild;

				bitNode->Lchild = childNode;
				qbit.QInsert(bitNode->Lchild);
			}
			//���ݸ���㣬�������ӽڵ㲢��������Ϣ��
			if (bitNode->Rchild) {
				if (isNew)
					childNode = new BiTNode<T>;
				else
					childNode = bitNode->Rchild;


				childNode->data = bitNode->Rchild->data;
				childNode->depth = bitNode->depth + 1;
				childNode->parent = bitNode;
				childNode->order = childNode->parent->order * 2 + 1;

				childNode->Lchild = bitNode->Rchild->Lchild;

				childNode->Rchild = bitNode->Rchild->Rchild;

				bitNode->Rchild = childNode;
				qbit.QInsert(bitNode->Rchild);
			}
			
		}

	}
}




template<typename T>
void BinaryTree<T>::CreateTree(BiTNode<T> *root,bool isNew) {
	AddInfoToBiTNode(root,isNew);
}

template<typename T>
void BinaryTree<T>::ReCreateTree(void) {
	BiTNode<T> *temp=root;
	root = NULL;
	CreateTree(temp,false);
	

}


template<typename T>
BinaryTree<T>::BinaryTree():root(NULL) {

}
template<typename T>
BinaryTree<T>::BinaryTree(BiTNode<T> *root){
	CreateTree(root);
}

template<typename T>
void BinaryTree<T>::CreateTreeBy(BiTNode<T> *p) {
	CreateTree(p);
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	DeleteTree(root);
	root = NULL;
}


//
template<typename T>
void BinaryTree<T>::DeleteTree(BiTNode<T> *root) {
	if (root != NULL) {

		if (root->Lchild) {
			DeleteTree(root->Lchild);
		}
		if (root->Rchild) {
			DeleteTree(root->Rchild);
		}
		delete root;

	}
	
}

//

//��������������
template<typename T>
int BinaryTree<T>::CountDepth(BiTNode<T> *root) {
	int leftdepth, rightdepth, maxdepth;
	if (root == NULL)
		return 0;
	leftdepth = CountDepth(root->Lchild);
	rightdepth = CountDepth(root->Rchild);
	maxdepth = leftdepth < rightdepth ? rightdepth : leftdepth;
	return maxdepth + 1;

}

template<typename T>
int BinaryTree<T>::GetDepth() {
	
	return CountDepth(root);
}

//�����������Ҷ������
template<typename T>
int BinaryTree<T>::CountLeaf(BiTNode<T> *root) {
	if (root == NULL)
		return 0;
	if ((root->Lchild == NULL) && (root->Rchild == NULL))
		return 1;
	return CountLeaf(root->Lchild) + CountLeaf(root->Rchild);
}
template<typename T>
int BinaryTree<T>::GetLeafNum(void) {
	return CountLeaf(root);
}



//������ʾ��
template<typename T>
void BinaryTree<T>::PreOrderListTree(void) {
	PreOrder(this->root);
	cout << endl;

}

template<typename T>
void BinaryTree<T>::PreOrder(BiTNode<T> *root) {
	if (root) {

		cout << root->data << " ";

		if (root->Lchild) {
			PreOrder(root->Lchild);
		}
		if (root->Rchild) {
			PreOrder(root->Rchild);
		}
		
	}
	

}

//�������������
template<typename T>
void BinaryTree<T>::InOrder(BiTNode<T> *root) {
	if (root) {
		if (root->Lchild) 
			InOrder(root->Lchild);
		cout << root->data<<" ";
		if (root->Rchild)
			InOrder(root->Rchild);
		
	}
}
template<typename T>
void BinaryTree<T>::InOrderListTree(void) {
	InOrder(root);
	cout << endl;
}

//�������������

template<typename T>
void BinaryTree<T>::PostOrder(BiTNode<T> *root) {
	if (root) {
		if (root->Lchild)
			InOrder(root->Lchild);
		if (root->Rchild)
			InOrder(root->Rchild);
		cout << root->data << " ";

	}

}
template<typename T>
void BinaryTree<T>::PostOrderListTree(void) {
	PostOrder(root);
	cout << endl;
}


//�������������


template<typename T>
void BinaryTree<T>::LayerOrderListTree(void) {
	Queue<BiTNode<T>*> qbit;
	BiTNode<T> *p;
	if (root) {
		qbit.QInsert(root);
		while (!qbit.QEmpty()) {

			p = qbit.QDelete();
			cout << p->data << " ";
			if (p->Lchild) {
				qbit.QInsert(p->Lchild);

			}
			if (p->Rchild) {
				qbit.QInsert(p->Rchild);
			}
		}
		cout << endl;

	} 
}


//��ȡ�ڵ�

template<typename T>
BiTNode<T> *BinaryTree<T>::GetRootBiTNode(void)const {
	return root;
}

template<typename T>
BiTNode<T> *BinaryTree<T>::GetBiTNode(T& item) {

	Queue<BiTNode<T>*> qbit;
	BiTNode<T> *p=NULL;
	if (root) {
		qbit.QInsert(root);
		while (!qbit.QEmpty()) {

			p = qbit.QDelete();
			if (p->data == item)
				break;
			if (p->Lchild) {
				qbit.QInsert(p->Lchild);

			}
			if (p->Rchild) {
				qbit.QInsert(p->Rchild);
			}

		}
		return p;
	

	}
	return NULL;
}

template<typename T>
BiTNode<T> *BinaryTree<T>::GetBiTNodeByParent(T& parentitem, bool isLeft) {
	Queue<BiTNode<T>*> qbit;
	BiTNode<T> *p = NULL;
	if (root) {
		qbit.QInsert(root);
		while (!qbit.QEmpty()) {

			p = qbit.QDelete();
			if (p->data == parentitem) {
				return isLeft ? p->Lchild : p->Rchild;
			}
			
			if (p->Lchild) {
				qbit.QInsert(p->Lchild);

			}
			if (p->Rchild) {
				qbit.QInsert(p->Rchild);
			}

		}
		return NULL;
	}
	else {
		return NULL;
	}

}


//����ڵ�
template<typename T>
bool BinaryTree<T>::InsertBiTNode(T& parentitem, T& childitem, bool IsLeft) {
	BiTNode<T> *tempBiTNode = GetBiTNode(parentitem);
	if (tempBiTNode) {
		if ((!tempBiTNode->Lchild) && (IsLeft)) {
			tempBiTNode->Lchild = new BiTNode<T>;
			tempBiTNode->Lchild->data = childitem;
			return true;
		}
		else if ((!tempBiTNode->Rchild) && (!IsLeft)) {
			tempBiTNode->Rchild = new BiTNode<T>;
			tempBiTNode->Rchild->data = childitem;
			return true;
		}
		return false;
		
	}
	else {
		return false;
	}
}


template<typename T>
bool BinaryTree<T>::InsertTwoBiTNode(T& parentitem, T& leftchilditem, T& rightchilditem) {
	BiTNode<T> *tempBiTNode = GetBiTNode(parentitem);
	if (tempBiTNode) {
		if ((!tempBiTNode->Lchild) && (!tempBiTNode->Rchild)) {
			tempBiTNode->Lchild = new BiTNode<T>;
			tempBiTNode->Lchild->data = leftchilditem;
			tempBiTNode->Rchild = new BiTNode<T>;
			tempBiTNode->Rchild->data = rightchilditem;
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}


//�ֶ�����������
template<typename T>
void BinaryTree<T>::ManualCreate(BiTNode<T> *p) {
	int val;
	if (p) {


		cout << "������ " << p->data << " �����ӽڵ��ֵ��";
		cin >> val;
		if (val != -1) {
			p->Lchild = new BiTNode<T>;
			p->Lchild->data = val;

		}
		cout << "������ " << p->data << " �����ӽڵ��ֵ��";
		cin >> val;
		if (val != -1) {
			p->Rchild = new BiTNode<T>;
			p->Rchild->data = val;

		}
		//
		ManualCreate(p->Lchild);
		ManualCreate(p->Rchild);
	}
}



template<typename T>
void BinaryTree<T>::ManualCreateTree(void) {
	int val;
	BiTNode<T> *r;
	cout << "���������������ֵ��";
	cin >> val;
	if (val != -1) {
		if (root)
			DeleteTree(root);
		root = new BiTNode<T>;
		root->data = val;
		
		ManualCreate(root);
	
		CreateTree(root);
		
		
	}
}


//ͼ����ʾ������

template<typename T>
void BinaryTree<T>::DisplayBinaryTree(void) {
	//����ostringstream���ѽڵ���������������ostringstream�У�Ȼ���������cout�ϡ�
	ostringstream oss;
	
	//���ö�����Ϊ��ȡ�������ڵ�Ĺ���
	Queue<BiTNode<T>*> qbit;
	//��¼ǰ�������ڵ��ָ��
	BiTNode<T> *p, *pre;
	//��Ҫ��ʾ�Ľڵ�ֵ�Ŀ�ȡ�
	//ż����ѣ������п������ݾ�����Ӱ�죬�����������ȡ�
	//������ʾ���ڿ�ȡ�����̫�󡣶�����ģ��ṹPrintLine<T>���档
	int deltawidth = PrintLine<T>::DeltaWidth;
	//��������������ȣ���������
	int treeDepth = GetDepth();

	//���ݶ��������һ����ܴ��ڵ�Ԫ��������ȷ�����������ȡ��˱���δʹ�ã�������⡣
	//int maxwidth = deltawidth * pow(2, treeDepth - 1);


	//Ԫ��֮�������
	//������ÿ��Ԫ����һ��������������������������Χ�ڣ�ʣ���Ԫ��֮��Ŀհ׿��
		//���㹫ʽ����2^(������-��ǰ������-1��/2  �����в�����1��ʼ��
		//ÿ���һ���ڵ�֮ǰ�����һ���ڵ�֮����������Ϊ��1*distance�������ڵ�֮��Ϊ2*distance��ȡ�
	int distance;
	//��������ȣ�������
	int depth;
	//ͬ��Ԫ�ص���ţ���0��ʼ��ÿ��Ԫ��Ϊ��2^(����-1������ÿ��������Ϊ��2^(����-1��-1 ����
	int order;
	//ÿ����ܴ��ڵ�Ԫ�ص���������
	int nodesNum;
	//������ÿ�����һ��Ԫ������󣬽���������з���ı�־����
	int flagEnter = 0;
	//��һ��Ԫ�ص����
	int _preOrder;


	//��һ��Ԫ��ָ�루��ʼΪ����㣩
	pre = root;
	/*�������ö����Ƚ��ȳ����ص㣬ѭ����ȡ�������ڵ㣬
	�������ɸ���㵽������������ζ�ȡԪ�أ�
	�����ݻ�ȡ��Ԫ�������Ϣ��ʽ�����������ÿ��Ԫ�ء�
	�������������ֲ����õݹ鷽��ʱ�����ö��е��Ƚ��ȳ����ص����ʵ�ֱ����ˡ�
		*/
	if (root) {
		qbit.QInsert(root);
		while (!qbit.QEmpty()) {
			//ÿ���ڵ����ʱ�������ȵı��������ڼ���ڵ������ȵĹ����е��ۼƣ�
			int totalwidth = 0;
			p = qbit.QDelete();
			//��ǰ�ڵ����ȣ�������
			depth = p->depth;
			//��ǰ�ڵ����ţ���������ĳ��ڼ����ڵ㣩
			order = p->order;
			//ÿ��Ԫ�������������սڵ㣩
			nodesNum = pow(2, depth - 1);
			if (pre->depth != p->depth) {
				
				cout << oss.str();//���ͬ�����нڵ�
				oss.str("");//�������գ�Ȼ��ʼ�µ�һ��ڵ�����
				
				oss << endl;
				
				flagEnter = 1;
			}


			//��λ���������ؼ��㣡������
			//���ݶ������Ĳ�������ȣ����Զ������õ�Ԫ������ĵ�λ��ȣ�
			//ֱ�Ӽ����Ԫ��֮��ļ��ĵ�λ����Ԫ��֮��ļ��=2*distance.
			//ÿ��ļ�಻һ�������һ����Ϊ0.��distanceΪ0.
			distance = deltawidth * (pow(2, treeDepth - depth) - 1) / 2;
			//��������ڲ㣬����һ�㵥�����������ȡ�
			//��һ�㣺maxwidth=distance+�ڵ�(��һ����λ�Ŀ�����)+distance.
			if (depth == 1) {
				totalwidth = distance + deltawidth;
				
				oss.width(totalwidth);
				
			}
			else {
				//����Ϊ���ǵ�һ��ڵ�����Ŀ�ȵļ��㷽��
					//�����һ�ڵ�����һ�����һ��Ԫ�����������˻��з���
					//��һ�п�ʼ������ǰ�ڵ㣩��Ҫ�������һ��������ȡ���Ϊdistance��ֵ��
				if (flagEnter == 1) {
					totalwidth += distance;
					flagEnter = 0;
				}

				//����ÿ���һ�����ڵ�Ԫ�ص���Ų���Ϊ0�������ͳһ������һ��Ԫ�ص�������ó�-1��
					//�������Ԫ��֮��ļ�ࣨ��һ�����������������Ԫ�أ�
				if (pre->depth != depth) {
					_preOrder = -1;
				}
				else {
					//���ǵ�һ����Ԫ�ص������ȻΪԭ��š�
					_preOrder = pre->order;
				}

				//ÿ��Ԫ�ص������ȵļ��㹫ʽ��Ԫ�ر���Ŀ��+Ԫ��֮���ࣩ--(ʵ�ʴ��ڵ�Ԫ��֮�䲻һ�������������
					//ͬ���������������Ԫ��֮��ļ��=2*distance.
				totalwidth += (order - _preOrder)*(deltawidth + 2 * distance) - 2 * distance;
				
				oss.width(totalwidth);
				


			}

			
			
			//���Ԫ�أ��ڵ㣩��ֵ
			
			oss << p->data;
				
			//ÿ��Ԫ�������ļ�����������һ�㣨���㣩�ļ��Ϊ0���������
			if ((depth != treeDepth) && (order < nodesNum - 1)) {
				
				oss.width(2 * distance);
				oss << " ";
				
			}


			//oss.fill(cc);

			//��ʼ�������----------------------------


				if (p->depth != pre->depth) {

					cout << endl;
					
					

				}
				//��ʼ����ڵ��Ӧ�ķ���-------------------------------------------------------
				if (p != root) {
					//��ȡ��ǰ�ڵ��Ӧ��Ҫ��ӵķ������͡����Ͷ������LineType
					LineType Ltype = PrintLine<int>::GetLineType(p);
					//������������
					if (p->depth != pre->depth) {
						//ÿ���һ���ڵ��ǰ��ڵ㶼�ǿսڵ�֮��ĵ�һ���ڵ�
						PrintLine<int>::Print(totalwidth, deltawidth, distance, Ltype);
					}
					else {
						if (PrintLine<int>::GetLineType(pre) == LineType::Lline) {
							//ֻ����ڵ㣬û���ҽڵ�
							PrintLine<int>::Print(totalwidth + distance - deltawidth / 2, deltawidth, distance, Ltype);
						}
						else {
							//���������������������
							PrintLine<int>::Print(totalwidth + 2 * distance, deltawidth, distance, Ltype);
						}
					}

				}


			//�����������--------------------------------------------------------------------


			//�ѵ�ǰ�ڵ����ó���һ���ڵ��ǰһ���ڵ㡣
			pre = p;
			//������ԭ��ѭ���������Ԫ�ء��㶨������
			if (p->Lchild) {
				qbit.QInsert(p->Lchild);

			}
			if (p->Rchild) {
				qbit.QInsert(p->Rchild);
			}
		}
		//���һ��ڵ�����
		cout << oss.str();
		//�����
		oss.str("");
		//������һ�����з���
		cout << endl;
	}
}
