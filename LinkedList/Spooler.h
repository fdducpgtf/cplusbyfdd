#pragma once
#include "LinkedList.h"



struct PrintJob
{
	int number;
	char filename[20];
	int pagesize;

};

const int PRINTSPEED = 8;

class Spooler
{
private:
	LinkedList<PrintJob> joblist;
	int deltatime;
	void UpdateSpooler(int time);
	
public:
	Spooler();
	
	void _AddJob(PrintJob j);
	int CheckJob(int jobno);
	void ListJobs(void);
	int NumberOfJobs(void);
	void update(void);
	~Spooler();
};

