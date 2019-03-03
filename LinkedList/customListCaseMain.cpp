#include<iostream>
#include<time.h>
#include<string>
#include "LinkedList.cpp"
using namespace std;




int customListCaseMain() {



	//cout << "This is customListCaseMain()." << endl;
	
	LinkedList<int> mylist;
	
	for (int i = 0;i <15;i++) {
		mylist.InsertBack(i);
		
	}
	
	mylist.CoutLinkedList();
	
	
	return 0;
}