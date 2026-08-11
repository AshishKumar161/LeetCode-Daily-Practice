class Solution
{
public:
    ListNode *successor = NULL;

    ListNode *reverseN(ListNode *head, int n)
    {
        // Base case
        if (n == 1)
        {
            successor = head->next;
            return head;
        }

        // Reverse remaining nodes
        ListNode *last = reverseN(head->next, n - 1);

        // Reverse current connection
        head->next->next = head;

        // Connect to remaining list
        head->next = successor;

        return last;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL || left == right)
        {
            return head;
        }

        // If left is 1,
        // reverse first 'right' nodes
        if (left == 1)
        {
            return reverseN(head, right);
        }

        // Move toward left
        head->next = reverseBetween(
            head->next,
            left - 1,
            right - 1);

        return head;
    }
};