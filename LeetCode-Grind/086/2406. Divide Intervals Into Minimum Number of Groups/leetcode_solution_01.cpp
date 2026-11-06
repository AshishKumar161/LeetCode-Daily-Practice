class Solution {
    public:
        int minGroups(vector<vector<int>>& nums) {
            int n = nums.size() ;
            
            vector < int > s ;
            vector < int > e ;
            
            if (n == 1)
            {
                return 1 ;
            }
    
            for (int i = 0 ; i < n ; i++)
            {
                s.push_back(nums[i][0]) ;
                e.push_back(nums[i][1]) ;
            }
    
            sort (s.begin() , s.end()) ;
            sort (e.begin() , e.end()) ;
    
            int count = 0 ;
            int ans = INT_MIN ;
            int i = 0 ;
            int j = 0 ;
    
            while ( i < n && j < n )
            {
                if (s[i] <= e[j] )
                {
                    count++ ;
                    i++ ;
                }
    
                else
                {
                    count-- ;
                    j++ ;
                }
    
                ans = max (ans , count ) ;
            }
    
            return ans ;
        }
    };