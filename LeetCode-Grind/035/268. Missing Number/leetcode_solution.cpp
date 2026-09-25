class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;

        unordered_map<int ,int > hash ;

        for (int i = 0 ;i < n; i++ )
        {
            hash[nums[i]] = i ;
        }

        for(int i = 0 ; i< n ; i++)
        {
            if (hash.find(i) ==  hash.end())
            {
                return i ;
            } 
        }

        return n ;
    }
};