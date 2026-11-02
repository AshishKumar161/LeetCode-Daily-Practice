class Solution {
    public:
        int findLongestChain(vector<vector<int>>& nums) {
    
            // vector < vector < int >> nums ;
    
            // for (int i = 0 ; i < n ; i++)
            // {
            //     int p1 = pairs[i][0] ;
            //     int p2 = pairs[i][1] ;
            //     int idx = i ;
    
            //     nums.push_back({p1 , p2 , idx}) ;
            // }
    
            sort(nums.begin() , nums.end() , [](vector < int >& a , vector < int >& b)
            {
                return a[1] < b[1] ;
            }) ;
    
            int curr_time = 1 ;
            int free_time = nums[0][1] ;
    
            for (int i = 1 ; i < nums.size() ; i++)
            {
                if(nums[i][0] > free_time )
                {
                    curr_time++ ;
                    free_time = nums[i][1] ;
                }
            }
    
            return curr_time ;
        }
    };