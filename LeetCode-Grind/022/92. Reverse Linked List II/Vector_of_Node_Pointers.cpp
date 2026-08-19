class solution 
{
    public:
    ListNode* reverseBetween(ListNode* head , int left , int right)
    {
        if(head == NULL || head -> next == NULL || left == right)
        {
            return head ;
        }

        vector <ListNode*> nodes ;
        ListNode* curr = head ;
        while(curr != NULL)
        {
            nodes.push_back(curr) ;
            curr = curr -> next ;
        }
        left-- ;
        right-- ;

        while (left < right)
        {
            int val = nodes[left] -> val ;
            nodes[left] -> val = nodes[right] -> val ;
            nodes[right] -> val = val ;
        }
        return head ;
        
    }
}