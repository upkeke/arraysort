#include "二叉树.h"


namespace 二叉树 {
	
	AVLTree* 生成平衡树()
	{
		//vector<int> 获得数组无重复数(int size);
		//vector<int> arr = 获得数组无重复数(10); // 获得一个size为11的vector

		vector<int> arr{ 5,40,43,51,55,65,70,83,96,100 };
		AVLTree* head = new AVLTree(arr);
		cout << "中序遍历" << endl;
		head->中序遍历();
		return head;
		//delete head;
	}
}
void 二叉树测试()
{
	using namespace 二叉树;
	
	AVLTree* av = 生成平衡树();
	av->insert(1);
	av->层级遍历();
	cout << "插入 50 后" << endl;
	av->insert(50);
	av->层级遍历();
	cout << "++++++++++++++++" << endl;
}