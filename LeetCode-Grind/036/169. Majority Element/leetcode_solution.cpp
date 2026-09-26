class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;

        unordered_map <int , int > hash ;

        for(int i = 0 ; i < n ; i++)
        {
            hash[nums[i]]++ ;
        }

        for (auto x :hash)
        {
            if(x.second > n/2)
            {
                return x.first ;
            }
        }

        return -1 ;
    }
};