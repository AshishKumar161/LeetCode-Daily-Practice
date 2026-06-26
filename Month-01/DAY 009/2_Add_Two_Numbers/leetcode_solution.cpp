
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string a = "";
        string b = "";

        while (l1 != NULL)
        {
            a = a + to_string(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            b += to_string(l2->val);
            l2 = l2->next;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";

        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum = sum + a[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                sum = sum + b[j] - '0';
                j--;
            }

            ans = ans + to_string(sum % 10);
            carry = sum / 10;
        }

        ListNode dummy(0);
        ListNode *temp = &dummy;

        for (int k = 0; k < ans.length(); k++)
        {
            temp->next = new ListNode(ans[k] - '0');
            temp = temp->next;
        }

        return dummy.next;
    }
};