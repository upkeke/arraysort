#include "������.h"


namespace ������ {
	
	AVLTree* ����ƽ����()
	{
		//vector<int> ����������ظ���(int size);
		//vector<int> arr = ����������ظ���(10); // ���һ��sizeΪ11��vector

		vector<int> arr{ 5,40,43,51,55,65,70,83,96,100 };
		AVLTree* head = new AVLTree(arr);
		cout << "�������" << endl;
		head->�������();
		return head;
		//delete head;
	}
}
void ����������()
{
	using namespace ������;
	
	AVLTree* av = ����ƽ����();
	av->insert(1);
	av->�㼶����();
	cout << "���� 50 ��" << endl;
	av->insert(50);
	av->�㼶����();
	cout << "++++++++++++++++" << endl;
}