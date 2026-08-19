class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *tail;

        ListNode *temp = head;

        // for count
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        // for n = 1  or count 1 ;
        if (count == n)
        {
            ListNode *deleteNode = head;
            head = head->next;
            delete deleteNode;
            return head;
        }
        tail = temp; // there in no use of tail
        temp = head;

        for (int i = 1; i < count - n && temp != NULL; i++)
        {
            temp = temp->next;
        }

        ListNode *deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
        return head;
    }
};