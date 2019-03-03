#include<iostream>
#include "Queue.h"
#include<time.h>


using namespace std;
template<typename T>
void printArray(T *arr, int size);
//��radixSortCaseMain���������ÿ��ԣ�Main()������extern���������������
	//Ҳ���Ըĳ�Main()����ֱ��ʹ�á�
int radixSortCaseMain() {
	//�����������ö���ʵ�֡�10�����У����ܶ࣬Ҳ�����١�
	const int QUEUE_NUM = 10;
	//�������������������ֵ�λ�������� rand()����0-32767֮�����֣�
		//������λ��ֻ��5λ�ˣ�����������ֶ��ԣ���
	const int NUMBER_OF_DIGIT = 5;
	//�����������������������������ȷ���������λ�������á�
	const int  MODULAR_NUM = std::pow(10, NUMBER_OF_DIGIT);
	//������������ָ�����ע�ⲻҪ���������ܴ洢��Ԫ�ظ��������ֵ��
	const int size = MAXSIZE;
	//�洢�������ֵ����顣
	int number[size];
	//�̶���10������
	Queue<int> q[QUEUE_NUM];
	

	
	int i, j, n;

	//����������ӣ���֤ÿ�����в��������ֶ���һ����
	std::srand(time(0));
	for (i = 0;i < size;i++) {
		number[i] = std::rand() % MODULAR_NUM;
		
	}
	//����ǰ������
	printArray(number, size);

	//��������м�λ�������ż��Ρ�
	for (n = 0;n < NUMBER_OF_DIGIT;n++) {
		//ÿһ������˼·������ͬ�ġ���һ��ѭ����Ը�λ���֣�Ȼ������ʮλ����λ����

		//��һ�����ֱ���ݸ�λ��ʮλ����λ�����Ѷ�Ӧ���ַ����Ӧ�±�Ķ��������
			//�磺123��������3���Ͱ�123�Ž������±�Ϊ3�Ķ������档����q[3]�����������ƣ�
		for (i = 0;i < size;i++) {
			q[int(number[i] / std::pow(10, n)) % 10].QInsert(number[i]);
		}
	
		//�ڶ������������±�0��9��˳�����ΰ�ÿ����������ܰ���������ȫ��ȡ������
			//���ηŽ�ԭ����number[]�С�ֻ��ÿ������ȡ��֮�󣬲Ž�����һ������ȡ�����ݡ�
		for (i = 0,j = 0;i < 10;i++) {
			//�Ӷ���ȡ���ݡ����ڶ������ݵ�����ɾ��������ȡ��ȫ�����ݺ󣬲���ȥ��ն��С�
			while (!q[i].QEmpty()) {
				number[j++] = q[i].QDelete();
			}
			
		}

		
	}

	cout << "�����Ľ����" << endl;
	printArray(number, size);


	return 0;
}

//����������ݣ���ʱ�򾭳�ʹ�ã��ɴ����������ɣ�
template<typename T>
void printArray(T *arr, int size) {

	for (int i = 0;i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
