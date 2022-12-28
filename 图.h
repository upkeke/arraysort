#pragma once
#include "标头.h"

namespace 图
{
	struct Line
	{
		int p1;  //线段的起点
		int p2;  //线段的终点
		int val; //线段的权重
		Line(int _p1,int _p2,int _val):p1(_p1),p2(_p2),val(_val)
		{}
		bool operator<(const Line& othor)const
		{
			return val < othor.val;	
		}
	};

	// 搭配数组使用，数组个数是图的节点个数，数组下标index每个节点
	struct PrimPoint
	{
		int lowCost; // index节点到A	区的最小权重
		int point;  // 这个是A区的点，index到point才让lowCost最低
		PrimPoint(int _point = 0,int _lowCost=INT_MAX):
			point(_point),lowCost(_lowCost){}
	};
}

// 返回最小生成树的权重
void 建立最小生成树Kruskal();
void 建立最小生成树Prim();

