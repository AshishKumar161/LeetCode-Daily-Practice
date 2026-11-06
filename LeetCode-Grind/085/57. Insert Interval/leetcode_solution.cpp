class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& arr) {
            int n = nums.size() ;
            int i = 0 ;
            vector < vector < int >> ans ;
            
            while (i < n && nums[i][1] < arr[0])
            {
                ans.push_back({nums[i]}) ;
                i++ ;
            }
    
            int start = arr[0] ;
            int end   = arr[1] ; 
    
            while(i < n && nums[i][0] <= end)
            {
                start = min(start, nums[i][0]) ;
                end   = max(end  , nums[i][1]) ;
                i++ ;
            }
    
            ans.push_back({start, end}) ;
    
            while (i < n)
            {
                ans.push_back({nums[i]}) ;
                i++ ;
            }
    
            return ans ;
        }
    };