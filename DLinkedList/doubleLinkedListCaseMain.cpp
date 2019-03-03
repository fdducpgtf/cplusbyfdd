#include<iostream>
#include "DLinkedList.h"
#include "../Stack/Stack.h"

using namespace std;

int doubleLinkedListCaseMain() {

	
	DLinkedList<int> dlist;
	int a[] = { 1,3,2,4,5,6,7,8,9,0};
	const int size =(sizeof a)/sizeof(int) ;
	
	for (int i = 0;i < size;i++) {
		dlist.InsertEnd(a[i]);
	}
	dlist.coutDList();

	dlist.Sort();
	dlist.coutDList();
	


	return 0;
}

