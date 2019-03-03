#include "WindowList.h"


WindowList::WindowList() {
	windCount = 0;
	for (int i = 0;i < 10;i++) {
		windAvail[i] = 1;
	}
}


int WindowList::GetWindowNumber(void) {
	int i;
	for (i = 0;i < 10;i++) {
		if (windAvail[i]) {
			windAvail[i] = 0;
			break;
		}

	}
	return i;
}

void WindowList::PintWindowList(void) {
	if (windCount == 0) {
		cout << "当前没有任何窗口存在！" << endl;

	}
	else {


		for (DNode<Window> *p = windList.Head()->NextNodeRight();p != windList.Head();p = p->NextNodeRight()) {

			cout << p->data;
		}
	}
}

void WindowList::New(void) {
	if (windCount == 10) {
		cerr << "No more windows available until one is closed." << endl;

	}
	else {
		Window win("Untitled", GetWindowNumber());
		windList.InsertFront(win);
		windCount++;

	}
}

void WindowList::Close(void) {
	windList.DeleteFront();
	windCount--;
	windAvail[windCount] = 1;
}

void WindowList::CloseAll(void) {
	windList.ClearDList();
	windCount = 0;
	for (int i = 0;i < 10;i++) {
		windAvail[i] = 1;
	}
}

void WindowList::SaveAs(const string& name) {
	windList.Head()->NextNodeRight()->data.ChangeTitle(name);
}

int WindowList::FindAndDelete(Window& wind) {
	int retval;
	DNode<Window> *p;

	for (p = windList.Head()->NextNodeRight();p != windList.Head();p = p->NextNodeRight()) {
		if (wind.GetWindowNumber() == p->data.GetWindowNumber()) {
			break;
		}




	}

	if (p == windList.Head()) {
		retval = 0;

	}
	else {

		wind = p->data;
		p->DeleteDNode();
		windCount--;
		windAvail[windCount] = 1;
		retval = 1;
	}

	return retval;
}


void WindowList::Activate(int windownum) {
	Window win("Dummy Name", windownum);
	if (FindAndDelete(win)) {
		windList.InsertFront(win);
		windAvail[windCount] = 0;
		windCount++;
	}

	else
		cerr << "Incorrect window number." << endl;


}

void WindowList::SelectItem(int& item, string& name) {
	cout << "请输入你要执行的命令序号,名称：";
	cin >> item;

}


