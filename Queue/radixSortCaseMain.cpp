#include<iostream>
#include "Queue.h"
#include<time.h>


using namespace std;
template<typename T>
void printArray(T *arr, int size);
//把radixSortCaseMain当作函数用可以（Main()外面用extern声明这个函数），
	//也可以改成Main()函数直接使用。
int radixSortCaseMain() {
	//基数排序，利用队列实现。10个队列，不能多，也不能少。
	const int QUEUE_NUM = 10;
	//参与排序的最大整数数字的位数。由于 rand()产生0-32767之间数字，
		//因此最大位置只有5位了（随机产生数字而言）！
	const int NUMBER_OF_DIGIT = 5;
	//如果排序的数字随机产生，设置它以确保符合最大位数的设置。
	const int  MODULAR_NUM = std::pow(10, NUMBER_OF_DIGIT);
	//参与排序的数字个数。注意不要超过队列能存储的元素个数的最大值。
	const int size = MAXSIZE;
	//存储排序数字的数组。
	int number[size];
	//固定的10个队列
	Queue<int> q[QUEUE_NUM];
	

	
	int i, j, n;

	//设置随机种子，保证每次运行产生的数字都不一样。
	std::srand(time(0));
	for (i = 0;i < size;i++) {
		number[i] = std::rand() % MODULAR_NUM;
		
	}
	//排序前的数字
	printArray(number, size);

	//最大数字有几位数，就排几次。
	for (n = 0;n < NUMBER_OF_DIGIT;n++) {
		//每一次排序思路都是相同的。第一次循环针对个位数字，然后依次十位、百位……

		//第一步：分别根据个位、十位、百位……把对应数字放入对应下标的队列数组里。
			//如：123，个数是3，就把123放进队列下标为3的队列里面。即：q[3]……其它类似！
		for (i = 0;i < size;i++) {
			q[int(number[i] / std::pow(10, n)) % 10].QInsert(number[i]);
		}
	
		//第二步：按队列下标0到9的顺序，依次把每个队列里可能包含的数据全部取出来，
			//依次放进原数组number[]中。只有每个队列取完之后，才进行下一个队列取出数据。
		for (i = 0,j = 0;i < 10;i++) {
			//从队列取数据。由于队列数据弹出即删除，所以取出全部数据后，不必去清空队列。
			while (!q[i].QEmpty()) {
				number[j++] = q[i].QDelete();
			}
			
		}

		
	}

	cout << "排序后的结果：" << endl;
	printArray(number, size);


	return 0;
}

//输出数组数据，有时候经常使用，干脆整个函数吧！
template<typename T>
void printArray(T *arr, int size) {

	for (int i = 0;i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
