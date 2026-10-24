class Solution {
    public:
    
        ListNode* getMiddle(ListNode* head)
        {
            ListNode* slow = head ;
            ListNode* fast = head -> next ;
    
            while (fast != NULL && fast -> next != NULL)
            {
                slow = slow -> next ;
                fast = fast -> next -> next ;
            }
    
            return slow ;
        }
    
        ListNode* mergeList (ListNode* left , ListNode* right)
        {
            ListNode dummy(0) ;
            ListNode* tail = &dummy ;
    
            while (left != NULL && right != NULL)
            {
                if (left -> val <= right -> val)
                {
                    tail -> next = left ;
                    left = left -> next ;
                }
    
                else 
                {
                    tail -> next = right ;
                    right = right -> next ;
                }
    
                tail = tail -> next ;
            }
    
            if (left != NULL)
            {
                tail -> next = left ;
            }
    
            else
            {
                tail -> next = right ; 
            }
    
            return dummy.next ;
        }
    
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head -> next == NULL)
            {
                return head ;
            }
            ListNode* middle = getMiddle(head) ;
            ListNode* right = middle -> next ; 
    
            middle -> next = NULL ;
            ListNode* left = head ;
    
            left = sortList(left) ;
            right = sortList(right) ;
    
            return mergeList(left , right) ;
        }
    };