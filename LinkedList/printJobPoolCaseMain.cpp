
#include<iostream>
#include<thread>
#include<time.h>
#include<Windows.h>
#include "Spooler.h"


using namespace std;

//���̵߳��ú���
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
				cout << "��Ҫ�ҵ�jobû���ҵ������ܱ�Ŵ�������Ѿ���������˳��ˣ�������" << endl;
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



//���̵߳��ú��������̲߳�������������Ҫ����
//��ָ�뷽ʽ���ݱȽϺá��������������������״̬��
void updateThread(Spooler *pspool, char *pc) {
	for (;;) {
		//�������߳��˳�����
		if (*pc == 'Y') {
			cout << "���߳̾�Ҫ�˳��ˣ�" << endl;
			break;
		}

		//���߳�ѭ��ִ������
		if (pspool->NumberOfJobs() > 0)
			pspool->update();
		//pspool->ListJobs();
	//ִ����������1000Ϊ1�롣
		Sleep(1000);

	}


}