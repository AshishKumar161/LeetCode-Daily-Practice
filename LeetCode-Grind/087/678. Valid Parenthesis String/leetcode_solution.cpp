class Solution {
    public:
        bool checkValidString(string s) {
            int a = 0 ;
            int b = 0 ;
    
            int n = s.length() ;
    
            for (int i = 0 ; i < n ; i++)
            {
                if (s[i] == '(')
                {
                    a++ ;
                    b++ ;
                }
                else if (s[i] == ')')
                {
                    a-- ;
                    b-- ;
                }
    
                else 
                {
                    a-- ;
                    b++ ;
                }
    
                if (b < 0) 
                {
                    return false;
                }
    
                if (a < 0) 
                {
                    a = 0;
                }
            }
    
            return a == 0 ;
        }
    };