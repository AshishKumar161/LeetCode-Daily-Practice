class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n = startTime.size() ;
    
            vector < vector < int >> SortedJob ;
    
            for (int i = 0 ; i < n ; i++)
            {
                SortedJob.push_back({startTime[i] , endTime[i] , profit[i]}) ;
            }
    
            sort(SortedJob.begin() , SortedJob.end()) ;
    
            vector < int > ans(n+1 ,0) ;
    
            vector < int > starts ;
    
            for (int i = 0; i < n; i++)
            {
                starts.push_back(SortedJob[i][0]);
            }
    
            for (int i = n - 1 ; i >= 0 ; i--)
            {
                int curr_time = SortedJob[i][1] ;
    
                int next = lower_bound(
                    starts.begin() + i + 1 ,
                    starts.end() ,
                    curr_time
                ) - starts.begin() ;
    
                int take = SortedJob[i][2] + ans[next] ; 
    
                int skip = ans[i + 1] ;
    
                ans[i] = max(take, skip) ; 
            }
            return ans[0] ;
        }
    };