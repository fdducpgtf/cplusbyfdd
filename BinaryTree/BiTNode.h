#pragma once
template<typename T>
struct BiTNode {
	BiTNode<T> *Lchild=NULL, *Rchild=NULL,*parent=NULL;
	T data;
	int depth=0;
	int order = 0;
};
