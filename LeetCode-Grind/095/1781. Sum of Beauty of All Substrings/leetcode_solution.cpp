class Solution {
    public:
        int beautySum(string s) 
        {   
            int n = s.size() ;
            int ans = 0 ;
    
    
            for (int i = 0 ; i < n ; i++)
            {
                string temp = "" ;
    
                for (int j = i ; j < n ; j++)
                {
                    temp += s[j] ;
               
    
                    vector < int > freq (26, 0) ;
    
                    for ( int k = 0 ; k < temp.size() ; k++)
                    {
                        freq[temp[k] - 'a']++ ;
                    }
    
                    int maxx = 0 ;
                    int minn = INT_MAX ;
    
                    for (int k = 0 ; k < 26 ; k++)
                    {
                        if (freq[k] > 0)
                        {
                            maxx = max (maxx , freq[k]) ;
                            minn = min (minn , freq[k]) ;
                        }
    
                    }
    
                    ans += (maxx - minn) ;
                    }
                }
    
            return ans ;
    
        }
    };