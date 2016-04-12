//在O(N lgK) 时间内合并K个有序链表， 这里N指的是K个链表中所有的元素个数。
//建立最小堆，用顶点的next结点Min_Heapify
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
		//交换s->GetPointData(i)和s->GetPointData(min)
		Min_Heapify(s,min);
	}
}