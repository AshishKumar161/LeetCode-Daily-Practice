class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        // empty list or one node
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *temp = &dummy;

        while (temp->next != NULL &&
               temp->next->next != NULL)
        {
            ListNode *h1 = temp->next;
            ListNode *h2 = h1->next;

            // swap links
            h1->next = h2->next;
            h2->next = h1;
            temp->next = h2;

            // move temp
            temp = h1;
        }

        return dummy.next;
    }
};