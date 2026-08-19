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

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void deleteDuplicates()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *t1 = head;
        Node *t2 = head;
        Node *t3 = head->next;

        while (t3 != NULL)
        {
            if (t2->data == t3->data)
            {
                if (t2 == head)
                {
                    head = t3;

                    delete t2;

                    t2 = head;

                    t3 = head->next;
                }
                else
                {
                    t1->next = t3;

                    delete t2;

                    t2 = t3;

                    t3 = t2->next;
                }
            }
            else
            {
                t1 = t2;

                t2 = t3;

                t3 = t2->next;
            }
        }
    }
};

int main()
{
    system("cls");

    List l;

    l.push_back(1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(3);

    cout << "Original List:" << endl;
    l.print();

    l.deleteDuplicates();

    cout << "\nAfter Removing Duplicates:" << endl;
    l.print();

    system("pause");
    return 0;
}