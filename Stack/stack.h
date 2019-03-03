#pragma once
using namespace std;



static const unsigned MAX = 10;
template<typename T>
class Stack
{
private:
	T stackList[MAX];
	int top;
public:
	
	
	Stack();
	void Push(const T& item);
	T Pop(void);
	T Peek(void) const;

	void ClearStack(void);
	int StackEmpty(void) const;
	int StackFull(void) const;


	~Stack();
};


template<typename T>
Stack<T>::Stack(){
	top = -1;
}
template<typename T>
void Stack<T>::Push(const T& item){
	if (top == MAX - 1) {
		cerr << "Stack overflow!" << endl;
		exit(1);
	}
		
	top++;
	stackList[top] = item;
}
template<typename T>
T Stack<T>::Pop(void){
	if (top == -1) {
		cerr << "Attempt to an empty stack!" << endl;
		exit(1);
	}
		
	return stackList[top--];
}
template<typename T>
T Stack<T>::Peek(void) const{
	if (top == -1) {
		cerr << "空栈！无法返回任何值！" << endl;
		exit(1);
	}
	return stackList[top];
}

template<typename T>
void Stack<T>::ClearStack(void){
	top = -1;

}
template<typename T>
int Stack<T>::StackEmpty(void) const{
	return top == -1;
}
template<typename T>
int Stack<T>::StackFull(void) const{
	return top == MAX - 1;
}


template<typename T>
Stack<T>::~Stack(){
}

