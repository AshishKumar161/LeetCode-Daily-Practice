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

    void reverseList()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *t1 = head;
        Node *t2 = head;
        Node *t3 = head;

        t2 = t2->next;
        t3 = t2->next;

        t1->next = NULL;

        while (t2 != NULL)
        {
            t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }

        tail = head;
        head = t1;
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

int main()
{
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original List: ";
    ll.display();

    ll.reverseList();

    cout << "Reversed List: ";
    ll.display();

    return 0;
}