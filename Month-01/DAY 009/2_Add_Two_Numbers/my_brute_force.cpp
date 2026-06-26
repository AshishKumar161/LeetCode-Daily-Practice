class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *temp = &dummy;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        long long a = 0;
        while (temp1 != NULL)
        {
            a = a * 10 + temp1->val;
            temp1 = temp1->next;
        }
        long long b = 0;
        while (temp2 != NULL)
        {
            b = b * 10 + temp2->val;
            temp2 = temp2->next;
        }
        long long c = 0;
        while (a != 0)
        {
            c = c * 10 + a % 10;
            a = a / 10;
        }
        long long d = 0;
        while (b != 0)
        {
            d = d * 10 + b % 10;
            b = b / 10;
        }

        long long e = c + d;

        if (e == 0)
        {
            return new ListNode(0);
        }
        while (e != NULL)
        {
            int f = e % 10;
            temp->next = new ListNode(f);
            temp = temp->next;
            e = e / 10;
        }
        return dummy.next;
    }
};