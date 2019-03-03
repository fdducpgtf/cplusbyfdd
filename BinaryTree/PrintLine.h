#pragma once
#include<iostream>
#include "BiTNode.h"

using namespace std;


//ÿ���ڵ㣨�������⣩��ӦҪ��������ӷ��ŵ�����
enum LineType { LRline ,RLline, Lline, Rline };

//������������ӷ�����صĽṹ�࣬��Ҫ���ڶ���������ӷ��ŵķ�����
template<typename T>
struct PrintLine
{
	static const int DeltaWidth=4;
	static LineType GetLineType(BiTNode<T> *p);
	static void Print(int width, int deltawidth,int distance, LineType line);
};


//��ȡÿ���ڵ㣨����㲻��Ҫ����Ҫ��ӵ��������ŵ����͡�
	//��������PintLine<T>::LineType�ж���ġ�
template<typename T>
LineType PrintLine<T>::GetLineType(BiTNode<T> *p) {
	if (p->order % 2) {//orderΪż����˵��Ϊ�ҽڵ㡣
		if (p->parent->Lchild) {
			return LineType::RLline;//��ǰΪ�ҽڵ㣬���Ҵ�����ڵ㡣
		}
		else {
			return LineType::Rline;//��ǰΪ�ҽڵ㣬����û����ڵ㡣
		}
	}
	else {//orderΪ������˵��Ϊ��ڵ㡣
		if (p->parent->Rchild) {
			return LineType::LRline;//��ǰΪ��ڵ㣬���Ҵ����ҽڵ㡣
		}
		else {
			return LineType::Lline;//��ǰΪ��ڵ㣬����û���ҽڵ㡣
		}
	}

}

//�����ĳһ��ڵ��Ӧ�����ӷ��š�
	//����磺v-----^-----v�����ӷ��ţ����ڸ��ڵ��������ӽڵ�֮������ӣ�ֱ����ʾ���ǵĹ�ϵ��
template<typename T>
void PrintLine<T>::Print(int width, int deltawidth, int distance, LineType line) {
	char childC = 118;//����ҽڵ��Ӧ�ķ��ţ�v
	char parentC = 94;//���ڵ��Ӧ�ķ��ţ�^
	char lineC = '-';//�ڵ�����м�����ӷ���
	char c;//���ʱδ����Ŀռ���ʹ�õ����ķ���
	
	switch (line)
	{
		//�����ӽڵ㶼��ʱ�����ӽڵ�
			//��������ҽڵ��е���ڵ�ʱ�������ҽڵ��Ӧ�����ӷ���ȫ�����
			//��������ҽڵ��е��ҽڵ�ʱ��ʲôҲ����
	case LRline:

		cout.width(width);
		cout << childC;
		c = cout.fill(lineC);
		cout.width(distance + deltawidth / 2);
		cout << parentC;
		cout.width(distance + deltawidth - deltawidth / 2);
		cout << childC;
		cout.fill(c);
		break;
		//ֻ�����ӽڵ�����
	case Lline:
		cout.width(width);
		cout << childC;
		c=cout.fill(lineC);
		cout.width(distance + deltawidth / 2);
		cout << parentC;
		cout.fill(c);
		break;
		//�����ӽڵ㶼��ʱ�����ӽڵ�
	case RLline:
		
		break;
	
		//ֻ�����ӽڵ�����
	case Rline:
		cout.width(width-deltawidth-distance+ deltawidth / 2);
		cout << parentC;
		cout.width(distance+deltawidth- deltawidth / 2);
		c = cout.fill(lineC);
		cout << childC;
		cout.fill(c);
		break;
	default:
		break;
	}
}