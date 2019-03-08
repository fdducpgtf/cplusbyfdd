#include<iostream>
#include<list>
#include "HaffBiTNode.h"

using namespace std;

int CalculateWeight(HaffBiTNode<int> *hp);

int main() {
	
	list<HaffBiTNode<int>> mylist;
	const int n = 4;
	int weight[n] = { 2,4,5,7 };

	cout << "叶子节点：";
	for (int i = 0;i < n;i++) {
		HaffBiTNode<int> *temp = new HaffBiTNode<int>;
		temp->data = weight[i];
		mylist.push_front(*temp);
		cout << weight[i] << " ";
	}
	cout << endl;

	mylist.sort();
	
	HaffBiTNode<int> *p=NULL;
	list<HaffBiTNode<int>>::iterator it;
	while (mylist.size() < 2 * n - 1) {
		list<HaffBiTNode<int>>::iterator ita, itb;
		ita = mylist.begin();
		
		while ((*ita).parent) {
			ita++;
		}
		
		itb = ++ita;
		--ita;

		while ((*itb).parent) {
			itb++;
		}
		
		p = new HaffBiTNode<int>;
		p->data = (*ita).data + (*itb).data;
		p->Lchild = &(*ita);
		p->Rchild = &(*itb);
		(*ita).parent = p;
		(*itb).parent = p;
		
		
		
		for (it = mylist.begin();it != mylist.end();it++) {
			if (*it >= *p)
				break;
		}
		mylist.insert(it, *p);
		
	}

	cout << "霍夫曼树：";
	for (it = mylist.begin();it != mylist.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
	

	cout <<"霍夫曼树叶子节点权重:"<< CalculateWeight(p) << endl;

	return 0;
}

int CalculateWeight(HaffBiTNode<int> *hp) {
	static int depth = 0;
	if (hp) {

		if (!hp->Lchild && !hp->Rchild) {
			return hp->data*depth;
		}
		else if (!hp->Lchild&&hp->Rchild) {
			depth++;
			return CalculateWeight(hp->Rchild);
		}
		else if (hp->Lchild && !hp->Rchild) {
			depth++;
			return CalculateWeight(hp->Lchild);
		}
		else {
			depth++;
			return CalculateWeight(hp->Lchild) + CalculateWeight(hp->Rchild);
		}

	}
	else {
		return 0;
	}
}