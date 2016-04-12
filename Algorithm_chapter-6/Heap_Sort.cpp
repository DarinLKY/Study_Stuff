//二叉树的2^n特性可以用数组构建完全二叉树
//数组的A[0]冲突,起始的位置为A[1];
//数组的长度问题
#include<iostream>
using namespace std;
void Max_Heapify(int *A, int i,int heap_size)
{
	int left_node = 2 * i;
	int right_node = left_node + 1;
	int largest = -1;
	if (i <= heap_size / 2)
	{
		if ( left_node <= heap_size&&A[left_node] > A[i] )
		{
			largest = left_node;
		}
		else
		{
			largest = i;
		}
		if (right_node <= heap_size &&A[right_node] > A[largest] )
		{
			largest = right_node;
		}
		if (largest != i)
		{
			int use_for_change = A[i];
			A[i] = A[largest];
			A[largest] = use_for_change;
			Max_Heapify(A, largest, heap_size);//递归调用原来的值与下一级的数做比较，
		}
	}
}
void Build_Max_Heap(int *A)
{
	int heap_size=0;
	for (int i = 0; i<10000; i++)
	{
		if (A[i+1]>0)
			heap_size++;
		else
			break;
	}
	for (int i = heap_size / 2; i >=1; i--)
	{
		Max_Heapify(A, i, heap_size);
	}
}
void Heap_Sort(int *A)
{
	Build_Max_Heap(A); int length = 0;
	for (int i = 0; i<10000; i++)
	{
		if (A[i+1]>0)
			length++;
		else
			break;
	}
	int use_for_exchange = 0, heap_size = length;
	for (int i = length; i >=2; i--)
	{
		use_for_exchange = A[1];
		A[1] = A[i];
		A[i] = use_for_exchange;
		heap_size--;
		Max_Heapify(A, 1, heap_size);
	}
}

//int main()
//{
//	int s[11] = { -13, 23, 44, 45, 3, 23, 454, 45, 7, 4,67 };
//	Heap_Sort(s);
//	for (int i = 0; i<10; i++)
//	{
//		cout << s[i + 1] << " ";
//	}
//}