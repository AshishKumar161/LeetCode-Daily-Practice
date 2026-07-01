#include <iostream>
using namespace std;

class Node
{
   public:
   int data ;
   Node* next ;
   Node(int data)
   {
       this -> data = data ;
       this ->  next = NULL ;
   }
};

class list
{
   public:
   Node* head ;
   Node* tail ;
   list()
   {
       head = tail = NULL ;
   }
    void push_front(int val)
    {
        Node* newNode = new Node(val) ;

        if (head == NULL)
        {
            head = tail = newNode ;
            return ;
        }

        newNode->next = head ;
        head = newNode ;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val) ;

        if (head == NULL)
        {
            head = tail = newNode ;
            return ;
        }

        tail->next = newNode ;
        tail = newNode ;
    }

    Node* merge(Node* list1 , Node* list2)
    {
        Node dummy(-1) ;
        Node* temp = &dummy ;
        Node* t1 = list1 ;
        Node* t2 = list2 ;

        while (t1  != NULL && t2 != NULL)
        {
            if (t1 -> data <= t2 -> data)
            {   
                temp -> next = t1 ;
                t1 = t1 -> next ; 
            }
            else
            {
                temp -> next = t1 ;
                t2 = t2 -> next ;
            }
            
            temp = temp -> next ;
        }
        
    if (t1 != NULL)
    {
        temp -> next = t1 ;
    }

    else
    {
        temp -> next = t2 ;
    }

    return dummy.next;

    }
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n" ;
            return ;
        }

        Node* temp = head ;

        while (temp != NULL)
        {
            cout << temp->data << " -> " ;
            temp = temp->next ;
        }

        cout << "NULL\n" ;
    }

};

int main() {
     system("cls");
    list l1;
    list l2;

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

    Node* ans = l1.merge(l1.head, l2.head);

    cout << "Merged List: ";

    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    cout << "\n";

      
     system("pause");
     system("cls");
     return 0;
}