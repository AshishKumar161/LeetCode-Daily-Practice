class Solution {
    public:
        string removeOuterParentheses(string s) {
            // stack < int > st ;
            // string  ans ;
    
            // for (char c : s )
            // {
            //     if (c == '(' ) 
            //     {
            //         if (!st.empty())
            //         {
            //             ans = ans + c ;
            //         }
            //         st.push(c) ;
            //     }
    
            //     else
            //     {
            //         st.pop() ;
    
            //         if (!st.empty())
            //         {
            //             ans = ans + c ;
            //         }
            //     }
            // }
    
    
            int count = 0 ;
            string ans = "" ;
    
            for (int i = 0 ; i < s.length() ; i++)
            {
                if (s[i] == ')')
                {
                    count-- ;
                }
    
                if (count > 0)
                {
                    ans.push_back(s[i]) ;
                }
    
                if(s[i] == '(')
                {
                    count++ ;
                }
            }
    
    
            return ans ;
        }
    };