class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0 ;
        int min_profit = arr[0];
        
        for(int i = 0 ;  i < arr.size() ; i++)
        {
            min_profit = min(arr[i] , min_profit) ;
            profit = max(profit ,  arr[i] - min_profit) ;
        }
        
        return profit ;
    }
};