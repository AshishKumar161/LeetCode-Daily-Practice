class Solution {
    public:
        int minimizeSum(vector<int>& nums) {
            
            int n = nums.size() ;
    
            int s1 = INT_MAX ;
            int s2 = INT_MAX ;
            int s3 = INT_MAX ;
    
            int l1 = 0 ;
            int l2 = 0 ;
            int l3 = 0 ;
    
            for ( int i = 0 ; i < n  ; i++)
            {
                if(s1 > nums[i])
                {
                    s3 = s2 ;
                    s2 = s1 ;
                    s1 = nums[i] ;
                }
                else if (s2 > nums[i])
                {
                    s3 = s2 ;
                    s2 = nums[i] ;
                } 
                else if (s3 > nums[i])
                {
                    s3 = nums[i] ;
                }
    
                if (l1 < nums[i])
                {
                    l3 = l2 ;
                    l2 = l1 ;
                    l1 = nums[i] ;
                }
                else if (l2 < nums[i])
                {
                    l3 = l2 ;
                    l2 = nums[i] ;
                }
                else if (l3 < nums[i])
                {
                    l3 = nums[i] ;
                }
    
            }
    
            return min({l1 - s3 , l2 - s2 , l3 - s1 }) ;
        }
    };