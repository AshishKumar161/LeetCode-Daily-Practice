class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        ListNode *curr = head;

        while (curr && curr->next)
        {
            // Duplicate node found
            if (curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                // Move only when values are different
                curr = curr->next;
            }
        }

        return head;
    }
};