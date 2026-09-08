class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map <int , int > hash ;
        for(int i = 0 ; i < n ; i++)
        {
            if(hash.find(nums[i]) != hash.end())
            {
                return true ;
            }
            hash[nums[i]] = i ;
        }
        return false ;
    }
};