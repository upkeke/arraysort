#include "图.h"

namespace 图
{
}
namespace
{
	using namespace 图;

	// parent事先先将每个元素初始化为-1，当查到元素的父元素是-1时，返回自生
	int 查找点的根节点(vector<int>& parent, int p)
	{
		if (parent[p] == -1)
			return p;
		p = parent[p];
		return 查找点的根节点(parent, p);
	}
	
	bool 合并2棵树(vector<int>& parent, int p1, int p2)
	{
		int root1 = 查找点的根节点(parent, p1);
		int root2 = 查找点的根节点(parent, p2);
		if (root1 == root2) //2个点的根节点相同，形成环路
			return false;
		//没有形成环路，合并
		parent[root1] = root2;
	}
}
void 建立最小生成树Kruskal()
{
	using namespace 图;
	vector <vector<int>> data{
		{0,2,4,0},
		{2,0,3,5},
		{4,3,0,1},
		{0,5,1,0}
	};
	set<Line> 线段集合;
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (i >= j|| data[i][j]==0)
				continue;
			线段集合.emplace(i, j, data[i][j]);
		}
	}
	vector<int> parent(线段集合.size(), -1);
	int sum = 0;
	for (auto& line : 线段集合)
	{
		if (合并2棵树(parent, line.p1, line.p2))
		{
			cout << line.p1 << '\t' << line.p2 << "--" << line.val << endl;
			sum += line.val;
		}
	}
	cout <<"sum =" << sum;
}
//const vector <vector<int>> &data1
void 建立最小生成树Prim()
{
	using namespace 图;
	//vector <vector<int>> data{
	//	{0,2,4,0},
	//	{2,0,3,5},
	//	{4,3,0,1},
	//	{0,5,1,0}
	//};	
	vector <vector<int>> data{
		{0,3,0,0,0,4,0,0,0},
		{3,0,8,0,0,0,6,0,5},
		{0,8,0,12,0,0,0,0,2},
		{0,0,12,0,10,0,14,6,11},
		{0,0,0,10,0,18,0,1,0},
		{4,0,0,0,18,0,7,0,0},
		{0,6,0,14,0,7,0,9,0},
		{0,0,0,6,1,0,9,0,0},
		{0,5,2,11,0,0,0,0,0}
	};
	// 分为 A区和B区，A区是已经含有的节点，B区是没有包含的节点，flag是A区到B区某一个节点区域
	vector<PrimPoint> flag(data.size(), PrimPoint());
	int cur_point = 0;
	int sum = 0;
	cout <<">>>" << cur_point<<endl;

	for (size_t i = 0; i < data.size()-1; i++)
	{
		// i 点到j 点距离
		//自己被包含到A区，所以自己到A区的距离是0
		flag[cur_point].lowCost = 0;
		for (size_t j = 0; j < data.size(); j++)
		{
			if (data[cur_point][j] == 0)
			{
				continue;
			}
			if (flag[j].lowCost > data[cur_point][j])
			{
				flag[j].lowCost = data[cur_point][j];
				flag[j].point = cur_point;
			}
		}
		int min_cost = INT_MAX;
		//遍历找出lowCost最小的下标k，这个k就是要融入A区的那个节点
		for (size_t k = 0; k < flag.size(); k++)
		{
			if(flag[k].lowCost==0)
				continue;
			if (min_cost > flag[k].lowCost)
			{
				cur_point = k;
				min_cost = flag[k].lowCost;
			}
		}
		sum += min_cost;
		cout << flag[cur_point].point <<">>>" << cur_point << "---权重：" << min_cost << endl;
	}
	cout << "sum = " << sum;
}
