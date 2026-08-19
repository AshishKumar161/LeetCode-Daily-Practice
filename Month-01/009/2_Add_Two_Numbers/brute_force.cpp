#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string a = "";
        string b = "";

        while (l1 != NULL)
        {
            a = a + to_string(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            b = b + to_string(l2->val);
            l2 = l2->next;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";

        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum = sum + a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum = sum + b[j] - '0';
                j--;
            }

            ans = ans + to_string(sum % 10);
            carry = sum / 10;
        }

        ListNode dummy(0);
        ListNode *temp = &dummy;

        for (int k = 0; k < ans.length(); k++)
        {
            temp->next = new ListNode(ans[k] - '0');
            temp = temp->next;
        }

        return dummy.next;
    }
};

void push_back(ListNode *&head, ListNode *&tail, int val)
{
    ListNode *newNode = new ListNode(val);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << "\n";
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *tail1 = NULL;

    ListNode *l2 = NULL;
    ListNode *tail2 = NULL;

    push_back(l1, tail1, 2);
    push_back(l1, tail1, 4);
    push_back(l1, tail1, 3);

    push_back(l2, tail2, 5);
    push_back(l2, tail2, 6);
    push_back(l2, tail2, 4);

    cout << "List 1: ";
    display(l1);

    cout << "List 2: ";
    display(l2);

    Solution s;

    ListNode *ans = s.addTwoNumbers(l1, l2);

    cout << "Answer List: ";
    display(ans);

    return 0;
}