#pragma once
#include "��ͷ.h"

namespace ͼ
{
	struct Line
	{
		int p1;  //�߶ε����
		int p2;  //�߶ε��յ�
		int val; //�߶ε�Ȩ��
		Line(int _p1,int _p2,int _val):p1(_p1),p2(_p2),val(_val)
		{}
		bool operator<(const Line& othor)const
		{
			return val < othor.val;	
		}
	};

	// ��������ʹ�ã����������ͼ�Ľڵ�����������±�indexÿ���ڵ�
	struct PrimPoint
	{
		int lowCost; // index�ڵ㵽A	������СȨ��
		int point;  // �����A���ĵ㣬index��point����lowCost���
		PrimPoint(int _point = 0,int _lowCost=INT_MAX):
			point(_point),lowCost(_lowCost){}
	};
}

// ������С��������Ȩ��
void ������С������Kruskal();
void ������С������Prim();

