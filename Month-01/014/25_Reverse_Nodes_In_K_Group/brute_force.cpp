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

Node *reverseKGroup(Node *head, int k)
{
    Node dummy(0);

    dummy.next = head;

    Node *prev = &dummy;

    while (true)
    {
        Node *t1 = prev;

        for (int i = 0; i < k; i++)
        {
            t1 = t1->next;

            if (t1 == NULL)
            {
                return dummy.next;
            }
        }

        Node *t2 = prev->next;

        Node *t3 = t1->next;

        Node *curr = t2;

        Node *prevNode = t3;

        while (curr != t3)
        {
            Node *temp = curr->next;

            curr->next = prevNode;

            prevNode = curr;

            curr = temp;
        }

        prev->next = t1;

        prev = t2;
    }
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

    head = reverseKGroup(head, 2);

    cout << "After Reversing k Group: ";
    display(head);

    return 0;
}