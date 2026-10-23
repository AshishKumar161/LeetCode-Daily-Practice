class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* temp = head ;
            ListNode* slow = head ;
            ListNode* fast = head ;
    
            while (fast != NULL && fast -> next != NULL)
            {
                slow = slow -> next ;
                fast = fast -> next -> next ;
    
                if (slow == fast)
                {
                    slow = head ;
                    while (slow != fast)
                    {
                        slow = slow -> next ;
                        fast = fast -> next ;
                    }
                    return slow ;
                }
            }
    
    
    
            // unordered_set < ListNode* > hash ;
    
            // while (temp !=  NULL)
            // {
            //     if (hash.find(temp) != hash.end()) 
            //     {
            //         return temp ;
            //     }
    
            //     hash.insert(temp) ;
            //     temp = temp -> next ;
    
            // }
    
            return nullptr ;
        }
    };