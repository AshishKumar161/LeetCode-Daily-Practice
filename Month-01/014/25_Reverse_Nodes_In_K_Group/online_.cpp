class Solution
{
public:
    // reverse linked list from first to last
    ListNode *reverse(ListNode *head)
    {

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // edge case
        if (head == NULL || k == 1)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroup = &dummy;

        while (true)
        {

            // find kth node
            ListNode *kth = prevGroup;

            for (int i = 0; i < k && kth != NULL; i++)
            {
                kth = kth->next;
            }

            // less than k nodes left
            if (kth == NULL)
            {
                break;
            }

            // group pointers
            ListNode *groupStart = prevGroup->next;
            ListNode *nextGroup = kth->next;

            // detach group
            kth->next = NULL;

            // reverse group
            prevGroup->next = reverse(groupStart);

            // connect tail to next part
            groupStart->next = nextGroup;

            // move prevGroup
            prevGroup = groupStart;
        }

        return dummy.next;
    }
};