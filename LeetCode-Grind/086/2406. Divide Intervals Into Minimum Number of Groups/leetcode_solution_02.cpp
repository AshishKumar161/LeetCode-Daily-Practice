class Solution {
    public:
        int minGroups(vector<vector<int>>& nums) {
    
            int n = nums.size() ;
    
            sort(nums.begin(), nums.end()) ;
    
            priority_queue<int, vector<int>, greater<int>> pq ;
    
            for (int i = 0 ; i < n ; i++)
            {
                if (!pq.empty() && nums[i][0] > pq.top())
                {
                    pq.pop() ;
                }
    
                pq.push(nums[i][1]) ;
            }
    
            return pq.size() ;
        }
    };