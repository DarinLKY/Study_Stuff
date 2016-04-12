//Quick_Sort,For MOST situations;
//time complexity is O(n*lgn);
#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int*A,int p,int r)
{
	int key = A[r], record = p;
	for (int i = p; i <= r - 1; i++)
	{
		if (A[i] > key)					//This statement is the key to decide how to sort(ascending or descending);
		{
			swap(A[i], A[record]);
			record++;
		}
	}
	swap(A[r], A[record]);
	return record;
}
void Quick_Sort(int *A,int start,int end)
{
	if (start < end)
	{
		int key = Partition(A, start, end);
		Quick_Sort(A,start,key-1);
		Quick_Sort(A, key+1, end);
	}
}
int main()
{
	int s[11] = { -13, 23, -44, 45, 3, 23, 454, 45, 7, 300 ,67 };
	Quick_Sort(s,0,10);
	for (int i = 0; i<11; i++)
	{
		cout << s[i] << " ";
	}
}
