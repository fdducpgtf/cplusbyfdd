#include<iostream>
#include "Queue.h"
#include <thread>
#include<Windows.h>
#include<iomanip>


using namespace std;



//���ö��߳��Զ����¶��У�
template<typename T>
void InsertCustomer(Queue<T> *q,int* cutomernum);


int queueTestCaseMain() {

	//ģ���ճ�Ӫҵ���Ŷӷ���

	Queue<int> queue;

	int customer = 500;
	//���ö��߳��Զ������ŶӶ��У�
	//����ָ��ʱҪע��������ڵ�ʱ�估��Χ����Ȼ������NULLָ��Ĵ���
	std::thread t(InsertCustomer<int>,&queue,&customer);
	t.detach();


	int exitflag = 0;
	int enter = 0;
	Sleep(100);
	for (;;) {
		//���û�����Ŷ��ˣ����ҵ�ǰ�Ŷӵ���Ҳ�Ѿ�û���˵Ļ����˳�ѭ�����°��ˣ���
		if (queue.QEmpty()&&(customer==-1)) {

			break;

		}
		else {
			//�������νкţ��ù˿͵���̨����ҵ��
			//�·�������Ӫҵ���кŵ���������������
			if (!queue.QEmpty()) {
				cout <<setw(4)<<"�˿�:"<<left<< setw(3)<<queue.QDelete() << setw(2) << "";
				enter++;
				if (enter > 10) {
					enter = 0;
					cout << endl;
				}
			}
			//��Ҫ����һ������һ������ģ��˿Ͱ���ҵ���ʱ�䡣
			Sleep(50);

			
			
		}
		
	}

	return 0;
}


//�������̣߳��Զ������ŶӵĹ˿�
template<typename T>
void InsertCustomer(Queue<T> *q, int *cutomernum) {
	//��ǰ���ź��ۼƼ�������̬������
	static int total = 1;
	//���������������ޣ�ģ�����Ӫҵ�����ܷ���Ĺ˿�û���ˣ�
	while (total <= *cutomernum) {
		//����Ŷӵ�λ���Ƿ��Ѿ�������û�����õȺ�������˽����Ŷӡ�
		//�����Ƕ��߳�ִ�У�������ȻҪ����ۼ������Ƿ񵽴�����(���Ƿ�û�����ˣ�
		while (!(q->QFull()) && (total <= *cutomernum)) {
			//������λ��ֱ���������ޣ���û�������������ˣ�
			if (q->QInsert(total)) {
				total++;
			}

		}
		//���������˳����̣߳���û�����˾��°��ˣ���
		if (total > *cutomernum) {
			//�޸Ĵ����ı������������߳��Ѿ�û�����Ŷ��ˡ�
			*cutomernum = -1;
			break;
		}
			

		//���߳���Ϣһ���������Һô�Ҳźã�
		Sleep(50);
	}
}