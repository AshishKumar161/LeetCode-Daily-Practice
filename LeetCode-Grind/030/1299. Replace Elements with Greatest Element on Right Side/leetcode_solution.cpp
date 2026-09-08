class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ;
        int max = -1 ;
        for(int i = n - 1  ; i >= 0 ; i--)
        {
            int temp = arr[i] ;
            arr[i] = max ;

            if (temp > max )
            {
                max = temp ;
            }
        }

        return arr ;
    }
};