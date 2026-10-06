vector < int > RowGenerate(int n ) 
{
    long long ans = 1;
    vector < int > answer ;
    answer.push_back(1) ;
    for (int i = 1 ; i < n ; i++)
    {
        ans = ans * (n - i) ;
        ans = ans / i ;
        answer.push_back(ans) ;
    }
    return answer ;
}


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector < vector < int > > ans ; 

        for (int i = 1 ; i <= numRows ; i++ )
        {
            ans.push_back(RowGenerate(i)) ;
        }

        return ans ;
    }
};