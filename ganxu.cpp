#include "ganxu.h"


Tree* initTree(const vector<int>& data)
{
	stack<Tree*> sk;
	Tree* head = nullptr;
	Tree** cur = &head;
	for (int i = 0; i < data.size(); ++i)
	{

		if (data[i] != -1)
		{
			*cur = new Tree(data[i]);
			sk.push(*cur);
			cur = &((*cur)->left);
		}
		else
		{
			if (sk.empty())
				continue;
			cur = &(sk.top()->right);
			sk.pop();
		}
	}
	return head;
}

void printLHRTree(Tree* head)
{
	if (head == nullptr) return;
	Tree* stack_[100];
	int top = 0;
	stack_[top] = head; //��ѹջ
	Tree** current = &head->left;
	int y = 0;
	while (top != -1||*current!=nullptr)
	{
		// ѹջ
		if (*current != nullptr)
		{
			stack_[++top] = *current;
			current = &stack_[top]->left;//-> ���� &
		}
		else
		{
			cout << stack_[top]->val << '\t'; 
			current = &stack_[top]->right;
			top--; //��ջ
		}

	}
}

void printLHRTree11(Tree* head)
{
	if (head == nullptr) return;
	Tree* stack_[100];
	int top = 0;
#if 0
	stack_[top] = head; //��ѹջ
	Tree* current = head->left;
	int y = 0;
	while (top != -1 || current != nullptr)
	{
		// ѹջ
		if (current != nullptr)
		{
			stack_[++top] = current;
			current = stack_[top]->left;//-> ���� &
		}
		else
		{
			cout << stack_[top]->val << '\t';
			current = stack_[top]->right;
			top--; //��ջ
		}
	}
#endif
	stack_[++top] = head;
	Tree* current = head;
	do
	{
		if (current->left != nullptr)
		{
			stack_[++top] = current->left;
			current = stack_[top];
		}
		else
		{
			cout << stack_[top]->val << '\t';
			top--;
			if (stack_[top+1]->right != nullptr)
			{
				current = stack_[top+1]->right;
				stack_[++top] = current;
			}
		}
	} while (top != 0||current!=nullptr);
	
}


static int ���ֲ���(int* arr, int size,int val)
{
	if (size == 0) return -1;
	//�����val�ĵ�һ���±�
	int left = -1;
	int right = size;
	while (left+1!=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] <= val)
			left = mid;
		else
			right = mid;
	}
	//right = right == -1 ? 0 : right;
	return right;
}
void arrayInsert()
{
	int arr[30]{ 0 };
	for (int i = 0; i < 30; ++i)
	{
		int val = 0;
		printf("����һ����\n���룺");
		scanf_s("%d", &val);
		if (i == 0)
			arr[0] = val;
		else
		{
			int index = ���ֲ���(arr, i, val);//�ҵ�arr�е�һ������temp���±�
			memcpy(arr + index + 1, arr + index, sizeof(int) * (i + 1 - index));
			arr[index] = val;
		}
		printf("������飺");
		for (int j = 0; j <= i; ++j)
		{
			printf("%d\t", arr[j]);
		}
		printf("\n\n");
	}

}

void �㵽��()
{
	cout << "�����ж��ٸ��� n" << endl;
	//int n;
	//std::cin >> n;
	vector<pair<int, int>> data = {
		{1,2},{3,3},{6,2},
		{5,0},{3,1}
	};
	vector<Point> arrP;
	for (auto da : data)
	{
		arrP.emplace_back(da.first, da.second);
	}
	Point& p1 = arrP[0];
	float Maxd = 0;

}


vector<int> getArray(int size)
{
	vector<int> arr(size, 0);
	srand(time(0));
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand() % 100;
	}
	return arr;
}
vector<int> ����������ظ���(int size)
{

	vector<int> re(size,0);

	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<unsigned> u(0, 100);
	int n = size;     
	set<int> temp;
	for (size_t i = 0;; )
	{
		int t = u(e);
		if (temp.count(t) > 0)
			continue;
		re[i] = t;
		temp.insert(t);
		++i;
		if (temp.size() == size)
			break;
	}
	return re;
}
namespace
{
	int ���н�(vector<int>& arr, int left, int right)
	{
		if (left == right) return left;
		int midVal = arr[right]; //��midVal Ϊ�н罫С�ڵ���midVal��������ߣ����ڵķ����ұ� //ȡrightҲ�������ұߵ�ֵΪ�м�ֵ
		int midIndex = left; //ʼ��ָ�����midVal�ĵ�һ���±�
		for (int i = left; i < right; ++i)
		{
			//������һ��ֵС��midVal�������ֵ��midIndexָ���ֵ������midIndex��һ��midIndex��Ȼָ���һ������midVal��ֵ
			if (arr[i] <= midVal)
			{
				std::swap(arr[i], arr[midIndex]);
				midIndex++;
			}
		}
		std::swap(arr[right], arr[midIndex]); //��rightָ���ֵ��midindex���������midIndexָ����м�ֵ
		return midIndex;
	}
	/// <summary>
	/// ���������±�mid�ֳ����룬mid���С��midָ��ֵ��mid�ұߴ���midָ���ֵ
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="left"></param>
	/// <param name="right"></param>
	void ��������(vector<int>& arr, int left, int right)
	{
		if (right <= left) return;
		int mid = ���н�(arr, left, right);
		��������(arr, left, mid - 1);
		��������(arr, mid + 1, right);
	}
}
namespace{
	//������ֳ�2��������ʹ��2�����鶼�����򣬺ϲ�����2������Ķ��ϵ�Ԫ�ض��Ǹ���������С��Ԫ�أ����߱Ƚϣ�ȡ2������С��ֵ�ŵ�Ŀ���������β
	//�ظ����沽�裬������õ������������
	void �ϲ�����(vector<int>& arr, int left1, int left2, int right)
	{
		vector<int> temp = arr; // ������Ƶ�������飬��ʵֻ�ø���left1 �� right������Ŀǰ��ôд����۲��㷨����
		int mid = left2;
		for (int i = left1; i <= right; ++i)
		{
			//���˵��һ��left2 > right���п���left2-right�ⲿ�ֶ�С��ǰһ���֣��������Ȱ��ⲿ�ַŵ�Ŀ���������ˣ�left2�Ѿ�Խ�磬���Ǻ�Ҳû��Ҫ�Ƚ� temp[left1] < temp[left2]
			//ֱ�Ӱ�ǰһ����ʣ������ŵ�Ŀ����������
			if (left2 > right||(left1 < mid && temp[left1] < temp[left2]))
			{
				arr[i] = temp[left1++];
				continue;
			}
			arr[i] = temp[left2++];
		}
	}
	void �鲢����(vector<int>& arr,int left,int right)
	{
		if (left >= right) return;
		int mid = (left + right) / 2;
		�鲢����(arr, left, mid); //������mid-1�������������ѭ��
		�鲢����(arr, mid+1, right); //������mid+1
		�ϲ�����(arr, left, mid+1, right);
	}
}
namespace
{
	/// <summary>
	/// ��begin�±�Ϊ��㣬stepsΪ���������������飬�����������в�������
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="begin">��������</param>
	/// <param name="steps">����</param>
	void _��������(vector<int>& arr,int begin,int steps)
	{
		for (int i = 1; i * steps < arr.size(); ++i)
		{
			int t = i;
			for (int j = i - 1; j >= 0; --j)
			{
				if (arr[j * steps] > arr[t * steps])
				{
					std::swap(arr[j * steps], arr[t * steps]);
					t = j;
				}
			}
		}
	}

	void ϣ������(vector<int>& arr)
	{
		int size = arr.size();
		int steps = size/2;
		while (steps!=0)
		{
			for (int i = 0; i < steps; ++i)
			{
				_��������(arr, i, steps);
			}
			steps /= 2;
		}
	}
}
namespace {
	/*
	������
	�±�Ϊi�Ľڵ�ĸ��ڵ���±�Ϊ (i-1)/2
	�±�Ϊi�Ľڵ�����ӽڵ��±�Ϊ i*2+1
	�±�Ϊi�Ľڵ�����ӽڵ��±�Ϊ i*2+2
	*/
	/// <summary>
	/// ���ָ��ڵ�����ӽڵ�,���ڵ�Ϊ���ֵ�����ú������
	/// </summary>
	/// <param name="arr">������</param>
	/// <param name="index">���ڵ�</param>
	/// <param name="index">��ǰ�ѵĽڵ�������������Ĵ�С</param>
	void ά���󶥶�(vector<int>& arr,int index,int size)
	{
		if (index >= size)
			return;
		int leftChild = index * 2 + 1; //��ڵ���±�
		int rightChild = index * 2 + 2;//�ҽڵ���±�
		ά���󶥶�(arr, leftChild, size);
		ά���󶥶�(arr, rightChild, size);
		int maxChild;
		if (rightChild < size)//�������ӽڵ�
			maxChild = arr[leftChild] > arr[rightChild] ? leftChild : rightChild;
		else if (leftChild < size)//û�����ӽڵ�
			maxChild = leftChild;
		else //û���ӽڵ�							 
			maxChild = index;
		if (arr[index] < arr[maxChild])
			std::swap(arr[index], arr[maxChild]);
	}
	/// <summary>
	/// ���� =�� �󶥶�
	/// </summary>
	/// <param name="arr">�����������</param>
	void ������(vector<int>& arr)
	{
		for (int i = arr.size() - 1; i > 0; --i)
		{
			ά���󶥶�(arr, 0, i + 1);
			std::swap(arr[i], arr[0]);
		}
	}
}
namespace
{
	// Ͱ����
	void _��������_Ͱ()
	{
		int x[10] = { 0 };
	}

	void Ͱ����(vector<int>& arr)
	{
		;
	}
}

void �������()
{
	vector<int> arr = getArray(10);
	cout << "���ԭ����" << endl;
	for (int i : arr)
		cout << i << '\t';
	cout << endl;
	//��������(arr, 0, arr.size() - 1); //��������
	//�鲢����(arr, 0, arr.size() - 1);  //�鲢����
	//ϣ������(arr);
	������(arr);

	cout << "������������" << endl;
	for (int i : arr)
		cout << i << '\t';
}

void testFunc()
{
	Point p(10, 12);
	cout << p.x << endl;
	function<void(void)> func = [&]() {
		cout << "in func" << endl;
		cout << p.x << endl;
		Point p1(70, 12);
		cout << p1.x << endl;
	};
	func();
}