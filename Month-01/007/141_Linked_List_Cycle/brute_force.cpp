#include <iostream>
#include <unordered_set>
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

bool hasCycle(Node *head)
{
    unordered_set<Node *> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited.find(temp) != visited.end())
        {
            return true;
        }

        visited.insert(temp);
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    fourth->next = second;

    if (hasCycle(head))
    {
        cout << "Cycle Found\n";
    }
    else
    {
        cout << "No Cycle\n";
    }

    return 0;
}