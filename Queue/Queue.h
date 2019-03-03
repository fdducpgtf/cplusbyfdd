#pragma once
using namespace std;


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