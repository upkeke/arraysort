#pragma once
#include"标头.h"

namespace 二叉树{


	// 二叉查找树，左<中<右

	//二叉平衡树 任何一个节点的高度差<=1；
	struct Tree
	{
		int val;
		Tree* left;
		Tree* right;
		Tree(int val = 0,
			Tree* left = nullptr,
			Tree* right = nullptr) :
			val(val), left(left), right(right) {}
		void 层级遍历()
		{
			////http://520it.com/binarytrees/
			queue<Tree*> qu;
			qu.push(this);
			while (!qu.empty())
			{
				auto h = qu.front();
				cout << h->val << ',';
				qu.pop();
				if (h->left != nullptr)
					qu.push(h->left);
				if (h->right != nullptr)
					qu.push(h->right);
			}
			cout << endl;
		}
		void 中序遍历()
		{
			function<void(Tree*)> func = [&](Tree* head)
			{
				if (head == nullptr) return;
				func(head->left);
				cout << head->val << '\t';
				func(head->right);
			};
			func(this);
			cout << endl;
		}
		void 释放树节点(Tree* head)
		{
			if (head == nullptr)return;
			释放树节点(head->left);
			释放树节点(head->right);
			free(head);
		}

		~Tree()
		{
			释放树节点(left);
			释放树节点(right);
		}
	
	};
	class AVLTree
	{
	private:
		Tree* head;
		Tree* 失衡点 =nullptr;
		Tree 中转点;
		Tree* _初始化二叉查找树(const vector<int>& data, int lIndex, int rIndex)
		{
			if (lIndex > rIndex) return nullptr;
			int mIndex = (lIndex + rIndex) / 2;
			Tree* head = new Tree(data[mIndex]);
			head->left = _初始化二叉查找树(data, lIndex, mIndex - 1);
			head->right = _初始化二叉查找树(data, mIndex + 1, rIndex);
			return head;
		}
		//平衡因子 左子节点的高度减右子节点的高度
		int _节点高度(Tree* _head)
		{
			if (_head == nullptr) return 0;
			int left_h = _节点高度(_head->left);
			int right_h = _节点高度(_head->right);
			return std::max(left_h, right_h) + 1;
		}
		// 二叉查找树，左<中<右
		bool _insert(Tree* _head, int val)
		{
			if (_head->val == val)
			{
				return false;// 后续不需要平衡
			}
			Tree** temp = nullptr;
			if (_head->val > val)
				temp = &_head->left;
			else
				temp = &_head->right;
			if (*temp == nullptr)
			{
				*temp = new Tree(val);
				return true; //后续需要进行平衡
			}
			else
				_insert(*temp, val);
		}
		// 1）找到节点说明树不平衡, 此时 失衡点不等于nullptr
		// 2）不平衡点一定在根节点到插入这个点路径上
		void _获得失衡节点(Tree* _head,int val)
		{
			if (_head->val == val)return;
			if (_head == nullptr) return;
			if (_head->val > val) //当前值大于插入节点，插入节点在左边，
				_获得失衡节点(_head->left, val);
			else
				_获得失衡节点(_head->right, val);
			if (失衡点 == nullptr) //到最深处的失衡点
			{
				int left_h = _节点高度(_head->left);
				int right_h = _节点高度(_head->right);
				if (abs(left_h - right_h) > 1)
					失衡点 = _head;
			}
		}
		void _insert()
		{

		}
		void 保持平衡()
		{

		}
	public:
		explicit AVLTree(Tree* head = nullptr):head(head), 中转点(){}
		explicit AVLTree(vector<int> data):AVLTree()
		{
			std::sort(data.begin(), data.end());
			int rIndex = data.size()-1;
			head = _初始化二叉查找树(data, 0, rIndex);
		}
		void insert(int val)
		{
			bool flag = _insert(head,val);
			if (flag)
			{
				失衡点 = nullptr;
				_获得失衡节点(head, val);

				//找到这个失衡点后，然后沿着它往插入点的方向收集三个树节点
				if (失衡点 != nullptr)
					cout << "失衡点的值：" << 失衡点->val << endl;
				else
					cout << "插入后二叉树依然平衡" << endl;
			}
			else
			{
				cout << "二叉树中已经有这个值了，不需要插入" << endl;
			}
		}
		void 层级遍历()
		{
			head->层级遍历();
		}
		void 中序遍历()
		{
			head->中序遍历();
		}
		void test()
		{
			cout << _节点高度(head) << endl;
			
		}
		~AVLTree()
		{
			delete head;
		}
	};

}

void 二叉树测试();


