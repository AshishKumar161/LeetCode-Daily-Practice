class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        while (true)
        {
            ListNode *t1 = prev;
            for (int i = 0; i < k; i++)
            {
                t1 = t1->next;
                if (t1 == NULL)
                {
                    return dummy.next;
                }
            }

            ListNode *t2 = prev->next;
            ListNode *t3 = t1->next;

            ListNode *curr = t2;
            ListNode *prevNode = t3;

            while (curr != t3)
            {
                ListNode *temp = curr->next;

                curr->next = prevNode;

                prevNode = curr;

                curr = temp;
            }

            prev->next = t1;

            prev = t2;
        }
    }
};