#pragma once
#include "Window.h"
#include "DLinkedList.h"



class WindowList {
private:
	DLinkedList<Window> windList;
	int windAvail[10];
	int windCount;
	int GetWindowNumber(void);
	int FindAndDelete(Window& wind);
	

public:
	WindowList(void);

	void New(void);
	void Close(void);
	void CloseAll(void);
	void SaveAs(const string& name);
	void Activate(int windownum);

	void SelectItem(int& item, string& name);
	void PintWindowList(void);



};


