class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (prev->next != NULL && prev->next->next != NULL)
        {
            ListNode *first = prev->next;
            ListNode *second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        return dummy.next;
    }
};