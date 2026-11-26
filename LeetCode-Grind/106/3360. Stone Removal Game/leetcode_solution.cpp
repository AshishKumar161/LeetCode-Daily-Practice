class Solution {
    public:
        bool canAliceWin(int n) {
            int remove = 10 ;
    
            while (remove > 0)
            {
                if (remove % 2 == 0)
                {
                    if(n >= remove)
                    {
                        n = n - remove ;
                        remove-- ;
                        continue ;
                    }
                    else
                    {
                        return false ;
                    }
                }
    
                if (remove % 2 == 1)
                {
                    if (n >= remove)
                    {
                        n = n - remove ;
                        remove-- ;
                        continue ;
                    }
                    else
                    {
                        return true  ;
                    }
                }
            }
    
            return false ;
        }
    };