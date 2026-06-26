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

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val)
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

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }
};

Node *mergeList(Node *list1, Node *list2)
{
    Node dummy(-1);
    Node *tail = &dummy;

    Node *temp1 = list1;
    Node *temp2 = list2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            tail->next = temp1;
            temp1 = temp1->next;
        }

        else
        {
            tail->next = temp2;
            temp2 = temp2->next;
        }

        tail = tail->next;
    }

    if (temp1 != NULL)
    {
        tail->next = temp1;
    }

    else
    {
        tail->next = temp2;
    }

    return dummy.next;
}

int main()
{
    List l1;
    List l2;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(4);

    l2.push_back(1);
    l2.push_back(3);
    l2.push_back(4);

    cout << "List 1: ";
    l1.display();

    cout << "List 2: ";
    l2.display();

    Node *ans = mergeList(l1.head, l2.head);

    cout << "Merged List: ";

    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    cout << "\n";

    return 0;
}