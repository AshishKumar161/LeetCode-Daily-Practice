class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size() ;
            int maxx = 0 ;
            for (int i = 0 ; i < n ; i++)
            {
                if (i > maxx)
                {
                    return false ;
                }
                
                maxx = max(maxx , nums[i] + i) ;
            }
    
            return true ;
        }
    };