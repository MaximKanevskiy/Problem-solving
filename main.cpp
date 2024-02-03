#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

static void print_linked_list(Node* node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

static void push(Node*& head_reference, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_reference;
    head_reference = new_node;
}

static void insert(Node*& previous_node, int new_data) 
{
    if (previous_node == nullptr) 
    {
        std::cout << "the given previous node cannot be NULL" << std::endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;
}

static void append(Node*& head_reference, int new_data) 
{
    Node* new_node = new Node();
    Node* last = head_reference;
    new_node->data = new_data;
    new_node->next = nullptr;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = new_node;
}

int main()
{
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    print_linked_list(head);
    push(head, 56);
    insert(second, 100);
    append(head, 78);
    std::cout << std::endl;
    print_linked_list(head);
}