//经过计算，d叉树i结点的孩子从(i*d-d+2)到(i*d+1)
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void Max_Heapify_d(int *s,int d, int i, int heap_size)
{
	int max = i;
	/*int ChlidNum = 0;
	for (int j = 0; j < d; j++)
	{
		if (i*d - d + 2 + j > heap_size)
			break;
		else
		{
			Child[j] = s[i*d - d + 2 + j];
			ChlidNum++;
		}
	}*/
	for (int j = 0; j < d; j++)
	{
		if (i*d - d + 2 + j > heap_size)
			break;
		if (s[i*d - d + 2 + j] > s[i])
			max = i*d - d + 2 + j;
	}
	if (max != i)
	{
		swap(s[i], s[max]);
		Max_Heapify_d(s, d, max, heap_size);
	}
}
int Heap_extract_Max(int *s, int d,int &heap_size)//数组退出最大值，重新形成新的最大堆.
{
	if (heap_size < 1)
		return;
	int max = s[1];
	s[1]=s[heap_size] ;
	heap_size--;
	Max_Heapify_d(s, d, 1, heap_size);

}