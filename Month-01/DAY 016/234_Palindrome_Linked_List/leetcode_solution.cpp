class Solution
{
public:
    ListNode *recursion(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL)
        {
            slow = slow->next;
        }
        ListNode *rev = recursion(slow);
        while (rev != NULL)
        {
            if (head->val != rev->val)
            {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};