class Solution {
    public:
        int mostBooked(int rooms, vector<vector<int>>& meetings) {
            int n = meetings.size() ;
            priority_queue <
                    vector < long long > ,
                    vector < vector < long long >> ,
                    greater< vector < long long >> 
                    > pq ;
            
        //  create rooms ;
            for (int i = 0 ; i < rooms ; i++)
            {
                pq.push({ 0, i, 0}) ; 
            }
    
            sort(meetings.begin() , meetings.end()) ;
    
            for (int i = 0 ; i < n ; i++)
            {
                long long start    = meetings[i][0] ;
                long long end      = meetings[i][1] ;
                long long duration = end - start ;
    
                vector < vector < long long >> temp ;
                // find free rooms ;
                while (!pq.empty() && pq.top()[0] <= start )
                {
                    temp.push_back(pq.top()) ;
                    pq.pop() ;
                }
    
                if (!temp.empty())
                {
                        sort(temp.begin() , temp.end() , []( vector< long long >& a , vector < long long>& b) 
                        {
                            return a[1] < b[1] ;
                        }) ;
                    vector < long long > room  = temp[0] ;
    
                    long long roomidx = room[1] ;
                    long long count   = room[2] + 1 ;
    
                    pq.push({end , roomidx , count}) ;
    
                    // push remaining rooms back ;
                    for (int i = 1 ; i < temp.size() ; i++)
                    {
                        pq.push(temp[i]) ;
                    }
                }
    
                else
                {
                    // all rooms are busy 
                    vector < long long > room = pq.top() ;
                    pq.pop() ;
    
                    long long newEnd = room[0] + duration ;
                    long long roomIdx = room[1] ;
                    long long count = room[2] + 1 ;
    
                    pq.push({newEnd , roomIdx , count }) ;
                }
            } 
    
            // max meeting 
            vector < long long > count (rooms ,0) ;
            while (!pq.empty())
            {
                vector < long long > room = pq.top() ;
                pq.pop() ;
    
                count[room[1]] = room[2] ;
            }
    
            int ans = 0 ;
            for (int i = 0 ; i < rooms ; i++ )
            {
                if (count[i] > count [ans])
                {
                    ans = i ;
                }
            }
    
            return ans ;
        }
    };