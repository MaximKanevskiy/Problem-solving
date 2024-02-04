#include <iostream>

class Node
{
private:
	Node* next;
public:
	Node()
	{
		this->next = nullptr;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

	Node* getNext()
	{
		return this->next;
	}
};

static int getLoopSize(Node* startNode)
{
	if (startNode == nullptr)
	{
		return 0;
	}

	Node* turtleptr = startNode;
	Node* rabbitptr = startNode;

	while (rabbitptr != nullptr && rabbitptr->getNext() != nullptr)
	{
		turtleptr = turtleptr->getNext();
		rabbitptr = rabbitptr->getNext()->getNext();

		if (turtleptr == rabbitptr)
		{
			int loopSize = 1;
			Node* current = turtleptr;

			while (current->getNext() != turtleptr)
			{
				loopSize++;
				current = current->getNext();
			}

			return loopSize;
		}
	}

	return 0;
}

int main()
{
	Node n0, n00, n1, n2, n3, n4;

	n0.setNext(&n00);
	n00.setNext(&n1);
	n1.setNext(&n2);
	n2.setNext(&n3);
	n3.setNext(&n4);
	n4.setNext(&n1);

	Node* startNode = &n1;
	int actual = getLoopSize(startNode);
	std::cout << actual << std::endl;
}