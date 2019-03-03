#pragma once
#include <iostream>
#include<string>
using namespace std;

class Window {
private:
	string windowTitle;
	int windowNumber;
public:
	Window();
	Window(const string& title, int wnum);

	void ChangeTitle(const string& title);
	string GetTitle(void);
	int GetWindowNumber(void);

	bool operator==(const Window w);
	friend ostream& operator<<(ostream& ostr, const Window& w);

};

