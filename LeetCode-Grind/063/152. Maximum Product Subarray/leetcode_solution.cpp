class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            
            double max_prod = INT_MIN; 
            double pref = 1, suff = 1;
    
            for (int i = 0; i < n; i++) {
               
                if (pref == 0) pref = 1;
                if (suff == 0) suff = 1;
    
               
                pref = pref * nums[i];
                suff = suff * nums[n - i - 1];
    
                
                max_prod = max({max_prod, pref, suff});
            }
    
            return max_prod;
        }
    };