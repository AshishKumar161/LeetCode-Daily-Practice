class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        // edge cases
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        // find length and tail
        int len = 1;
        ListNode *tail = head;

        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        // reduce unnecessary rotations
        k = k % len;

        // no rotation needed
        if (k == 0)
        {
            return head;
        }

        // make circular linked list
        tail->next = head;

        // find new tail
        int steps = len - k - 1;

        ListNode *newTail = head;

        while (steps--)
        {
            newTail = newTail->next;
        }

        // new head
        ListNode *newHead = newTail->next;

        // break circle
        newTail->next = NULL;

        return newHead;
    }
};