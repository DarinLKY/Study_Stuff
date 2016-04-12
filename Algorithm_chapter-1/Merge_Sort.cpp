////此为归并算法的的演示，所用Merge_Sort（s,0,x）

void Merge(int *s, int p, int q, int r)
{
	const int  n1 = (q - p + 1);
	const int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
	{
		L[i] = s[p + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = s[q + j + 1];                                                                  //此处的+1容易忽略
	}
	L[n1] = 10000000;                                                                     //此处的哨兵用法为考虑其中一组数组已经排完的情况；
	R[n2] = 10000000;

	/*for (int i = 0; i < (n1 + n2-1); i++)
	{
	int Lsize = 0, Rsize = 0;
	if(Lsize==n1)
	{
	for (int j = 0; j < Rsize-i; j++)
	{
	s[p + i+j] = R[Rsize+j];
	}break;
	}
	if(Rsize==n2)
	{
	for (int j = 0; j < Lsize-i; j++)
	{
	s[p + i+j] = L[Lsize+j];
	}break;
	}
	if (L[Lsize] <= R[Rsize])
	{
	s[p + i] = L[Lsize]; Lsize++;
	}
	if (L[Lsize] > R[Rsize])
	{
	s[p + i] = R[Rsize]; Rsize++;
	}
	}*/                          //若不使用哨兵的情况                                                         


	for (int i = 0, j = 0, k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			s[k] = L[i];
			i++;
		}
		else{
			s[k] = R[j];
			j++;
		}
	}

	delete[]L;
	delete[]R;
}
void Merge_Sort(int *s, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		Merge_Sort(s, p, q);
		Merge_Sort(s, q + 1, r);
		Merge(s, p, q, r);
	}
}