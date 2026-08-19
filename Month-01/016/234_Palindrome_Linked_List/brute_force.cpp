#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node* head;
    Node* tail;

    List()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    bool isPalindrome()
    {
        vector<int> arr;

        Node* temp = head;

        while(temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        while(i < j)
        {
            if(arr[i] != arr[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main()
{
    system("cls");

    List l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(1);

    if(l.isPalindrome())
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";

    return 0;
}