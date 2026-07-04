
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *t1 = head;
        ListNode *t2 = head;
        ListNode *t3 = head->next;
        while (t3 != NULL)
        {
            if (t2->val == t3->val)
            {
                if (t2 == head)
                {
                    head = t3;
                    delete t2;
                    t2 = head;
                    t3 = head->next;
                }
                else
                {
                    t1->next = t3;
                    delete t2;
                    t2 = t3;
                    t3 = t2->next;
                }
            }
            else
            {
                t1 = t2;
                t2 = t3;
                t3 = t2->next;
            }
        }
        return head;
    }
};