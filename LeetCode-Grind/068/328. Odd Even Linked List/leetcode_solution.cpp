class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
    
            if(head == NULL || head -> next == NULL)
            {
                return head ;
            }
    
            ListNode* oddptr = head ;
            ListNode* evenptr = head -> next ;
            ListNode* even = evenptr ;
    
            while(evenptr != NULL && evenptr -> next != NULL )
            {
                oddptr -> next = evenptr -> next ;
                oddptr = oddptr -> next ;
    
                evenptr -> next = oddptr -> next ;
                evenptr = evenptr -> next ;
            }
            
            oddptr -> next = even ;
    
            return head ;
        }
    };