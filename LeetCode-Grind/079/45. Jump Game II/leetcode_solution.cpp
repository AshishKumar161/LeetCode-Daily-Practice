class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size() ;
    
            int jump = 0 ;
            int curr_End = 0 ;
            int farthest = 0 ;
    
            for (int i = 0 ; i < n- 1 ; i++) 
            {
                farthest = max (farthest , nums[i] + i) ;
    
                if (curr_End == i)
                {
                    jump++ ;
                    curr_End = farthest ;
                }
            }
    
            return jump ;
        }
    };