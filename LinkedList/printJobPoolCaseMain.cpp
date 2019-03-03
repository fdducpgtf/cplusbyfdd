
#include<iostream>
#include<thread>
#include<time.h>
#include<Windows.h>
#include "Spooler.h"


using namespace std;

//子线程调用函数
void updateThread(Spooler*, char*);


int printJobPoolCaseMain() {
	
	Spooler spool;
	int jnum;
	int jobno = 0;
	int rempages;

	char response = 'C';
	PrintJob j;
	thread t(updateThread,&spool,&response);
	t.detach();
	

	for (;;) {



		if (spool.NumberOfJobs() != 0) {

			cout << "Add(A) List(L) Check(C) Quit(Q):==>";
		}
		else {
			cout<< "Add(A) Quit(Q):==>";
		}
		cin >> response;
		switch (response)
		{
		case 'A':
			j.number = jobno++;
			cout << "filename:";
			cin >> j.filename;
			cout << "pages:";
			cin >> j.pagesize;
			spool._AddJob(j);

			break;


		case 'L':
			
			
			spool.ListJobs();
			break;


		case 'C':
			cout << "Enter job number:";
			cin >> jnum;
			rempages = spool.CheckJob(jnum);
			if(rempages==-1)
				cout << "你要找的job没有找到，可能编号错误或者已经完成任务退出了！哈哈！" << endl;
			else {
				if (rempages > 0) {
					cout << "Job in the queue:------>" << rempages << "  pages remain to print." << endl;
				}
				else {
					cout << "Job has completed!" << endl;
				}
			}
			break;
		case 'Q':
			break;

		default:
			cout << "Invalid spooler command. " << endl;
			break;
		}
	
		if (response == 'Q')
			break;

		
	}
	
	

	
	return 0;
}



//子线程调用函数（子线程参数传递至关重要）。
//用指针方式传递比较好。可以与主程序共享变量及状态。
void updateThread(Spooler *pspool, char *pc) {
	for (;;) {
		//设置子线程退出机制
		if (*pc == 'Y') {
			cout << "子线程就要退出了！" << endl;
			break;
		}

		//子线程循环执行任务
		if (pspool->NumberOfJobs() > 0)
			pspool->update();
		//pspool->ListJobs();
	//执行任务间隔：1000为1秒。
		Sleep(1000);

	}


}