#include "Window.h"

string Window::GetTitle(void) {
	return windowTitle;
}

ostream& operator<<(ostream& ostr, const Window& w) {
	ostr << w.windowTitle << ":" << w.windowNumber << endl;
	return ostr;
}


bool Window::operator==(const Window w) {
	return w.windowNumber == windowNumber;
}


int Window::GetWindowNumber(void) {
	return windowNumber;
}



void Window::ChangeTitle(const string& title) {
	windowTitle = title;
}




Window::Window(const string& title, int wnum) {
	windowTitle = title;
	windowNumber = wnum;
}

Window::Window() {
	windowTitle = "Untitled";
	windowNumber = 0;
}
