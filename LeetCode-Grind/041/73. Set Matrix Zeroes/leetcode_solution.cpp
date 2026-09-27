class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_set<int> row_index;
        unordered_set<int> col_index;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index.insert(i);
                    col_index.insert(j);
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (row_index.count(i) || col_index.count(j))
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};






//                                    with unordered_map

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        unordered_map < int , bool> row_index;
        unordered_map < int , bool > col_index;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row_index[i] = true ;
                    col_index[j] = true ;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (row_index.count(i) || col_index.count(j))
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};