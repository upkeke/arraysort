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
	stack_[top] = head; //先压栈
	Tree** current = &head->left;
	int y = 0;
	while (top != -1||*current!=nullptr)
	{
		// 压栈
		if (*current != nullptr)
		{
			stack_[++top] = *current;
			current = &stack_[top]->left;//-> 大于 &
		}
		else
		{
			cout << stack_[top]->val << '\t'; 
			current = &stack_[top]->right;
			top--; //弹栈
		}

	}
}

void printLHRTree11(Tree* head)
{
	if (head == nullptr) return;
	Tree* stack_[100];
	int top = 0;
#if 0
	stack_[top] = head; //先压栈
	Tree* current = head->left;
	int y = 0;
	while (top != -1 || current != nullptr)
	{
		// 压栈
		if (current != nullptr)
		{
			stack_[++top] = current;
			current = stack_[top]->left;//-> 大于 &
		}
		else
		{
			cout << stack_[top]->val << '\t';
			current = stack_[top]->right;
			top--; //弹栈
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


static int 二分查找(int* arr, int size,int val)
{
	if (size == 0) return -1;
	//求大于val的第一个下标
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
		printf("输入一个数\n输入：");
		scanf_s("%d", &val);
		if (i == 0)
			arr[0] = val;
		else
		{
			int index = 二分查找(arr, i, val);//找到arr中第一个大于temp的下标
			memcpy(arr + index + 1, arr + index, sizeof(int) * (i + 1 - index));
			arr[index] = val;
		}
		printf("输出数组：");
		for (int j = 0; j <= i; ++j)
		{
			printf("%d\t", arr[j]);
		}
		printf("\n\n");
	}

}

void 点到点()
{
	cout << "输入有多少个点 n" << endl;
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
vector<int> 获得数组无重复数(int size)
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
	int 分中界(vector<int>& arr, int left, int right)
	{
		if (left == right) return left;
		int midVal = arr[right]; //以midVal 为中界将小于等于midVal放在其左边，大于的放在右边 //取right也就是最右边的值为中间值
		int midIndex = left; //始终指向大于midVal的第一个下标
		for (int i = left; i < right; ++i)
		{
			//遍历到一个值小于midVal，将这个值和midIndex指向的值交换，midIndex加一，midIndex依然指向第一个大于midVal的值
			if (arr[i] <= midVal)
			{
				std::swap(arr[i], arr[midIndex]);
				midIndex++;
			}
		}
		std::swap(arr[right], arr[midIndex]); //将right指向的值和midindex交换，最后midIndex指向的中间值
		return midIndex;
	}
	/// <summary>
	/// 将数组以下标mid分成两半，mid左边小于mid指的值，mid右边大于mid指向的值
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="left"></param>
	/// <param name="right"></param>
	void 快速排序(vector<int>& arr, int left, int right)
	{
		if (right <= left) return;
		int mid = 分中界(arr, left, right);
		快速排序(arr, left, mid - 1);
		快速排序(arr, mid + 1, right);
	}
}
namespace{
	//将数组分成2拨，并且使得2拨数组都是有序，合并方法2个数组的顶上的元素都是各自组内最小的元素，二者比较，取2个中最小的值放到目标数组的首尾
	//重复上面步骤，最后所得的数组是有序的
	void 合并数组(vector<int>& arr, int left1, int left2, int right)
	{
		vector<int> temp = arr; // 这儿复制的这个数组，其实只用复制left1 到 right，但是目前这么写方便观察算法过程
		int mid = left2;
		for (int i = left1; i <= right; ++i)
		{
			//这儿说明一下left2 > right，有可能left2-right这部分都小于前一部分，这样就先把这部分放到目标数组中了，left2已经越界，这是后也没必要比较 temp[left1] < temp[left2]
			//直接把前一部分剩余的数放到目标数组里面
			if (left2 > right||(left1 < mid && temp[left1] < temp[left2]))
			{
				arr[i] = temp[left1++];
				continue;
			}
			arr[i] = temp[left2++];
		}
	}
	void 归并排序(vector<int>& arr,int left,int right)
	{
		if (left >= right) return;
		int mid = (left + right) / 2;
		归并排序(arr, left, mid); //不能是mid-1，否则会陷入死循环
		归并排序(arr, mid+1, right); //必须是mid+1
		合并数组(arr, left, mid+1, right);
	}
}
namespace
{
	/// <summary>
	/// 以begin下标为起点，steps为步数，建立的数组，对这个数组进行插入排序
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="begin">数组的起点</param>
	/// <param name="steps">步数</param>
	void _插入排序(vector<int>& arr,int begin,int steps)
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

	void 希尔排序(vector<int>& arr)
	{
		int size = arr.size();
		int steps = size/2;
		while (steps!=0)
		{
			for (int i = 0; i < steps; ++i)
			{
				_插入排序(arr, i, steps);
			}
			steps /= 2;
		}
	}
}
namespace {
	/*
	堆排序
	下标为i的节点的父节点的下标为 (i-1)/2
	下标为i的节点的左子节点下标为 i*2+1
	下标为i的节点的左子节点下标为 i*2+2
	*/
	/// <summary>
	/// 保持父节点大于子节点,根节点为最大值，采用后序遍历
	/// </summary>
	/// <param name="arr">堆数组</param>
	/// <param name="index">父节点</param>
	/// <param name="index">当前堆的节点数，不是数组的大小</param>
	void 维护大顶堆(vector<int>& arr,int index,int size)
	{
		if (index >= size)
			return;
		int leftChild = index * 2 + 1; //左节点的下标
		int rightChild = index * 2 + 2;//右节点的下标
		维护大顶堆(arr, leftChild, size);
		维护大顶堆(arr, rightChild, size);
		int maxChild;
		if (rightChild < size)//有左右子节点
			maxChild = arr[leftChild] > arr[rightChild] ? leftChild : rightChild;
		else if (leftChild < size)//没有右子节点
			maxChild = leftChild;
		else //没有子节点							 
			maxChild = index;
		if (arr[index] < arr[maxChild])
			std::swap(arr[index], arr[maxChild]);
	}
	/// <summary>
	/// 升序 =》 大顶堆
	/// </summary>
	/// <param name="arr">待排序的数组</param>
	void 堆排序(vector<int>& arr)
	{
		for (int i = arr.size() - 1; i > 0; --i)
		{
			维护大顶堆(arr, 0, i + 1);
			std::swap(arr[i], arr[0]);
		}
	}
}
namespace
{
	// 桶排序
	void _插入排序_桶()
	{
		int x[10] = { 0 };
	}

	void 桶排序(vector<int>& arr)
	{
		;
	}
}

void 排序测试()
{
	vector<int> arr = getArray(10);
	cout << "输出原数组" << endl;
	for (int i : arr)
		cout << i << '\t';
	cout << endl;
	//快速排序(arr, 0, arr.size() - 1); //快速排序
	//归并排序(arr, 0, arr.size() - 1);  //归并排序
	//希尔排序(arr);
	堆排序(arr);

	cout << "输出排序后数组" << endl;
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