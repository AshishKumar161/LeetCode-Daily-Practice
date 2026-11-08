class Solution {
    public:
        int candy(vector<int>& nums) {
            int n = nums.size() ;
    
            vector < int > left ;
            vector < int > right ;
    
            left.push_back(1) ;
            right.push_back(1) ;
    
            for (int i = 1 ; i < n ; i++)
            {
                if (nums[i] > nums[i-1])
                {
                    left.push_back(left[i-1] + 1) ;
                }
    
                if (nums[i] <= nums[i-1])
                {
                    left.push_back(1) ;
                } 
            }
    
            for (int i = n - 2 ; i >= 0 ; i--)
            {
                if (nums[i] > nums[i+1])
                {
                    right.push_back(right.back() + 1) ;
                }
    
                else 
                {
                    right.push_back(1) ;
                }
            }
    
            reverse(right.begin() , right.end()) ;
            
            int sum = 0 ;
    
            for (int i = 0 ; i < n ; i++)
            {
                sum += max(left[i] , right[i]) ;
            
            }
    
            return sum ;
        }
    };
    