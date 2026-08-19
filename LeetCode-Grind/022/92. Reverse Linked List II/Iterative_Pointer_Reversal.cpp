class Solution
{
    ListNode* reverseBetween(ListNode* head , int left , int right)
    {
        if(head == NULL ; head -> next == NULL ; left == right )
        {
            return head ;
        }

        ListNode dummy(0);
        dummy.next = head ;
        ListNode* prev = &dummy ;
        for (int i = 1 ; i < left ; i++ )
        {
            prev = prev -> next ;
        }

        ListNode* curr = prev -> next ;

        for(int = 0 ; i < right - left ; i++)
        {
            ListNode* next = curr -> next ;
            curr -> next = next -> next ;
            next -> next = prev -> next ;
            prev -> next = next ;
        }
        return dummy.next ;
    }
}