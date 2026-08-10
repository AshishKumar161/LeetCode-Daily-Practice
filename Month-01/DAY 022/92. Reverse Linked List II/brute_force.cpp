class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head -> next == NULL || left == right)
        {
            return head ;
        }

        int count = (right - left + 1) / 2 ;
        for (int i = 0 ; i < count ; i++ )
        {
            ListNode* t1 = head ;
            for(int j = 1 ; j < left + i ; j++)
            {
                t1 = t1 -> next ;
            }
            
            ListNode* t2 = head ; 
            for (int j = 1 ; j < right - i ; j++)
            {
                t2 = t2 -> next ;
            }

            // swap ;
            int vall = t1 -> val ;
            t1 -> val = t2 -> val ;
            t2 -> val = vall ;
        }
        return head ; 
    }
};