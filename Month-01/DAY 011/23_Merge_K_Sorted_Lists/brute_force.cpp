#include <iostream>
#include <vector>
#include <algorithm>
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

Node *mergeKLists(vector<Node *> &lists)
{
    vector<int> arr;

    for (int i = 0; i < lists.size(); i++)
    {
        Node *temp = lists[i];

        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }

    sort(arr.begin(), arr.end());

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        push_back(head, tail, arr[i]);
    }

    return head;
}

int main()
{
    Node *l1 = NULL;
    Node *t1 = NULL;

    Node *l2 = NULL;
    Node *t2 = NULL;

    Node *l3 = NULL;
    Node *t3 = NULL;

    push_back(l1, t1, 1);
    push_back(l1, t1, 4);
    push_back(l1, t1, 5);

    push_back(l2, t2, 1);
    push_back(l2, t2, 3);
    push_back(l2, t2, 4);

    push_back(l3, t3, 2);
    push_back(l3, t3, 6);

    vector<Node *> lists = {l1, l2, l3};

    Node *ans = mergeKLists(lists);

    cout << "Merged List: ";
    display(ans);

    return 0;
}