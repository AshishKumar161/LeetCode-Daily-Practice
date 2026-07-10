//                                         Recursive

ListNode *left;

bool solve(ListNode *right)
{
    if (right == NULL)
        return true;

    if (!solve(right->next))
        return false;

    if (left->val != right->val)
        return false;

    left = left->next;

    return true;
}

bool isPalindrome(ListNode *head)
{
    left = head;
    return solve(head);
}