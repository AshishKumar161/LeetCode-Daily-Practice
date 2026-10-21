class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map < int , int > hash ;
            int n = nums.size() ;
            int sum = 0 ;
            int count = 0 ;
            hash[0] = 1 ;
            
            for (int i = 0 ; i < n ; i++)
            {
                sum = sum + nums[i] ;
    
                if(hash.find(sum - k ) != hash.end())
                {
                    count = count + hash[sum - k] ;
                }
                hash[sum]++ ;
            }
    
            return count ;
        }
    };