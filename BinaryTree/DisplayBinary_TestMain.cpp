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
//������Ԫ����������
static const int MAXSIZE=100;

/*ģ�������
*/

template<typename T>
class Queue {
private:
	//���ף�ָ�����ȳ����е�Ԫ��λ�á�
	int front;
	//��β��ָ����һ�β������Ԫ��λ�á�
	int rear;
	//�Ѿ�������е�Ԫ�ظ�����
	int count;
	//�����ڱ���Ԫ�ص����顣
	T qList[MAXSIZE];
public:
	//���캯��
	Queue();
	//����Ԫ�صĺ���
	bool QInsert(T& item);
	//����Ԫ�صĺ���
	T QDelete(void);
	//��ն���
	void QClear(void);
	//���������Ŷӵ�Ԫ�ظ�����
	int QGetCount(void);
	//����״̬�������Ƿ�Ϊ�ա�
	bool QEmpty();
	//����״̬�������Ƿ�������
	bool QFull();
	//��������
	~Queue();
};

template<typename T>
Queue<T>::Queue() :front(0),rear(0),count(0){
}

template<typename T>
bool Queue<T>::QInsert(T& item){
	if (QFull()) {
		cout << "��������������ʧ�ܣ�" << endl;
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
		cout << "�����ǿյģ��������˳���" << endl;
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

//���ƶ���������BiTNode�ṹ�࣬�����ȡ�����Լ����ڵ����Ϣ
template<typename T>
BiTNode<T> *CreateBiTTreeFrom(BiTNode<T> *p) {
	//����pΪ���������������BiTNode��ر�����Ϣ��
	Queue<BiTNode<T> *> qbit;
	BiTNode<T> *root=NULL,*bitNode, *childNode;
	if (p) {
		//����㸴��
		root = new BiTNode<T>;
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
				childNode = new BiTNode<T>;
				childNode->data = bitNode->Lchild->data;
				childNode->depth = bitNode->depth + 1;
				childNode->parent = bitNode;
				//���ݸ��ڵ�����ȷ����һ��Ԫ�صĸ������Ӷ�����ȷ����ǰ�ڵ��ڵ�ǰ�����š�
				//��ż���Ҫ����������в����ڵ�������ӽڵ����������Ų���ָʵ�ʴ��ڵ�ͬ��ڵ����š�
				childNode->order = childNode->parent->order * 2;
				childNode->Lchild = bitNode->Lchild->Lchild;

				childNode->Rchild = bitNode->Lchild->Rchild;

				bitNode->Lchild = childNode;
				qbit.QInsert(bitNode->Lchild);
			}
			//���ݸ���㣬�������ӽڵ㲢��������Ϣ��
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



//��������֮��Ķ�������ͼ����ʾ���
template<typename T>
void DisplayBiTTree(BiTNode<T> *root) {

	//���ö�����Ϊ��ȡ�������ڵ�Ĺ���
	Queue<BiTNode<T>*> qbit;
	//��¼ǰ�������ڵ��ָ��
	BiTNode<T> *p, *pre;
	//��Ҫ��ʾ�Ľڵ�ֵ�Ŀ�ȡ�
	//ż����ѣ�������ʾ���ڿ�ȡ�����̫��
	int deltawidth = 4;
	//��������������ȣ���������
	int treeDepth = GetDepth<T>(root);
	//���ݶ��������һ����ܴ��ڵ�Ԫ��������ȷ������������
	int maxwidth = deltawidth * pow(2, treeDepth - 1);
	//Ԫ��֮�������
	//������ÿ��Ԫ����һ��������������������������Χ�ڣ�ʣ���Ԫ��֮��Ŀհ׿��
		//���㹫ʽ����2^(������-��ǰ������-1��/2  �����в�����1��ʼ��
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

			//��λ���������ؼ��㣡������
			//���ݶ������Ĳ�������ȣ����Զ������õ�Ԫ������ĵ�λ��ȣ�
			//ֱ�Ӽ����Ԫ��֮��ļ��ĵ�λ����Ԫ��֮��ļ��=2*distance.
			//ÿ��ļ�಻һ�������һ����Ϊ0.��distanceΪ0.
			distance = deltawidth * (pow(2, treeDepth - depth) - 1) / 2;
			//��������ڲ㣬����һ�㵥�����������ȡ�
			//��һ�㣺maxwidth=distance+�ڵ�(��һ����λ�Ŀ�����)+distance.
			if (depth == 1) {
				cout.width(distance + deltawidth);
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
				//Ԫ��ֵ���ʱ�Ŀ�����á�
				cout.width(totalwidth);



			}



			//���Ԫ�أ��ڵ㣩��ֵ
			cout << p->data;
			//ÿ��Ԫ�������ļ�����������һ�㣨���㣩�ļ��Ϊ0���������
			if (depth != treeDepth) {
				cout.width(2 * distance);

				cout << " ";
			}
			//�����ÿ�����һ��Ԫ�أ���������з���
			if (order == nodesNum - 1) {
				cout << endl;
				//���û��з������־��
				flagEnter = 1;
			}



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


	}
}

//��������������
template<typename T>
int GetDepth(BiTNode<T> *root) {
	return CountDepth<T>(root);
}


//��������������
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

//�������鴴���ڵ�ֻ��data,LChild,RChild���ݵĶ�����
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
