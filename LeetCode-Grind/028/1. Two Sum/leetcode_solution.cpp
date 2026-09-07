class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int , int> hash ;
        
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int need = target - nums[i] ;
            if(hash.find(need) != hash.end())
            {
                return {hash[i] , i } ;
            }
            hash[nums[i]] = i ; 
        }
        return {} ;
    }
}