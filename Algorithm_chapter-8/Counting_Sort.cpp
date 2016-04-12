//Conunting_Sort,only for every element is greater than 0;
//time complexity is O(n+k);linear time
//k is the largest element in destination array;
//Question:How to get the length of destination array in the function?
#include<iostream>
using namespace std;
void Counting_Sort(int *a,int k,int length)
{
	int *counting = new int[k+1];
	for (int i = 0; i <= k; i++)
	{
		*(counting + i) = 0;
	}
	int i = 0;
	for (int i = 0; i<length;i++)
	{
		if (a[i]>0)
			(*(counting + a[i]))++;					//counting数组用下标存储了原数组的数据，用下标中的数据记录了有几个是相同的。
	}												//这样在counting数组中的下标本身就已经排好了顺序，升序。
	int change_index = 0; int original_index = 0;	//change_index为counting临时存储数据的下标，original_index为目标数组的下标；
	for ( change_index = 0; change_index <= k; change_index++)
	{
		if (*(counting + change_index) != 0)
		{
			for (int j = 0; j < (*(counting + change_index)); j++)
			{
				a[original_index++] = change_index;
			}
		}
	}
	delete[]counting;
}

void main()
{
	int s[10] = { 5, 3, 4, 6, 100, 34, 3, 34, 34, 2 };
	int k = 100;
	int length = sizeof(s) / sizeof(s[0]);
	Counting_Sort(s, k,length);
	for (int i = 0; i < 10; i++)
	{
		cout << s[i]<<" ";
	}
}