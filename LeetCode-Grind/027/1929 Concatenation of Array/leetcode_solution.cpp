class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() ;
        int arr[2*n] ;
        int count = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            arr[i] = nums[i]; 
            count++ ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            arr[count] = nums[i] ;
            count++ ;
        }



        // vector < int > ans(2*n) ;
        // for (int i = 0 ; i < n ; i++)
        // {
        //     ans[i] = nums[i] ;
        //     ans[i + n] = nums[i] ;
        // }
        // return ans ;



        vector<int> ans(arr, arr + 2 * n);
        return ans ;
    }
};