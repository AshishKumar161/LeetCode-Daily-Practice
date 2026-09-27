class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;

        int left = 0 ;

        vector < int > matrixx ;

        while (left <  n)
        {
            for (int i = n-1 ; i >= 0 ; i--)
            {
                matrixx.push_back(matrix[i][left]) ;
            }
            left++ ;

        }

        int k = 0 ; 
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                matrix[i][j] = matrixx[k] ;
                k++;
            }
        }
    }
};