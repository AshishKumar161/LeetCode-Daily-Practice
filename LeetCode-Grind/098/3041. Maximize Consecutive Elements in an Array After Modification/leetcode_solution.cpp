class Solution {
    public:
        int maxSelectedElements(vector<int>& nums) {
    
            int n = nums.size() ;
            sort(nums.begin() , nums.end()) ;
    
            vector<int> ans ;
            vector<bool> bumped ;
    
            ans.push_back(nums[0]) ;
            bumped.push_back(false) ;
    
            int idx = 0 ;
            int maxi = 1 ;
    
            for (int i = 1 ; i < n ; i++) 
            {
    
                if (ans[idx] == nums[i]) 
                {
                    ans.push_back(nums[i] + 1) ;
                    bumped.push_back(true) ;
                    idx++ ;
                }
    
                else if (ans[idx] + 1 == nums[i]) 
                {
                    ans.push_back(nums[i]) ;
                    bumped.push_back(false) ;
                    idx++ ;
                }
    
                else if (ans[idx] + 2 == nums[i]) 
                {
    
                    int fullStart = idx ;
    
                    while (fullStart > 0 && ans[fullStart] == ans[fullStart - 1] + 1) 
                    {
                        fullStart-- ;
                    }
    
                    maxi = max(maxi , idx - fullStart + 1) ;
    
                    if (!bumped[idx]) 
                    {
    
                        int start = idx ;
    
                        while (start > 0 && ans[start] == ans[start - 1] + 1 && !bumped[start - 1]) 
                        {
                            start-- ;
                        }
    
                        for (int k = start ; k <= idx ; k++) 
                        {
                            ans[k]++ ;
                            bumped[k] = true ;
                        }
                    }
    
                    ans.push_back(nums[i]) ;
                    bumped.push_back(false) ;
                    idx++ ;
                }
    
                else if (ans[idx] < nums[i]) 
                {
                    ans.push_back(nums[i]) ;
                    bumped.push_back(false) ;
                    idx++ ;
                }
            }
    
            int count = 1 ;
    
            for (int i = 1 ; i < ans.size() ; i++) 
            {
                if(ans[i] == ans[i - 1] + 1) 
                {
                    count++ ;
                }
    
                else 
                {
                    count = 1 ;
                }
    
                maxi = max(maxi , count) ;
            }
    
            return maxi ;
        }
    };