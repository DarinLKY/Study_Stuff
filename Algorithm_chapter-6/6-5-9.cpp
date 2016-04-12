//��O(N lgK) ʱ���ںϲ�K���������� ����Nָ����K�����������е�Ԫ�ظ�����
//������С�ѣ��ö����next���Min_Heapify
class LinkedNode
{
	friend LinkedList;
public:
	LinkedNode()
	{
		data = -100086;
		next = nullptr;
	}
	LinkedNode(int x)
	{
		data = x;
		next = nullptr;
	}
public:
	int data;
	LinkedNode *next;
};
class LinkedList
{
	friend LinkedNode;
public:
	LinkedList()
	{
		head = new LinkedNode();
	}
	int GetLength();
	int GetPointData(int position);
private:
	LinkedNode *head;
};
void Min_Heapify(LinkedList *s, int i)
{
	int leftChild = 2 * i, rightChild = 2 * i + 1, min = -1;
	if (leftChild <= s->GetLength&&s->GetPointData(leftChild) < s->GetPointData(i))
		min = leftChild;
	else
	{
		min = i;
	}
	if (rightChild <= s->GetLength&&s->GetPointData(rightChild) < s->GetPointData(min))
	{
		min = rightChild;
	}
	if (min != i)
	{
		//����s->GetPointData(i)��s->GetPointData(min)
		Min_Heapify(s,min);
	}
}