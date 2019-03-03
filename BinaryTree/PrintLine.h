#pragma once
#include<iostream>
#include "BiTNode.h"

using namespace std;


//每个节点（根结点除外）对应要输出的连接符号的类型
enum LineType { LRline ,RLline, Lline, Rline };

//定义与输出连接符号相关的结构类，主要用于定义输出连接符号的方法。
template<typename T>
struct PrintLine
{
	static const int DeltaWidth=4;
	static LineType GetLineType(BiTNode<T> *p);
	static void Print(int width, int deltawidth,int distance, LineType line);
};


//获取每个节点（根结点不需要）需要添加的连续符号的类型。
	//此类型在PintLine<T>::LineType中定义的。
template<typename T>
LineType PrintLine<T>::GetLineType(BiTNode<T> *p) {
	if (p->order % 2) {//order为偶数，说明为右节点。
		if (p->parent->Lchild) {
			return LineType::RLline;//当前为右节点，并且存在左节点。
		}
		else {
			return LineType::Rline;//当前为右节点，并且没有左节点。
		}
	}
	else {//order为奇数，说明为左节点。
		if (p->parent->Rchild) {
			return LineType::LRline;//当前为左节点，并且存在右节点。
		}
		else {
			return LineType::Lline;//当前为左节点，并且没有右节点。
		}
	}

}

//输出与某一层节点对应的连接符号。
	//输出如：v-----^-----v的连接符号，用于父节点与左右子节点之间的连接，直观显示它们的关系。
template<typename T>
void PrintLine<T>::Print(int width, int deltawidth, int distance, LineType line) {
	char childC = 118;//左或右节点对应的符号：v
	char parentC = 94;//父节点对应的符号：^
	char lineC = '-';//节点符号中间的连接符号
	char c;//输出时未用完的空间所使用的填充的符号
	
	switch (line)
	{
		//左右子节点都有时的左子节点
			//如果是左右节点中的左节点时，把左右节点对应的连接符号全部输出
			//如果是左右节点中的右节点时就什么也不做
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
		//只有左子节点的情况
	case Lline:
		cout.width(width);
		cout << childC;
		c=cout.fill(lineC);
		cout.width(distance + deltawidth / 2);
		cout << parentC;
		cout.fill(c);
		break;
		//左右子节点都有时的右子节点
	case RLline:
		
		break;
	
		//只有右子节点的情况
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