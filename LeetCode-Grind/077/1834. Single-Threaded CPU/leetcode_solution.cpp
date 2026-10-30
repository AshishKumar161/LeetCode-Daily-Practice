class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n  = tasks.size() ;
            vector < vector < int >> sortedTasks ;
    
            for (int i = 0; i < n ; i++)
            {
                int enqueueTime    = tasks[i][0] ;
                int processingTime = tasks[i][1] ;
                int index          = i           ;
    
                sortedTasks.push_back({enqueueTime , processingTime , index}) ; 
            }
    
            sort (sortedTasks.begin() , sortedTasks.end()) ;
    
            vector < int > ans ;
            long long curr_time = 0 ;
            int idx = 0 ;
    
            // priority queue 
            priority_queue  < pair < int , int >  ,
                     vector < pair < int , int >> ,
                    greater < pair < int , int >> 
                            > pq ;
    
            while ( idx < n || !pq.empty())
            {
                if (pq.empty() && curr_time < sortedTasks[idx][0])
                {
                    curr_time = sortedTasks[idx][0] ;
                }
    
                while (idx < n && sortedTasks[idx][0] <= curr_time)
                {
                    pq.push({sortedTasks[idx][1] , sortedTasks[idx][2]}) ;
                    idx++ ;
                }
    
                auto task = pq.top() ;
                pq.pop() ;
    
                curr_time = curr_time + task.first ;
                ans.push_back(task.second) ;
            }  
            
            return ans ;
        }
    };