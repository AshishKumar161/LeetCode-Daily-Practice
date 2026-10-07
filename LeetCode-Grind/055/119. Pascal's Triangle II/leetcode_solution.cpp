class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector <int > answer ;
            
            long long ans = 1 ;
            answer.push_back(ans) ;
    
            for (int i = 1 ; i < rowIndex + 1 ; i++)
            {
                ans = ans * ((rowIndex + 1) - i) ;
                ans = ans / i ;
                answer.push_back(ans) ;
            }
    
            return answer ;
        }
    };