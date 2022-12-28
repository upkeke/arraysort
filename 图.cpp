#include "ͼ.h"

namespace ͼ
{
}
namespace
{
	using namespace ͼ;

	// parent�����Ƚ�ÿ��Ԫ�س�ʼ��Ϊ-1�����鵽Ԫ�صĸ�Ԫ����-1ʱ����������
	int ���ҵ�ĸ��ڵ�(vector<int>& parent, int p)
	{
		if (parent[p] == -1)
			return p;
		p = parent[p];
		return ���ҵ�ĸ��ڵ�(parent, p);
	}
	
	bool �ϲ�2����(vector<int>& parent, int p1, int p2)
	{
		int root1 = ���ҵ�ĸ��ڵ�(parent, p1);
		int root2 = ���ҵ�ĸ��ڵ�(parent, p2);
		if (root1 == root2) //2����ĸ��ڵ���ͬ���γɻ�·
			return false;
		//û���γɻ�·���ϲ�
		parent[root1] = root2;
	}
}
void ������С������Kruskal()
{
	using namespace ͼ;
	vector <vector<int>> data{
		{0,2,4,0},
		{2,0,3,5},
		{4,3,0,1},
		{0,5,1,0}
	};
	set<Line> �߶μ���;
	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (i >= j|| data[i][j]==0)
				continue;
			�߶μ���.emplace(i, j, data[i][j]);
		}
	}
	vector<int> parent(�߶μ���.size(), -1);
	int sum = 0;
	for (auto& line : �߶μ���)
	{
		if (�ϲ�2����(parent, line.p1, line.p2))
		{
			cout << line.p1 << '\t' << line.p2 << "--" << line.val << endl;
			sum += line.val;
		}
	}
	cout <<"sum =" << sum;
}
//const vector <vector<int>> &data1
void ������С������Prim()
{
	using namespace ͼ;
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
	// ��Ϊ A����B����A�����Ѿ����еĽڵ㣬B����û�а����Ľڵ㣬flag��A����B��ĳһ���ڵ�����
	vector<PrimPoint> flag(data.size(), PrimPoint());
	int cur_point = 0;
	int sum = 0;
	cout <<">>>" << cur_point<<endl;

	for (size_t i = 0; i < data.size()-1; i++)
	{
		// i �㵽j �����
		//�Լ���������A���������Լ���A���ľ�����0
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
		//�����ҳ�lowCost��С���±�k�����k����Ҫ����A�����Ǹ��ڵ�
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
		cout << flag[cur_point].point <<">>>" << cur_point << "---Ȩ�أ�" << min_cost << endl;
	}
	cout << "sum = " << sum;
}
