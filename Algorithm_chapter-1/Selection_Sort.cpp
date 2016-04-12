//简单插入排序/降序
#include<iostream>
using namespace std;
int main()
{
	int s[10], temp;
	for (int i = 0; i < 10; i++)
	{
		s[i] = i + 1;
	}
	int record;
	for (int j = 1; j < 10; j++)
	{
		temp = s[j];
		record = j - 1;
		while (s[record]>temp && record >= 0)                                   //record==0时有特殊情况
		{
			s[record + 1] = s[record];
			record--;
		}
		s[record + 1] = temp;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << s[i] << " ";
	}
}



void Sort(int *s)//for every data >0 
{
	int record, temp, length = 0, i = 0;
	while (s[i] > 0)
	{
		length++;
		i++;
	}
	for (int j = 1; j < length; j++)
	{
		temp = s[j];
		record = j - 1;
		while (s[record]>temp && record >= 0)
		{
			s[record + 1] = s[record];
			record--;
		}
		s[record + 1] = temp;
	}
}