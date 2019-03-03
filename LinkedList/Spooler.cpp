#include "Spooler.h"
#include<time.h>	


Spooler::Spooler()
{
	std::srand(int(time(0)));
	this->deltatime = std::rand() % 5 + 1;
	cout << "deltatime:" << this->deltatime << endl;
}

void Spooler::UpdateSpooler(int time) {
	PrintJob j;
	int PrintedPaged = time * PRINTSPEED;
	//����
	this->joblist.ResetPosition();
	while (!this->joblist.ListEmpty() && PrintedPaged > 0) {
		j = this->joblist.Data();
		if (PrintedPaged >= j.pagesize) {
			PrintedPaged -= j.pagesize;
			this->joblist.DeleteFront();
			cout << "����" << j.filename << "�Ѿ���ӡ��ϣ�" << endl;
		}
		else {
			j.pagesize -= PrintedPaged;
			PrintedPaged = 0;
			this->joblist.Data() = j;
		}

	}
}

void Spooler::update(void) {
	this->UpdateSpooler(this->deltatime);
	this->deltatime = 1 + std::rand() % 5;
}

//����PintJob�ṹ�������
void Spooler::_AddJob(PrintJob j) {
	this->joblist.InsertBack(j);
}



int Spooler::CheckJob(int jobno) {
	PrintJob j;
	
	this->UpdateSpooler(this->deltatime);

	for (joblist.ResetPosition();!joblist.EndOfList();joblist.Next()) {
		j = joblist.Data();
		if (j.number == jobno)
			break;
	}
	if (joblist.EndOfList()) {
		
		return -1;
	}
	return j.pagesize;

	
}
void Spooler::ListJobs(void) {
	PrintJob j;
	this->UpdateSpooler(this->deltatime);
	this->deltatime = 1 + std::rand() % 5;
	if (this->joblist.ListSize() == 0) {
		cout << "��ӡ�����Ѿ�ȫ����ɣ�" << endl;
	}
	else {
		
		for (this->joblist.ResetPosition();!this->joblist.EndOfList();this->joblist.Next()) {
			j = this->joblist.Data();
			cout << "Job--->��ţ�" << j.number << ";   ���֣�" << j.filename << "     " << j.pagesize << "  Pages Remaining." << endl;
		}
	}

}



//��������
int Spooler::NumberOfJobs(void) {
	return this->joblist.ListSize();
}


Spooler::~Spooler()
{
}
