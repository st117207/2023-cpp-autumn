#include<iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node() { data = 0; next = nullptr; }
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { dispose(); }
	void PushHead(int data);
	void Insert(int index, int data);
	void PushTail(int data);
	int PopHead();
	int Extract(int index);
	int PopTail();
	bool IsEmpty() { return head == nullptr; }
	int Length();
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
private:
	Node* head;
	void InsertNode(int index, Node* node);
	int PopData(Node* node);

	void dispose();
	bool indexValid(int index);
	void swapWithHead(int index);
	void swapHeadWithTail();
	void swapWithTail(int index);

};

int main(int argc, char* argv[])
{
	LinkedList list;
	list.PushHead(1);
	list.PushTail(3);
	list.Insert(1, 2);
	list.Insert(3, 4);
	list.Insert(3, 5);
	list.Insert(3, 7);
	list.Insert(4, 8);
	list.Insert(3, 7);
	list.Insert(6, 11);
	list.Insert(6, 8);
	list.Insert(5, 6);
	list.Insert(5, 8);
	list.Insert(3, 6);
	list.Insert(3, 2);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

void LinkedList::PushHead(int data)
{
	head = new Node(data, head);
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	if (indexValid(index))
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(data, tmp->next);
	}
}

void LinkedList::PushTail(int data)
{
	if (IsEmpty())
	{
		return PushHead(data);
	}
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(data);
}

int LinkedList::PopHead()
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}

int LinkedList::Extract(int index)
{
	if (index == 0)
	{
		return PopHead();
	}
	if (index == Length() - 1)
	{
		return PopTail();
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* nres = tmp->next;
	tmp->next = tmp->next->next;
	int res = nres->data;
	delete nres;
	return res;
}

int LinkedList::PopTail()
{
	if (IsEmpty())
	{
		return -1;
	}
	if (head->next == nullptr)
	{
		return PopHead();
	}
	Node* tmp = head;
	while (tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data;
	delete tmp->next;
	tmp->next = nullptr;
	return res;

}

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

int LinkedList::Data(int index)
{
	Node* tmp = head;
	if (!indexValid(index))
	{
		return 0;
	}
	for (int i = 0; i < index-1; ++i)
	{
		tmp = tmp->next;
	}
	return tmp->next->data;

}

void LinkedList::swap(int ia, int ib)
{
	if (ia == ib)
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	if (ia == 0)
	{
		return swapWithHead(ib);
	}
	if (ib == Length())
	{
		return swapWithTail(ia);
	}
	if ((ia == 0) && (ib == Length() - 1))
	{
		return swapHeadWithTail();
	}
	Node* tmp = head;
	Node* tmp1 = head;
	Node* tmp2 = head;
	Node* tmp3 = head;
	Node* tmp4 = head;
	Node* tmp5 = head;
	Node* tmp6 = head;
	for (int i = 0; i < Length(); ++i)
	{
		if ((i + 1) == ia)
		{
			tmp1 = tmp;
			tmp2 = tmp->next;
			tmp3 = tmp->next->next;
		}
		if ((i + 1) == ib)
		{
			tmp4 = tmp;
			tmp5 = tmp->next;
			tmp6 = tmp->next->next;
		}
		tmp = tmp->next;
	}
	if (ib - ia == 1)
	{
		tmp1->next = tmp5;
		tmp5->next = tmp2;
		tmp2->next = tmp6;
	}
	else
	{
		tmp1->next = tmp5;
		tmp5->next = tmp3;
		tmp4->next = tmp2;
		tmp2->next = tmp6;
	}
	delete tmp;
}

void LinkedList::sort()
{
	Node* tmpA = head;
	Node* tmpB = head;
	Node* tmp = head;
	int a = 0;
	int b = 0;
	for (int i = 0; i < Length(); ++i)
	{
		tmpB = tmpA->next;
		a = Data(i);
		for (int j = i + 1; j < Length(); ++j)
		{
			b = Data(j);
			if (a > b)
			{
				swap(i, j);
				tmp = tmpA;
				tmpA = tmpB;
				tmpB = tmp;
			}
			if (tmpB->next != nullptr)
			{
				tmpB = tmpB->next;
			}
		}
		if (tmpA->next != nullptr)
		{
			tmpA = tmpA->next;
		}
	}
}

int LinkedList::PopData(Node* node)
{
	Node* tmp = head;
	int res = 0;
	if (node == head)
	{
		return PopHead();
	}
	while (tmp->next != node)
	{
		tmp = tmp->next;
	}
	if (tmp->next->next = nullptr)
	{
		return PopTail();
	}
	res = tmp->next->data;
	tmp->next = tmp->next->next;
	return res;
	
}

void LinkedList::InsertNode(int index, Node* node)
{
	Node* tmp = head;
	if (index == 0)
	{
		node->next = head;
		head = node;
		return;
	}
	if (index == Length())
	{
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* tmp2 = head;
	tmp2 = tmp->next;
	tmp->next = node;
	node->next = tmp2;


}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

bool LinkedList::indexValid(int index)
{
	return (0 <= index && index < Length());
}

void LinkedList::swapWithHead(int index)
{
	// swapWithHead(3)
	// 1 2 3 4 5
	// 2 3 4 5                      1
	// 2 3 4 1 5
	// 4 2 3 1 5
	Node* tmpHead = head;
	head = head->next;
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	tmpHead->next = tmp->next;
	tmp->next = tmpHead;
	if (index != 1)
	{
		tmp = head;
		for (int i = 0; i < index - 2; ++i)
		{
			tmp = tmp->next;
		}
		Node* newHead = tmp->next;
		tmp->next = tmp->next->next;
		newHead->next = head;
		head = newHead;
	}
}

void LinkedList::swapHeadWithTail()
{
	Node* tmpTail = head;
	while (tmpTail->next != nullptr)
	{
		tmpTail = tmpTail->next;
	}
	Node* PredTail = head;
	while (PredTail->next->next != nullptr)
	{
		PredTail = PredTail->next;
	}
	Node* tmphead = head;
	Node* posthead = head->next;
	PredTail->next = tmphead;
	tmphead->next = nullptr;
	tmpTail->next = posthead;
	head = tmpTail;
}

void LinkedList::swapWithTail(int index)
{
	Node* Tail = head;
	while (Tail->next != nullptr)
	{
		Tail = Tail->next;
	}
	Node* PredTail = head;
	while (PredTail->next->next != nullptr)
	{
		PredTail = PredTail->next;
	}
	Node* tmp1 = head;
	Node* tmp2 = head;
	Node* tmp3 = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp1 = tmp1->next;
	}
	tmp2 = tmp1->next;
	tmp3 = tmp1->next->next;
	if (index == Length() - 2)
	{
		tmp1->next = Tail;
		Tail->next = tmp2;
		tmp2->next = nullptr;
		delete tmp3;
		delete PredTail;
	}
	tmp1->next = Tail;
	Tail->next = tmp3;
	PredTail->next = tmp2;
	tmp2->next = nullptr;

}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}