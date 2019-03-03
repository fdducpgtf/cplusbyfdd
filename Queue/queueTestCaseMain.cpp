#include<iostream>
#include "Queue.h"
#include <thread>
#include<Windows.h>
#include<iomanip>


using namespace std;



//运用多线程自动更新队列！
template<typename T>
void InsertCustomer(Queue<T> *q,int* cutomernum);


int queueTestCaseMain() {

	//模拟日常营业厅排队服务

	Queue<int> queue;

	int customer = 500;
	//运用多线程自动更新排队队列！
	//传递指针时要注意变量存在的时间及范围。不然会引发NULL指针的错误。
	std::thread t(InsertCustomer<int>,&queue,&customer);
	t.detach();


	int exitflag = 0;
	int enter = 0;
	Sleep(100);
	for (;;) {
		//如果没有人排队了，并且当前排队的人也已经没有了的话就退出循环（下班了！）
		if (queue.QEmpty()&&(customer==-1)) {

			break;

		}
		else {
			//否则，依次叫号，让顾客到柜台办理业务。
			//仿佛听到了营业厅叫号的声音……哈哈！
			if (!queue.QEmpty()) {
				cout <<setw(4)<<"顾客:"<<left<< setw(3)<<queue.QDelete() << setw(2) << "";
				enter++;
				if (enter > 10) {
					enter = 0;
					cout << endl;
				}
			}
			//不要急，一个接着一个来！模拟顾客办理业务的时间。
			Sleep(50);

			
			
		}
		
	}

	return 0;
}


//运用子线程，自动加载排队的顾客
template<typename T>
void InsertCustomer(Queue<T> *q, int *cutomernum) {
	//当前的排号累计计数（静态变量）
	static int total = 1;
	//当天人数超过上限（模拟进入营业厅接受服务的顾客没有了）
	while (total <= *cutomernum) {
		//检查排队的位置是否已经坐满，没满就让等候的其它人进来排队。
		//由于是多线程执行，所以仍然要检查累计人数是否到达上限(即是否没有人了）
		while (!(q->QFull()) && (total <= *cutomernum)) {
			//排满座位，直到到达上限（即没有其它的人来了）
			if (q->QInsert(total)) {
				total++;
			}

		}
		//超过上限退出此线程（即没有人了就下班了！）
		if (total > *cutomernum) {
			//修改传来的变量，告诉主线程已经没有人排队了。
			*cutomernum = -1;
			break;
		}
			

		//让线程休息一会儿！你好我好大家才好！
		Sleep(50);
	}
}