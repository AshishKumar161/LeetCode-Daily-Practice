class Solution {
    public:
        int minimizeSum(vector<int>& nums) {
            int n = nums.size() ;
    
            sort(nums.begin() , nums.end()) ;
            int ans = 0 ;
    
            // two smallest remove
            int a = nums[n - 1] - nums[2] ;
    
            // two largest remove
            int b = nums[n-3] - nums[0] ;
    
            // one smallest and one largest remove
            int c = nums[n - 2] - nums[1] ;
    
            ans = min({a ,b , c}) ;
    
            return ans ;
        }
    };
    