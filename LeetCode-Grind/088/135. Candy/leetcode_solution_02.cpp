class Solution {
    public:
        int candy(vector<int>& nums) {
            int n = nums.size() ;
            int total_candy = n ;
            int i = 1 ;
    
            while ( i < n )
            {
                if (nums[i] == nums[i-1])
                {
                    i++ ;
                    continue ;
                }
    
                int curr_peak = 0 ;
    
                while ( i < n && nums[i] > nums[i-1])
                {
                    curr_peak++ ;
                    total_candy += curr_peak ;
                    i++ ;
                }
    
                if (i == n )
                {
                    return total_candy ;
                }
    
                int curr_valley = 0 ;
    
                while (i < n && nums[i] < nums[i-1])
                {
                    curr_valley++ ;
                    total_candy += curr_valley ;
                    i++ ;
                }
    
                total_candy -= min(curr_peak , curr_valley) ;
            }
    
            return total_candy ; 
    
        }
    };