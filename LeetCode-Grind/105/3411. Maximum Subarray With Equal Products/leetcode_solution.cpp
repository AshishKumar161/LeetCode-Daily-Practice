class Solution {
    public:
        int maxLength(vector<int>& nums) {
            int  n = nums.size() ;
            int ans = 0 ;
    
            long long max_lcm = 1 ;
            int max_val = 0 ;
    
            for (int x : nums)
            {
                max_lcm = lcm(max_lcm , (long long) x) ;
                max_val = max(max_val , x) ;
            }
    
            long long max_prod = max_lcm * max_val ;
    
            for (int i = 0 ; i < n ; i++)
            {
                long long nums_prod = 1 ;
                long long nums_lcm  = 1 ;
                long long nums_gcd  = 0 ;
    
                for (int j = i ; j < n ; j++)
                {
                    nums_prod *= nums[j] ;
    
                    nums_lcm = lcm(nums_lcm , (long long) nums[j]) ;
                    nums_gcd = gcd(nums_gcd , (long long) nums[j]) ;
    
                    if (nums_prod == nums_lcm * nums_gcd)
                    {
                        ans = max(ans , j - i + 1) ;
                    }
    
                    if (nums_prod > max_prod)
                    {
                        break ;
                    }
                }
            }
    
            return ans ;
        }
    };
    