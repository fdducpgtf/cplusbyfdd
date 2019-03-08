#pragma once
#include<iostream>
using namespace std;



template<typename T>
struct HaffBiTNode
{
	T data;
	HaffBiTNode<T> *Lchild=NULL;
	HaffBiTNode<T> *Rchild = NULL;
	HaffBiTNode<T> *parent = NULL;

	friend ostream &operator<<(ostream &cout, HaffBiTNode<T>& hbit) {
		cout<<hbit.data;
		return cout;
	}

	bool operator<(const HaffBiTNode<T> &hbit) const  {


		return this->data < hbit.data;
	}

	bool operator<=(const HaffBiTNode<T> &hbit) const {


		return this->data <= hbit.data;
	}

	bool operator>(const HaffBiTNode<T> &hbit) const {


		return this->data > hbit.data;
	}

	bool operator>=(const HaffBiTNode<T> &hbit) const {


		return this->data >= hbit.data;
	}

	bool operator==(const HaffBiTNode<T> &hbit) const {


		return this->data == hbit.data;
	}

};

