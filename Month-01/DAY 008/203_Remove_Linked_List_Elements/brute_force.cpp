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
        head = tail = NULL;
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

    void removeElements(int val)
    {
        while (head != NULL && head->data == val)
        {
            head = head->next;
        }

        Node *curr = head;
        Node *prev = head;

        while (curr != NULL)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
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
    ll.push_back(6);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    cout << "Original List: ";
    ll.display();

    ll.removeElements(6);

    cout << "After Removing 6: ";
    ll.display();

    return 0;
}