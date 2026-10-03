class Solution {
    public:
        void reverseString(vector<char>& s) {
            int n = s.size() ;
    
            int second = n -1 ;
    
            for (int i = 0; i < n/2 ; i++)
            {
                char temp = s[i] ;
                s[i] = s[second] ;
                s[second] = temp ;
                second-- ;
            }
    
            return ;
        }
    };