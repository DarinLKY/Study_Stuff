//递归函数（栈）的运行原理
//何时用引用或拷贝

class Node_3
{
	//简单类隐藏构造函数
public:
	int low;
	int high;
	int sum;
};
Node_3 Find_Crossing_Maximum_Subarray(int *subarray, int low, int mid, int high)
{
	int left_sum = -1000, sum = 0, max_left_record = 0;
	for (int i = mid - 1; i >= 0; i--)
	{
		sum = sum + subarray[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left_record = i + 1;//??????
		}
	}
	int right_sum = -1000, max_right_record = 0;
	sum = 0;
	for (int i = mid; i <high; i++)
	{
		sum = sum + subarray[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_left_record = i + 1;
		}
	}
	Node_3 *Ces = new Node_3();
	Ces->high = max_right_record;
	Ces->low = max_left_record;
	Ces->sum = left_sum + right_sum;
	return *Ces;
}

Node_3 Find_Maximum_Subarray(int *subarray, int low, int high)
{
	if (high == low)
	{
		Node_3 *rec = new Node_3();
		rec->high = high;
		rec->low = low;
		rec->sum = subarray[low];
		return *rec;
	}
	else
	{
		int mid = (low + high) / 2;						// left_low, left_high, left_sum;
		Node_3 Lec=Find_Maximum_Subarray(subarray, low, mid);
		Node_3 Rec=Find_Maximum_Subarray(subarray, mid + 1, high);
		Node_3 Cec=Find_Crossing_Maximum_Subarray(subarray, low, mid, high);
		if (Lec.sum >= Cec.sum&&Lec.sum >= Rec.sum)
			return Lec;
		else if (Rec.sum >= Cec.sum&&Rec.sum >= Lec.sum)
			return Rec;
		else
			return Cec;
	}
}


#include<iostream>
using namespace std;
int main()
{
	int s[8] = { -3, 3, -5, 7, 3, -4, 5, -3 };
	Node_3 node1 = Find_Maximum_Subarray(s, 0, 8);
	cout << node1.sum << endl;
}