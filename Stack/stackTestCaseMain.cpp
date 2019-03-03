#include<iostream>
#include "../Stack/Stack.h"

using namespace std;

int stackTestCaseMain() {

	

	Stack<int> stack;
	cout << "��������Ҫִ�е�����ı�Ż������ݣ�" << endl;
	int order = -1;
	for (;;) {
		if (order > 5)
			break;
		cin >> order;
		switch (order)
		{
		case 0:
			stack.ClearStack();
			cout << "ջ�������" << endl;
			break;
		case 1:
			int val;
			cout << "��������Ҫ��ջ�����֣�";
			cin >> val;
			if (!stack.StackFull()) {
				stack.Push(val);
			}
			else {
				cout << "ջ�Ѿ����ˣ��������ɹ���" << endl;
			}
			break;
		case 2:
			cout << "����ջ��Ԫ�أ�" << endl;
			if (!stack.StackEmpty())
				cout << "ջ��ֵΪ��--->" << stack.Peek() << endl;
			else
				cout << "ջ�ǿյģ�����ʧ�ܣ�" << endl;

			break;
		case 3:
			cout << "�׳�ջ��Ԫ�أ�ֵΪ�� -->";
			if (!stack.StackEmpty())
				cout << stack.Pop() << endl;
			else
				cout << endl << "ջ�ǿյģ��׳�ʧ�ܣ�" << endl;
			break;
		case 4:
			cout << "ջ�Ƿ�Ϊ�գ�--->" << stack.StackEmpty() << endl;
			break;
		case 5:
			cout << "ջ�Ƿ��Ѿ����ˣ�--->" << stack.StackFull() << endl;
			break;
		default:

			break;
		}


	}


	return 0;
}

