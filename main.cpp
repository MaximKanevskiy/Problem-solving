#include <iostream>

// Структура узла.
// Имеет ячейку для информации и ячейку для указателя на следующий узел.
class Node
{
public:
	int data;
	Node* next;
};

// Печатает односвязный список.
static void print_linked_list(Node* node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

// Добавляет узел в начало списка.
// Новый узел будет указывать на старый начальный,
// а ссылка на начало списка переместится на новый узел.
static void push(Node*& head_reference, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_reference;
    head_reference = new_node;
}

// Добавляет в определённое место списка.
// Принимает ссылку на предыдущий узел и информацию для нового узла.
// Новый узел будет указывать на тот, на который раньше указывал предыдущий,
// а предыдущий будет указывать на новый.
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

// Добавляет узел в конец списка. 
// Принимает на вход начальный узел и новую информацию для нового узла.
// Новый узел, так как он в конце, никуда не указывает.
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

// Удаляет односвязный список. Принимает на вход начало списка.
static void delete_linked_list(Node*& head_reference)
{
    Node* current_node = head_reference;
    Node* next = nullptr;

    while (current_node != nullptr)
    {
        next = current_node->next;
        delete current_node;
        current_node = next;
    }

    head_reference = nullptr;
}

// Все узлы явно инициализируются nullptr и создаются динамически с помощью оператора new.
// Затем все узлы должны быть заполнены определёнными данными, например, целыми числами.
// Все кроме последнего указывают на следующий узел. Последний никуда не указывает.
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

    delete_linked_list(head);
}