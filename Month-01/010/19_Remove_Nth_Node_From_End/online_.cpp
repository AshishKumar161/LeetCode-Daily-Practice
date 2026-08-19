class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // delete head
        if (fast == NULL)
        {
            ListNode *deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *deleteNode = slow->next;
        slow->next = deleteNode->next;

        delete deleteNode;

        return head;
    }
};