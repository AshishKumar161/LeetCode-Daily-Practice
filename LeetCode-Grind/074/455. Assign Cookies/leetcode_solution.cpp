class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
    
            sort(g.begin() , g.end()) ;
            sort(s.begin() , s.end()) ;
    
            int i = 0 ; // it pointes to greed  
            int j = 0 ; // it pointes to cookies 
    
            while (i < g.size() && j < s.size())
            {
                if (s[j] >= g[i])
                {
                    i++ ;
                }
                j++ ;
            }
    
            return i ;
        }
    };