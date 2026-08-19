#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void push_back(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << "\n";
}

Node *swapPairs(Node *head)
{
    Node dummy(0);
    dummy.next = head;

    Node *prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL)
    {
        Node *first = prev->next;
        Node *second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);

    cout << "Original List: ";
    display(head);

    head = swapPairs(head);

    cout << "After Swapping: ";
    display(head);

    return 0;
}