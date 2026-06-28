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

    void removeNthFromEnd(int n)
    {
        int count = 0;

        Node *temp = head;

        // Count total nodes
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        // If head node needs to be deleted
        if (count == n)
        {
            Node *deleteNode = head;
            head = head->next;

            delete deleteNode;
            return;
        }

        temp = head;

        // Move to node before target node
        for (int i = 1; i < count - n; i++)
        {
            temp = temp->next;
        }

        // Delete node
        Node *deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;
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

    ll.removeNthFromEnd(2);

    cout << "After Removing Node: ";
    ll.display();

    return 0;
}