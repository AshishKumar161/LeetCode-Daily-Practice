class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
    
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                ListNode *nodeToDelete = curr->next;
                curr->next = curr->next->next; 
                delete nodeToDelete;
            }
            else
            {
                curr = curr->next; 
            }
        }

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};