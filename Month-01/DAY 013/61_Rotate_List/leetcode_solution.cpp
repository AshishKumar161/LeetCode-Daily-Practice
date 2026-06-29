class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int len = 1;

        ListNode *tail = head;

        while (tail->next != NULL)
        {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if (k == 0)
        {
            return head;
        }

        tail->next = head;

        int step = len - k;

        ListNode *temp = head;

        for (int i = 1; i < step; i++)
        {
            temp = temp->next;
        }

        head = temp->next;

        temp->next = NULL;

        return head;
    }
};