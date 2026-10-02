class Solution {
    public:
        bool checkPerfectNumber(int nums) {
            
            if (nums <= 1) {
                return false;
            }
    
            vector<int> ans;
            ans.push_back(1); 
    
            for (int i = 2; i * i <= nums; i++) {
                if (nums % i == 0) {
                    ans.push_back(i); 
                    
                    
                    if (i != nums / i) {
                        ans.push_back(nums / i);
                    }
                }
            }
    
            int m = ans.size();
            int sum = 0;
        
            
            for (int i = 0; i < m; i++) {
                sum += ans[i];
            }
    
            
            if (sum == nums) {
                return true;
            }
    
            return false;
        }
    };