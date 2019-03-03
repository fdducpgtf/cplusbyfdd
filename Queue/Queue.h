#pragma once
using namespace std;


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