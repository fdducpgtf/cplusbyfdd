#include<iostream>
#include "../Stack/Stack.h"

using namespace std;

int stackTestCaseMain() {

	

	Stack<int> stack;
	cout << "请输入你要执行的命令的编号或者内容：" << endl;
	int order = -1;
	for (;;) {
		if (order > 5)
			break;
		cin >> order;
		switch (order)
		{
		case 0:
			stack.ClearStack();
			cout << "栈被清空了" << endl;
			break;
		case 1:
			int val;
			cout << "请输入你要进栈的数字：";
			cin >> val;
			if (!stack.StackFull()) {
				stack.Push(val);
			}
			else {
				cout << "栈已经满了！操作不成功。" << endl;
			}
			break;
		case 2:
			cout << "访问栈顶元素！" << endl;
			if (!stack.StackEmpty())
				cout << "栈顶值为：--->" << stack.Peek() << endl;
			else
				cout << "栈是空的，访问失败！" << endl;

			break;
		case 3:
			cout << "抛出栈顶元素！值为： -->";
			if (!stack.StackEmpty())
				cout << stack.Pop() << endl;
			else
				cout << endl << "栈是空的，抛出失败！" << endl;
			break;
		case 4:
			cout << "栈是否为空？--->" << stack.StackEmpty() << endl;
			break;
		case 5:
			cout << "栈是否已经满了？--->" << stack.StackFull() << endl;
			break;
		default:

			break;
		}


	}


	return 0;
}

