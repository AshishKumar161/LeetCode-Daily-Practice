class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) {
            int n = events.size() ;
    
            sort (events.begin() , events.end()) ;
            int count = 0 ;
            
             // priority queue 
            priority_queue  < pair < int , int >  ,
                     vector < pair < int , int >> ,
                    greater < pair < int , int >> 
                            > pq ;
    
            long long startDay = 0 ;
            int idx = 0 ;
    
            while (idx < n || !pq.empty())
            {
                if (pq.empty() && startDay < events[idx][0])
                {
                    startDay = events[idx][0] ;
                }
    
                while (idx < n && events[idx][0] <= startDay )
                {
                    pq.push({events[idx][1] , events[idx][0]}) ;
                    idx++ ;
                }
    
                while (!pq.empty()  && pq.top().first < startDay )
                {
                    pq.pop() ;
                }
                
                if (!pq.empty())
                {
                    pq.pop() ;
                    count++ ;
                    startDay++ ;
                }
            }
    
            return count ;
        }
    };