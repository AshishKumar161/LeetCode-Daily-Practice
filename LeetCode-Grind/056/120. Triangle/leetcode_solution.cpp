class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            vector < int > minimum ;
    
            for (auto &row : triangle) 
            {
                int mn = *min_element(row.begin(), row.end());
                minimum.push_back(mn) ;
            }
            
            int sum  = 0 ;
            for (auto &row : minimum)
            {
                    sum = sum + row ;
            }
    
            return sum ;
        }
    };