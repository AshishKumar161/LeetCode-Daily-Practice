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

    void reverse()
    {
        Node* prev = NULL ;
        Node* curr = head ;

        while (curr != NULL)
        {
            Node* nextNode = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = nextNode ;
        }

        tail = head ;
        head = prev ;
        
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

     list ll;

     ll.push_back(1);
     ll.push_back(2);
     ll.push_back(3);
     ll.push_back(4);
     ll.push_back(5);

     cout << "Original List: ";
     ll.display();

     ll.reverse();

     cout << "Reversed List: ";
     ll.display();

     system("pause");
     system("cls");
     return 0;
}