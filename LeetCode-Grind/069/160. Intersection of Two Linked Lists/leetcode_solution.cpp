class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    
            // unordered_set < ListNode* > st ;
    
            // ListNode* temp = headA ;
    
            // while (temp != nullptr) 
            // {
            //     st.insert(temp) ;
            //     temp = temp -> next ;
            // }
    
            // temp = headB ;
    
            // while (temp != nullptr) 
            // {
            //     if (st.find(temp) != st.end()) 
            //     {
            //         return temp ;
            //     }
    
            //     temp = temp -> next ;
            // }
    
            // return nullptr ;
    
    
    
    
    
    
        ListNode* t1 = headA ;
        ListNode* t2 = headB ;
    
    
        ListNode* temp = headA ;
        int countA = 0 ;
    
        while(temp != nullptr) 
        {
            countA++ ;
            temp = temp -> next ;
        }
    
        temp = headB ;
        int countB = 0 ;
    
        while(temp != nullptr)
        {
            countB++ ;
            temp = temp -> next ;
        }
    
        if (countA > countB)
        {
            int sub = countA - countB ;
    
            for(int i = 0 ; i < sub ; i++)
            {
                t1 = t1 -> next ;
            }
        }
        
        else if (countA < countB)
        {
            int sub = countB - countA ;
    
            for (int i = 0 ; i < sub ; i++)
            {
                t2 = t2 -> next ;
            }
        }
    
        while (t1 != NULL && t2 != NULL)
        {
            if (t1 == t2)
            {
                return t1 ;
            }
    
            t1 = t1 -> next ;
            t2 = t2 -> next ;
        }
    
        return nullptr ;
    
    
    
    
    
            // ListNode* a = headA ;
            // ListNode* b = headB ;
    
            // while (a != b)
            // {
            //     if (a == NULL)
            //     {
            //         a = headB ;
            //     }
    
            //     else
            //     {
            //         a = a -> next ;
            //     }
    
            //     if (b == NULL)
            //     {
            //         b = headA ;
            //     }
    
            //     else 
            //     {
            //         b = b -> next ;
            //     }
            // } 
    
            // return a;
        }
    };
    
    
    
    
    
    
    
    
    
    
    
    
    