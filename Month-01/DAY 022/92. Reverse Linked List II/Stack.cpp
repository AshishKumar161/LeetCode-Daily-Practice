class Solution
{
    public:
    ListNode* reverseBetween(ListNode* head , int left , int right)
    {
        if (head == NULL || head -> next || NULL || left == right)
        {
            return head ;
        }
        for(int i = 1 ; i < left ; i++ )
        {
            curr = curr -> next ;
        }

        ListNode* start = curr ;
        
        stack <int> st ;

        for (int i = left ; i <= right ; i++)
        {
            st.push(curr -> val);
            curr = curr -> next ;
        }

        curr = start ;

        for(int i = left ; i <= right ; i++)
        {
            curr -> val = st.top();
            st.pop;
            curr = curr -> next ;
        }
        return head ;
    }
}