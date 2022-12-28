#pragma once
#include"标头.h"
template <typename T1, typename T2, unsigned M = 1>
class ATree
{
public:
	T2* p_val0;
	T1* left0;
	T1* right0;

	ATree(T1* h)
	{
		char* p = reinterpret_cast<char*>(h);
		p_val0 = nullptr;
		left0 = nullptr;
		right0 = nullptr;
		if (p != nullptr)
		{
			// M 为 val 在类的第几个成员
			switch (M)
			{
			case 1:
				p_val0 = reinterpret_cast<T2*>(p);
				p += 8;
				left0 = *(reinterpret_cast<T1**>(p));
				p += 8;
				right0 = *(reinterpret_cast<T1**>(p));
				break;
			case 2:
				left0 = *(reinterpret_cast<T1**>(p));
				p += 8;
				p_val0 = reinterpret_cast<T2*>(p);
				p += 8;
				right0 = *(reinterpret_cast<T1**>(p));
				break;
			case 3:
				left0 = *(reinterpret_cast<T1**>(p));
				p += 8;
				right0 = *(reinterpret_cast<T1**>(p));
				p += 8;
				p_val0 = reinterpret_cast<T2*>(p);
				break;
			default:
				break;
			}
		}
	}
	void print()
	{
		dpth = getdpth(this);
		vector<T2> v;
		getItemByBfs(this, v);
		int zichang = 1;
		int lenth = (1 << (dpth - 2)) * (3 * zichang + 4) + (1 << (dpth - 2)) * zichang - 1;
		queue<int> q;
		q.push(lenth / 2);
		int count = 1;
		int index = 0;
		for (int i = 0; i < dpth; ++i)
		{
			int ct = 0;
			int mid = q.front();
			int temp = q.front() / 2;
			for (int j = 0; j < lenth; ++j)
			{
				if (mid + temp + 1 == j)
				{
					q.push(mid - temp - 1);
					q.push(mid + temp + 1);
					q.pop();
					ct++;
					mid = q.front();
					if (ct >= count)
						break;
				}
				if (j > mid - temp - 1 && j < mid + temp + 1)
				{
					if (j == mid)
						cout << v[index++];

					else
						cout << '_';
				}
				else
					cout << ' ';
			}
			count *= 2;
			cout << endl;
		}
	}

private:
	int zichang = 1; //数字的最大长度
	int dpth = 0;	 //深度
	int getdpth(ATree* h)
	{
		if (h->p_val0 == nullptr)
			return 0;
		ATree t1 = ATree(h->left0);
		int left_dth = getdpth(&t1);
		ATree t2 = ATree(h->right0);
		int right_dth = getdpth(&t2);
		return std::max(left_dth, right_dth) + 1;
	}
	void getItemByBfs(ATree* h, vector<T2>& v)
	{
		std::queue<ATree*> q;
		q.push(h);
		std::function<void(ATree*)> Bfs = [&](ATree* a)
		{
			if (a->p_val0 == nullptr)
			{
				v.push_back(0);
				return;
			}
			else
				v.push_back(*(a->p_val0));
			q.pop();
			ATree t1 = ATree(a->left0);
			q.push(&t1);
			ATree t2 = ATree(a->right0);
			q.push(&t2);
			Bfs(q.front());
		};
		Bfs(h);
	}
};


struct Tree
{
	int val;
	Tree* left;
	Tree* right;
	Tree(int x) :val(x), left(nullptr), right(nullptr) {}
	Tree() :val(0), left(nullptr), right(nullptr) {}
	void print()
	{
		function<void(Tree*)> func = [&](Tree* h)
		{
			if (h != nullptr)
			{
				cout << h->val << '\t';
				func(h->left);
				func(h->right);
			}
		};
		func(this);
		cout << endl;
	}

};

Tree* initTree(const vector<int>& data);
void printLHRTree(Tree* head);
void arrayInsert();

#define xXx(x) ((x)*(x))
class Point
{
public:
	friend void testFunc();
	Point(int x=0, int y=0):x(x),y(y){}
	int 到点的距离(const Point&other)
	{
		if (&other == this) return 0;
		return xXx(x - other.x) + xXx(y - other.y);
	}
	bool operator<(const Point& other)
	{
		if (x < other.x) return true;
		else
		{
			if (x<other.x)
			{
				if (y < other.y) return true;
			}
			return false;
		}

		return false;
	}
private:
	int x;
	int y;
};
void 点到点();

void 排序测试();