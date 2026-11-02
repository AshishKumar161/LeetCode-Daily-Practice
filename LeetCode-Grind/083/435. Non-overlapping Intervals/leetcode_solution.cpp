class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& nums) {
            sort (nums.begin() , nums.end() , [](vector < int >& a , vector < int >& b)
            {
                return a[1] < b[1] ;
            }) ;
    
            int count = 1 ;
            int free_time = nums[0][1] ;
        
            for (int i = 1 ; i < nums.size() ; i++)
            {
                if(nums[i][0] >= free_time )
                {
                    count++ ;
                    free_time = nums[i][1] ;
                }
            }
            return nums.size() - count  ;
        }
    };