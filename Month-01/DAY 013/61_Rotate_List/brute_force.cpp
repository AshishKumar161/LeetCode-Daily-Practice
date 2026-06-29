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

Node *rotateRight(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int len = 1;

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }

    k = k % len;

    if (k == 0)
    {
        return head;
    }

    tail->next = head;

    int step = len - k;

    Node *temp = head;

    for (int i = 1; i < step; i++)
    {
        temp = temp->next;
    }

    head = temp->next;

    temp->next = NULL;

    return head;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);
    push_back(head, tail, 5);

    cout << "Original List: ";
    display(head);

    head = rotateRight(head, 2);

    cout << "Rotated List: ";
    display(head);

    return 0;
}
