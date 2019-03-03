#include<iostream>
#include<iomanip>

using namespace std;

//************************************struct BiTNode****************************************************
template<typename T>
struct BiTNode {
	BiTNode<T> *Lchild = NULL, *Rchild = NULL, *parent = NULL;
	T data;
	int depth = 0;
	int order = 0;
};
//*****************************************************************************************


//************************************class Queue*****************************************************
//队列内元素最大个数：
static const int MAXSIZE=100;

/*模板队列类
*/

template<typename T>
class Queue {
private:
	//队首，指向最先出队列的元素位置。
	int front;
	//队尾，指向下一次插入的新元素位置。
	int rear;
	//已经插入队列的元素个数。
	int count;
	//队列内保存元素的数组。
	T qList[MAXSIZE];
public:
	//构造函数
	Queue();
	//插入元素的函数
	bool QInsert(T& item);
	//弹出元素的函数
	T QDelete(void);
	//清空队列
	void QClear(void);
	//返回正在排队的元素个数。
	int QGetCount(void);
	//队列状态函数：是否为空。
	bool QEmpty();
	//队列状态函数：是否已满。
	bool QFull();
	//析构函数
	~Queue();
};

template<typename T>
Queue<T>::Queue() :front(0),rear(0),count(0){
}

template<typename T>
bool Queue<T>::QInsert(T& item){
	if (QFull()) {
		cout << "队列已满！插入失败！" << endl;
		return false;
	}
	else {
		count++;
		qList[rear] = item;
		rear = (rear + 1) % MAXSIZE;
		return true;
	}
}



template<typename T>
T Queue<T>::QDelete(void){
	
	if (QEmpty()) {
		cout << "队列是空的！非正常退出！" << endl;
		exit(1);
	}
	else {
		T temp = qList[front];
		count--;
		front = (front + 1) % MAXSIZE;
		
		return temp;
	}

}
template<typename T>
void Queue<T>::QClear(void){
	front = rear =count= 0;
}


template<typename T>
int Queue<T>::QGetCount(void) {
	return count;
}


template<typename T>
bool Queue<T>::QEmpty(){
	return count == 0;
}
template<typename T>
bool Queue<T>::QFull(){
	return count == MAXSIZE;
}

template<typename T>
Queue<T>::~Queue() {

}
//*****************************************************************************************

template<typename T>
BiTNode<T> *CreateBiTTreeFrom(BiTNode<T> *p);

template<typename T>
void DisplayBiTTree(BiTNode<T> *root);

template<typename T>
int GetDepth(BiTNode<T> *root);

template<typename T>
int CountDepth(BiTNode<T> *root);

template<typename T>
void CreateTree(T *arr, int left, int right, BiTNode<T> *p);

template<typename T>
void DeleteTree(BiTNode<T> *root);

int DisplayBinary_TestMain() {
	BiTNode<int> *root;
	BiTNode<int> *p = new BiTNode<int>;
	const int size = 9;
	int a[size];
	for (int i = 0;i < size;i++)
		a[i] = i + 10;
	p->data = a[size - 1];

	CreateTree<int>(a, 0, size - 2, p);

	root = CreateBiTTreeFrom<int>(p);
	DisplayBiTTree<int>(root);




	DeleteTree<int>(p);
	DeleteTree<int>(root);
	return 0;
}

//复制二叉树，按BiTNode结构类，添加深度、序号以及父节点等信息
template<typename T>
BiTNode<T> *CreateBiTTreeFrom(BiTNode<T> *p) {
	//复制p为根结点的树，并添加BiTNode相关变量信息。
	Queue<BiTNode<T> *> qbit;
	BiTNode<T> *root=NULL,*bitNode, *childNode;
	if (p) {
		//根结点复制
		root = new BiTNode<T>;
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
				childNode = new BiTNode<T>;
				childNode->data = bitNode->Lchild->data;
				childNode->depth = bitNode->depth + 1;
				childNode->parent = bitNode;
				//根据父节点的序号确定上一层元素的个数，从而可以确定当前节点在当前层的序号。
				//序号计算要包括父结点中不存在的左或右子节点的数量。序号不是指实际存在的同层节点的序号。
				childNode->order = childNode->parent->order * 2;
				childNode->Lchild = bitNode->Lchild->Lchild;

				childNode->Rchild = bitNode->Lchild->Rchild;

				bitNode->Lchild = childNode;
				qbit.QInsert(bitNode->Lchild);
			}
			//根据父结点，创建右子节点并添加相关信息。
			if (bitNode->Rchild) {

				childNode = new BiTNode<T>;
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
	return root;
}



//经过改造之后的二叉树的图形显示输出
template<typename T>
void DisplayBiTTree(BiTNode<T> *root) {

	//利用队列作为读取二叉树节点的工具
	Queue<BiTNode<T>*> qbit;
	//记录前后两个节点的指针
	BiTNode<T> *p, *pre;
	//需要显示的节点值的宽度。
	//偶数最佳，根据显示调节宽度。不宜太大。
	int deltawidth = 4;
	//整个二叉树的深度（最大层数）
	int treeDepth = GetDepth<T>(root);
	//根据二叉树最大一层可能存在的元素最多个数确定输出的最大宽度
	int maxwidth = deltawidth * pow(2, treeDepth - 1);
	//元素之间间距变量
	//二叉树每层元素以一定宽度输出后，在上述最大宽度输出范围内，剩余的元素之间的空白宽度
		//计算公式：（2^(最大层数-当前层数）-1）/2  ，其中层数从1开始。
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

			//单位间距变量（关键点！！！）
			//根据二叉树的层数（深度）和自定义设置的元素输出的单位宽度，
			//直接计算出元素之间的间距的单位量：元素之间的间距=2*distance.
			//每层的间距不一样，最大一层间距为0.即distance为0.
			distance = deltawidth * (pow(2, treeDepth - depth) - 1) / 2;
			//根结点所在层，即第一层单独设置输出宽度。
			//第一层：maxwidth=distance+节点(按一定单位的宽度输出)+distance.
			if (depth == 1) {
				cout.width(distance + deltawidth);
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
				//元素值输出时的宽度设置。
				cout.width(totalwidth);



			}



			//输出元素（节点）的值
			cout << p->data;
			//每个元素输出后的间距输出。最深一层（最大层）的间距为0，不输出。
			if (depth != treeDepth) {
				cout.width(2 * distance);

				cout << " ";
			}
			//如果是每层最后一个元素，就输出换行符。
			if (order == nodesNum - 1) {
				cout << endl;
				//设置换行符输出标志。
				flagEnter = 1;
			}



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


	}
}

//计算二叉树的深度
template<typename T>
int GetDepth(BiTNode<T> *root) {
	return CountDepth<T>(root);
}


//计算二叉树的深度
template<typename T>
int CountDepth(BiTNode<T> *root) {
	int leftdepth, rightdepth, maxdepth;
	if (root == NULL)
		return 0;
	leftdepth = CountDepth(root->Lchild);
	rightdepth = CountDepth(root->Rchild);
	maxdepth = leftdepth < rightdepth ? rightdepth : leftdepth;
	return maxdepth + 1;

}

//根据数组创建节点只有data,LChild,RChild数据的二叉树
template<typename T>
void CreateTree(T *arr, int left, int right, BiTNode<T> *p) {

	if (p) {

		if (left == right) {
			BiTNode<T> *newnode = new BiTNode<T>;
			newnode->data = arr[left];
			if (!p->Lchild)
				p->Lchild = newnode;
			else if (!p->Rchild)
				p->Rchild = newnode;
		}
		if (left < right) {
			int mid = (left + right) / 2;

			if (p->Lchild)
				CreateTree(arr, left, mid, p->Lchild);
			else
				CreateTree(arr, left, mid, p);

			if (p->Rchild)
				CreateTree(arr, mid + 1, right, p->Rchild);
			else
				CreateTree(arr, mid + 1, right, p);
		}




	}


}

template<typename T>
void DeleteTree(BiTNode<T> *root) {

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
