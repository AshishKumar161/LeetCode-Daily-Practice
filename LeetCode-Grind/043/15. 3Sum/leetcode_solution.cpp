class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size() ;
        vector < vector < int >> ans ;

        // sort 
        sort(nums.begin() , nums.end()) ;

        for (int i = 0 ; i < n ; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue ;
            }
            int first = i + 1 ;
            int second = n - 1 ;

            while(first < second)
            {

                int sum = (nums[i] + nums[first] + nums[second]) ;

                if (sum == 0 )
                {
                    ans.push_back({nums[i] , nums[first] , nums[second]}) ;
                
                    while (first < second && nums[first] == nums[first + 1])
                    {
                        first++ ;
                    }

                    while (first < second && nums[second] == nums[second - 1 ])
                    {
                        second-- ;
                    }

                    first++ ;
                    second-- ;
                }

                else if (sum < 0 ) 
                {
                    first++ ;
                }
                
                else 
                {
                    second-- ;
                }

            }
        }
        return ans ;
    }
};