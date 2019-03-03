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

	//复制p为根结点的树，并添加BiTNode相关变量信息。
	Queue<BiTNode<T> *> qbit;
	BiTNode<T> *bitNode,*childNode;
	if (p) {
		//根结点复制
		if (isNew)
			root = new BiTNode<T>;
		else
			root = p;

		root->data = p->data;
		root->depth = 1;
		//ordero为节点序号。节点序号编排原则：从0开始；空节点也要占据相应位置。非实际节点序号。
		root->order = 0;
		root->Lchild = p->Lchild;
		root->Rchild = p->Rchild;

		qbit.QInsert(root);
		//其它节点的复制循环，利用队列先进先出特点，按层序复制所有节点。
		while (!qbit.QEmpty()) {
			bitNode = qbit.QDelete();
			//根据父结点，创建左子节点并添加相关信息。
			if (bitNode->Lchild) {
				if (isNew)
					childNode = new BiTNode<T>;
				else
					childNode = bitNode->Lchild;


				childNode->data = bitNode->Lchild->data;
				childNode->depth = bitNode->depth + 1;
				childNode->parent = bitNode;
				//根据父节点的序号确定上一层元素的个数，从而可以确定当前节点在当前层的序号。
				//序号计算要包括父结点中不存在的左或右子节点的数量。序号不是指实际存在的同层节点的序号。
				childNode->order = childNode->parent->order * 2 ;
				childNode->Lchild = bitNode->Lchild->Lchild;

				childNode->Rchild = bitNode->Lchild->Rchild;

				bitNode->Lchild = childNode;
				qbit.QInsert(bitNode->Lchild);
			}
			//根据父结点，创建右子节点并添加相关信息。
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

//计算二叉树的深度
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

//计算二叉树的叶子总数
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



//先序显示树
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

//中序遍历二叉树
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

//后序遍历二叉树

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


//按层遍历二叉树


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


//获取节点

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


//插入节点
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


//手动创建二叉树
template<typename T>
void BinaryTree<T>::ManualCreate(BiTNode<T> *p) {
	int val;
	if (p) {


		cout << "请输入 " << p->data << " 的左子节点的值：";
		cin >> val;
		if (val != -1) {
			p->Lchild = new BiTNode<T>;
			p->Lchild->data = val;

		}
		cout << "请输入 " << p->data << " 的右子节点的值：";
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
	cout << "请输入二叉树根的值：";
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


//图形显示二叉树

template<typename T>
void BinaryTree<T>::DisplayBinaryTree(void) {
	//利用ostringstream流把节点输出的内容输出到ostringstream中，然后再输出到cout上。
	ostringstream oss;
	
	//利用队列作为读取二叉树节点的工具
	Queue<BiTNode<T>*> qbit;
	//记录前后两个节点的指针
	BiTNode<T> *p, *pre;
	//需要显示的节点值的宽度。
	//偶数最佳，否则有可能数据精度受影响，造成输出不均等。
	//根据显示调节宽度。不宜太大。定义在模板结构PrintLine<T>里面。
	int deltawidth = PrintLine<T>::DeltaWidth;
	//整个二叉树的深度（最大层数）
	int treeDepth = GetDepth();

	//根据二叉树最大一层可能存在的元素最多个数确定输出的最大宽度。此变量未使用，用于理解。
	//int maxwidth = deltawidth * pow(2, treeDepth - 1);


	//元素之间间距变量
	//二叉树每层元素以一定宽度输出后，在上述最大宽度输出范围内，剩余的元素之间的空白宽度
		//计算公式：（2^(最大层数-当前层数）-1）/2  ，其中层数从1开始。
		//每层第一个节点之前，最后一个节点之后的缩进宽度为：1*distance。两个节点之间为2*distance宽度。
	int distance;
	//二叉树深度（层数）
	int depth;
	//同层元素的序号：从0开始，每层元素为：2^(层数-1）个。每层最大序号为：2^(层数-1）-1 个。
	int order;
	//每层可能存在的元素的最大个数。
	int nodesNum;
	//二叉树每层最后一个元素输出后，接着输出换行符后的标志设置
	int flagEnter = 0;
	//上一个元素的序号
	int _preOrder;


	//上一个元素指针（初始为根结点）
	pre = root;
	/*以下利用队列先进先出的特点，循环读取二叉树节点，
	按层序由根结点到最大层从左到右依次读取元素，
	并根据获取的元素相关信息格式化输出二叉树每层元素。
	当遍历二叉树又不想用递归方法时，利用队列的先进先出的特点就能实现遍历了。
		*/
	if (root) {
		qbit.QInsert(root);
		while (!qbit.QEmpty()) {
			//每个节点输出时的输出宽度的变量（用于计算节点输出宽度的过程中的累计）
			int totalwidth = 0;
			p = qbit.QDelete();
			//当前节点的深度（层数）
			depth = p->depth;
			//当前节点的序号（即二叉树某层第几个节点）
			order = p->order;
			//每层元素总数（包括空节点）
			nodesNum = pow(2, depth - 1);
			if (pre->depth != p->depth) {
				
				cout << oss.str();//输出同层所有节点
				oss.str("");//输出后清空，然后开始新的一层节点的输出
				
				oss << endl;
				
				flagEnter = 1;
			}


			//单位间距变量（关键点！！！）
			//根据二叉树的层数（深度）和自定义设置的元素输出的单位宽度，
			//直接计算出元素之间的间距的单位量：元素之间的间距=2*distance.
			//每层的间距不一样，最大一层间距为0.即distance为0.
			distance = deltawidth * (pow(2, treeDepth - depth) - 1) / 2;
			//根结点所在层，即第一层单独设置输出宽度。
			//第一层：maxwidth=distance+节点(按一定单位的宽度输出)+distance.
			if (depth == 1) {
				totalwidth = distance + deltawidth;
				
				oss.width(totalwidth);
				
			}
			else {
				//以下为：非第一层节点输出的宽度的计算方法
					//如果上一节点是上一层最后一个元素输出并输出了换行符，
					//下一行开始（即当前节点）就要首先输出一个缩进宽度。即为distance的值。
				if (flagEnter == 1) {
					totalwidth += distance;
					flagEnter = 0;
				}

				//存在每层第一个存在的元素的序号不是为0的情况，统一把它第一个元素的序号设置成-1，
					//方便计算元素之间的间距（不一定是序号相连的两个元素）
				if (pre->depth != depth) {
					_preOrder = -1;
				}
				else {
					//不是第一个的元素的序号仍然为原序号。
					_preOrder = pre->order;
				}

				//每个元素的输出宽度的计算公式（元素本身的宽度+元素之间间距）--(实际存在的元素之间不一定序号相连）。
					//同层序号相连的两个元素之间的间距=2*distance.
				totalwidth += (order - _preOrder)*(deltawidth + 2 * distance) - 2 * distance;
				
				oss.width(totalwidth);
				


			}

			
			
			//输出元素（节点）的值
			
			oss << p->data;
				
			//每个元素输出后的间距输出。最深一层（最大层）的间距为0，不输出。
			if ((depth != treeDepth) && (order < nodesNum - 1)) {
				
				oss.width(2 * distance);
				oss << " ";
				
			}


			//oss.fill(cc);

			//开始输出符号----------------------------


				if (p->depth != pre->depth) {

					cout << endl;
					
					

				}
				//开始输出节点对应的符号-------------------------------------------------------
				if (p != root) {
					//获取当前节点对应的要添加的符号类型。类型定义见：LineType
					LineType Ltype = PrintLine<int>::GetLineType(p);
					//分情况输出符号
					if (p->depth != pre->depth) {
						//每层第一个节点或前面节点都是空节点之后的第一个节点
						PrintLine<int>::Print(totalwidth, deltawidth, distance, Ltype);
					}
					else {
						if (PrintLine<int>::GetLineType(pre) == LineType::Lline) {
							//只有左节点，没有右节点
							PrintLine<int>::Print(totalwidth + distance - deltawidth / 2, deltawidth, distance, Ltype);
						}
						else {
							//除以上两种情况以外的情况
							PrintLine<int>::Print(totalwidth + 2 * distance, deltawidth, distance, Ltype);
						}
					}

				}


			//结束输出符号--------------------------------------------------------------------


			//把当前节点设置成下一个节点的前一个节点。
			pre = p;
			//按层序原则循环输出其它元素。搞定！！！
			if (p->Lchild) {
				qbit.QInsert(p->Lchild);

			}
			if (p->Rchild) {
				qbit.QInsert(p->Rchild);
			}
		}
		//最后一层节点的输出
		cout << oss.str();
		//清空流
		oss.str("");
		//输出最后一个换行符。
		cout << endl;
	}
}
