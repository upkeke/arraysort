#pragma once
#include"��ͷ.h"

namespace ������{


	// �������������<��<��

	//����ƽ���� �κ�һ���ڵ�ĸ߶Ȳ�<=1��
	struct Tree
	{
		int val;
		Tree* left;
		Tree* right;
		Tree(int val = 0,
			Tree* left = nullptr,
			Tree* right = nullptr) :
			val(val), left(left), right(right) {}
		void �㼶����()
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
		void �������()
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
		void �ͷ����ڵ�(Tree* head)
		{
			if (head == nullptr)return;
			�ͷ����ڵ�(head->left);
			�ͷ����ڵ�(head->right);
			free(head);
		}

		~Tree()
		{
			�ͷ����ڵ�(left);
			�ͷ����ڵ�(right);
		}
	
	};
	class AVLTree
	{
	private:
		Tree* head;
		Tree* ʧ��� =nullptr;
		Tree ��ת��;
		Tree* _��ʼ�����������(const vector<int>& data, int lIndex, int rIndex)
		{
			if (lIndex > rIndex) return nullptr;
			int mIndex = (lIndex + rIndex) / 2;
			Tree* head = new Tree(data[mIndex]);
			head->left = _��ʼ�����������(data, lIndex, mIndex - 1);
			head->right = _��ʼ�����������(data, mIndex + 1, rIndex);
			return head;
		}
		//ƽ������ ���ӽڵ�ĸ߶ȼ����ӽڵ�ĸ߶�
		int _�ڵ�߶�(Tree* _head)
		{
			if (_head == nullptr) return 0;
			int left_h = _�ڵ�߶�(_head->left);
			int right_h = _�ڵ�߶�(_head->right);
			return std::max(left_h, right_h) + 1;
		}
		// �������������<��<��
		bool _insert(Tree* _head, int val)
		{
			if (_head->val == val)
			{
				return false;// ��������Ҫƽ��
			}
			Tree** temp = nullptr;
			if (_head->val > val)
				temp = &_head->left;
			else
				temp = &_head->right;
			if (*temp == nullptr)
			{
				*temp = new Tree(val);
				return true; //������Ҫ����ƽ��
			}
			else
				_insert(*temp, val);
		}
		// 1���ҵ��ڵ�˵������ƽ��, ��ʱ ʧ��㲻����nullptr
		// 2����ƽ���һ���ڸ��ڵ㵽���������·����
		void _���ʧ��ڵ�(Tree* _head,int val)
		{
			if (_head->val == val)return;
			if (_head == nullptr) return;
			if (_head->val > val) //��ǰֵ���ڲ���ڵ㣬����ڵ�����ߣ�
				_���ʧ��ڵ�(_head->left, val);
			else
				_���ʧ��ڵ�(_head->right, val);
			if (ʧ��� == nullptr) //�������ʧ���
			{
				int left_h = _�ڵ�߶�(_head->left);
				int right_h = _�ڵ�߶�(_head->right);
				if (abs(left_h - right_h) > 1)
					ʧ��� = _head;
			}
		}
		void _insert()
		{

		}
		void ����ƽ��()
		{

		}
	public:
		explicit AVLTree(Tree* head = nullptr):head(head), ��ת��(){}
		explicit AVLTree(vector<int> data):AVLTree()
		{
			std::sort(data.begin(), data.end());
			int rIndex = data.size()-1;
			head = _��ʼ�����������(data, 0, rIndex);
		}
		void insert(int val)
		{
			bool flag = _insert(head,val);
			if (flag)
			{
				ʧ��� = nullptr;
				_���ʧ��ڵ�(head, val);

				//�ҵ����ʧ����Ȼ���������������ķ����ռ��������ڵ�
				if (ʧ��� != nullptr)
					cout << "ʧ����ֵ��" << ʧ���->val << endl;
				else
					cout << "������������Ȼƽ��" << endl;
			}
			else
			{
				cout << "���������Ѿ������ֵ�ˣ�����Ҫ����" << endl;
			}
		}
		void �㼶����()
		{
			head->�㼶����();
		}
		void �������()
		{
			head->�������();
		}
		void test()
		{
			cout << _�ڵ�߶�(head) << endl;
			
		}
		~AVLTree()
		{
			delete head;
		}
	};

}

void ����������();


